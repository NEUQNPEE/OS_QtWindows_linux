#ifndef OS_QTWINDOWS_H
#define OS_QTWINDOWS_H

#pragma once

#include "./ui_os_qtwindows.h"

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QToolBar>
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QResizeEvent>
#include <QTableWidget>
#include <QHeaderView>
#include <QTreeView>
#include <QFileSystemModel>
#include <QPainter>
#include <QSplitter>
#include <QTextEdit>
#include <QMessageBox>
#include <QTimer>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QMenu>
#include <QModelIndex>
#include <QInputDialog>

#include <QMouseEvent>

#include "UI/ui.h"

#include "process/process_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class OS_QtWindows;
}
QT_END_NAMESPACE

class OS_QtWindows : public QMainWindow
{
    Q_OBJECT

public:
    OS_QtWindows(QWidget *parent = nullptr);
    ~OS_QtWindows();

    // close()函数
    void close();

    // 接收全局事件
    void notify(QEvent * event);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::OS_QtWindows *ui;

    StatusBar *statusBar;
    Win *win_btn;
    WinWindow *win_window;
    QLabel *timeLabel;

    InitProcess initProc = InitProcess::create("init", PIDGenerator::generatePID(), 0, ProcessType::INIT_PROCESS);
    
    void showTaskManager();

    void showWinWindow();

    // 以下为UI交互部分
    void StatusBarLeftClicked();
    void StatusBarRightClicked();

signals:
    void globalLeftClicked(QMouseEvent *event);
    void globalRightClicked(QMouseEvent *event);
    void globalClicked(QMouseEvent *event);
};
#endif // OS_QTWINDOWS_H
