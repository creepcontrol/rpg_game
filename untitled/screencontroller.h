#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H
#include "screensstack.h"
#include "frame.h"
#include "form.h"
#include "graphview.h"
#include "menu.h"

class ScreenController : public ScreensStack
{
    Q_OBJECT
public:
    explicit ScreenController(QWidget *parent = 0);
public slots:
    void on_level();
private:
    Frame *frameWindow;
    Form *formWindow;
    Menu *menuWindow;
    GraphView *graph;
};

#endif // SCREENCONTROLLER_H
