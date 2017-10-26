#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace logger {
    class Logger;
}

class ConfigAccessor;
class CreatorWidget;

class QStackedWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool init(QString config_filename);

private:
    Ui::MainWindow *ui;

    logger::Logger      *log;
    ConfigAccessor      *accessor;

    QStackedWidget      *mainStack;

    CreatorWidget       *creatorWidget;

    int                  creatorWidget_index;
};

#endif // MAINWINDOW_H
