#include "closebutton.h"

CloseButton::CloseButton()
{

}
void CloseButton::mousePressEvent(QMouseEvent * event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        exit(0);
    }
}
void CloseButton::enterEvent(QEvent *e)
{
    setCursor(Qt::PointingHandCursor);
}
void CloseButton::leaveEvent(QEvent *e)
{
    setCursor(Qt::ArrowCursor);
}
