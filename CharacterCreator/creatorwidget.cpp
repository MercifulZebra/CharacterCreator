#include "creatorwidget.h"

#include "classtabwidget.h"
#include "racetabwidget.h"

CreatorWidget::CreatorWidget(QWidget *parent) : QTabWidget(parent),
    log(NULL),
    configAccessor(NULL),
    raceTab(NULL),
    classTab(NULL)

{

}

bool CreatorWidget::init(logger::Logger *nLog, ConfigAccessor *accessor) {
    log = nLog;
    configAccessor = accessor;

    //Set Dimensions
    setMinimumWidth(500);
    setMinimumHeight(500);

    classTab = new ClassTabWidget(this);
    raceTab = new RaceTabWidget(this);

    raceTab->init(log, configAccessor);

    addTab(classTab, "Class");
    addTab(raceTab, "Race");

    setCurrentIndex(1);

    return true;

}
