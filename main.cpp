#include <QApplication>

#include <memory>

#include <game.h>


std::unique_ptr<Game> game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game.reset(new Game());
    game->show();

    return a.exec();
}
