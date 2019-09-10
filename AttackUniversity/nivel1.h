#ifndef NIVEL1_H
#define NIVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
namespace Ui {
class nivel1;
}

class nivel1 : public QWidget
{
    Q_OBJECT

public:
    explicit nivel1(QWidget *parent = nullptr);
    ~nivel1();

private:
    Ui::nivel1 *ui;
    QGraphicsScene *scene;
};

#endif // NIVEL1_H
