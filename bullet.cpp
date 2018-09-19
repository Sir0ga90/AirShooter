#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include <memory>

#include "bullet.h"
#include "enemy.h"
#include "game.h"

extern std::unique_ptr<Game> game;

Bullet::Bullet(QGraphicsItem* _parent) :
    QObject(),
    QGraphicsPixmapItem (_parent)
{
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect to signal
    auto timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    //destroy bullet and enemy if they are collided
    QList<QGraphicsItem*> collidItems = collidingItems();
    for(auto collidItem : collidItems){
        if (typeid(*collidItem) == typeid(Enemy )){
            scene()->removeItem(collidItem);
            scene()->removeItem(this);

            game->increaseScore();

            delete collidItem;
            delete this;
            return;
        }
    }

    setPos(x(), y()-10);

    constexpr uint SCREEN_TOP = 0u;
    if(pos().y() + pixmap().size().height() < SCREEN_TOP){
        scene()->removeItem(this);
        delete this;
    }
}
