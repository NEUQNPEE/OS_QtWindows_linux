#include "os_qtwindows.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QThread>

#include "application/OS.h"
#include "OSThread/OSThread.h"

#include "protobufData/MyTest.h"

int main(int argc, char *argv[])
{
    MyTest t;
    t.test();

    OSApplication os(argc, argv);

    // 创建窗口
    OS_QtWindows *w1 = new OS_QtWindows();

    // 创建线程
    OSThread thread1(w1);

    // 连接OSApplication的notify信号到窗口的notify槽函数，本质上这模拟了鼠标点击的硬件中断
    void (OSApplication::*notify)(QEvent *) = &OSApplication::notify;
    QObject::connect(&os, notify, w1, &OS_QtWindows::notify);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "OS_QtWindows_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            os.installTranslator(&translator);
            break;
        }
    }

    // 启动线程
    thread1.start();

    int ret = os.exec();
    
    // 等待线程结束
    thread1.wait();

    return ret;
}
