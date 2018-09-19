#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QMediaPlayer>

#include <memory>

#include "player.h"
#include "score.h"
#include "health.h"
#include "winloosegametext.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget* _parent=nullptr);

    void increaseScore();
    void decreaseHealth();
    void showWinText();
    void showLoseText();

private:
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
    QMediaPlayer* backGroundMusicPlayer;
    WinLoseGameText* winLoseGameText;

    static uint constexpr VIEW_WIDTH = 800;
    static uint constexpr VIEW_HEIGHT = 600;

    void processWinLose();
};

#endif // GAME_H
