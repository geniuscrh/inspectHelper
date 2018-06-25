#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initHttp();

    tableViewService=new TableViewService();
    tableViewService->setSite_table(ui->site_table);
    tableViewService->initSiteTable();

    timer = new QTimer;
    timeRecord = new QTime(0, 0, 0); //初始化时间
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initHttp(){
    m_accessManager =  new QNetworkAccessManager();
    request= new QNetworkRequest();
    networkCookieJar=new NetworkCookieJar();
    m_accessManager->setCookieJar(networkCookieJar);

    QObject::connect(m_accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpReplySlot(QNetworkReply*)));
}

void MainWindow::my_debug(QString s)
{
    ui->console_edit->append(s);
}

void MainWindow::httpReplySlot(QNetworkReply *reply){
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QString string = QString::fromUtf8(bytes);


        QString url=reply->url().toString();


        if(url.contains("Login.action")&&url.contains("183.252.192.25")){

            string=string.replace("\"","'");

            if(string.contains("登录成功")){
                my_debug("易运维界面登录成功！");

            }else{
                my_debug("易运维界面登录失败！");

            }
        }
        else if(url.contains("183.252.192.28")&&url.contains("androidAction")&&string.contains("developerSerialNumber")){

            string=string.replace("\"","'");
            int sp,ep;
            sp=string.indexOf("JID");
            sp=string.indexOf(":",sp)+1;
            ep=string.indexOf("}",sp);
            QString JSESSIONID=string.mid(sp,ep-sp);
            JSESSIONID=JSESSIONID.replace("'","");

            ui->cookieEdit->setText("JSESSIONID="+JSESSIONID+"; username="+ui->userName->text());

            my_debug("获取Cookie成功:"+JSESSIONID);

        }
        else if(url.contains("inspectSpotcheckAction")&&string.contains("RN")&&string.contains("RESID")){

            string=string.replace("\"","'");

            //QList<SiteObject*>* siteList=new QList<SiteObject*>();
            int sp=0,ep=0;
            while(true){
                sp=string.indexOf("{",ep);
                ep=string.indexOf("}",sp);

                if(sp==-1){
                    break;
                }
                QString o_text=string.mid(sp,ep-sp);
                SiteObject *site_o=new SiteObject(o_text);
                tableViewService->insertSiteTableItem(site_o);
            }
            my_debug("获取抽检清单成功！");
        }
        else if(string.contains("planName")&&string.contains("deptMagId")&&string.contains("returnList")){
            //获取PlanID

            string=string.replace("\"","'");
            int sp,ep;
            sp=string.indexOf("id");
            sp=string.indexOf(":",sp)+1;
            ep=string.indexOf(",",sp);
            QString planID=string.mid(sp,ep-sp);
            planID=planID.replace("'","");

            ui->planIdEdit->setText(planID);
            my_debug("获取PlanID成功:"+string);
        }
        else if(url.contains("inspectSpotcheckAction")&&string.contains("success")&&string.contains("true")){
            //获取PlanID
            my_debug("成功");
           //ui->statusBar->showMessage("签退成功",2*1000);
        }


        else{
            qDebug()<<url;
            qDebug()<<string;
        }



    }
    else
    {
        //myDebug("finishedSlot出错");
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        //myDebug("found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
        //myDebug(qPrintable(reply->errorString()));
    }
    reply->deleteLater();
}

void MainWindow::my_post(QString url, QString postDataStr)
{


}

void MainWindow::on_testBtn_clicked()
{

}

void MainWindow::on_loginBtn_clicked()
{
    QString url="http://183.252.192.25:3012/MobilePlatformWeb/login/Login.action";
    QString postDataStr="verify=28CC2FC54C3DB8228ADB3527993E69D7&loginname="+ui->userName->text()+"&psde="+ui->userPwd->text()+"&is4A=false";

    request->setUrl(QUrl(url));
    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Apache-HttpClient/UNAVAILABLE (java 1.4)");
    request->setRawHeader("Connection","Keep-Alive");


    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);


    /*
    QString url="http://183.252.192.25:3012/MobilePlatformWeb/locationRecord/saveLocation.action";
    QString postDataStr="username=CHENRONGHUI&lon=118.15706&lat=24.730101&time=2018-05-19+17%3A07%3A27&operateid=4&operatetype=%E7%94%A8%E6%88%B7%E5%8D%95%E7%82%B9&clienttype=android&versioncode=30303&appName=%E5%B1%9E%E5%9C%B0%E5%8C%96%E5%B7%A1%E6%A3%80&imsi=460110268879956&mycheck=DS8iKSwlECwhNCYvMi0XJSI%3D";

    request->setUrl(QUrl(url));
    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Apache-HttpClient/UNAVAILABLE (java 1.4)");
    request->setRawHeader("Connection","Keep-Alive");



    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
    */

}


