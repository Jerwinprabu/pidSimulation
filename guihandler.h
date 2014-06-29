#ifndef GUIHANDLER_H
#define GUIHANDLER_H

#include <QObject>

class KPlotWidget;

class GuiHandler : public QObject
{
    Q_OBJECT

public:
    GuiHandler(KPlotWidget* plotWidget);

public slots:
    void runSimulation(double kp, double ki, double kd);
    void clearSimulation();

private:
    KPlotWidget* mPlotWidget;
};

#endif // GUIHANDLER_H
