/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_list;
    QVBoxLayout *verticalLayout;
    QLineEdit *pageIndexEdit;
    QTableView *site_table;
    QPushButton *getSiteListBtn;
    QPushButton *clearSiteTableBtn;
    QGroupBox *groupBox_login;
    QPushButton *loginBtn;
    QLineEdit *cookieEdit;
    QPushButton *getCookieBtn;
    QLineEdit *planIdEdit;
    QPushButton *getPlanIdBtn;
    QLineEdit *userName;
    QLineEdit *userPwd;
    QGroupBox *groupBox_inspect;
    QPushButton *SignBtn;
    QPushButton *testBtn;
    QLineEdit *resIdEdit;
    QLineEdit *longitudeEdit;
    QLineEdit *latitudeEdit;
    QPushButton *checkSignBtn;
    QPushButton *checkSignBtn2;
    QPushButton *timeStartBtn;
    QLineEdit *siteNameEdit;
    QLineEdit *tableIndexEdit;
    QLineEdit *auto_task_num_edit;
    QTextEdit *console_edit;
    QPushButton *hideBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1318, 703);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/image/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_list = new QGroupBox(centralWidget);
        groupBox_list->setObjectName(QStringLiteral("groupBox_list"));
        groupBox_list->setGeometry(QRect(20, 130, 991, 391));
        verticalLayout = new QVBoxLayout(groupBox_list);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pageIndexEdit = new QLineEdit(groupBox_list);
        pageIndexEdit->setObjectName(QStringLiteral("pageIndexEdit"));

        verticalLayout->addWidget(pageIndexEdit);

        site_table = new QTableView(groupBox_list);
        site_table->setObjectName(QStringLiteral("site_table"));

        verticalLayout->addWidget(site_table);

        getSiteListBtn = new QPushButton(groupBox_list);
        getSiteListBtn->setObjectName(QStringLiteral("getSiteListBtn"));

        verticalLayout->addWidget(getSiteListBtn);

        clearSiteTableBtn = new QPushButton(groupBox_list);
        clearSiteTableBtn->setObjectName(QStringLiteral("clearSiteTableBtn"));

        verticalLayout->addWidget(clearSiteTableBtn);

        groupBox_login = new QGroupBox(centralWidget);
        groupBox_login->setObjectName(QStringLiteral("groupBox_login"));
        groupBox_login->setGeometry(QRect(10, 10, 941, 111));
        loginBtn = new QPushButton(groupBox_login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(260, 20, 151, 23));
        cookieEdit = new QLineEdit(groupBox_login);
        cookieEdit->setObjectName(QStringLiteral("cookieEdit"));
        cookieEdit->setGeometry(QRect(20, 50, 471, 20));
        getCookieBtn = new QPushButton(groupBox_login);
        getCookieBtn->setObjectName(QStringLiteral("getCookieBtn"));
        getCookieBtn->setGeometry(QRect(420, 20, 75, 23));
        planIdEdit = new QLineEdit(groupBox_login);
        planIdEdit->setObjectName(QStringLiteral("planIdEdit"));
        planIdEdit->setGeometry(QRect(20, 80, 231, 20));
        getPlanIdBtn = new QPushButton(groupBox_login);
        getPlanIdBtn->setObjectName(QStringLiteral("getPlanIdBtn"));
        getPlanIdBtn->setGeometry(QRect(270, 80, 75, 23));
        userName = new QLineEdit(groupBox_login);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(20, 20, 113, 20));
        userPwd = new QLineEdit(groupBox_login);
        userPwd->setObjectName(QStringLiteral("userPwd"));
        userPwd->setGeometry(QRect(140, 20, 113, 20));
        groupBox_inspect = new QGroupBox(centralWidget);
        groupBox_inspect->setObjectName(QStringLiteral("groupBox_inspect"));
        groupBox_inspect->setGeometry(QRect(30, 530, 761, 111));
        SignBtn = new QPushButton(groupBox_inspect);
        SignBtn->setObjectName(QStringLiteral("SignBtn"));
        SignBtn->setGeometry(QRect(20, 80, 75, 23));
        testBtn = new QPushButton(groupBox_inspect);
        testBtn->setObjectName(QStringLiteral("testBtn"));
        testBtn->setGeometry(QRect(670, 50, 75, 23));
        resIdEdit = new QLineEdit(groupBox_inspect);
        resIdEdit->setObjectName(QStringLiteral("resIdEdit"));
        resIdEdit->setGeometry(QRect(90, 20, 113, 20));
        longitudeEdit = new QLineEdit(groupBox_inspect);
        longitudeEdit->setObjectName(QStringLiteral("longitudeEdit"));
        longitudeEdit->setGeometry(QRect(20, 50, 161, 20));
        latitudeEdit = new QLineEdit(groupBox_inspect);
        latitudeEdit->setObjectName(QStringLiteral("latitudeEdit"));
        latitudeEdit->setGeometry(QRect(190, 50, 191, 20));
        checkSignBtn = new QPushButton(groupBox_inspect);
        checkSignBtn->setObjectName(QStringLiteral("checkSignBtn"));
        checkSignBtn->setGeometry(QRect(110, 80, 75, 23));
        checkSignBtn2 = new QPushButton(groupBox_inspect);
        checkSignBtn2->setObjectName(QStringLiteral("checkSignBtn2"));
        checkSignBtn2->setGeometry(QRect(200, 80, 75, 23));
        timeStartBtn = new QPushButton(groupBox_inspect);
        timeStartBtn->setObjectName(QStringLiteral("timeStartBtn"));
        timeStartBtn->setGeometry(QRect(570, 20, 75, 23));
        siteNameEdit = new QLineEdit(groupBox_inspect);
        siteNameEdit->setObjectName(QStringLiteral("siteNameEdit"));
        siteNameEdit->setGeometry(QRect(210, 20, 171, 20));
        tableIndexEdit = new QLineEdit(groupBox_inspect);
        tableIndexEdit->setObjectName(QStringLiteral("tableIndexEdit"));
        tableIndexEdit->setGeometry(QRect(20, 20, 61, 20));
        auto_task_num_edit = new QLineEdit(groupBox_inspect);
        auto_task_num_edit->setObjectName(QStringLiteral("auto_task_num_edit"));
        auto_task_num_edit->setGeometry(QRect(440, 20, 113, 20));
        console_edit = new QTextEdit(centralWidget);
        console_edit->setObjectName(QStringLiteral("console_edit"));
        console_edit->setGeometry(QRect(1020, 10, 291, 601));
        hideBtn = new QPushButton(centralWidget);
        hideBtn->setObjectName(QStringLiteral("hideBtn"));
        hideBtn->setGeometry(QRect(960, 10, 51, 111));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1318, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\212\275\346\243\200\345\212\251\346\211\213", 0));
        groupBox_list->setTitle(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\210\227\350\241\250", 0));
        pageIndexEdit->setText(QApplication::translate("MainWindow", "0", 0));
        getSiteListBtn->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\270\205\345\215\225", 0));
        clearSiteTableBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\241\250\346\240\274", 0));
        groupBox_login->setTitle(QApplication::translate("MainWindow", "\347\231\273\345\275\225\350\216\267\345\217\226Cookie", 0));
        loginBtn->setText(QApplication::translate("MainWindow", "\346\230\223\350\277\220\347\273\264\344\270\273\347\225\214\351\235\242\347\231\273\345\275\225", 0));
        cookieEdit->setText(QApplication::translate("MainWindow", "JSESSIONID=6215F2A44F8F98C61194A5CDB1AA89EB; username=CHENRONGHUI", 0));
        getCookieBtn->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226Cookie", 0));
        planIdEdit->setText(QString());
        getPlanIdBtn->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226PlanId", 0));
        userName->setText(QApplication::translate("MainWindow", "CHENRONGHUI", 0));
        userPwd->setText(QApplication::translate("MainWindow", "PA4ZG1NMT04%3D", 0));
        groupBox_inspect->setTitle(QApplication::translate("MainWindow", "\346\212\275\346\243\200", 0));
        SignBtn->setText(QApplication::translate("MainWindow", "\347\255\276\345\210\260", 0));
        testBtn->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225", 0));
        checkSignBtn->setText(QApplication::translate("MainWindow", "\347\255\276\351\200\200", 0));
        checkSignBtn2->setText(QApplication::translate("MainWindow", "\347\255\276\351\200\2002", 0));
        timeStartBtn->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\212\275\346\243\200", 0));
        auto_task_num_edit->setText(QApplication::translate("MainWindow", "5", 0));
        hideBtn->setText(QApplication::translate("MainWindow", "\351\232\220\350\227\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
