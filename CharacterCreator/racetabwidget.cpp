#include "racetabwidget.h"

#include "configaccessor.h"
#include "logger.h"
#include "raceobject.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

RaceTabWidget::RaceTabWidget(QWidget *parent) : QWidget(parent),
    log(NULL),
    config_accessor(NULL),
    thisLayout(NULL)
{

}

bool RaceTabWidget::init(logger::Logger *nLog, ConfigAccessor *accessor) {

    log = nLog;
    config_accessor = accessor;

    bool initSuccess_flag = true;


    if ((log != NULL) &&
        (config_accessor != NULL)) {

        thisLayout = new QGridLayout(this);
        thisLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

        centralWidget = new QGroupBox(this);
        thisLayout->addWidget(centralWidget);

        centralLayout = new QVBoxLayout(centralWidget);
        centralLayout->setSizeConstraint(QLayout::SetMinimumSize);
        centralWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);


        if(!loadRaces()) {
            initSuccess_flag = false;
        }
    }
    else {
        initSuccess_flag = false;
    }

    return initSuccess_flag;
}

bool RaceTabWidget::loadRaces() {
    bool loadSuccess_flag = false;

    if ((log != NULL) &&
        (config_accessor != NULL)) {

        loadSuccess_flag = true;

        for (int i = 0; i < config_accessor->races.count(); i++) {
            RaceObject* nRace = config_accessor->races.at(i);
            QPushButton* nButton = nRace->getRaceButton(this);
            centralLayout->addWidget(nButton, Qt::AlignLeft);
        }
    }

    return loadSuccess_flag;
}
