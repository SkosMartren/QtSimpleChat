#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QRegExp>


QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE


class ClientWindow : public QMainWindow
{
    Q_OBJECT


public:
    ClientWindow(QWidget *parent = nullptr);

    ~ClientWindow();






private slots:

    void onReadyRead();

    void onConnected();

    void onDisonnected();

    void on_Sign_clicked();

    void on_Send_clicked();

private:
    Ui::ClientWindow *ui;
    QTcpSocket *socket;

};
#endif // CLIENTWINDOW_H
