#include "aboutactor.h"
#include "animatedgraphicsitem.h"
#include "QGraphicsItemAnimation"
#include "QGraphicsScene"

AboutActor::AboutActor(QObject *parent)
    : AnimatedGraphicsItem(parent),
      m_moveAnimationTimer(nullptr),
      m_currentAction(AnimationID::Animation_AboutActor)
{
    setScale(0.3);
    setSprites(m_currentAction,true);
}

void AboutActor::setSprites(AnimationID sprites, bool force) {
    if (force || sprites != m_currentAction) {
        animation(sprites, Mode::Loop, true);
    }
}

void AboutActor::OnAnimationFinished() {

}