void MainWindow::on_getSiteListBtn_clicked()
{
    ui->statusBar->showMessage("正在获取抽检清单……",5*1000);

    QString url="http://183.252.192.28:8080/web/partner/inspect/inspectSpotcheckAction.do";
    QString pageIndex=ui->pageIndexEdit->text();
    QString postDataStr="latitude=&resName=&planId="+ui->planIdEdit->text()+"&method=findInspectPlanResSpotcheckList&longitude=&inspectState=-1&pageIndex="+pageIndex;

    QString cookie_str=ui->cookieEdit->text();

    request->setUrl(QUrl(url));

    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded; charset=utf-8");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Android_client");
    request->setRawHeader("Accept-Encoding","gzip");
    request->setRawHeader("appPackageName","com.boco.inspectplan");
    request->setRawHeader("appVersionCode","1086");
    request->setRawHeader("appVersionName","1.0.8.6");
    request->setRawHeader("appDeviceId","359850051017395");
    request->setRawHeader("Connection","Keep-Alive");
    request->setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request->setRawHeader("Accept-Language","zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    request->setRawHeader("Cookie",cookie_str.toUtf8());


    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
}

void MainWindow::on_SignBtn_clicked()
{
    int table_index=ui->tableIndexEdit->text().toInt();
    tableViewService->updateSiteTable_signInTime(table_index);



    QString resId=ui->resIdEdit->text();
    QString lng=ui->longitudeEdit->text();
    QString lat=ui->latitudeEdit->text();

    QString url="http://183.252.192.28:8080/web/partner/inspect/inspectSpotcheckAction.do";
    QString postDataStr="latitude="+lat+"&resId="+resId+"&method=saveInspectSpotcheckSign&status=1&longitude="+lng+"&type=android";

    QString cookie_str=ui->cookieEdit->text();
    request->setUrl(QUrl(url));

    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded; charset=utf-8");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Android_client");
    request->setRawHeader("Accept-Encoding","gzip");
    request->setRawHeader("appPackageName","com.boco.inspectplan");
    request->setRawHeader("appVersionCode","1086");
    request->setRawHeader("appVersionName","1.0.8.6");
    request->setRawHeader("appDeviceId","359850051017395");
    request->setRawHeader("Connection","Keep-Alive");
    request->setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request->setRawHeader("Accept-Language","zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    request->setRawHeader("Cookie",cookie_str.toUtf8());


    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
}

void MainWindow::on_site_table_doubleClicked(const QModelIndex &index)
{
    if(index.row()<0){
            return;
     }

    loadSite(index.row());


}

void MainWindow::loadSite(int i)
{
    QStandardItemModel  *myModel =(QStandardItemModel*)ui->site_table->model();

    QString resId=myModel->index(i,1).data().toString();
    double lng=myModel->index(i,3).data().toString().toDouble();
    double lat=myModel->index(i,4).data().toString().toDouble();
    QString siteName=myModel->index(i,2).data().toString();


    lng+=0.0001;
    lat+=0.0001;

    ui->tableIndexEdit->setText(QString::number(i));
    ui->siteNameEdit->setText(siteName);
    ui->resIdEdit->setText(resId);
    ui->longitudeEdit->setText(QString::number(lng,'f',6));
    ui->latitudeEdit->setText(QString::number(lat,'f',6));

    my_debug("加载站点："+siteName);
}

void MainWindow::on_checkSignBtn_clicked()
{
    QString resId=ui->resIdEdit->text();
    QString lng=ui->longitudeEdit->text();
    QString lat=ui->latitudeEdit->text();

    QString url="http://183.252.192.28:8080/web/partner/inspect/inspectSpotcheckAction.do";
    QString postDataStr="latitude="+lat+"&resId="+resId+"&method=saveInspectSpotcheckEnd&status=1&longitude="+lng;

    QString cookie_str=ui->cookieEdit->text();
    request->setUrl(QUrl(url));

    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded; charset=utf-8");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Android_client");
    request->setRawHeader("Accept-Encoding","gzip");
    request->setRawHeader("appPackageName","com.boco.inspectplan");
    request->setRawHeader("appVersionCode","1086");
    request->setRawHeader("appVersionName","1.0.8.6");
    request->setRawHeader("appDeviceId","359850051017395");
    request->setRawHeader("Connection","Keep-Alive");
    request->setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request->setRawHeader("Accept-Language","zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    request->setRawHeader("Cookie",cookie_str.toUtf8());


    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
}

