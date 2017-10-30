#ifndef RACEOBJECT_H
#define RACEOBJECT_H

#include <QObject>

class RaceObject : public QObject
{
    Q_OBJECT
public:
    explicit RaceObject(QObject *parent = nullptr);

    QString name;
    QString description;
signals:

public slots:
};

#endif // RACEOBJECT_H
