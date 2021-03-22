#include <iostream>
#include <string>
#include "Engimon.hpp"
#include "Skill.hpp"
using namespace std;

Engimon::Engimon(){
    this->monName = "";
    this->namaSpecies = "";
    this->monLevel = 1;
    this->monExp = 0;
    this->monCtvExp = 2000;
}

Engimon::Engimon(string monName){
    this->monName = monName;
    this->namaSpecies = "";
    this->monLevel = 1;
    this->monExp = 0;
    this->monCtvExp = 2000;
}
void Engimon::setName(string name)
{
    this->monName = name;
}

void Engimon::setLevel(int level) {
    this->monLevel = level;
}
bool Engimon::addExp(int additionalExp) {
    int virtualExp = this->monLevel * 100;
    this->monExp += additionalExp;
    std::cout << "Anda Mendapatkan " << additionalExp << " exp" << std::endl;  
    if (monExp >= monCtvExp)
    {
        delete this;
        return false;
    }
    else if (this->monLevel != ((this->monExp + virtualExp)/ 100))  {
        std::cout << "LEVEL UP!! Engimon anda naik " 
        << ((this->monExp + virtualExp)/ 100) - this->monLevel << " level" << std::endl; 
        this->monLevel = ((this->monExp + virtualExp) / 100);
    }
    return true;
}

// Engimon::Engimon(string monName, const Engimon& parent1, const Engimon& parent2){
//     this->monName = monName;
//     this->monLevel = 5;
//     this->monExp = 0;
//     this->monCtvExp = 0;
// }

Engimon& Engimon::operator=(const Engimon& other){
    this->monName = other.getName();
    this->namaSpecies = other.getNamaSpecies();
    this->monLevel = other.monLevel;
    this->monExp = other.monExp;
    this->monCtvExp = other.monCtvExp;
    return *this;
}

string Engimon :: getNamaSpecies() const{
    return namaSpecies;
}
string Engimon :: getName() const{
    return monName;
}
int Engimon :: getLevel() const{
    return this->monLevel;
}

ElementType Engimon :: getFirstElement()
{
    return None;
}

ElementType Engimon :: getSecondElement()
{
    return None;
}

Engimon :: ~Engimon(){

}

ostream& operator<<(ostream& os, const Engimon& e){
    os << "Engimon || Nama : " << e.getName() << " || Spesies : " << e.getNamaSpecies() << " || Level : " << e.getLevel();
    return os;
}
void Engimon::printInfo() {
    cout << "Nama : " << this->monName << endl;
    printInfoSafe();
    cout << "Exp : " << this->monExp << endl;
    cout << "Cumulative Exp : " << this->monCtvExp << endl;
}

void Engimon::printInfoSafe() {
    cout << "Nama Spesies : " << this->namaSpecies << endl;
    cout << "Level : " << this->monLevel << endl;
}