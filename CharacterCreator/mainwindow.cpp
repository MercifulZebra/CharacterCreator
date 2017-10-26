#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "configaccessor.h"
#include "creatorwidget.h"
#include "logger.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log(NULL),
    accessor(NULL),
    mainStack(NULL),
    creatorWidget(NULL),
    creatorWidget_index(-1)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init(QString config_filename) {
    bool initSuccess_flag = true;

    log = new logger::Logger();

    if (log->init("config.txt")) {
        log->info("Successfully initialized Logger.");

        log->debug("Initializing Main Stack Widget.");
        mainStack = new QStackedWidget(this);
        setCentralWidget(mainStack);

        log->debug("Initialize Configuration Accessor.");
        accessor = new ConfigAccessor(this);
        if (!accessor->loadConfig(config_filename)) {
            log->err("Failed to load configuration file. Exiting initialization.");
            initSuccess_flag = false;
        }

        if (initSuccess_flag) {
            log->debug("Starting Character Screen Initialization.");
            creatorWidget = new CreatorWidget(this);
            if (!creatorWidget->init(log, accessor)) {
                initSuccess_flag = false;
            }
        }

    }

    return initSuccess_flag;

}
