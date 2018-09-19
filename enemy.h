#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy : public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    static constexpr uint STD_ENEMY_HIGHT = 100;
    static constexpr uint STD_ENEMY_WIDTH = 100;
public slots:
    void move();
};

#endif // ENEMY_H
