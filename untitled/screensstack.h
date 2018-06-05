#ifndef SCREENSSTACK_H
#define SCREENSSTACK_H

#include <QWidget>
#include <QGridLayout>
#include <QStack>

class ScreensStack : public QWidget {
    Q_OBJECT
public:
    explicit ScreensStack(QWidget *parent = 0);
public slots:
    void push(QWidget* widget);
    void pop();
    int lenght();
private:
    QStack<QWidget*> m_widgets;
    QGridLayout m_layout;
};

#endif // SCREENSSTACK_H
