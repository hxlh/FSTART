#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainpage.h"
#include "headbar.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitUI();

private slots:
    void minWin();
    void winMove_slo(int offsetX,int offsetY,int wx,int wy);
private:
    Ui::MainWindow *ui;
    //定位点
    QRect *brcRect=nullptr;
    QRect *blcRect=nullptr;
    QRect *topRect=nullptr;
    QRect *rRect=nullptr;
    QRect *lRect=nullptr;
    QRect *bRect=nullptr;
protected:

};
#endif // MAINWINDOW_H
