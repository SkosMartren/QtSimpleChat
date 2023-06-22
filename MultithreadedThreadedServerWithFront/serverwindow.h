#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSet>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
class server;

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWindow; }
QT_END_NAMESPACE

class ServerWindow : public QMainWindow
{
    Q_OBJECT


public:
    ServerWindow();

    ~ServerWindow();


private slots:

    void StartStopServer();
    void logMessage(const QString &msg);

private:
    Ui::ServerWindow *ui;
    server* Server;

};
#endif // SERVERWINDOW_H
