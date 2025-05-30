#ifndef MATIERESERVICE_H_INCLUDED
#define MATIERESERVICE_H_INCLUDED

#include <string>
#include "Matiere.h"

#define MAX_MATIERES 100

class MatiereService
{
private:
    Matiere matieres[MAX_MATIERES];
    int nbMatieres;

public:
    MatiereService();

    void addMatiereDansFichier(Matiere);
    bool ajouterMatiere(const Matiere &matiere);
    bool modifierMatiere(const std::string &idMatiere, const Matiere &nouvelleMatiere);
    bool supprimerMatiere(const std::string &idMatiere);
    Matiere *searchMatiereById(string &idMatiere);
    void listerToutesLesMatieres();

    void chargerMatieresDepuisFichier();
    void sauvegarderMatieresDansFichier();
};

#endif // MATIERESERVICE_H_INCLUDED
