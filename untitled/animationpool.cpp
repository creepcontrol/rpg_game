#include "animationpool.h"
#include <QPixmap>

void AnimationPool::load(AnimationID id, QString filename, int nFrames,
                         int height, int width)
{
    QPixmap frames(filename);
    for (int nFrame = 0; nFrame < nFrames; ++nFrame)
        m_animations[id].push_back(cropFrame(frames, nFrames,height,width,nFrame));
}

QVector<QPixmap*>& AnimationPool::get(AnimationID id) throw(LoadException) {
    if (false == m_animations.contains(id))
        throw LoadException();
    return m_animations[id];
}

QPixmap* AnimationPool::cropFrame(const QPixmap frames, const int nFrames,
                                  const int height, const int width, const int nFrame)
{
    const int frameWidth = frames.width() / nFrames,
            frameHeigth = frames.height();

    return new QPixmap(frames.copy(nFrame*frameWidth, 0, frameWidth, frameHeigth)
                       .scaled(width, height, Qt::IgnoreAspectRatio, Qt::FastTransformation)
                       );
}
