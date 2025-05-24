#include "Matiere.h"

Matiere::Matiere(){}


Matiere::Matiere(std::string i, std::string l) : id(i), libelle(l) {}

std::string Matiere::getId() const {
    return id;
}

std::string Matiere::getLibelle() const {
    return libelle;
}
