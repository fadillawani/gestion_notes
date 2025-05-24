#include "Professeur.h"

Professeur::Professeur(){}
Professeur::Professeur(std::string i, std::string n, std::string p) : id(i), nom(n), prenom(p) {}

std::string Professeur::getId() const {
    return id;
}

std::string Professeur::getNom() const {
    return nom;
}

std::string Professeur::getPrenom() const {
    return prenom;
}
