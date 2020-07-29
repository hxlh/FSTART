#ifndef LISTVIEWITEM_H
#define LISTVIEWITEM_H

#include <QWidget>
#include "QStyleOption"
#include "QPainter"
#include "mylabel.h"
#include "QLabel"
#include "QVBoxLayout"
#include "QMenu"
#include "QContextMenuEvent"
#include <QFileIconProvider>
#include "QDesktopServices"
#include "QDebug"

class listViewItem : public QWidget
{
    Q_OBJECT
public:
    explicit listViewItem(QWidget *parent = nullptr);
    void init(int index, QString path);
    bool selected=false;
    int index=-1;
signals:
    void selectedItem(int index);
    void removeSign(int index);
private:
    void contextMenuEvent(QContextMenuEvent *e);


private slots:
    void removeSlot();
    void openUrl(QString path);
protected:
    void paintEvent(QPaintEvent *event);

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent * event);

};

#endif // LISTVIEWITEM_H
