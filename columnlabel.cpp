#include "columnlabel.h"

ColumnLabel::ColumnLabel(QWidget *parent) : QLabel(parent)
{
    setStyleSheet(m_leave_color);
}
void ColumnLabel::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    p.drawText(rect(),Qt::AlignHCenter|Qt::AlignVCenter,m_columnName);
}
void ColumnLabel::enterEvent(QEvent *)
{
    this->setStyleSheet(m_enter_color);
}
void ColumnLabel::leaveEvent(QEvent *)
{
    this->setStyleSheet(m_leave_color);
}
void ColumnLabel::setText(QString columnName)
{
    this->m_columnName=columnName;
    update();
}
void ColumnLabel::mousePressEvent(QMouseEvent * event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        emit clicked(this->m_columnName);
    }
}
QString ColumnLabel::getText()
{
    return this->m_columnName;
}
void ColumnLabel::contextMenuEvent(QContextMenuEvent *e)
{
    QAction *removeAt=new QAction("删除栏目");
    connect(removeAt,&QAction::triggered,this,[=](){
       emit sg_remove(this->m_columnName);
    });
    QAction *addAt=new QAction("添加栏目");
    connect(addAt,&QAction::triggered,this,[=](){
        emit sg_add();
    });
    QMenu *menu=new QMenu();
    menu->addAction(removeAt);
    menu->addAction(addAt);
    menu->exec(e->globalPos());
    delete menu;
    delete removeAt;
    delete addAt;
    menu=nullptr;
    removeAt=nullptr;
    addAt=nullptr;

}
