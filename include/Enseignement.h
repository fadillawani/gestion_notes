#ifndef ENSEIGNEMENT_H
#define ENSEIGNEMENT_H

#include <string>
#include "Classe.h"
#include "Matiere.h"
#include "Professeur.h"

class Enseignement {
private:
    Classe classe;
    Matiere matiere;
    int volumeHoraire;
    float coefficient;
    Professeur professeur;
    std::string annee;

public:
    Enseignement();
    Enseignement(Classe c, Matiere m, int vh, float coef, Professeur p, std::string an);

    Classe getClasse() const;
    Matiere getMatiere() const;
    int getVolumeHoraire() const;
    float getCoefficient() const;
    Professeur getProfesseur() const;
    std::string getAnnee() const;
};

#endif
