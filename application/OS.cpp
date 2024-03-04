#include "OS.h"

OSApplication::OSApplication(int &argc, char *argv[]): QApplication(argc, argv)
{
}

bool OSApplication::notify(QObject* obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            emit notify(event);
        }

        if (mouseEvent->button() == Qt::RightButton)
        {
            emit notify(event);
        }
    }

    return QApplication::notify(obj, event);
}
