#include "sqlctr.h"

//必须有否则报错
/*
 error: multiple definition of `SqlCtr::m_ptr'
*/
/*
CREATE TABLE column_item
(
    ID INTEGER identity(1,1) primary key,
    GUID varchar(255),
    FileName varchar(255),
    FilePath varchar(255),
    FileIcon varchar(255)
)
*/
SqlCtr* SqlCtr::m_ptr = NULL;

SqlCtr::SqlCtr()
{
    QFileInfo f("FADataBase.db");
    if(!f.exists())
    {
        init();//创建文件并连接
        //创建column表
        /*
                CREATE TABLE columns_table
               (
                   ID INTEGER primary key AUTOINCREMENT,
                   Column	varchar(100)
               )
        */
        QSqlQuery q;
        QString cmd=QString("CREATE TABLE %1(ID INTEGER primary key AUTOINCREMENT,Column	varchar(100))").arg(column_table);
        q.exec();
    }else
    {
        init();
    }
}
//创建数据库和创建column表
void SqlCtr::init()
{
    m_db=QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("FADataBase.db");
    m_db.setUserName("Ratcliffe");
    m_db.setPassword("FASTART");
    if (!m_db.open())
    {
        qDebug() << "Error: Failed to connect database." << m_db.lastError();
    }
}
QList<ListViewItemInfo *> &SqlCtr::queryColumnItems(QString columnName)
{
    QSqlQuery q;
    QString cmd=QString("SELECT * FROM %0").arg(columnName+"_item");
    QList<ListViewItemInfo*>*itemList=new QList<ListViewItemInfo*>();
    q.exec(cmd);
    while (q.next()) {
        ListViewItemInfo *item=new ListViewItemInfo(q.value(2).toString(),q.value(3).toString(),q.value(4).toString(),q.value(1).toString());
        itemList->append(item);
    }
    return *itemList;
}
void SqlCtr::addcolumn(QString columnName)
{

    QSqlQuery q;
    //添加column
    QString cmd1="INSERT INTO "+column_table+" VALUES(NULL,\'"+columnName+"\')";
    //创建column的item表
    QString cmd2="CREATE TABLE "
                +columnName+"_item"+
                "(ID INTEGER primary key AUTOINCREMENT,"
                "GUID varchar(255),"
                "FileName varchar(255),"
                "FilePath varchar(255),"
                "FileIcon varchar(255))";
    q.exec(cmd1);
    q.exec(cmd2);
}

void SqlCtr::columnAdditem(QString columnName,const ListViewItemInfo &item)
{
    QSqlQuery q;
    QString cmd=QString("INSERT INTO %0 VALUES(NULL,\'%1\',\'%2\',\'%3\',\'%4\')").arg(columnName+"_item",item.GUID,item.fileName,item.filePath,item.fileIcon);
    q.exec(cmd);
}

QList<QString>SqlCtr::queryColumns()
{
    QList<QString>columnList;
    QSqlQuery q;
    QString cmd=QString("SELECT * FROM %0").arg(column_table);
    q.exec(cmd);
    while (q.next()) {
        columnList.append(q.value(1).toString());
    }
    return columnList;
}
void SqlCtr::deleteColumnItem(QString columnName,QString guid)
{
    //DELETE FROM hxlh33333_item WHERE GUID=='{6706a198-e0b4-4279-8dde-5e4fc01b3a12}'
    QSqlQuery q;
    QString cmd=QString("DELETE FROM %1 WHERE GUID==\'%2\'").arg(columnName+"_item",guid);
    q.exec(cmd);
}
