#include "minbutton.h"

MinButton::MinButton()
{

}
void MinButton::mousePressEvent(QMouseEvent * event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        emit minWin_sg();
    }
}
void MinButton::enterEvent(QEvent *e)
{
    setStyleSheet("background-color: rgb(231, 234, 237);");

}
void MinButton::leaveEvent(QEvent *e)
{
    setStyleSheet("background-color: rgb(231, 234, 237);");
}
