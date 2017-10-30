#include "configaccessor.h"

#include "raceobject.h"

#include <QFile>
#include <QRegExp>
#include <QStringList>


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

    int     speed = 30;

    int     str_bonus = 0;
    int     dex_bonus = 0;
    int     con_bonus = 0;
    int     wis_bonus = 0;
    int     int_bonus = 0;
    int     cha_bonus = 0;
    int     any_bonus = 0;


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
                name = currentLine.right(currentLine.length() - 5);
                name = name.trimmed();
            }
            else if (currentLine.startsWith("Description:")) {
                description = currentLine.right(currentLine.length() - 12);
                description = description.trimmed();
            }
            else if (currentLine.startsWith("Attributes:")) {
                QString attr;
                QStringList attr_list;
                attr = currentLine.right(currentLine.length() - 11);
                attr = attr.trimmed();
                attr_list = attr.split(",");

                for (int i = 0; i < attr_list.count(); i++) {
                    QRegExp seperator(" ");
                    QStringList current_attr = attr_list.at(i).mid(1, attr_list.at(i).length() - 2).split(seperator);
                    if (current_attr.count() == 2) {
                        if (current_attr.at(0).contains("STR", Qt::CaseInsensitive)) {
                            str_bonus = current_attr.at(1).toInt();
                        }
                        else if (current_attr.at(0).contains("DEX", Qt::CaseInsensitive)) {
                            dex_bonus = current_attr.at(1).toInt();
                        }
                        else if (current_attr.at(0).contains("CON", Qt::CaseInsensitive)) {
                            con_bonus = current_attr.at(1).toInt();
                        }
                        else if (current_attr.at(0).contains("INT", Qt::CaseInsensitive)) {
                            int_bonus = current_attr.at(1).toInt();
                        }
                        else if (current_attr.at(0).contains("WIS", Qt::CaseInsensitive)) {
                            wis_bonus = current_attr.at(1).toInt();
                        }
                        else if (current_attr.at(0).contains("CHA", Qt::CaseInsensitive)) {
                            cha_bonus = current_attr.at(1).toInt();
                        }
                        else if (current_attr.at(0).contains("ANY", Qt::CaseInsensitive)) {
                            any_bonus = current_attr.at(1).toInt();
                        }
                    }
                }


            }
            else if (currentLine.startsWith("Speed:")) {
                speed = currentLine.right(currentLine.length() - 6).toInt();
            }
        }
    }

    if (!name.isEmpty() &&
        !description.isEmpty()) {
        nRace = new RaceObject(this);
        nRace->name = name;
        nRace->description = description;
        nRace->speed = speed;
        nRace->str_bonus = str_bonus;
        nRace->dex_bonus = dex_bonus;
        nRace->con_bonus = con_bonus;
        nRace->int_bonus = int_bonus;
        nRace->wis_bonus = wis_bonus;
        nRace->cha_bonus = cha_bonus;
        nRace->any_bonus = any_bonus;
    }

    return nRace;

}
