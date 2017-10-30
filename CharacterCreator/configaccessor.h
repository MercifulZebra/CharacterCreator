#ifndef CONFIGACCESSOR_H
#define CONFIGACCESSOR_H

#include <QObject>
#include <QTextStream>
#include <QVector>

class RaceObject;

class ConfigAccessor : public QObject
{
    Q_OBJECT
public:
    explicit ConfigAccessor(QObject *parent = nullptr);

    void clear();
    bool loadConfig(QString config_filename);

    QVector<RaceObject *> races;

private:
    RaceObject* loadRace(QTextStream &inFile);

signals:

public slots:
};

#endif // CONFIGACCESSOR_H
