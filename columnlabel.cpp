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
