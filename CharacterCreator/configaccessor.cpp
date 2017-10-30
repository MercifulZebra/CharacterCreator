#include "configaccessor.h"

#include "raceobject.h"

#include <QFile>


const std::string AM_AM_DESCRIPTOR("[Race]");

ConfigAccessor::ConfigAccessor(QObject *parent) : QObject(parent),
    races()
{

}

void ConfigAccessor::clear() {

    races.clear();
}

bool ConfigAccessor::loadConfig(QString config_filename) {
    bool initSucces_flag = true;

    clear();

    QFile inputFile(config_filename);

    if (inputFile.open(QIODevice::ReadOnly)) {

        QTextStream inStream(&inputFile);

        while(!inStream.atEnd()) {

            QString currentLine = inStream.readLine();

            bool lineReadSucces_flag = true;
            int revertStream = inStream.pos();

            if (!(currentLine.startsWith("#")) &&
                !(currentLine.startsWith("//")) &&
                !(currentLine.isEmpty())) {

                //
                //Load various objects
                //


                if (currentLine.startsWith("[Race]")) {                 //Load Race
                    RaceObject *nRace = loadRace(inStream);

                    if (nRace != NULL) {
                        races.append(nRace);
                    }
                    else {
                        lineReadSucces_flag = false;
                    }
                }

                //Revert back to line after insuccessful read
                if (!lineReadSucces_flag) {
                    inStream.seek(revertStream);
                }

            }

        }

        inputFile.close();
    }



    return initSucces_flag;
}

//Private

RaceObject* ConfigAccessor::loadRace(QTextStream &inFile) {
    QString name;
    QString description;

    bool receivedStart_flag = false;
    bool continue_flag = true;

    RaceObject *nRace = NULL;

    while(!inFile.atEnd() && continue_flag) {

        QString currentLine = inFile.readLine();
        currentLine = currentLine.trimmed();

        if (!receivedStart_flag) {
            if (currentLine.startsWith("{")) {
                receivedStart_flag = true;
            }
        }
        else {
            if (currentLine.startsWith("}")) {
                continue_flag = false;
            }
            else if (currentLine.startsWith("Name:")) {
                name = currentLine;
            }
            else if (currentLine.startsWith("Description:")) {
                description = currentLine;
            }
        }
    }

    if (!name.isEmpty() &&
        !description.isEmpty()) {
        nRace = new RaceObject(this);
        nRace->name = name;
        nRace->description = description;
    }

    return nRace;

}
