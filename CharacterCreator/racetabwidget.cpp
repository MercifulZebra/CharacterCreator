#include "racetabwidget.h"

#include "configaccessor.h"
#include "logger.h"
#include "raceobject.h"

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

RaceTabWidget::RaceTabWidget(QWidget *parent) : QWidget(parent),
    log(NULL),
    config_accessor(NULL)
{

}

bool RaceTabWidget::init(logger::Logger *nLog, ConfigAccessor *accessor) {
    log = nLog;
    config_accessor = accessor;

    QVBoxLayout *thisLayout = new QVBoxLayout(this);

    if ((log != NULL) &&
        (config_accessor != NULL)) {

        for (int i = 0; i < config_accessor->races.count(); i++) {
            RaceObject* nRace = config_accessor->races.at(i);

            QLabel *nLabel = new QLabel(this);
            nLabel->setText(nRace->name + ": " + nRace->description);
            thisLayout->addWidget(nLabel);
        }
    }

    return true;
}
