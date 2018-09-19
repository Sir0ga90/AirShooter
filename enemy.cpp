#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include <memory>
#include <stdlib.h> //rand()

#include "enemy.h"
#include "game.h"

extern std::unique_ptr<Game> game;


Enemy::Enemy(){
    int randomNumber = rand() % 700;
    setPos(randomNumber, 0);
    setPixmap(QPixmap(":/images/enemy.png"));

    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    qreal rotationAngle = 180.0;
    setRotation(rotationAngle);

    //connect to signal
    auto timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    setPos(x(), y()+5);

    const auto SCREEN_BOTTOM = scene()->height();

    if(pos().y() > SCREEN_BOTTOM){
        scene()->removeItem(this);
        game->decreaseHealth();

        delete this;
    }
}
