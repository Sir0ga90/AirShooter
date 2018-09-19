#include <QFont>

#include "winloosegametext.h"

WinLoseGameText::WinLoseGameText(QGraphicsItem* _parent/*=nullptr*/) :
    QGraphicsTextItem (_parent),
    winText("You win!!!"),
    loseText("You lose!!!")
{
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 50));
}


void WinLoseGameText::showWinText()
{
    setPlainText(winText);
}


void WinLoseGameText::showLoseText()
{
    setPlainText(loseText);
}

void WinLoseGameText::setPosToMiddleOfMainView(uint _mainViewWidth, uint _mainViewHeight)
{
    setPos(_mainViewWidth/2 - boundingRect().width()/2,
           _mainViewHeight/2 - boundingRect().height()/2);

}
