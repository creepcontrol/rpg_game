#include "screencontroller.h"
#include "frame.h"
#include <QMessageBox>
#include "graphview.h"

ScreenController::ScreenController(QWidget *parent)
    : ScreensStack(parent)
{
    menuWindow = new Menu(this);
    connect(menuWindow, SIGNAL(exit()), this, SLOT(on_level()));
    menuWindow->hide();

    graph = new GraphView(500,400,this);
    graph->hide();

    menuWindow->setVisible(true);
    push(menuWindow);
}

void ScreenController::on_level() {
    push(graph);
}
