#include "Module.h"

Module::Module(){}
Module::Module(Matiere m, Classe c, int d, float coef)
    : matiere(m), classe(c), duree(d), coefficient(coef) {}

Matiere Module::getMatiere() const {
    return matiere;
}

Classe Module::getClasse() const {
    return classe;
}

int Module::getDuree() const {
    return duree;
}

float Module::getCoefficient() const {
    return coefficient;
}
