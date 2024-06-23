#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teapotwidget.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TeapotWidget *teapotWidget = new TeapotWidget(this);
    setCentralWidget(teapotWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

