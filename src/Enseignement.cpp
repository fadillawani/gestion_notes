#include "Enseignement.h"

Enseignement::Enseignement(){}
Enseignement::Enseignement(Classe c, Matiere m, int vh, float coef, Professeur p, std::string an)
    : classe(c), matiere(m), volumeHoraire(vh), coefficient(coef), professeur(p), annee(an) {}

Classe Enseignement::getClasse() const {
    return classe;
}

Matiere Enseignement::getMatiere() const {
    return matiere;
}

int Enseignement::getVolumeHoraire() const {
    return volumeHoraire;
}

float Enseignement::getCoefficient() const {
    return coefficient;
}

Professeur Enseignement::getProfesseur() const {
    return professeur;
}

std::string Enseignement::getAnnee() const {
    return annee;
}
