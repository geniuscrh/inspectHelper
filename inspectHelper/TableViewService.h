#ifndef TABLEVIEWSERVICE_H
#define TABLEVIEWSERVICE_H

#include <QtGui>
#include <QTableView>
#include <QHeaderView>
#include <SiteObject.h>

class TableViewService
{
public:
    TableViewService();


    QTableView *site_table() const;
    void setSite_table(QTableView *site_table);

    void initSiteTable();
    void clearSiteTable();
    void insertSiteTableItem(SiteObject *o);
    int loadSiteTableItemIndex();
    void updateSiteTable_signInTime(int index);
    void updateSiteTable_signOutTime(int index);


private:
    QTableView *m_site_table;


};

#endif // TABLEVIEWSERVICE_H
