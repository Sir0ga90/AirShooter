#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "player.h"
#include "bullet.h"
#include "enemy.h"

#include "memory"


Player::Player(QGraphicsItem* _parent/*=nullptr*/) :
    isGameInProcess(true)
{
    bulletSound.reset(new QMediaPlayer());
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent* _event){
    constexpr uint MOVE_STEP = 10u;

    if(isGameInProcess){
        switch (_event->key()) {
        case Qt::Key_Left:{

            if(x() > 0){
                setPos(x() - MOVE_STEP, y());
            }
            break;
        }
        case Qt::Key_Right:{

            if(x() + pixmap().size().width() < scene()->width()){
                setPos(x() + MOVE_STEP, y());
            }
            break;
        }
        case Qt::Key_Space:{
            std::unique_ptr<Bullet> bullet(new Bullet());

            //middle of player and middle of bullet
            auto bulletXPosition = x()+pixmap().width()/2 - bullet->pixmap().width()/2;
            bullet->setPos(bulletXPosition, y());
            scene()->addItem(bullet.release());

            if(bulletSound->state() == QMediaPlayer::PlayingState){
                constexpr qint64 startBulletSoundPosition = 0;
                bulletSound->setPosition(startBulletSoundPosition);
            }
            else if (bulletSound->state() == QMediaPlayer::StoppedState){
                bulletSound->play();
            }

            break;
        }
        default:
            setPos(x(), y());
            break;
        }
    }

}


void Player::setGameEnd(){
    isGameInProcess = false;
}


void Player::spawn(){

    if(isGameInProcess)
    {
        std::unique_ptr<Enemy> enemy(new Enemy());
        scene()->addItem(enemy.release());
    }

}

