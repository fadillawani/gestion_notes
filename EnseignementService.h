#ifndef ENSEIGNEMENTSERVICE_H_INCLUDED
#define ENSEIGNEMENTSERVICE_H_INCLUDED

#include <string>
#include "ClasseService.h"
#include "MatiereService.h"
#include "ProfesseurService.h"
#include "Enseignement.h" // Doit contenir : classe, mati�re, professeur, ann�e, volumeHoraire, coefficient

#define MAX_ENSEIGNEMENTS 100

class EnseignementService
{
private:
    int nbEnseignements;
    ClasseService classeService;
    MatiereService matiereService;
    ProfesseurService professeurService;

public:
    Enseignement enseignements[MAX_ENSEIGNEMENTS];
    EnseignementService(); // Charge les donn�es au d�marrage
    EnseignementService(ClasseService, MatiereService, ProfesseurService);
    void afficheEnseignements();

    int getNbEnseignements();
    void setNbEnseignements(int);

    Enseignement *searchEnseignementById(string &idEnseignement);

    // Associer un professeur � une mati�re pour une classe et une ann�e acad�mique
    bool ajouterEnseignement(const Enseignement &e);

    // Afficher le corps professoral d�une classe pour une ann�e donn�e
    void afficherCorpsProfessoral(const std::string &nomClasse, const std::string &annee);

    // Optionnel : afficher tous les enseignements (utile pour d�bogage ou administration)
    void listerTousLesEnseignements();
    void listerTousLesEnseignementsDeClasse(string idClasse, string annee);

    void chargerEnseignementsDepuisFichierDeClasseEtAnnee(string idClasse, string annee);
    

private:
    void chargerEnseignementsDepuisFichier();
    void sauvegarderEnseignementsDansFichier();
};

#endif // ENSEIGNEMENTSERVICE_H_INCLUDED
