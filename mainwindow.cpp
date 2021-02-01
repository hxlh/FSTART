#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "framelesswidget.h"
#include "sqlctr.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("FSTART");
    ui->setupUi(this);
    InitUI();
    setWindowFlags (Qt::FramelessWindowHint);//去除边框
    //设置窗体置顶
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::InitUI()
{


    QWidget *widget = new QWidget();//新添加的内容   创建一个QWidget实例

    this->setCentralWidget(widget);//新添加的内容      将创建的实例设置为centralWidget：

    QVBoxLayout *m_layout=new QVBoxLayout(widget);//不可以填this
    m_layout->setMargin(0);

    widget->setLayout(m_layout);

    HeadBar *headbar=new HeadBar();
    headbar->setFixedHeight(35);
    connect(headbar,&HeadBar::minWin_sg,this,&MainWindow::minWin);
    connect(headbar,&HeadBar::winMove_sg,this,&MainWindow::winMove_slo);

    m_layout->addWidget(headbar);

    FramelessWidget *w=new FramelessWidget(this);
    w->setWidget(this);
    w->setMoveEnable(false);
    w->setResizeEnable(true);

    MainPage *mainPage=new MainPage();
    m_layout->addWidget(mainPage);
}

void MainWindow::minWin()
{
    this->showMinimized();
}

void MainWindow::winMove_slo(int offsetX,int offsetY,int wx,int wy)
{
    this->move(wx+offsetX,wy+offsetY);

//    qDebug()<<offsetX;
//    qDebug()<<offsetY;
        //qDebug()<<wx;
        //qDebug()<<wy;

}
int MainWindow::getHideFlag()
{
    return this->m_hideFlag;
}
void MainWindow::setHideFlag(int flag)
{
    this->m_hideFlag=flag;
}
