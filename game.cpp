#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QImage>

#include <memory>

#include "game.h"
#include "player.h"


Game::Game(QWidget* _parent/*=nullptr*/){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT);
    scene->setBackgroundBrush(QBrush(QImage(":/images/backGround.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(VIEW_WIDTH, VIEW_HEIGHT);

    player = new Player();
    player->setPos(width()/2,
                   height() - player->pixmap().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
    score = new Score();
    scene->addItem(score);

    health = new Health();
    constexpr qreal DIFF_BETWEEN_LINES = 25;
    health->setPos(score->x(), score->y()+DIFF_BETWEEN_LINES);
    scene->addItem(health);

    //add enemys
    auto timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    //play bg music
    backGroundMusicPlayer = new QMediaPlayer();
    backGroundMusicPlayer->setMedia(QUrl("qrc:/sounds/backGround.mp3"));
    backGroundMusicPlayer->play();

    show();
}


void Game::increaseScore()
{
    score->increase();
}


void Game::decreaseHealth()
{
    health->decrease();
}


void Game::showWinText()
{
    processWinLose();
    winLoseGameText->showWinText();
    winLoseGameText->setPosToMiddleOfMainView(VIEW_WIDTH, VIEW_HEIGHT);
}


void Game::showLoseText()
{
    processWinLose();
    winLoseGameText->showLoseText();
    winLoseGameText->setPosToMiddleOfMainView(VIEW_WIDTH, VIEW_HEIGHT);
}


void Game::processWinLose()
{
    winLoseGameText = new WinLoseGameText();
    winLoseGameText->window();

    scene->addItem(winLoseGameText);

    player->setGameEnd();
}
