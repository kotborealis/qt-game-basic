#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QVector2D>
#include <Qt>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector2D playerPosition{100, 100};
    QTimer timer;

    void paintEvent(QPaintEvent*) {
        QPainter painter(this);

        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(5);

        painter.setPen(pen);
        painter.drawRect(playerPosition.x(), playerPosition.y(), 50, 50);
    }

    bool movingLeft{false}, movingRight{false};

    void keyPressEvent(QKeyEvent *e) override {
        if(e->key() == Qt::Key_Left)
            movingLeft = true;
        if(e->key() == Qt::Key_Right)
            movingRight = true;
    }
    void keyReleaseEvent(QKeyEvent *e) override {
        if(e->key() == Qt::Key_Left)
            movingLeft = false;
        if(e->key() == Qt::Key_Right)
            movingRight = false;
    }

    void updateGameLogic() {
        playerPosition += {1.f * (movingRight - movingLeft), 0};
    }

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
