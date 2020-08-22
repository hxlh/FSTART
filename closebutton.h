#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <QObject>
#include "QLabel"
#include "QMouseEvent"
class CloseButton : public QLabel
{
    Q_OBJECT
public:
    CloseButton();

protected:
    void mousePressEvent(QMouseEvent * event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

};

#endif // CLOSEBUTTON_H
