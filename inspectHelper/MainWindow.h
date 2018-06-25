#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtGui"

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkCookieJar>

#include <NetworkCookieJar.h>

#include "TableViewService.h"
#include "SiteObject.h"
#include "mshtml.h"
#include "comutil.h"
#include <ActiveQt/QAxObject>
#include "AutoThread.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void httpReplySlot(QNetworkReply *reply);

    void on_testBtn_clicked();

    void on_loginBtn_clicked();



    void on_getSiteListBtn_clicked();

    void on_SignBtn_clicked();

    void on_site_table_doubleClicked(const QModelIndex &index);

    void on_checkSignBtn_clicked();

    void on_checkSignBtn2_clicked();

    void on_getPlanIdBtn_clicked();

    void on_clearSiteTableBtn_clicked();

    void on_getCookieBtn_clicked();

    void on_timeStartBtn_clicked();

    void updateTime();

    void receiveAutoThreadMsg(ThreadMsg s);

    void loadSite(int index);
private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *m_accessManager;
    NetworkCookieJar *networkCookieJar;
    QNetworkRequest *request;

    TableViewService *tableViewService;

    void my_post(QString url,QString postDataStr);
    void initHttp();

    void my_debug(QString s);

    QTimer * timer;
    QTime * timeRecord;

};

#endif // MAINWINDOW_H
