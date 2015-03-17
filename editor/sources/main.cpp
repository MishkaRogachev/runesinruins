#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;

//    qmlRegisterType<presentation::VolumeRenderer>("RIR", 1, 0, "VolumeRenderer");

    view.setSource(QUrl("qrc:/qml/Main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setMinimumSize(QSize(1280, 800));
    view.show();
    return app.exec();
}
