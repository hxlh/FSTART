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

#include "QDesktopServices"
#include "QDebug"

class listViewItem : public QWidget
{
    Q_OBJECT
public:
    explicit listViewItem(QWidget *parent = nullptr);
    ~listViewItem();
    void init(int index, QString fileName, QString filePath, QString iconPath);
    bool selected=false;
    int index=-1;

signals:
    void selectedItem(int index);
    void removeSign(int index);
private:

    QHBoxLayout *m_widgetLayout=nullptr;
    QLabel *m_icoLabel=nullptr;
    QPixmap *m_ico=nullptr;
    MyLabel *m_nameLabel=nullptr;
private slots:
    void removeSlot();
    void openUrl(QString path);
protected:
    void paintEvent(QPaintEvent *event);
    void contextMenuEvent(QContextMenuEvent *e);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent * event);

};

#endif // LISTVIEWITEM_H
