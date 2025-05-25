#ifndef ENSEIGNEMENT_H
#define ENSEIGNEMENT_H

#include <string>
#include "Classe.h"
#include "Matiere.h"
#include "Professeur.h"
using namespace std;

class Enseignement {
private:
    Classe classe;
    Matiere matiere;
    int volumeHoraire;
    float coefficient;
    Professeur professeur;
    string annee;

public:
    Enseignement();
    Enseignement(Classe c, Matiere m, int vh, float coef, Professeur p, string an);

    Classe getClasse() const;
    Matiere getMatiere() const;
    int getVolumeHoraire() const;
    float getCoefficient() const;
    Professeur getProfesseur() const;
    string getAnnee() const;

    void setClasse(Classe);
    void setMatiere(Matiere);
    void setVolumeHoraire(int);
    void setCoefficient(float);
    void setProf(Professeur);
    void setAnnee(string);
};

#endif
