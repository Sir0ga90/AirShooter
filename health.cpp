#include <QFont>

#include "health.h"
#include "winloosegametext.h"
#include "game.h"

extern std::unique_ptr<Game> game;

Health::Health(QGraphicsItem* _parent/*=nullptr*/) :
    QGraphicsTextItem(_parent)
{
    health = 1;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}


void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));

    if (health < 0)
    {
        game->showLoseText();
    }
}


int Health::getHealth()
{
    return health;
}
