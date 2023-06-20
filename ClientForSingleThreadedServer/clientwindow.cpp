#include "clientwindow.h"
#include "ui_clientwindow.h"

#include <QMessageBox>

ClientWindow::ClientWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::ClientWindow)
{
    qDebug() << QTime::currentTime()<< "clientwindow.cpp: START ClientWindow";

    ui->setupUi(this);

    socket = new QTcpSocket(this);

    ui->stackedWidget->setCurrentWidget(ui->Login);

    connect(socket, &QTcpSocket::readyRead, this, &ClientWindow::onReadyRead);

    connect(socket, &QTcpSocket::connected, this, &ClientWindow::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ClientWindow::onDisonnected);


}


ClientWindow::~ClientWindow() {delete ui;}


//_____________REALISE_WIDGETS________________________________________________________________________


void ClientWindow::on_Sign_clicked()
{
    qDebug() << QTime::currentTime()<< "clientwindow.cpp: START on_Sign_clicked";

    socket->connectToHost("localhost", 8080);

}


void ClientWindow::on_Send_clicked()
{

    qDebug() << QTime::currentTime() << "clientwindow.cpp: START Send";

    QString Message =  ui->MessagelineEdit->text().trimmed();
    if(!Message.isEmpty()){socket->write(QString(Message + "\n").toUtf8());}

     ui->MessagelineEdit->clear();
}


//_____________REALISE_SLOTS________________________________________________________________________


void ClientWindow::onReadyRead()
{
    qDebug() << QTime::currentTime() << "clientwindow.cpp: START readyRead";


    while(socket->canReadLine())
    {

        QString line = QString::fromUtf8(socket->readLine()).trimmed();


        if(QRegExp usersRegex("^/users:(.*)$"); usersRegex.exactMatch(line)) /* используется для сигнала, полученнго из
                                                                                server.cpp: SendUserList*/
        {

            QStringList users = usersRegex.cap(1).split(",");
            ui->UserlistWidget->clear();

            foreach(const QString user, users){

                // https://doc.qt.io/qt-6/qlistwidgetitem.html#QListWidgetItem-2
                // файл user.png находится в той же папке, где и chatterbox.pro
                new QListWidgetItem(QPixmap(":/user.png"), user, ui->UserlistWidget);
            }

        }

        else

            /*
            user == messageRegex.cap(1);
            message == messageRegex.cap(2);
            */
            if(QRegExp messageRegex("^([^:]+):(.*)$"); messageRegex.exactMatch(line)) /* используется для сигнала, полученнго из
                                                                                         server.cpp: onDisconnected
                                                                                         server.cpp: onReadyRead*/
        {
            ui->MessagesBox->append("<b>" + messageRegex.cap(1) + "</b>: " + messageRegex.cap(2));
        }
    }

}


void ClientWindow::onConnected()
{
    qDebug() << QTime::currentTime() << "clientwindow.cpp: START connected";

    // /CheckingForNewUser: необходимо для качественно обрабоки входных данных в onReadyRead на стороне сервера
    socket->write(QString("/CheckingForNewUser:" + ui->UserlineEdit->text() + "\n").toUtf8());

    ui->stackedWidget->setCurrentWidget(ui->Chat);
}


void ClientWindow::onDisonnected()
{
QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
}

