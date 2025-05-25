#ifndef ENSEIGNEMENTSERVICE_H_INCLUDED
#define ENSEIGNEMENTSERVICE_H_INCLUDED

#include <string>
#include "Enseignement.h" // Doit contenir : classe, matière, professeur, année, volumeHoraire, coefficient

#define MAX_ENSEIGNEMENTS 100

class EnseignementService {
private:
    Enseignement enseignements[MAX_ENSEIGNEMENTS];
    int nbEnseignements;

public:
    EnseignementService(); // Charge les données au démarrage

    // Associer un professeur à une matière pour une classe et une année académique
    bool ajouterEnseignement(const Enseignement& e);

    // Afficher le corps professoral d’une classe pour une année donnée
    void afficherCorpsProfessoral(const std::string& nomClasse, const std::string& annee);

    // Optionnel : afficher tous les enseignements (utile pour débogage ou administration)
    void listerTousLesEnseignements();

private:
    void chargerEnseignementsDepuisFichier();
    void sauvegarderEnseignementsDansFichier();
};

#endif // ENSEIGNEMENTSERVICE_H_INCLUDED
