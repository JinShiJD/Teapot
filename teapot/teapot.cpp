#include "teapotwidget.h"

TeapotWidget::TeapotWidget(QWidget *parent)
    : QOpenGLWidget(parent) {
    // 构造函数实现
}

void TeapotWidget::initializeGL() {
    // 初始化OpenGL
}

void TeapotWidget::paintGL() {
    // 绘制OpenGL场景
}

void TeapotWidget::resizeGL(int w, int h) {
    // 调整OpenGL视口
}
