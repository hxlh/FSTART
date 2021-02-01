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
    wid_layout->addWidget(listView);
}

void MainPage::addNewColumn(QString columnName)
{
    //UI更新
    ColumnLabel *cl=new ColumnLabel();
    connect(cl,&ColumnLabel::clicked,this,&MainPage::sl_change);
    connect(cl,&ColumnLabel::sg_remove,this,&MainPage::sl_removeColumn);
    connect(cl,&ColumnLabel::sg_add,this,&MainPage::sl_addNewColumn);
    cl->setFixedHeight(30);
    cl->setText(columnName);
    cl->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    columnLabelList->append(cl);

    this->wid_layout->addWidget(cl);

    //写入数据库
    SqlCtr *ctr=SqlCtr::getInstance();
    ctr->addcolumn(columnName);
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
        this->addColumn(columnList.at(i));
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
void MainPage::sl_removeColumn(QString columnName)
{
    int count=this->columnLabelList->length();
    int index=0;
    for (int i=0;i<count;++i) {
        if(columnName==columnLabelList->at(i)->getText())
        {
            index=i;
            break;
        }
    }
    this->wid_layout->removeWidget(columnLabelList->at(index));
    ColumnLabel *temp=columnLabelList->takeAt(index);
    columnLabelList->removeOne(temp);
    delete temp;
    temp=nullptr;
    //如果删除目标当前存在listView,则需要删除listView内容并指向最后一个column
    SqlCtr *ctr=SqlCtr::getInstance();
    if(this->currentColumn==columnName)
    {
        listView->clear();
        //从数据库内取出items


        this->currentColumn=columnLabelList->last()->getText();
        listView->setCurrentColumn(this->currentColumn);

        QList<ListViewItemInfo*>*item=&ctr->queryColumnItems(this->currentColumn);
        listView->setItemInfos(item);
        //调整listView位置
        this->wid_layout->removeWidget(listView);
        this->wid_layout->addWidget(listView);

    }
    ctr->deleteColumn(columnName);

    if(columnLabelList->size()==0)
    {
        //当删除所有column后
        //自动添加一个新建栏目
        listView->clear();
        this->wid_layout->removeWidget(listView);
        this->addNewColumn("新建栏目");
        this->wid_layout->addWidget(listView);
        this->currentColumn="新建栏目";
        listView->setCurrentColumn("新建栏目");
    }

    //数据库删除column字段和有关的表




}
void MainPage::contextMenuEvent(QContextMenuEvent *e)
{

}
void MainPage::sl_addNewColumn()
{
    QDialog *dia=new QDialog();

    QWidget *widget=new QWidget;

    QHBoxLayout *Hlayout=new QHBoxLayout();

    QVBoxLayout *Vlayout=new QVBoxLayout();

    widget->setLayout(Hlayout);
    Vlayout->addWidget(widget);


    QLabel *label=new QLabel;
    label->setText("新目录名：");
    QLineEdit *le=new QLineEdit;

    QPushButton *button=new QPushButton();
    button->setText("添加");
    connect(button,&QPushButton::clicked,this,[=](){
        if(le->text()!="")
        {
            this->addNewColumn(le->text());
        }
        //退出
        dia->close();
    });
    Vlayout->addWidget(button,Qt::AlignHCenter);

    Hlayout->addWidget(label);
    Hlayout->addWidget(le);

    dia->setLayout(Vlayout);
    dia->exec();

    delete label;
    delete le;
    delete Hlayout;
    delete button;
    delete widget;
    delete Vlayout;
    delete dia;
    label=nullptr;
    le=nullptr;
    Hlayout=nullptr;
    button=nullptr;
    widget=nullptr;
    Vlayout=nullptr;
    dia=nullptr;
}
void MainPage::addColumn(QString columnName)
{
    //UI更新
    ColumnLabel *cl=new ColumnLabel();
    connect(cl,&ColumnLabel::clicked,this,&MainPage::sl_change);
    connect(cl,&ColumnLabel::sg_remove,this,&MainPage::sl_removeColumn);
    connect(cl,&ColumnLabel::sg_add,this,&MainPage::sl_addNewColumn);
    cl->setFixedHeight(30);
    cl->setText(columnName);
    cl->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    columnLabelList->append(cl);

    this->wid_layout->addWidget(cl);
}
