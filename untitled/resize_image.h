#ifndef RESIZE_IMAGE_H
#define RESIZE_IMAGE_H

#include <QPixmap>
#include <QPainter>
#include <QtConcurrent/QtConcurrentRun>
#include <QTransform>

enum DirectionRotate {toLeft,toRight};

static QPixmap concurrentRotate(QPixmap pxm,DirectionRotate type)
{
    QTransform trans;
    switch (type)
    {
        case toLeft:

            trans.rotate(-90,Qt::ZAxis);
            break;
        case toRight:
            trans.rotate(90,Qt::ZAxis);
            break;
    };

    return pxm.transformed(trans);
}

static QPixmap rotateImage(QPixmap pxm,DirectionRotate type)
{
        #ifndef QT_NO_CONCURRENT
           return QtConcurrent::run(concurrentRotate,pxm,type);
        #else
           return concurrentRotate(pxm,type);
        #endif
}

static QPixmap scaledPixmap(QPixmap pxm,int width,int height)
{
    if ((pxm.size().width() > width) || (pxm.size().height() > height))
    {
        while ((pxm.size().width() > width) || (pxm.size().height() > height))
        {
            if (pxm.isNull() == false)
            {
                QSize size_pxm = pxm.size();
                double K = 0;

                if (size_pxm.width() > width)
                {
                    double hei = size_pxm.height();
                    double wid = size_pxm.width();

                    K = wid / hei;

                    int hei_res = (width/K);

                    QPixmap draw(width-1,hei_res);
                    draw = pxm.scaled(width,hei_res,Qt::KeepAspectRatio,Qt::SmoothTransformation);
                    pxm = draw;
                }else
                {
                    double hei = size_pxm.height();
                    double wid = size_pxm.width();

                    K = hei / wid;

                    int wid_res = (height/K);

                    QPixmap draw(wid_res,height);
                    draw = pxm.scaled(wid_res,height,Qt::KeepAspectRatio,Qt::SmoothTransformation);
                    pxm = draw;
                }
            }
        }
    }

    return pxm;
}

static QPixmap resizePixmap(QPixmap pxm,int width,int height)
{
    #ifndef QT_NO_CONCURRENT
        return QtConcurrent::run(scaledPixmap,pxm,width,height);
    #else
        return scaledPixmap(pxm,width,height);
    #endif
}

static QPixmap resizePixmapFromByte(QByteArray data,int w,int h)
{
    QPixmap pxm;
    pxm.loadFromData(data);

    return resizePixmap(pxm,w,h);
}

#endif // RESIZE_IMAGE_H
