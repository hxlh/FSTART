#ifndef MINBUTTON_H
#define MINBUTTON_H

#include <QObject>
#include "QLabel"
#include "QMouseEvent"
class MinButton : public QLabel
{
    Q_OBJECT
public:
    MinButton();
signals:
    void minWin_sg();
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent * event);
};

#endif // MINBUTTON_H
