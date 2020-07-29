#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("FSTART");
    ui->setupUi(this);
    InitUI();
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

    widget->setLayout(m_layout);

    listView=new MyListView();

    listView->setObjectName("listViewO");

    listView->setStyleSheet("QWidget#listViewO{background-color: rgb(255, 255, 127);}");
    
    listView->addItem("file:///D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    m_layout->addWidget(listView);
}
