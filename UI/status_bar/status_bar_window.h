#pragma once
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
class StatusBarWindow : public QWidget
{
public:
    QPushButton *taskManagerBtn; // 任务管理器按钮
    // 构造函数
    StatusBarWindow(QWidget *parent = nullptr);

    void globalMousePressEvent(QMouseEvent *event);
};