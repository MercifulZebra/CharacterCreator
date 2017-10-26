#include "character.h"


Character::Character(QObject *parent) : QObject(parent),
    strength(10),
    dexterity(10),
    constitution(10),
    intelligence(10),
    wisdom(10),
    charisma(10)
{
    clear();
}

void Character::clear() {
    strength        = 10;
    dexterity       = 10;
    constitution    = 10;
    intelligence    = 10;
    wisdom          = 10;
    charisma        = 10;

    proficient_skills.clear();
    expertise_skills.clear();
}

void Character::setStats(int str, int dex, int con, int int_, int wis, int cha) {
    strength = str;
    dexterity = dex;
    constitution = con;
    intelligence = int_;
    wisdom = wis;
    charisma = cha;
}

void Character::setLevel(int nLevel) {
    level = nLevel;
}

int Character::getSkillBonus(Skills skill) {

    int prof_mod = getSkillProficiency(skill);

    int stat_mod = 0;

    switch (skill) {

        case ATHLETICS:
            stat_mod = getModifier(strength);
            break;
        case ACROBATICS:
        case SLEIGHT_OF_HAND:
        case STEALTH:
            stat_mod = getModifier(dexterity);
            break;
        case ARCANA:
        case HISTORY:
        case INVESTIGATION:
        case NATURE:
        case RELIGION:
            stat_mod = getModifier(intelligence);
            break;
        case ANIMAL_HANDLING:
        case INSIGHT:
        case MEDICINE:
        case PERCEPTION:
        case SURVIVAL:
            stat_mod = getModifier(wisdom);
            break;
        case DECEPTION:
        case INTIMIDATION:
        case PERFORMANCE:
        case PERSUASION:
            stat_mod = getModifier(charisma);
            break;
        default:
            break;
    }

    return stat_mod + prof_mod;
}

QString Character::getSkillName(Skills skill) {
    QString nName = "";
    switch (skill) {

    case ATHLETICS:
        nName = "Athletics";
        break;
    case ACROBATICS:
        nName = "Acrobatics";
        break;
    case SLEIGHT_OF_HAND:
        nName = "Sleight of Hand";
        break;
    case STEALTH:
        nName = "Stealth";
        break;
    case ARCANA:
        nName = "Arcana";
        break;
    case HISTORY:
        nName = "History";
        break;
    case INVESTIGATION:
        nName = "Investigation";
        break;
    case NATURE:
        nName = "Nature";
        break;
    case RELIGION:
        nName = "Religion";
        break;
    case ANIMAL_HANDLING:
        nName = "Animal Handling";
        break;
    case INSIGHT:
        nName = "Insight";
        break;
    case MEDICINE:
        nName = "Medicine";
        break;
    case PERCEPTION:
        nName = "Percpetion";
        break;
    case SURVIVAL:
        nName = "Survival";
        break;
    case DECEPTION:
        nName = "Deception";
        break;
    case INTIMIDATION:
        nName = "Intimidation";
        break;
    case PERFORMANCE:
        nName = "Performance";
        break;
    case PERSUASION:
        nName = "Persuasion";
        break;
    default:
        break;
    }

    return nName;
}

//
//
// Helper functions
//
//
//

int Character::getModifier(int score) {
    int half = floor(score / 2);

    return half - 5;
}

int Character::getProficiency() {
    return floor((getTotalLevel() - 1) / 4) + 2;
}

int Character::getTotalLevel() {
    return level;
}

void Character::clearSkills() {
    proficient_skills.clear();
}

void Character::addSkillProficiency(Skills nSkill) {
    if (!proficient_skills.contains(nSkill)) {
        proficient_skills.append(nSkill);
    }
}

void Character::addSkillExpertise(Skills nSkill) {
    if (!expertise_skills.contains(nSkill)) {
        expertise_skills.append(nSkill);
    }
}

int Character::getSkillProficiency(Skills tSkill) {
    int mod = 0;

    if (expertise_skills.contains(tSkill)) {
        mod = 2 * getProficiency();
    }
    else if (proficient_skills.contains(tSkill)) {
        mod = getProficiency();
    }

    return mod;
}


