#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QVector>

namespace {
class RaceManager;
class ClassManager;
class BackgroundManager;
class FeatManager;
class ASIManager;
}

enum Skills {
    ACROBATICS,
    ANIMAL_HANDLING,
    ARCANA,
    ATHLETICS,
    DECEPTION,
    HISTORY,
    INSIGHT,
    INTIMIDATION,
    INVESTIGATION,
    MEDICINE,
    NATURE,
    PERCEPTION,
    PERFORMANCE,
    PERSUASION,
    RELIGION,
    SLEIGHT_OF_HAND,
    STEALTH,
    SURVIVAL
};

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = nullptr);

    void clear();

    void setStats(int str, int dex, int con, int int_, int wis, int cha);
    void setLevel(int nLevel);

    int getSkillBonus(Skills skill);
    QString getSkillName(Skills skill);

protected:
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

    int level;

    QVector<Skills> proficient_skills;
    QVector<Skills> expertise_skills;

private:
    int getModifier(int score);
    int getProficiency();
    int getTotalLevel();

    void clearSkills();
    void addSkillProficiency(Skills nSkill);
    void addSkillExpertise(Skills nSkill);
    int getSkillProficiency(Skills tSkill);
    int getSkillExpertise(Skills tSkill);



signals:

public slots:
};

#endif // CHARACTER_H
