#ifndef SITEOBJECT_H
#define SITEOBJECT_H

#include <QtGui>

class SiteObject
{
public:
    SiteObject();
    SiteObject(QString text);

    QString getAttribute(QString attr_name);

    QString getRN() const;
    void setRN(const QString &value);

    QString getRESID() const;
    void setRESID(const QString &value);

    QString getRESNAME() const;
    void setRESNAME(const QString &value);

    QString getRES_LONGITUDE() const;
    void setRES_LONGITUDE(const QString &value);

    QString getRES_LATITUDE() const;
    void setRES_LATITUDE(const QString &value);

    QString getSIGN_TIME() const;
    void setSIGN_TIME(const QString &value);

    QString getCHECK_END_TIME() const;
    void setCHECK_END_TIME(const QString &value);

private:
    QString siteInfoText;
    QString RN,RESID,RESNAME,RES_LONGITUDE,RES_LATITUDE,SIGN_TIME,CHECK_END_TIME;

};

#endif // SITEOBJECT_H
