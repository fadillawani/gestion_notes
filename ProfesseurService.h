#ifndef PROFESSEURSERVICE_H_INCLUDED
#define PROFESSEURSERVICE_H_INCLUDED

#include <string>
#include <set>
#include "Professeur.h"
#include "Enseignement.h"

#define MAX_PROFESSEURS 100

class ProfesseurService
{
private:
    Professeur professeurs[MAX_PROFESSEURS];
    int nbProfesseurs;
    set<string> idProfsUniques;

public:
    ProfesseurService();

    bool ajouterProfesseur(const Professeur &professeur);
    bool modifierProfesseur(const std::string &idProfesseur, const Professeur &nouvelleProfesseur);
    bool supprimerProfesseur(const std::string &idProfesseur);
    Professeur *searchProfesseurById(string &idProfesseur);
    void listerToutesLesProfesseurs();
    void listerToutesLesProfesseursDeClasseEtAnnee(Enseignement enseignements[], int nbEnseignements, string idClasse, string annee);
    void trierEnseignementsEnSetIdProfs(Enseignement enseignements[], int);

    void chargerProfesseursDepuisFichier();
    void sauvegarderProfesseursDansFichier();
};

#endif // PROFESSEURSERVICE_H_INCLUDED
