#include "mylistview.h"

MyListView::MyListView(QWidget *parent) : QWidget(parent)
{

    //接受拖拽
    this->setAcceptDrops(true);

    m_layout=new QVBoxLayout(this);
    m_layout->setMargin(0);

    widget_layout=new QVBoxLayout();
    widget_layout->setMargin(0);

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

void MyListView::addItem(const ListViewItemInfo &itemInfo)
{
   listViewItem * item=new listViewItem();
   item->setFixedHeight(30);
   item->init(itemList->length(),itemInfo.fileName,itemInfo.filePath,itemInfo.fileIcon);
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
    ListViewItemInfo *info=itemInfos->takeAt(index);

    //数据库操作
    SqlCtr *ctr=SqlCtr::getInstance();
    ctr->deleteColumnItem(this->currentColumn,info->GUID);
    delete item;
    delete info;
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
        //去除file:///字段
        QString tempPath=temp.toString();
        QString filePath=tempPath.mid(8);
        //获取fileName
        int index=filePath.lastIndexOf("/")+1;
        //以后可扩展成去除后缀名
        QString fileName=filePath.mid(index);



        //获取icon图标并保存
        QFileIconProvider fip;
        QFileInfo fi;
        fi.setFile(filePath);
        QIcon icon=fip.icon(fi);
        //创建唯一标识符
        QUuid uuid=QUuid::createUuid();
        QString uuidstr=uuid.toString();
        QString savePath=QString("ico/%1.ico").arg(uuidstr);

        QPixmap pp=icon.pixmap(32,32);
        pp.save(savePath);

        //创建数据并加入数据库
        ListViewItemInfo *info=new ListViewItemInfo(fileName,filePath,savePath,uuidstr);
        //内存由iteminfos管理
        itemInfos->append(info);

        SqlCtr *ctr=SqlCtr::getInstance();
        ctr->columnAdditem(this->currentColumn,*info);
        addItem(*info);
    }
}
//根据传入的list初始化控件
void MyListView::setItemInfos(QList<ListViewItemInfo*>* itemInfos)
{
    clear();

    //传入后进行初始化
    this->itemInfos=itemInfos;
    for (int i=0;i<itemInfos->size();++i)
    {
        addItem(*itemInfos->at(i));
    }
}

void MyListView::setCurrentColumn(QString columnName)
{
    this->currentColumn=columnName;
}
void MyListView::clear()
{
    //qDebug()<<itemList->count();
    //不用remove方法 QList的length不会改变
    int len=itemList->length();
    if(len>0)
    {
        foreach (listViewItem*item, *itemList) {
            itemList->removeOne(item);
            delete item;
            item=nullptr;

        }
        foreach (ListViewItemInfo*info, *itemInfos) {
            itemInfos->removeOne(info);
            delete info;
            info=nullptr;
        }
    }

}
