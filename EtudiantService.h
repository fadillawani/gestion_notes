#ifndef ETUDIANTSERVICE_H_INCLUDED
#define ETUDIANTSERVICE_H_INCLUDED

#include "Etudiant.h"
#include "ClasseService.h"
#include "Evaluation.h"
#include "Matiere.h"

#include <string>
using namespace std;

#define MAX_ETUDIANTS 100

class EtudiantService {
private:
    Etudiant etudiants[MAX_ETUDIANTS];
    int nbEtudiants;
    ClasseService classeService;

public:
    EtudiantService();
    EtudiantService(ClasseService);

    int getNbEtudiants();
    void afficheEtudiants();

    void setNbEtudiants();

    // Ajouter un nouvel étudiant
    bool ajouterEtudiant(Etudiant& etu);


    // Modifier les informations d’un étudiant
    bool modifierEtudiant(const string& codeEtudiant, const Etudiant& etuModifie);

    // Supprimer un étudiant
    bool supprimerEtudiant(const string& codeEtudiant);

    // Rechercher un étudiant par son code
    Etudiant* searchEtudiantByCode(const string& codeEtudiant);

    // Lister les étudiants ayant participé à au moins 2 évaluations dans une année donnée
    void listerEtudiantsAvecMinEvaluations();
    void classesAvec2EvalMinimum(string classes2evalMininum[], int& nbClasses);
    void chargerIdClassesPassageEvalDepuisFichier(string idClasses[], int& nbIdClasses);
    void chargerEtudiantsDesClassesDepuisFichier(string idClasses[], int& nbClasses);
    void occurencesIdClasse(string idClasses[], int nbIdClasses);

    // Lister les étudiants d’une classe avec leur moyenne (rang à faire dans le .cpp)
    void listerEtudiantsAvecMoyennesEtRang(const string& nomClasse, const string& annee, Etudiant resultats[], float moyennes[], int& nbResultats);
    void chargerEtudiantsDepuisFichier();       // Lecture depuis fichier
    void addEtudiantDansFichier(Etudiant e);
    void sauvegarderEtudiantsDansFichier(); // Sauvegarde dans fichier

    

private:


    float calculerMoyenneEtudiant(Etudiant& etu, const string& annee);
};

#endif // ETUDIANTSERVICE_H_INCLUDED
