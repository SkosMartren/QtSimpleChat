/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *Chat;
    QGridLayout *gridLayout_2;
    QLineEdit *MessagelineEdit;
    QListWidget *UserlistWidget;
    QTextBrowser *MessagesBox;
    QPushButton *Send;
    QWidget *Login;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *LoginFrame;
    QGridLayout *gridLayout;
    QLabel *EmptyLabel;
    QLabel *UsernameLabel;
    QLineEdit *UserlineEdit;
    QLabel *EmptyLabel_2;
    QPushButton *Sign;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(800, 600);
        ClientWindow->setMinimumSize(QSize(100, 100));
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(100, 100));
        Chat = new QWidget();
        Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->setEnabled(true);
        Chat->setMinimumSize(QSize(100, 100));
        gridLayout_2 = new QGridLayout(Chat);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        MessagelineEdit = new QLineEdit(Chat);
        MessagelineEdit->setObjectName(QString::fromUtf8("MessagelineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MessagelineEdit->sizePolicy().hasHeightForWidth());
        MessagelineEdit->setSizePolicy(sizePolicy);
        MessagelineEdit->setMinimumSize(QSize(100, 0));
        MessagelineEdit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 10px;\n"
"     padding: 0 8px;\n"
"	 background: white;\n"
"     selection-background-color: darkgray;\n"
" }"));

        gridLayout_2->addWidget(MessagelineEdit, 1, 0, 1, 3);

        UserlistWidget = new QListWidget(Chat);
        UserlistWidget->setObjectName(QString::fromUtf8("UserlistWidget"));
        UserlistWidget->setStyleSheet(QString::fromUtf8("QListView {\n"
"     background-color: white;\n"
"	  border-radius: 15px;\n"
" }"));

        gridLayout_2->addWidget(UserlistWidget, 0, 0, 1, 1);

        MessagesBox = new QTextBrowser(Chat);
        MessagesBox->setObjectName(QString::fromUtf8("MessagesBox"));
        MessagesBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MessagesBox->sizePolicy().hasHeightForWidth());
        MessagesBox->setSizePolicy(sizePolicy1);
        MessagesBox->setMinimumSize(QSize(550, 100));
        MessagesBox->setStyleSheet(QString::fromUtf8("  QTextBrowser{\n"
"     background-color: white;\n"
"	 border-radius: 15px;\n"
" }"));

        gridLayout_2->addWidget(MessagesBox, 0, 1, 1, 3);

        Send = new QPushButton(Chat);
        Send->setObjectName(QString::fromUtf8("Send"));
        Send->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"\n"
"     min-width: 80px;\n"
"	 min-height: 25px;\n"
" }"));

        gridLayout_2->addWidget(Send, 1, 3, 1, 1);

        stackedWidget->addWidget(Chat);
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        gridLayout_4 = new QGridLayout(Login);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);

        LoginFrame = new QFrame(Login);
        LoginFrame->setObjectName(QString::fromUtf8("LoginFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LoginFrame->sizePolicy().hasHeightForWidth());
        LoginFrame->setSizePolicy(sizePolicy2);
        LoginFrame->setMinimumSize(QSize(550, 50));
        LoginFrame->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     border: 0px solid rgb(28, 43, 255);\n"
"     border-radius: 15px;\n"
"     padding: 2px;\n"
"	background-color: rgb(203, 206, 255);\n"
"\n"
" }"));
        LoginFrame->setFrameShape(QFrame::StyledPanel);
        LoginFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(LoginFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        EmptyLabel = new QLabel(LoginFrame);
        EmptyLabel->setObjectName(QString::fromUtf8("EmptyLabel"));

        gridLayout->addWidget(EmptyLabel, 0, 0, 1, 1);

        UsernameLabel = new QLabel(LoginFrame);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));

        gridLayout->addWidget(UsernameLabel, 1, 0, 1, 1);

        UserlineEdit = new QLineEdit(LoginFrame);
        UserlineEdit->setObjectName(QString::fromUtf8("UserlineEdit"));
        UserlineEdit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 10px;\n"
"     padding: 0 8px;\n"
"	 background: white;\n"
"     selection-background-color: darkgray;\n"
" }"));

        gridLayout->addWidget(UserlineEdit, 1, 1, 1, 1);

        EmptyLabel_2 = new QLabel(LoginFrame);
        EmptyLabel_2->setObjectName(QString::fromUtf8("EmptyLabel_2"));

        gridLayout->addWidget(EmptyLabel_2, 3, 0, 1, 1);

        Sign = new QPushButton(LoginFrame);
        Sign->setObjectName(QString::fromUtf8("Sign"));

        gridLayout->addWidget(Sign, 2, 1, 1, 1);


        gridLayout_4->addWidget(LoginFrame, 1, 1, 1, 1);

        stackedWidget->addWidget(Login);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(frame);

        ClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ClientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientWindow->setStatusBar(statusbar);

        retranslateUi(ClientWindow);
        QObject::connect(UserlineEdit, SIGNAL(returnPressed()), Sign, SLOT(animateClick()));
        QObject::connect(MessagelineEdit, SIGNAL(returnPressed()), Send, SLOT(animateClick()));

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QApplication::translate("ClientWindow", "ClientWindow", nullptr));
        MessagelineEdit->setPlaceholderText(QApplication::translate("ClientWindow", "Write a message...", nullptr));
        Send->setText(QApplication::translate("ClientWindow", "Send", nullptr));
        EmptyLabel->setText(QString());
        UsernameLabel->setText(QApplication::translate("ClientWindow", "User name", nullptr));
        UserlineEdit->setPlaceholderText(QApplication::translate("ClientWindow", "enter a nickname without the colon character", nullptr));
        EmptyLabel_2->setText(QString());
        Sign->setText(QApplication::translate("ClientWindow", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
