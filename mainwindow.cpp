#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer.start(1/60);
    connect(&timer, &QTimer::timeout, [&](){
        this->updateGameLogic();
        this->update();
    });
}

MainWindow::~MainWindow() {}
