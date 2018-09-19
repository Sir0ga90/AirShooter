#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

#include <memory>

class Player : public QObject,
        public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
    void setGameEnd();

public slots:
    void spawn();

private:
    std::unique_ptr<QMediaPlayer> bulletSound;
    bool isGameInProcess;
};

#endif // MYRECT_H
