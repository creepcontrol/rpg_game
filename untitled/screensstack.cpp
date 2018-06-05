#include "screensstack.h"

/*
 Стэк виджетов имеет методы:
 Push   - добавляем повверх стека новый виджет и показываем его
 Pop    - скрываем верхний виджет
 Length - количество виджетов в стеке
 */
ScreensStack::ScreensStack(QWidget *parent)
    : QWidget(parent), m_layout(this) {
    setLayout(&m_layout);
    m_layout.setMargin(0);
}

void ScreensStack::push(QWidget *widget) {
    if (false == m_widgets.empty()) {
        QWidget *top = m_widgets.front();
        top->hide();
    }
    m_layout.addWidget(widget);
    m_widgets.push_front(widget);

    widget->show();
}

void ScreensStack::pop() {
    if (m_widgets.empty())
        return;
    m_widgets.front()->hide();

    m_widgets.pop_front();
    if (false == m_widgets.empty()) {
        m_widgets.front()->show();
    }
}

int ScreensStack::lenght() {
    return m_widgets.length();
}
