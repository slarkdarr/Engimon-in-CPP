#include "Magnetize.hpp"

Magnetize::Magnetize() : Skill("Magnetize", "Ground", 150, 1) {
    this->species = "Articuno";
}

Magnetize::Magnetize(string species, int masteryLevel) : Skill("Magnetize", "Ground", 150, masteryLevel) {
    this->species = species;
}
