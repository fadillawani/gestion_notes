#ifndef CLASSESERVICE_H_INCLUDED
#define CLASSESERVICE_H_INCLUDED

#include "Classe.h"
#include "Evaluation.h"
#include "Matiere.h"

#include <string>
using namespace std;

#define MAX_CLASSES 100

class ClasseService {
private:
    Classe classes[MAX_CLASSES];
    int nbClasses;

public:
    ClasseService(); // Constructeur pour charger les donn�es

    int getNbClasses();
    void afficheClasses();

    void setNbClasses();

    // Ajouter un nouvel �tudiant
    bool ajouterClasse(Classe& cls);
    void addClasseDansFichier(Classe cls);

    // Modifier les informations d�un �tudiant
    bool modifierClasse(const string& codeClasse, const Classe& clsModifie);

    // Supprimer un �tudiant
    bool supprimerClasse(const string& codeClasse);

    // Rechercher un �tudiant par son code
    Classe* searchClasseById(const string& idClasse);

    // Lister les �tudiants ayant particip� � au moins 2 �valuations dans une ann�e donn�e
    void listerClassesAvecMinEvaluations(int minEvaluations, const string& annee, Classe resultats[], int& nbResultats);

    // Lister les �tudiants d�une classe avec leur moyenne (rang � faire dans le .cpp)
    void listerClassesAvecMoyennesEtRang(const string& nomClasse, const string& annee, Classe resultats[], float moyennes[], int& nbResultats);
    void chargerClassesDepuisFichier();       // Lecture depuis fichier
    void sauvegarderClassesDansFichier();     // Sauvegarde dans fichier

private:


    float calculerMoyenneClasse(Classe& cls, const string& annee);
};

#endif // CLASSESERVICE_H_INCLUDED
