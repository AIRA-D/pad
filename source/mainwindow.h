#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    explicit MainWindow(const QString &fileName);
    void tile(const QMainWindow *previous);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots: // для связи с основными функциями
    void newFile(); // новый файл
    void open(); // открыть файл
    bool save(); // сохранение
    bool saveAs(); // сохр. как
    void updateRecentFileActions(); // контроль действий
    void openRecentFile(); // открыть недавние файлы
    void documentWasModified(); // контроль редактирования документа

private:
    enum { MaxRecentFiles = 4 };
// основные функции
    void init();
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void openFile(const QString &fileName);
    void loadFile(const QString &fileName);
    static bool hasRecentFiles();
    void prependToRecentFiles(const QString &fileName);
    void setRecentFilesVisible(bool visible);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    static QString strippedName(const QString &fullFileName);
    [[nodiscard]] static MainWindow *findMainWindow(const QString &fileName) ;

    QTextEdit *textEdit{};

    QAction *recentFileActs[MaxRecentFiles]{};
    QAction *recentFileSeparator{};
    QAction *recentFileSubMenuAct{};

    QString curFile;
    bool isUntitled{};
};

#endif
