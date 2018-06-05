#include "hpitem.h"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "QGraphicsView"
#include "animatedgraphicsitem.h"
#include <QLabel>
/*
Класс содержит в себе методы управления прямоугольником
отображающий индикатор здоровья объекта
 */
HpItem::HpItem()
{

}
/*
Метод добавления индикатора здоровья к объекту после его расположения
на сцене
Параметры:
1) QGraphicsScene *scene      - Текущая графическая сцена
2) AnimatedGraphicsItem *item - Родительский объект которому устанавливаем индикатор
3) int height                 - Высота прямоугольника индикатора

Далее из родителя вычисляем pos(позицию) для индикатора, его надо
расположить чуть выше объекта
x = item->pixmap().rect().topLeft().x()+20
x левый верхний угол объекта + 20, т.е. чуть к центру

y = item->pixmap().rect().top()-hp_rect->rect().height()-5
от верхней точки персонажа - высота индикатора и еще - отступ 5
 */
void HpItem::setHpRect(QGraphicsScene *scene, AnimatedGraphicsItem *item, int height) {

    int width = item->pixmap().width()-30;
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,width,height);
    MainItem = item;
    hp_rect = scene->addRect(rect->rect());
    hp_rect->setParentItem(item);
    hp_rect->setRect(rect->rect());
    int x = item->pixmap().rect().topLeft().x()+20;
    int y = item->pixmap().rect().top()-hp_rect->rect().height()-5;
    hp_rect->setPos(x,y);

    Redhp_rect = scene->addRect(rect->rect());
    Redhp_rect->setParentItem(item);
    Redhp_rect->setRect(rect->rect());
    Redhp_rect->setPos(x,y);
    Redhp_rect->setBrush(Qt::green);
    color = new QColor(255,165,0); // оранжевый
    textCurHealth = new QGraphicsTextItem(QString::number(health));
    textCurHealth->setParentItem(Redhp_rect);
    CurHealth = health; //текущее здоровье в максимальное
}

/*
Уменьшаем индикатор здоровья:
Параметры:
value - Нанесенный урон имеет значение равно pAttack врага
Урон вычисляется по формуле Ширина прямоуголника текущего здоровья(Redhp_rect)-(нанесенный урон/количество здоровья персонажа
*ширину главного прямоугольника индикатора здоровья)
К примеру значение ширины индикатора = 200
Текущая ширина(Redhp_rect) здоровья персонажа = 150
Текущее здоровье 600
Максимальное здоровье персонажа(health) 800
Нанесенный урон = 20
Формула будет выглядить так:
150 - (20/800)*200 = 145
Соответственно персонаж получает 2,5% урона
*/

int HpItem::lessHpRect(qreal value) {
    qreal newWidth = Redhp_rect->rect().width()-(value/health * hp_rect->rect().width());
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,newWidth,30);
    Redhp_rect->setRect(rect->rect());
    CurHealth = CurHealth - value;
    textCurHealth->setPlainText(QString::number(CurHealth));
    qreal percent = CurHealth/health * 100;
    if (percent < 75 && percent > 30)
    {
        Redhp_rect->setBrush(*color);
    }
    if (percent < 31)
    {
        color->setRgb(255,69,0);
        Redhp_rect->setBrush(*color);
    }
    if (percent <= 0)
    {
        MainItem->deleteLater();
    }
    return CurHealth;
}
