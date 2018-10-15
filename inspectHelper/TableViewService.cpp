#include "TableViewService.h"

TableViewService::TableViewService()
{

}

void TableViewService::initSiteTable()
{
    QStandardItemModel  *myModel = new QStandardItemModel();
    myModel->setColumnCount(7);
    myModel->setHeaderData(0,Qt::Horizontal,"序列");
    myModel->setHeaderData(1,Qt::Horizontal,"RESID");
    myModel->setHeaderData(2,Qt::Horizontal,"站名");
    myModel->setHeaderData(3,Qt::Horizontal,"longitude");
    myModel->setHeaderData(4,Qt::Horizontal,"latitude");
    myModel->setHeaderData(5,Qt::Horizontal,"SIGN_TIME");
    myModel->setHeaderData(6,Qt::Horizontal,"CHECK_END_TIME");



    m_site_table->setModel(myModel);
    m_site_table->setColumnWidth(0,50);
    m_site_table->setColumnWidth(1,80);
    m_site_table->setColumnWidth(2,230);
    m_site_table->setColumnWidth(3,100);
    m_site_table->setColumnWidth(4,100);
    m_site_table->setColumnWidth(5,160);
    m_site_table->setColumnWidth(6,160);

    m_site_table->setAlternatingRowColors(true);//交替行
    m_site_table->horizontalHeader()->setStretchLastSection(true);//最后一列自动拉长
    m_site_table->setSortingEnabled(true);//可以排序
}

void TableViewService::clearSiteTable()
{
    QStandardItemModel  *myModel =(QStandardItemModel*)m_site_table->model();

    for(;myModel->rowCount()>0;){
          myModel->removeRow(0);
    }
}

void TableViewService::insertSiteTableItem(SiteObject *o)
{
    QStandardItemModel  *myModel =(QStandardItemModel*)m_site_table->model();
    int rowCount=myModel->rowCount();
    myModel->setItem(rowCount,0,new QStandardItem(o->getRN()));
    myModel->setItem(rowCount,1,new QStandardItem(o->getRESID()));
    myModel->setItem(rowCount,2,new QStandardItem(o->getRESNAME()));
    myModel->setItem(rowCount,3,new QStandardItem(o->getRES_LONGITUDE()));
    myModel->setItem(rowCount,4,new QStandardItem(o->getRES_LATITUDE()));
    myModel->setItem(rowCount,5,new QStandardItem(o->getSIGN_TIME()));
    myModel->setItem(rowCount,6,new QStandardItem(o->getCHECK_END_TIME()));
}

int TableViewService::loadSiteTableItemIndex()
{
     QStandardItemModel  *myModel =(QStandardItemModel*)m_site_table->model();

    for(int i=0;i<myModel->rowCount();i++){

        QString sign_time=myModel->index(i,5).data().toString().trimmed();
        QString check_time=myModel->index(i,6).data().toString().trimmed();



        if(check_time.isEmpty()||check_time=="null"){
            qDebug()<<"加载："+QString::number(i);
            return i;
        }
    }

    return -1;



}

void TableViewService::updateSiteTable_signInTime(int index)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("hh:mm");


    QStandardItemModel  *myModel =(QStandardItemModel*)m_site_table->model();
    myModel->setItem(index,5,new QStandardItem(current_date));
}

void TableViewService::updateSiteTable_signOutTime(int index)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("hh:mm");


    QStandardItemModel  *myModel =(QStandardItemModel*)m_site_table->model();
    myModel->setItem(index,6,new QStandardItem(current_date));
}

QTableView *TableViewService::site_table() const
{
    return m_site_table;
}

void TableViewService::setSite_table(QTableView *site_table)
{
    m_site_table = site_table;
}
