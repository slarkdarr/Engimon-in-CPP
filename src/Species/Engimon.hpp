#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include "../Skill/Skill.hpp"
#include "../Element.hpp"

using namespace std;

class Engimon{
protected:
    int monLevel;
    int monExp;
    int monCtvExp;
    int baseLevel;
    string monName;
    string namaSpecies;
    Skill *monSkills;
    Element *monElements;

    friend ostream& operator<<(ostream&, const Engimon&);

public:
    Engimon();
    Engimon(string);
    Engimon(const Engimon&);
    // Engimon(string, const Engimon&, const Engimon&);
    Engimon& operator=(const Engimon&);
    virtual void printInfo();
    void printInfoSafe();
    virtual ~Engimon();
    string getName() const;
    void setName(string);
    int getLevel() const;
    void setLevel(int level);
    bool addExp(int additionalExp);
    virtual ElementType getFirstElement();
    virtual ElementType getSecondElement();
    virtual float sumSkillPower();
    string getNamaSpecies() const;
    static float maxElAdv(Engimon* a, Engimon* b);

};

#endif