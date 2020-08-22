#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "sqlctr.h"
#include "mylistview.h"
#include "columnlabel.h"
class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(QWidget *parent = nullptr);
    void addColumn(QString columnName);

signals:

private slots:
    void sl_change(QString columnName);

private:
    void init();
    MyListView *listView=nullptr;
    QVBoxLayout *wid_layout=nullptr;
    QString currentColumn="";
    QList<ColumnLabel*>*columnLabelList=nullptr;

};

#endif // MAINPAGE_H
