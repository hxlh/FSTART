#ifndef COLUMNLABEL_H
#define COLUMNLABEL_H

#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
class ColumnLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ColumnLabel(QWidget *parent = nullptr);
    void setText(QString columnName);
    QString getText();
signals:
    void clicked(QString columnName);
    void sg_remove(QString columnName);
    void sg_add();
private:
    QString m_columnName="";
    QString m_enter_color="background-color: rgb(114, 163, 255);";
    QString m_leave_color="background-color: rgb(114, 211, 255);";

protected:
    void contextMenuEvent(QContextMenuEvent *e);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
signals:

};

#endif // COLUMNLABEL_H
