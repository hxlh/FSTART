#include "listviewitem.h"

listViewItem::listViewItem(QWidget *parent) : QWidget(parent)
{

}
listViewItem::~listViewItem()
{

}
void listViewItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void listViewItem::init(int index, QString fileName, QString filePath, QString iconPath)
{
    this->index=index;
    this->setStyleSheet("background-color: rgb(85, 255, 0);");

    m_widgetLayout=new QHBoxLayout();
    m_widgetLayout->setSpacing(8);

    m_ico=new QPixmap();

    m_ico->load(iconPath);
    m_icoLabel=new QLabel();
    m_icoLabel->setFixedSize(20,20);
    m_icoLabel->setScaledContents(true);
    m_icoLabel->setPixmap(*m_ico);

    m_nameLabel=new MyLabel();
    m_nameLabel->setText(fileName,filePath);
    connect(m_nameLabel,&MyLabel::label_clicked,this,&listViewItem::openUrl);

    m_widgetLayout->addWidget(m_icoLabel);
    m_widgetLayout->addWidget(m_nameLabel);
    m_widgetLayout->setMargin(0);

    this->setLayout(m_widgetLayout);
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
