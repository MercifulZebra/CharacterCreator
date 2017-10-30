#ifndef RACETABWIDGET_H
#define RACETABWIDGET_H

#include <QWidget>

namespace logger {
    class Logger;
}

class ConfigAccessor;

class QGroupBox;

class QGridLayout;
class QVBoxLayout;

class RaceTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RaceTabWidget(QWidget *parent = nullptr);


    bool init(logger::Logger *nLog, ConfigAccessor *accessor);

    bool loadRaces();

    logger::Logger *log;
    ConfigAccessor *config_accessor;

    QGroupBox      *centralWidget;

    QGridLayout    *thisLayout;
    QVBoxLayout    *centralLayout;

signals:

public slots:
};

#endif // RACETABWIDGET_H
