#include "Enseignement.h"
#include "Matiere.h"
using namespace std;
Enseignement::Enseignement() {}
Enseignement::Enseignement(Classe c, Matiere m, int vh, float coef, Professeur p, string an)
{
    classe = c;
    matiere = m;
    volumeHoraire = vh;
    coefficient = coef;
    professeur = p;
    annee = an;
}

Classe Enseignement::getClasse() const
{
    return classe;
}

Matiere Enseignement::getMatiere() const
{
    return matiere;
}

int Enseignement::getVolumeHoraire() const
{
    return volumeHoraire;
}

float Enseignement::getCoefficient() const
{
    return coefficient;
}

Professeur Enseignement::getProfesseur() const
{
    return professeur;
}

string Enseignement::getAnnee() const
{
    return annee;
}

void Enseignement::setClasse(Classe c)
{
    classe = c;
}

void Enseignement::setMatiere(Matiere m)
{
    matiere = m;
}

void Enseignement::setVolumeHoraire(int vh)
{
    volumeHoraire = vh;
}

void Enseignement::setCoefficient(float coef)
{
    coefficient = coef;
}

void Enseignement::setProf(Professeur p)
{
    professeur = p;
}

void Enseignement::setAnnee(string an)
{
    annee = an;
}
