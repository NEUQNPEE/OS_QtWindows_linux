#pragma once
#include <QThread>
#include <QMainWindow>

class OSThread :public QThread
{
    Q_OBJECT

public:
    // 构造函数
    OSThread(QMainWindow *mainWindow);

protected:
    // 重写run函数
    void run() override;

private:
    // 窗口
    QMainWindow *mainWindow;
};