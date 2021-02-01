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
    int getHideFlag();
    void setHideFlag(int flag);
private slots:
    void minWin();
    void winMove_slo(int offsetX,int offsetY,int wx,int wy);
private:
    Ui::MainWindow *ui;
    //等于0是为不隐藏,否则为1
    int m_hideFlag=0;
    //定位点

protected:

};
#endif // MAINWINDOW_H
