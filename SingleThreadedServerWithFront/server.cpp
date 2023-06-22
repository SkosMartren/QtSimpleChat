#include "server.h"



//______________SLOTS____________________________________________________________________


// используется в server.cpp: onReadyRead | onDisconnected [определенных ниже]
void server::SendUserList()
{
    qDebug() << QTime::currentTime() << "server.cpp: START SendUserList";

    QStringList userList;

    foreach(QString user, users.values()) { // users.values() == QList<QString> username all clients
        if(!user.isEmpty()){userList << user;}
    }

    // для каждого client будет вызываться сигнал readyRead на стороне клиента
    foreach(QTcpSocket * client, clients) {

        // /users: нужен для того, чтобы грамотно обрабоать регулярное выражение: QRegExp usersRegex("^/users:(.*)$")
        // в клиентском слоте readyRead
        client->write(QString("/users:" + userList.join(",") + "\n").toUtf8());
    }

}


void server::onReadyRead()
{

    qDebug() << QTime::currentTime() << "server.cpp: START onReadyRead";

    // Возвращает указатель на объект, отправивший сигнал, если он вызван в слоте, активированном сигналом
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender()); // client == client из incomingConnection == клиентский socket  со стороны клиента
    if( !client) {qWarning() <<"error cast";}

    while(client->canReadLine())
    {

        const QString line = QString::fromUtf8(client->readLine()).trimmed();
        //qDebug() << "Read line:" << line;
        emit logMessage(QLatin1String("Read line:") + line);

        // /CheckingForNewUser: добавлялся на стороне клиента в сокете connected()
        if(QRegExp meRegex("^/CheckingForNewUser:(.*)$"); meRegex.indexIn(line) != -1)/* обработка сигнала из clientwindow.cpp: onConnected*/

        {
            QString user = meRegex.cap(1);
            users[client] = user;

            foreach(QTcpSocket *client, clients){
                client->write(QString("Server:" + user + " joined the chat\n").toUtf8());
            }


            SendUserList();
        }
        else
            if(users.contains(client))/*обработка сигнала из clientwindow.cpp: on_Send_clicked*/

        {
            QString message = line;
            QString user = users[client];

            //qDebug() << "User:" << user;
            //qDebug() << "Message:" << message;
            //emit logMessage(QLatin1String("Message:") + message);

            // JSON
            emit logMessage(QString("JSON received {\n") +
                            "Data client: [\n" +
                            ("\"User\": ") + "\"" + user + "\"" + ",\n" +
                            ("\"Message\": ") + "\"" + message + "\"\n" +
                            "   ]\n" +
                            "}");




            foreach(QTcpSocket *otherClient, clients){
                otherClient->write(QString(user + ":" /*+ (QDateTime::currentDateTime()).toString()+"\n" */+ message + "\n").toUtf8());
            }
        }
        else
        {
            qWarning() << "Got bad message from client:" << client->peerAddress().toString() << line;
        }
    }

}


void server::onDisconnected()
{
    qDebug() << QTime::currentTime() << "server.cpp: START onDisconnected";

    // Возвращает указатель на объект, отправивший сигнал, если он вызван в слоте, активированном сигналом
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender()); // client == client из incomingConnection == клиентский socket  со стороны клиента
    if( !client) {qWarning() <<"error cast";}


    const QString user = users[client];

    if(CheckStopServer == 0  && !user.isEmpty()){

    qDebug() << "Client disconnected: " << client->peerName();
    emit logMessage(QLatin1String("Client ") + user  + QLatin1String(" disconnected"));

    qDebug() << "server.cpp: remove in onDisconnected";
    clients.remove(client);
    users.remove(client);
    client->disconnectFromHost();
    }


    SendUserList();

    // каждому подключенному клиенту пробрассывается соообщение о том, что user покинул чат.
    foreach(QTcpSocket *client, clients) {
       if(!users[client].isEmpty()) { client->write(QString("Server:" + user + " left the chat\n").toUtf8());}
    }

}


//__________________________________________________________________________________

server::server(QObject *parent) : QTcpServer(parent) {}
//server::server() {} // будет ошибка в serverwindow.cpp, ServerWindow


void server::incomingConnection(qintptr socketDescripter)
{
    qDebug() << QTime::currentTime() << "server.cpp: START incomingConnection";

    QTcpSocket *client = new QTcpSocket(this);

    // Устанавливаем дескриптор сокета, который этот сервер должен использовать при прослушивании входящих подключений к дескриптору сокета.
    client->setSocketDescriptor(socketDescripter);

    clients.insert(client);


    connect(client, &QTcpSocket::readyRead, this, &server::onReadyRead);

    connect(client, &QTcpSocket::disconnected, this, &server::onDisconnected);

    long long l_l_SocketDescripter = socketDescripter;
    //qDebug() << "New client with socket " << socketDescripter;
    // https://stackoverflow.com/questions/3211771/how-to-convert-int-to-qstring
    emit logMessage(QStringLiteral("New client Connected with socketDescripter ") + QString::number(l_l_SocketDescripter) );

    /*
    QObject::connect: No such slot QTcpServer::onReadyRead() in ..\server\server.cpp:28
    QObject::connect: No such slot QTcpServer::onDisconnected() in ..\server\server.cpp:30
    connect(client, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    connect(client, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    */
}


// используется в serverwindow.cpp: StartStopServer
void server::stopServer()
{
    qDebug() << QTime::currentTime() << "server.cpp: START stopServer";

    CheckStopServer = 1;

    for (QTcpSocket * client : clients) {

        if(!users[client].isEmpty()) {

        qDebug() << "Client disconnected: " << client->peerName();
        emit logMessage(QLatin1String("Client ") + users[client]  + QLatin1String(" disconnected"));
         client->disconnectFromHost(); // disconnectFromHost посылает сигнал disconnected
        }

    }

    clients.clear();
    users.clear();

    CheckStopServer = 0;
    close();
}
