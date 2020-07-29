#ifndef MYLABLE_H
#define MYLABLE_H

#include <QLabel>
#include "QStyleOption"
#include "QPainter"
#include "QMouseEvent"
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QLabel *parent = nullptr);
    void setText(QString name, QString path);
signals:
    void openUrl_Sg(QString path);
private:
    QString name="";
    QString path="";
protected:
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // MYLABLE_H
