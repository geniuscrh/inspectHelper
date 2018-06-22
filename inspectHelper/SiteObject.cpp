#include "SiteObject.h"



SiteObject::SiteObject()
{

}

SiteObject::SiteObject(QString text)
{
    this->siteInfoText=text;
    this->RN=getAttribute("RN");
    this->RESID=getAttribute("RESID");
    this->RESNAME=getAttribute("RESNAME");
    this->RES_LONGITUDE=getAttribute("RES_LONGITUDE");
    this->RES_LATITUDE=getAttribute("RES_LATITUDE");
    this->SIGN_TIME=getAttribute("SIGN_TIME");
    this->CHECK_END_TIME=getAttribute("CHECK_END_TIME");

}

QString SiteObject::getAttribute(QString attr_name)
{
    int sp,ep,ep_time;
    sp=this->siteInfoText.indexOf(attr_name);
    sp=this->siteInfoText.indexOf(":",sp)+1;

    //排除Data数据中的", "
    ep_time=this->siteInfoText.indexOf(", ",sp);
    ep=this->siteInfoText.indexOf(",",sp);
    if(ep==ep_time){
        ep=this->siteInfoText.indexOf(",",ep+1);
    }

    QString text=siteInfoText.mid(sp,ep-sp);
    text=text.replace("'","");
    qDebug()<<text;
    return text;
}

QString SiteObject::getRN() const
{
    return RN;
}

void SiteObject::setRN(const QString &value)
{
    RN = value;
}

QString SiteObject::getRESID() const
{
    return RESID;
}

void SiteObject::setRESID(const QString &value)
{
    RESID = value;
}

QString SiteObject::getRESNAME() const
{
    return RESNAME;
}

void SiteObject::setRESNAME(const QString &value)
{
    RESNAME = value;
}

QString SiteObject::getRES_LONGITUDE() const
{
    return RES_LONGITUDE;
}

void SiteObject::setRES_LONGITUDE(const QString &value)
{
    RES_LONGITUDE = value;
}

QString SiteObject::getRES_LATITUDE() const
{
    return RES_LATITUDE;
}

void SiteObject::setRES_LATITUDE(const QString &value)
{
    RES_LATITUDE = value;
}

QString SiteObject::getSIGN_TIME() const
{
    return SIGN_TIME;
}

void SiteObject::setSIGN_TIME(const QString &value)
{
    SIGN_TIME = value;
}

QString SiteObject::getCHECK_END_TIME() const
{
    return CHECK_END_TIME;
}

void SiteObject::setCHECK_END_TIME(const QString &value)
{
    CHECK_END_TIME = value;
}
