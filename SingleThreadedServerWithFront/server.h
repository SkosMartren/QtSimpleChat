#ifndef SERVER_H
#define SERVER_H


#include <QMap>
#include <QSet>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>

class server : public QTcpServer
{
    Q_OBJECT // в конструкторе ServerWindow посылается сигнал &server::logMessage

signals:
    void logMessage(const QString &msg);

public:

    //  server();  // будет ошибка в serverwindow.cpp, ServerWindow
     explicit server(QObject *parent = nullptr);

     void stopServer(); // в публичной секции так как используется в serverwindow.cpp: StartStopServer


 private slots:
     void onDisconnected();

     void onReadyRead();


protected:
    void incomingConnection(qintptr socketDescripter);


private:

    // в отличие от users, clients используется в incomingConnection, откуда не получить user name,
    // поэтому clients не заменить на users.keys() [https://doc.qt.io/qt-6/qmap.html#keys]
    // но, возможно, стоит попробовать и снять тест работы
    QSet<QTcpSocket*> clients;

    // отображает сокет в user name
    QMap<QTcpSocket*,QString> users;

    bool CheckStopServer = 0;

    void SendUserList();

};

#endif // SERVER_H
