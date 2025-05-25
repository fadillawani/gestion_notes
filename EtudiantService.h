#ifndef CLIENTSERVICE_H_INCLUDED
#define CLIENTSERVICE_H_INCLUDED

#include "Etudiant.h"
#include "Evaluation.h"
#include "Matiere.h"

#include <string>
using namespace std;

#define MAX_ETUDIANTS 100

class EtudiantService {
private:
    Etudiant etudiants[MAX_ETUDIANTS];
    int nbEtudiants;

public:
    EtudiantService(); // Constructeur pour charger les données

    // Ajouter un nouvel étudiant
    bool ajouterEtudiant(Etudiant& etu);

    // Modifier les informations d’un étudiant
    bool modifierEtudiant(const string& codeEtudiant, const Etudiant& etuModifie);

    // Supprimer un étudiant
    bool supprimerEtudiant(const string& codeEtudiant);

    // Rechercher un étudiant par son code
    Etudiant* searchEtudiantByCode(const string& codeEtudiant);

    // Lister les étudiants ayant participé à au moins 2 évaluations dans une année donnée
    void listerEtudiantsAvecMinEvaluations(int minEvaluations, const string& annee, Etudiant resultats[], int& nbResultats);

    // Lister les étudiants d’une classe avec leur moyenne (rang à faire dans le .cpp)
    void listerEtudiantsAvecMoyennesEtRang(const string& nomClasse, const string& annee, Etudiant resultats[], float moyennes[], int& nbResultats);

private:
    void chargerEtudiantsDepuisFichier();       // Lecture depuis fichier
    void sauvegarderEtudiantsDansFichier();     // Sauvegarde dans fichier

    float calculerMoyenneEtudiant(Etudiant& etu, const string& annee);
};

#endif // CLIENTSERVICE_H_INCLUDED
