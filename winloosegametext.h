#ifndef WINLOOSEGAMETEXT_H
#define WINLOOSEGAMETEXT_H


#include <QGraphicsTextItem>

class WinLoseGameText : public QGraphicsTextItem
{
public:
    WinLoseGameText(QGraphicsItem* _parent=nullptr);

    void showWinText();
    void showLoseText();
    void setPosToMiddleOfMainView(uint _mainViewWidth, uint _mainViewHight);
private:
    QString winText;
    QString loseText;
};

#endif // WINLOOSEGAMETEXT_H
