#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

#include "volume_render_item.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;

    qmlRegisterType<presentation::VolumeRenderItem>(
                "presentation", 1, 0, "VolumeRenderItem");

    view.setSource(QUrl("qrc:/qml/Main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setMinimumSize(QSize(1280, 800));
    view.show();
    return app.exec();
}
