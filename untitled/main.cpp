#include "screencontroller.h"
#include <QApplication>
#include "animationpool.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ANIMATION_POOL.load(AnimationID::Down,":/game/hedgehog_down.png", 11, 246, 280);
    ANIMATION_POOL.load(AnimationID::Fight,":/game/hedgehog_fight.png", 11, 246, 280);
    ANIMATION_POOL.load(AnimationID::Left,":/game/hedgehog_left.png", 11, 246, 280);
    ANIMATION_POOL.load(AnimationID::Right,":/game/hedgehog_right.png", 11, 246, 280);
    ANIMATION_POOL.load(AnimationID::Up,":/game/hedgehog_up.png", 11, 246, 280);
    ANIMATION_POOL.load(AnimationID::Stay,":/game/hedgehog_stay.png", 31, 246, 280);
    ANIMATION_POOL.load(AnimationID::Tower_Build,":/game/tower.png", 1, 246, 280);
    ANIMATION_POOL.load(AnimationID::Animation_AboutActor,":/game/about.png", 1, 280, 2695);

    ScreenController screen;
    screen.show();

    return a.exec();
}
