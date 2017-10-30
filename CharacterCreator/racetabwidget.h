#ifndef RACETABWIDGET_H
#define RACETABWIDGET_H

#include <QWidget>

namespace logger {
    class Logger;
}

class ConfigAccessor;

class RaceTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RaceTabWidget(QWidget *parent = nullptr);


    bool init(logger::Logger *nLog, ConfigAccessor *accessor);

    logger::Logger *log;
    ConfigAccessor *config_accessor;
signals:

public slots:
};

#endif // RACETABWIDGET_H
