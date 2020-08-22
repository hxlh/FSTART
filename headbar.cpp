#include "headbar.h"

HeadBar::HeadBar(QWidget *parent) : QWidget(parent)
{

    this->setMouseTracking(true);//自动触发   mouseMoveEvent

    widget_layout=new QHBoxLayout();
    widget_layout->setSpacing(0);

    background->setLayout(widget_layout);
    background->setStyleSheet("background-color: rgb(231, 234, 237);");

    layout=new QVBoxLayout(this);
    layout->setMargin(0);
    setLayout(layout);
    layout->addWidget(background);

    QLabel *title=new QLabel();
    title->setText("FSTART");


    widget_layout->addWidget(title,0,Qt::AlignLeft);
    widget_layout->addStretch();

    MinButton *minButton=new MinButton;
    connect(minButton,&MinButton::minWin_sg,this,&HeadBar::sendMinSg_slots);
    minButton->setText("");
    minButton->setFixedSize(20,20);
    QPixmap minp(":/picture/picture/min.png");
    minButton->setPixmap(minp.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    CloseButton *closeButton=new CloseButton;
    closeButton->setFixedSize(20,20);
    QPixmap closep(":/picture/picture/close.png");
    closeButton->setPixmap(closep.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    widget_layout->addWidget(minButton,0,Qt::AlignRight);
    widget_layout->addWidget(closeButton,0,Qt::AlignRight);
}
void HeadBar::sendMinSg_slots()
{
    emit minWin_sg();
}


//拖放窗体
void HeadBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        lastX=event->globalX();
        lastY=event->globalY();
    }
}

void HeadBar::mouseMoveEvent(QMouseEvent *event)
{
    int offsetX=event->globalX()-lastX;
    int offsetY=event->globalY()-lastY;
    lastX=event->globalX();
    lastY=event->globalY();
    emit winMove_sg(offsetX,offsetY,event->globalX()-event->x(),event->globalY()-event->y());


}
