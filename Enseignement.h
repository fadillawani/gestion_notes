#ifndef ENSEIGNEMENT_H
#define ENSEIGNEMENT_H

#include <string>
#include "Classe.h"
#include "Matiere.h"
#include "Professeur.h"
using namespace std;

class Enseignement
{
private:
    string id;
    Classe classe;
    Matiere matiere;
    int volumeHoraire;
    double coefficient;
    Professeur professeur;
    string annee;

public:
    Enseignement();
    Enseignement(Classe c, Matiere m, int vh, double coef, Professeur p, string an);

    string getId();
    Classe getClasse() const;
    Matiere getMatiere() const;
    int getVolumeHoraire() const;
    double getCoefficient() const;
    Professeur getProfesseur() const;
    string getAnnee() const;

    void setId(string);
    void setClasse(Classe);
    void setMatiere(Matiere);
    void setVolumeHoraire(int);
    void setCoefficient(double);
    void setProf(Professeur);
    void setAnnee(string);

    string toString();
};

#endif
