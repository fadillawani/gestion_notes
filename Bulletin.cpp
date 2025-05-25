#include "Bulletin.h"
#include "Etudiant.h"

Bulletin::Bulletin()
{
}

Bulletin::Bulletin(Etudiant e, string s, float m, int r)
{
    etudiant = e;
    semestre = s;
    moyenne = m;
    rang = r;
}

Etudiant Bulletin::getEtudiant()
{
    return etudiant;
}

string Bulletin::getSemestre()
{
    return semestre;
}

float Bulletin::getMoyenne()
{
    return moyenne;
}

int Bulletin::getRang()
{
    return rang;
}

void Bulletin::setEtudiant(Etudiant e)
{
    this->etudiant = e;
}

void Bulletin::setSemestre(string s)
{
    this->semestre = s;
}

void Bulletin::setMoyenne(float m)
{
    this->moyenne = m;
}

void Bulletin::setRang(int r)
{
    this->rang = r;
}
