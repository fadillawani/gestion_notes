#include "Module.h"

Module::Module() {}
Module::Module(Matiere m, Classe c, int d, double coef)
{
    matiere = m;
    classe = c;
    duree = d;
    coefficient = coef;
}

Matiere Module::getMatiere()
{
    return matiere;
}

Classe Module::getClasse()
{
    return classe;
}

int Module::getDuree()
{
    return duree;
}

double Module::getCoefficient()
{
    return coefficient;
}

void Module::setMatiere(Matiere m)
{
    matiere = m;
}

void Module::setClasse(Classe c)
{
    classe = c;
}

void Module::setDuree(int d)
{
    duree = d;
}

void Module::setCoefficient(double coef)
{
    coefficient = coef;
}
