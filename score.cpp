#include <QFont>

#include "score.h"
#include "game.h"

extern std::unique_ptr<Game> game;

Score::Score(QGraphicsItem* _parent/*=nullptr*/) :
    QGraphicsTextItem(_parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

}


void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));

    constexpr decltype (score) MAX_SCORE = 10;
    if (score == MAX_SCORE){
        game->showWinText();
    }
}


int Score::getScore()
{
    return score;
}
