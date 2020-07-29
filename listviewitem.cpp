#include "listviewitem.h"

listViewItem::listViewItem(QWidget *parent) : QWidget(parent)
{

}
void listViewItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void listViewItem::init(int index,QString path)
{
    //获取文件名
    int strIn=path.lastIndexOf("/")+1;
    int exIn=path.lastIndexOf(".");
    QString name="";
    if(exIn!=-1)
    {
        name=path.mid(strIn,exIn-strIn);
    }else{
        name=path.mid(strIn,path.length()-strIn);
    }
    //
    this->index=index;
    this->setStyleSheet("background-color: rgb(85, 255, 0);");

    QHBoxLayout *widgetLayout=new QHBoxLayout();
    widgetLayout->setSpacing(1);

    QLabel *icoLabel=new QLabel(this);
    //设置图片
    QString path_d=path.mid(8,path.length()-8);//除去path中的file:///字段
    //获取程序icon
    QFileInfo file_info(path_d);
    QFileIconProvider icon_provider;
    QIcon icon = icon_provider.icon(file_info);
    //
    icoLabel->setPixmap(icon.pixmap(16,16));
    icoLabel->setFixedSize(20,20);

    MyLabel *nameLabel=new MyLabel();
    nameLabel->setText(name,path_d);
    connect(nameLabel,&MyLabel::openUrl_Sg,this,&listViewItem::openUrl);

    widgetLayout->addWidget(icoLabel);
    widgetLayout->addWidget(nameLabel);
    
    this->setLayout(widgetLayout);
}
void listViewItem::contextMenuEvent(QContextMenuEvent *e)
{
    QAction *openA=new QAction("删除选中项");
    connect(openA,&QAction::triggered,this,&listViewItem::removeSlot);

    QMenu *menu = new QMenu();
    menu->addAction(openA);
    menu->exec(e->globalPos());

    delete openA;
    delete menu;
}

void listViewItem::enterEvent(QEvent *e)
{
    if(!selected)
    {
        setStyleSheet("background-color: rgb(182, 167, 255);");
    }

}
void listViewItem::leaveEvent(QEvent *e)
{
    if(!selected)
    {
        setStyleSheet("background-color: rgb(85, 255, 0);");
    }
}

void listViewItem::mousePressEvent(QMouseEvent * event)
{
    selected=true;
    setStyleSheet("background-color: rgb(255, 0, 0);");
    emit selectedItem(this->index);
}
void listViewItem::removeSlot()
{
    emit removeSign(this->index);
}

void listViewItem::openUrl(QString path)
{
    QDesktopServices qd;
    qd.openUrl(QUrl::fromLocalFile(path));
}
