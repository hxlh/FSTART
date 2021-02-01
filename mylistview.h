#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H
#include "listviewitem.h"
#include "QAction"
#include "QMimeData"//拖拽控件
#include "QScrollArea"
#include "listviewiteminfo.h"
#include <QFileIconProvider>
#include <QUuid>
#include "sqlctr.h"
class MyListView : public QWidget
{
    Q_OBJECT
public:
    explicit MyListView(QWidget *parent = nullptr);
    void  addItem(const ListViewItemInfo &itemInfo);
    QVBoxLayout *widget_layout;
    void setItemInfos(QList<ListViewItemInfo*>* itemInfos);
    void setCurrentColumn(QString columnName);
    void clear();
private:

    QVBoxLayout *m_layout;
    QList<listViewItem *> *itemList=new QList<listViewItem*>() ;
    QWidget *background=new QWidget();
    QList<ListViewItemInfo*>* itemInfos=nullptr;
    QString currentColumn="";

private slots:
    void adjustItemBackColor(int index);
    void removeItem(int index);
protected:

    void dragEnterEvent(QDragEnterEvent *event)
    {
        event->acceptProposedAction();
    }
    void dropEvent(QDropEvent *event);
    void paintEvent(QPaintEvent *event) ;
signals:

};

#endif // MYLISTVIEW_H