void MainWindow::on_checkSignBtn2_clicked()
{
    int table_index=ui->tableIndexEdit->text().toInt();
    tableViewService->updateSiteTable_signOutTime(table_index);


    QString resId=ui->resIdEdit->text();
    QString planId=ui->planIdEdit->text();


    QString url="http://183.252.192.28:8080/web/partner/inspect/inspectSpotcheckAction.do";
    QString postDataStr="planId="+planId+"&json=%5B%5D&resId="+resId+"&method=saveInspectSpotcheckByMobile";

    QString cookie_str=ui->cookieEdit->text();
    request->setUrl(QUrl(url));

    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded; charset=utf-8");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Android_client");
    request->setRawHeader("Accept-Encoding","gzip");
    request->setRawHeader("appPackageName","com.boco.inspectplan");
    request->setRawHeader("appVersionCode","1086");
    request->setRawHeader("appVersionName","1.0.8.6");
    request->setRawHeader("appDeviceId","359850051017395");
    request->setRawHeader("Connection","Keep-Alive");
    request->setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request->setRawHeader("Accept-Language","zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    request->setRawHeader("Cookie",cookie_str.toUtf8());


    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
}

void MainWindow::on_getPlanIdBtn_clicked()
{
    QString url="http://183.252.192.28:8080/web/partner/inspect/inspectSpotcheckAction.do";
    QString postDataStr="pageIndex=1&method=findInspectPlanMainList";

    QString cookie_str=ui->cookieEdit->text();
    request->setUrl(QUrl(url));

    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded; charset=utf-8");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Android_client");
    request->setRawHeader("Accept-Encoding","gzip");
    request->setRawHeader("appPackageName","com.boco.inspectplan");
    request->setRawHeader("appVersionCode","1086");
    request->setRawHeader("appVersionName","1.0.8.6");
    request->setRawHeader("appDeviceId","359850051017395");
    request->setRawHeader("Connection","Keep-Alive");
    request->setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request->setRawHeader("Accept-Language","zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    request->setRawHeader("Cookie",cookie_str.toUtf8());

   // m_accessManager->setCookieJar(networkCookieJar);

    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
}

void MainWindow::on_clearSiteTableBtn_clicked()
{
    tableViewService->clearSiteTable();
}

void MainWindow::on_getCookieBtn_clicked()
{
    QString url="http://183.252.192.28:8080/web/android/androidAction.do";
    QString postDataStr="isFirstRequest=false&versionName=1.0.8.6&packageName=com.boco.inspectplan&method=login&location=success&versionCode=1086&j_username=&imsi=460009530923128&j_password=";

    QString cookie_str=ui->cookieEdit->text();
    request->setUrl(QUrl(url));

    request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded; charset=utf-8");
    request->setHeader(QNetworkRequest::UserAgentHeader,"Android_client");
    request->setRawHeader("Accept-Encoding","gzip");
    request->setRawHeader("appPackageName","com.boco.inspectplan");
    request->setRawHeader("appVersionCode","1086");
    request->setRawHeader("appVersionName","1.0.8.6");
    request->setRawHeader("appDeviceId","359850051017395");
    request->setRawHeader("Connection","Keep-Alive");
    request->setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request->setRawHeader("Accept-Language","zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    request->setRawHeader("Cookie",cookie_str.toUtf8());


    QByteArray postData;
    postData.append(postDataStr);
    QNetworkReply* reply = m_accessManager->post(*request,postData);
}

void MainWindow::on_timeStartBtn_clicked()
{
    qRegisterMetaType<ThreadMsg>("ThreadMsg");
    AutoThread *autoThread=new AutoThread();
    connect(autoThread,SIGNAL(returnMsg(ThreadMsg)),this,SLOT(receiveAutoThreadMsg(ThreadMsg)));
    autoThread->start();



    timeRecord = new QTime(0, 0, 0);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);
}

void MainWindow::updateTime()
{
    *timeRecord = timeRecord->addSecs(1);
    if(timeRecord->minute()>=10){
        ui->statusBar->showMessage("计时10分钟完成",60*1000);
        timer->stop();
    }

    ui->statusBar->showMessage("计时："+timeRecord->toString("mm:ss"),1000);
}

void MainWindow::receiveAutoThreadMsg(ThreadMsg msg)
{
    if(msg.getMsgType()==AutoThread::Thread_SIGNAL_LOAD_SITE) {
       //my_debug("Thread Msg:"+msg.getMsgString());
       int table_index=tableViewService->loadSiteTableItemIndex();
       loadSite(table_index);
    }
    else if(msg.getMsgType()==AutoThread::Thread_SIGNAL_SIGNIN) {
       my_debug("Thread Msg:"+msg.getMsgString());
       on_SignBtn_clicked();
    }
    else if(msg.getMsgType()==AutoThread::Thread_SIGNAL_SIGNOUT_1) {
       my_debug("Thread Msg:"+msg.getMsgString());
       on_checkSignBtn_clicked();
    }
    else if(msg.getMsgType()==AutoThread::Thread_SIGNAL_SIGNOUT_2) {
       my_debug("Thread Msg:"+msg.getMsgString());
       on_checkSignBtn2_clicked();
    }
    else{
       my_debug("Thread Msg:"+msg.getMsgString());
    }


}



