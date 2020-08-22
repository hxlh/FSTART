#include "mainpage.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent)
{
    wid_layout=new QVBoxLayout;
    this->setLayout(wid_layout);

    this->setStyleSheet("background-color: rgb(85, 170, 0);");
    listView=new MyListView();
    columnLabelList=new QList<ColumnLabel*>();
    init();


    listView->setObjectName("listViewO");
    listView->setStyleSheet("QWidget#listViewO{background-color: rgb(255, 255, 127);}");
//    listView->addItem("file:///D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
//    listView->addItem("D:/ludashi/ComputerZ_CN.exe");
    wid_layout->addWidget(listView);
}

void MainPage::addColumn(QString columnName)
{
    SqlCtr *sc=SqlCtr::getInstance();
    sc->addcolumn(columnName);
}

void MainPage::init()
{
    //从数据库获取所有column
    SqlCtr *ctr=SqlCtr::getInstance();
    QList<QString>columnList=ctr->queryColumns();
    if(columnList.size()<=0)
    {
        return;
    }
    //最后一个作为初始化
    currentColumn=columnList.last();
    listView->setCurrentColumn(currentColumn);

    for (int i=0;i<columnList.size();++i) {
        ColumnLabel *cl=new ColumnLabel(this);
        connect(cl,&ColumnLabel::clicked,this,&MainPage::sl_change);

        cl->setFixedHeight(30);
        cl->setText(columnList.at(i));
        cl->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        columnLabelList->append(cl);

        wid_layout->addWidget(cl);
    }


    QList<ListViewItemInfo*>*items=&ctr->queryColumnItems(currentColumn);
    listView->setItemInfos(items);
}

//单击column后响应事件
void MainPage::sl_change(QString columnName)
{
    //qDebug()<<columnName;
    this->currentColumn=columnName;
    listView->setCurrentColumn(this->currentColumn);
    //更换listView内容
    SqlCtr *ctr=SqlCtr::getInstance();

    QList<ListViewItemInfo*>*items=&ctr->queryColumnItems(currentColumn);
    listView->setItemInfos(items);


    //调动listView的位置
    int pos=0;
    foreach (ColumnLabel* temp, *this->columnLabelList) {
       pos++;//比column的位置大1位
       if(temp->getText()==columnName)
       {
           break;
       }

    }
    wid_layout->removeWidget(listView);
    wid_layout->insertWidget(pos,listView);
}
