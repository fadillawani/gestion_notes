#include "Classe.h"

Classe::Classe(){}
Classe::Classe(std::string i, std::string n) : id(i), nom(n) {}

std::string Classe::getId() const {
    return id;
}

std::string Classe::getNom() const {
    return nom;
}
