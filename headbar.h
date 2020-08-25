#ifndef HEADBAR_H
#define HEADBAR_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include "closebutton.h"
#include "minbutton.h"
#include <QMouseEvent>

#include "qdebug.h"
class HeadBar : public QWidget
{
    Q_OBJECT
public:
    explicit HeadBar(QWidget *parent = nullptr);
signals:
    void minWin_sg();
    void winMove_sg(int offsetX,int offsetY,int wx,int wy);

private:
    QVBoxLayout *layout;
    QWidget *background=new QWidget();
    QHBoxLayout *widget_layout;

    //鼠标移动窗体
    int lastX=0;
    int lastY=0;
private slots:
    void sendMinSg_slots();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


};

#endif // HEADBAR_H
