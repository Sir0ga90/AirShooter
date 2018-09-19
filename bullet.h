#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>


class Bullet :
        public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* _parent = nullptr);

    static constexpr uint STD_BULLET_HIGHT = 50;
    static constexpr uint STD_BULLET_WIDTH = 10;
public slots:
    void move();
};

#endif // BULLET_H
