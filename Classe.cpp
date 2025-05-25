#include "Classe.h"
#include "Etudiant.h"

Classe::Classe()
{
}

Classe::Classe(string i, string n, string niveau)
{
    id = i;
    nom = n;
    this->niveau = niveau;
}

string Classe::getId()
{
    return id;
}

string Classe::getNom()
{
    return nom;
}

string Classe::getNiveau()
{
    return niveau;
}

void Classe::setId(string i)
{
    this->id = i;
}

void Classe::setNom(string n)
{
    this->nom = n;
}

void Classe::setNiveau(string niveau)
{
    this->niveau = niveau;
}
