#include "OSThread.h"

OSThread::OSThread(QMainWindow *mainWindow) : QThread()
{
    this->mainWindow = mainWindow;
}

void OSThread::run()
{
    mainWindow->show();
}

