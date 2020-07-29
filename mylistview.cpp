#include "mylistview.h"

MyListView::MyListView(QWidget *parent) : QWidget(parent)
{
    //接受拖拽
    this->setAcceptDrops(true);

    m_layout=new QVBoxLayout(this);

    widget_layout=new QVBoxLayout();

    background->setLayout(widget_layout);
    background->setStyleSheet("background-color: rgb(255, 170, 127);");

    this->setLayout(m_layout);

    widget_layout->setSpacing(1);
    widget_layout->addStretch();//先添加拉伸，后插入控件

    m_layout->setAlignment(Qt::AlignTop);

    QScrollArea *area=new QScrollArea();
    area->setWidget(background);
    area->setWidgetResizable(true);

    m_layout->addWidget(area);
}

void MyListView::addItem(QString path)
{
   listViewItem * item=new listViewItem();
   item->init(itemList->length(),path);
   connect(item,&listViewItem::selectedItem,this,&MyListView::adjustItemBackColor);
   connect(item,&listViewItem::removeSign,this,&MyListView::removeItem);

   itemList->append(item);//顺序不能乱

   widget_layout->insertWidget(widget_layout->count()-1,item);

}

void MyListView::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MyListView::adjustItemBackColor(int index)
{
    int len=itemList->length();
    for (int i=0;i<len;i++) {
        if( i !=index)
        {
            listViewItem * item=itemList->at(i);
            item-> setStyleSheet("background-color: rgb(85, 255, 0);");
            item->selected=false;
        }
    }
}

void MyListView::removeItem(int index)
{
    listViewItem * item=itemList->takeAt(index);
    delete item;
    //控件内部index更新
    for (int i=0;i<itemList->length();i++)
    {
        itemList->at(i)->index=i;
    }
}

void MyListView::dropEvent(QDropEvent *event)
{
    QList<QUrl>list=event->mimeData()->urls();
    foreach (QUrl temp, list) {
        QString name =temp.toString();
        addItem(name);
    }
}
