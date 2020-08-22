#ifndef SQLCTR_H
#define SQLCTR_H

#include <QObject>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>

#include "listviewiteminfo.h"

#include <QFileInfo>
class SqlCtr : public QObject
{
    Q_OBJECT
public:
    static SqlCtr *getInstance()
    {
        if(m_ptr==nullptr)
        {
            m_ptr=new SqlCtr();
        }
        return m_ptr;
    }

    void saveFileInfo(QString GUID,QString fileName,QString filePath,QString fileIcon);
    QList<ListViewItemInfo *>&queryColumnItems(QString columnName);
    QList<QString>queryColumns();
    void addcolumn(QString columnName);
    void columnAdditem(QString columnName,const ListViewItemInfo &item);
    void deleteColumnItem(QString columnName,QString guid);

private:
    //SqlCtr(QObject *parent = nullptr);
    SqlCtr();
    static SqlCtr* m_ptr;
    QSqlDatabase m_db;
    void init();
    QString column_table="column_table";
signals:

};

#endif // SQLCTR_H
