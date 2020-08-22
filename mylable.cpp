#include "myLabel.h"

MyLabel::MyLabel(QLabel *parent) : QLabel(parent)
{

}
void MyLabel::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    p.drawText(rect(),Qt::AlignLeft|Qt::AlignVCenter,name);
}

void MyLabel::enterEvent(QEvent *e)
{
    setCursor(Qt::PointingHandCursor);
}
void MyLabel::leaveEvent(QEvent *e)
{
    setCursor(Qt::ArrowCursor);
}
void MyLabel::setText(QString name,QString path)
{
    this->name=name;
    this->path=path;
    update();
}
void MyLabel::mousePressEvent(QMouseEvent * event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        emit clicked(path);
    }
}
