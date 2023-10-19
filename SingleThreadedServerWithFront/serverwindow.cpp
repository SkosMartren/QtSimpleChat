#include "serverwindow.h"
#include "ui_serverwindow.h"

#include "server.h" // необходим для работы ServerWindow, а именно сигнала &server::logMessage и Server(new server(this))


//______________SLOTS____________________________________________________________________


void ServerWindow::logMessage(const QString &msg)
{

    qDebug() << QTime::currentTime() << "serverwindow.cpp: START logMessage";

    ui->logBox->appendPlainText(msg + "\n"); // logBox из "serverwindow.ui"
}



void ServerWindow::StartStopServer()
{

    qDebug() << QTime::currentTime() << "serverwindow.cpp: START StartStopServer";

    if (Server->isListening()) {


        logMessage(QStringLiteral("Server Stopped"));
        Server->stopServer();

        ui->StartStopButton->setText(tr("Start Server"));  // StartStopButton из "serverwindow.ui"


    } else {
        if (!Server->listen(QHostAddress::Any, 8080)) {

            qDebug() << "serverwindow.cpp: Unable to start the server\n";
            return;
        }

        logMessage(QStringLiteral("Server Started"));
        ui->StartStopButton->setText(tr("Stop Server"));  // StartStopButton из "serverwindow.ui"
    }


}


//__________________________________________________________________________________


ServerWindow::ServerWindow() :  ui(new Ui::ServerWindow), Server(new server(this))
{
    qDebug() << QTime::currentTime() << "serverwindow.cpp: START ServerWindow";

    ui->setupUi(this);

    connect(ui->StartStopButton, &QPushButton::clicked, this, &ServerWindow::StartStopServer);  // StartStopButton из "serverwindow.ui"
    connect(Server, &server::logMessage, this, &ServerWindow::logMessage);
}


ServerWindow::~ServerWindow() {delete ui;}




