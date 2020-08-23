#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "sqlctr.h"
#include "mylistview.h"
#include "columnlabel.h"
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(QWidget *parent = nullptr);
    void addNewColumn(QString columnName);
    void addColumn(QString columnName);
signals:

private slots:
    void sl_change(QString columnName);
    void sl_removeColumn(QString columnName);
    void sl_addNewColumn();
private:
    void init();
    MyListView *listView=nullptr;
    QVBoxLayout *wid_layout=nullptr;
    QString currentColumn="";
    QList<ColumnLabel*>*columnLabelList=nullptr;
protected:
    void contextMenuEvent(QContextMenuEvent *e);
};

#endif // MAINPAGE_H
