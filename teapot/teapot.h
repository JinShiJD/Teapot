#ifndef TEAPOTWIDGET_H
#define TEAPOTWIDGET_H

#include <QOpenGLWidget>

class TeapotWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    explicit TeapotWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    // 私有成员和方法
};

#endif // TEAPOTWIDGET_H
