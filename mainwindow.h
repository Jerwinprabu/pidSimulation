#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class GuiHandler;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setKp(int slider);
    void setKi(int slider);
    void setKd(int slider);
    void run();

private:
    Ui::MainWindow *ui;
    GuiHandler* guiHandler;

    double mKp, mKi, mKd;
};

#endif // MAINWINDOW_H
