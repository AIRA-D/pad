#include <QApplication>
#include <QCommandLineParser> // см. документацию https://doc.qt.io/qt-6/qcommandlineparser.html
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser; //

    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file(s) to open.");
    parser.process(app);

    MainWindow *mainWin = nullptr;
    const QStringList posArgs = parser.positionalArguments();
    for (const QString &file : posArgs) {
        auto *newWin = new MainWindow(file);
        newWin->tile(mainWin);
        newWin->show();
        mainWin = newWin;
    }
    if (!mainWin)
        mainWin = new MainWindow;
    mainWin->show();

    return QApplication::exec();
}
