#include "teapotwidget.h"
#include <GL/glut.h>

TeapotWidget::TeapotWidget(QWidget *parent)
    : QOpenGLWidget(parent) {
}

TeapotWidget::~TeapotWidget() {

}

void TeapotWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

    // 初始化GLUT
    int argc = 1;
    char *argv[1] = {(char *)"Something"};
    glutInit(&argc, argv);
}

void TeapotWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // 眼睛位置
              0.0, 0.0, 0.0,  // 看向的点
              0.0, 1.0, 0.0); // 上方向

    glColor3f(1.0, 0.0, 0.0);
    glutSolidTeapot(1.0);  // 绘制茶壶
}

void TeapotWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, GLfloat(w) / h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
