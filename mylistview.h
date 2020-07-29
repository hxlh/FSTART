#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H
#include "listviewitem.h"
#include "QAction"
#include "QMimeData"//拖拽控件
#include "QScrollArea"
class MyListView : public QWidget
{
    Q_OBJECT
public:
    explicit MyListView(QWidget *parent = nullptr);
    void  addItem(QString path);
    QVBoxLayout *widget_layout;
private:

    QVBoxLayout *m_layout;
    QList<listViewItem *> *itemList=new QList<listViewItem*>() ;
    QWidget *background=new QWidget();
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
