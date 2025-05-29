#include "Module.h"

Module::Module() {}
Module::Module(string i, Matiere m, Classe c, int d, double coef)
{
    id = i;
    matiere = m;
    classe = c;
    duree = d;
    coefficient = coef;
}

string Module::getId()
{
    return id;
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

void Module::setId(string i)
{
    id = i;
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
