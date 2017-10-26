#ifndef CREATORWIDGET_H
#define CREATORWIDGET_H

#include <QWidget>
#include <QTabWidget>

namespace logger {
    class Logger;
}

class ConfigAccessor;

class CreatorWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit CreatorWidget(QWidget *parent = nullptr);

    bool init(ConfigAccessor *accessor, logger::Logger *nLog);

    logger::Logger *log;

    ConfigAccessor *configAccessor;


signals:

public slots:
};

#endif // CREATORWIDGET_H
