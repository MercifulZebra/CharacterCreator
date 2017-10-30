#include "raceobject.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

RaceObject::RaceObject(QObject *parent) : QObject(parent),
    name(),
    description(),
    speed(30),
    str_bonus(0),
    dex_bonus(0),
    con_bonus(0),
    int_bonus(0),
    wis_bonus(0),
    cha_bonus(0),
    any_bonus(0)
{

}

QPushButton* RaceObject::getRaceButton(QWidget *parent) {


    QPushButton *container_button = new QPushButton(parent);
    container_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    container_button->setMaximumWidth(300);
    QGridLayout *buttonLayout = new QGridLayout(container_button);

    QWidget *container_widget = new QWidget(container_button);
    container_widget->setMinimumWidth(300);
    container_widget->setMaximumWidth(300);
    QGridLayout *containerLayout = new QGridLayout(container_widget);
    containerLayout->setMargin(0);

    QPushButton *toggle_button = new QPushButton(container_button);
    toggle_button->setText("Hide Info");
    toggle_button->setObjectName("Toggle_Button");
    connect(toggle_button, SIGNAL(clicked(bool)), this, SLOT(handleToggleRaceButton()));

    //Name Label
    QLabel *nLabel = new QLabel(container_button);
    //nLabel->setFrameShape(QFrame::Box);
    nLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QString nameText = "";
    nameText = QString(name);
    nLabel->setText(nameText);

    //Description Label
    QLabel *dLabel = new QLabel(container_button);
    //dLabel->setFrameShape(QFrame::Box);
    dLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    dLabel->setWordWrap(true);
    dLabel->setMaximumWidth(300);

    dLabel->setObjectName("Description_Label");

    QString labelText = "";
    labelText = QString(labelText + "Speed +" + QString::number(speed) + "\n");

    QString attrText;
    if (str_bonus != 0) {
        attrText = QString(attrText + "STR " + QString("%1").arg(str_bonus < 0 ? '-' : '+') + QString::number(str_bonus) + ", ");
    }
    if (dex_bonus != 0) {
        attrText = QString(attrText + "DEX " + QString("%1").arg(dex_bonus < 0 ? '-' : '+') + QString::number(dex_bonus) + ", ");
    }
    if (con_bonus != 0) {
        attrText = QString(attrText + "CON " + QString("%1").arg(con_bonus < 0 ? '-' : '+') + QString::number(con_bonus) + ", ");
    }
    if (int_bonus != 0) {
        attrText = QString(attrText + "INT " + QString("%1").arg(int_bonus < 0 ? '-' : '+') + QString::number(int_bonus) + ", ");
    }
    if (wis_bonus != 0) {
        attrText = QString(attrText + "WIS " + QString("%1").arg(wis_bonus < 0 ? '-' : '+') + QString::number(wis_bonus) + ", ");
    }
    if (cha_bonus != 0) {
        attrText = QString(attrText + "CHA " + QString("%1").arg(cha_bonus < 0 ? '-' : '+') + QString::number(cha_bonus) + ", ");
    }
    if (any_bonus != 0) {
        attrText = QString(attrText + "ANY " + QString("%1").arg(any_bonus < 0 ? '-' : '+') + QString::number(any_bonus) + ", ");
    }

    if (!attrText.isEmpty()) {
        attrText = attrText.left(attrText.length() - 2);
        attrText = QString(attrText + "\n");
        labelText = QString(labelText + attrText);
    }

    labelText = QString(labelText + description + "\n");

    dLabel->setText(labelText);
    dLabel->hide();

    //Set Layout
    buttonLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    buttonLayout->addWidget(container_widget);
    containerLayout->addWidget(nLabel, 0, 0, Qt::AlignLeft);
    containerLayout->addWidget(toggle_button, 0, 1, Qt::AlignRight);
    containerLayout->addWidget(dLabel, 1, 0, 1, 2);

    return container_button;
}

void RaceObject::handleToggleRaceButton() {
    QPushButton* senderButton = dynamic_cast<QPushButton*> (sender());

    if (senderButton != NULL) {
        QWidget* containerWidget = dynamic_cast<QWidget*>(senderButton->parent());

        if (containerWidget != NULL) {
            QPushButton* containerButton = dynamic_cast<QPushButton*>(containerWidget->parent());

            if (containerButton != NULL) {
                QLabel* descLabel = containerButton->findChild<QLabel*>("Description_Label");
                QPushButton* toggleButton = containerButton->findChild<QPushButton*>("Toggle_Button");

                if (descLabel != NULL &&
                        toggleButton != NULL) {

                    if (descLabel->isHidden()) {
                        toggleButton->setText("hide info");
                        descLabel->show();
                    }
                    else {
                        toggleButton->setText("show info");
                        descLabel->hide();
                    }

                }
            }
        }
    }
}
