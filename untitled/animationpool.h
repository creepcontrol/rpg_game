#ifndef ANIMATIONPOOL_H
#define ANIMATIONPOOL_H

#include <QMap>
#include <QVector>
#include <QString>

#include "singleton.h"
class QPixmap;

enum AnimationID {
  Stay, Up, Down, Left, Right, Tower_Build, Animation_AboutActor
    ,Fight
};

class AnimationPool
{
public:
    struct LoadException : public std::exception
    {
        virtual const char* what() const noexcept {
            return "Animation not loaded\n";
        }
    };


void load(AnimationID id, QString filename, int nFrames, int height, int width);
QVector<QPixmap*>& get(AnimationID id) throw(LoadException);

private:
    QPixmap* cropFrame(const QPixmap frames, const int nFrames, const int height, const int width,
                       const int nFrame);
    QMap<AnimationID, QVector<QPixmap*> > m_animations;

friend class Singleton<AnimationPool>;
};

#define ANIMATION_POOL Singleton<AnimationPool>::instance()
#endif // ANIMATIONPOOL_H
