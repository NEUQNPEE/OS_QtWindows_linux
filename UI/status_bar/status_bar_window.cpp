#include "status_bar_window.h"
#include <QDebug>

StatusBarWindow::StatusBarWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("选项");
    this->resize(200, 100);  // 调整窗口大小
    
    // 设置窗口背景颜色为白色
    this->setStyleSheet("background-color: white;");

    this->move(300, 300);



    // 创建并设置任务管理器按钮
    taskManagerBtn = new QPushButton("任务管理器", this);
    taskManagerBtn->setFixedSize(120, 30); // 设置按钮大小
    taskManagerBtn->move((this->width() - taskManagerBtn->width()) / 2, (this->height() - taskManagerBtn->height()) / 2);
}

void StatusBarWindow::globalMousePressEvent(QMouseEvent *event)
{
//     qDebug() << "状态栏窗口读取坐标";
//     qDebug() << event->globalPos();
//     qDebug() << this->geometry();


    if (!this->geometry().contains(event->pos()))
    {
        this->close();
    }
}
