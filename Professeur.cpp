#include "Professeur.h"
using namespace std;

Professeur::Professeur() {}
Professeur::Professeur(string i, string n, string p, string spec)
{
    id = i;
    nom = n;
    prenom = p;
    this->spec = spec;
}

string Professeur::getId()
{
    return id;
}

string Professeur::getNom()
{
    return nom;
}

string Professeur::getPrenom()
{
    return prenom;
}

string Professeur::getSpec()
{
    return spec;
}

void Professeur::setId(string i)
{
    id = i;
}

void Professeur::setNom(string n)
{
    nom = n;
}

void Professeur::setPrenom(string p)
{
    prenom = p;
}

void Professeur::setSpec(string s)
{
    spec = s;
}
