#ifndef COLUMNLABEL_H
#define COLUMNLABEL_H

#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
class ColumnLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ColumnLabel(QWidget *parent = nullptr);
    void setText(QString columnName);
    QString getText();
signals:
    void clicked(QString columnName);
private:
    QString m_columnName="";
    QString m_enter_color="background-color: rgb(114, 163, 255);";
    QString m_leave_color="background-color: rgb(114, 211, 255);";
    int m_index=-1;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
signals:

};

#endif // COLUMNLABEL_H
