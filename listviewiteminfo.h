#ifndef LISTVIEWITEMINFO_H
#define LISTVIEWITEMINFO_H

#include <QObject>

class ListViewItemInfo : public QObject
{
    Q_OBJECT
public:
    ListViewItemInfo(QString fileName,QString filePath,QString fileIcon,QString GUID);
    QString fileName="";
    QString filePath="";
    QString fileIcon="";
    QString GUID="";
    ~ListViewItemInfo();
private:

signals:

};

#endif // LISTVIEWITEMINFO_H
