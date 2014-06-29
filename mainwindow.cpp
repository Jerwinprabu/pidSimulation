#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "guihandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->kpLowTb->setText("0");
    ui->kpHighTb->setText("1");
    ui->kpSlider->setMinimum(0);
    ui->kpSlider->setMaximum(1000);
    ui->kpLabel->setText("0.00");

    ui->kiLowTb->setText("0");
    ui->kiHighTb->setText("1");
    ui->kiSlider->setMinimum(0);
    ui->kiSlider->setMaximum(1000);
    ui->kiLabel->setText("0.00");

    ui->kdLowTb->setText("0");
    ui->kdHighTb->setText("1");
    ui->kdSlider->setMinimum(0);
    ui->kdSlider->setMaximum(1000);
    ui->kdLabel->setText("0.00");

    guiHandler = new GuiHandler(ui->plotWidget);
    QObject::connect(ui->runPb, SIGNAL(clicked()), this, SLOT(run()));
    QObject::connect(ui->clearPb, SIGNAL(clicked()), guiHandler, SLOT(clearSimulation()));
    QObject::connect(ui->kpSlider, SIGNAL(valueChanged(int)), this, SLOT(setKp(int)));
    QObject::connect(ui->kiSlider, SIGNAL(valueChanged(int)), this, SLOT(setKi(int)));
    QObject::connect(ui->kdSlider, SIGNAL(valueChanged(int)), this, SLOT(setKd(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setKp(int slider)
{
    mKp = double(slider) / 1000.0;
    guiHandler->runSimulation(mKp, mKi, mKd);
}

void MainWindow::setKi(int slider)
{
    mKi = double(slider) / 1000.0;
    guiHandler->runSimulation(mKp, mKi, mKd);
}

void MainWindow::setKd(int slider)
{
    mKd = double(slider) / 1000.0;
    guiHandler->runSimulation(mKp, mKi, mKd);
}

void MainWindow::run()
{
    guiHandler->runSimulation(mKp, mKi, mKd);
}
