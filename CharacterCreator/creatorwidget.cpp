#include "creatorwidget.h"

CreatorWidget::CreatorWidget(QWidget *parent) : QTabWidget(parent),
    log(NULL),
    configAccessor(NULL)

{

}

bool CreatorWidget::init(ConfigAccessor *accessor, logger::Logger *nLog) {
    log = nLog;
    configAccessor = accessor;

}
