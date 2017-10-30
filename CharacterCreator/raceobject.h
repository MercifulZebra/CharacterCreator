#ifndef RACEOBJECT_H
#define RACEOBJECT_H

#include <QObject>

class QPushButton;

class RaceObject : public QObject
{
    Q_OBJECT
public:
    explicit RaceObject(QObject *parent = nullptr);

    QPushButton* getRaceButton(QWidget *parent = 0);

    QString name;
    QString description;

    int     speed;
    int     str_bonus;
    int     dex_bonus;
    int     con_bonus;
    int     int_bonus;
    int     wis_bonus;
    int     cha_bonus;
    int     any_bonus;

signals:

public slots:

    void handleToggleRaceButton();
};

#endif // RACEOBJECT_H
