#include <kplotwidget.h>
#include <kplotobject.h>

#include "guihandler.h"
#include "sim.h"

GuiHandler::GuiHandler(KPlotWidget *plotWidget)
{
    mPlotWidget = plotWidget;
}

void GuiHandler::clearSimulation()
{
    mPlotWidget->removeAllPlotObjects();
}

void GuiHandler::runSimulation(double kp, double ki, double kd)
{
    mPlotWidget->removeAllPlotObjects();

    double minX, minY;
    minX = minY = std::numeric_limits<double>::max();
    double maxX, maxY;
    maxX = maxY = -1 * std::numeric_limits<double>::max();
    int colorIx = 0;

    QColor colors[] = {
        Qt::red,
        Qt::green,
        Qt::blue,
        Qt::cyan,
        Qt::magenta,
        Qt::yellow,
        Qt::darkRed,
        Qt::darkGreen,
        Qt::darkBlue,
        Qt::darkCyan,
        Qt::darkMagenta,
        Qt::darkYellow,
        Qt::white,
        Qt::lightGray
    };

    for (int setpoint = 2; setpoint < 10; setpoint += 2)
    {
        std::vector<SimPoint> simulation = controlResponse(300, setpoint, kp, ki, kd);

        KPlotObject* plotData = new KPlotObject(colors[colorIx], KPlotObject::Lines, 2);
        if (++colorIx >= ARRAY_SIZE(colors)) colorIx = 0;

        for (SimPoint pt : simulation)
        {
            plotData->addPoint(pt.first, pt.second);
            minX = std::min(minX, pt.first);
            maxX = std::max(maxX, pt.first);
            minY = std::min(minY, pt.second);
            maxY = std::max(maxY, pt.second);
        }
        mPlotWidget->addPlotObject(plotData);
    }
    if (minX == maxX) ++maxX;
    if (minY == maxY) ++maxY;
    mPlotWidget->setLimits(minX, maxX, minY, maxY);
    mPlotWidget->update();
}
