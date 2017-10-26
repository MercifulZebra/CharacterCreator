#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "character.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Character character;
    character.setLevel(1);
    character.setStats(8, 10, 12, 14, 16, 18);

    qDebug() << character.getSkillName(ATHLETICS) << ":" << character.getSkillBonus(ATHLETICS);
    qDebug() << character.getSkillName(ACROBATICS) << ":" <<  character.getSkillBonus(ACROBATICS);
    qDebug() << character.getSkillName(ARCANA) << ":" <<  character.getSkillBonus(ARCANA);
    qDebug() << character.getSkillName(ANIMAL_HANDLING) << ":" <<  character.getSkillBonus(ANIMAL_HANDLING);
    qDebug() << character.getSkillName(DECEPTION) << ":" <<  character.getSkillBonus(DECEPTION);

    return a.exec();
}
