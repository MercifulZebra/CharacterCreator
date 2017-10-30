#ifndef CREATORWIDGET_H
#define CREATORWIDGET_H

#include <QWidget>
#include <QTabWidget>

namespace logger {
    class Logger;
}

class ConfigAccessor;

class ClassTabWidget;
class RaceTabWidget;


class CreatorWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit CreatorWidget(QWidget *parent = nullptr);

    bool init(logger::Logger *nLog, ConfigAccessor *accessor);

    logger::Logger *log;

    ConfigAccessor *configAccessor;

    RaceTabWidget *raceTab;
    ClassTabWidget *classTab;

signals:

public slots:
};

#endif // CREATORWIDGET_H
