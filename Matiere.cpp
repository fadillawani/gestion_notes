#include "Matiere.h"
using namespace std;
Matiere::Matiere() {}

Matiere::Matiere(string i, string l)
{
    id = i;
    libelle = l;
}

string Matiere::getId()
{
    return id;
}

string Matiere::getLibelle()
{
    return libelle;
}

void Matiere::setId(string i)
{
    id = i;
}

void Matiere::setLibelle(string l)
{
    libelle = l;
}
