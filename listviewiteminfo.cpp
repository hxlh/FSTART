#include "listviewiteminfo.h"

#include <QDebug>
ListViewItemInfo::ListViewItemInfo(QString fileName,QString filePath,QString fileIcon,QString GUID)
{
    this->fileName=fileName;
    this->filePath=filePath;
    this->fileIcon=fileIcon;
    this->GUID=GUID;
}
ListViewItemInfo::~ListViewItemInfo()
{
    //qDebug()<<"~ListViewItemInfo";
}
