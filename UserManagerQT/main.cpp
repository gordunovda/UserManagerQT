#include <QGuiApplication>
#include <qqmlcontext.h>
#include <QQmlApplicationEngine>    
#include "UserController.h"
#include "StaticUserManager.h"

int main(int argc, char *argv[])
{
    StaticUserManager userManager;
    userManager.Init();

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController userController(&userManager);
    userManager.Attach(&userController);

    engine.rootContext()->setContextProperty("userController", &userController);
    
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    
    return app.exec();
}
