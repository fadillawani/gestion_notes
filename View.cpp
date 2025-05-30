#include "View.h"
#include "Etudiant.h"
#include "Professeur.h"
#include "Evaluation.h"
#include "Matiere.h"
#include <iostream>
using namespace std;
View::View(){}

void View::appuyerPourContinuer()
{
    string a;
    cout << endl << "Ecrire un mot et valider pour continuer..." << endl;
    cin >> a;
}

Etudiant View::saisieEtudiant()
{
    string code, nom, prenom, dateNaiss, lieuNaiss, adresse, classeId;
    Classe *classe = nullptr;

    cout << "Code étudiant: ";
    cin >> code;
    cout << "Nom: ";
    cin >> nom;
    cout << "Prénom: ";
    cin >> prenom;
    cout << "Date de naissance (jj/mm/aaaa): ";
    cin >> dateNaiss;
    cout << "Lieu de naissance: ";
    cin >> lieuNaiss;
    cout << "Adresse: ";
    cin >> adresse;

    do
    {
        cout << "ID de la classe: ";
        cin >> classeId;
        classe = classeS.searchClasseById(classeId);
        if (classe == nullptr)
        {
            cout << "Classe introuvable. Veuillez réessayer.\n";
        }
    } while (classe == nullptr);

    return Etudiant(code, nom, prenom, dateNaiss, lieuNaiss, adresse, *classe);
}

Professeur View::saisieProfesseur()
{
    string code, nom, prenom, spec;

    cout << "Code professeur: ";
    cin >> code;
    cout << "Nom: ";
    cin >> nom;
    cout << "Prénom: ";
    cin >> prenom;
    cout << "Specialité: ";
    cin >> spec;

    return Professeur(code, nom, prenom, spec);
}

Matiere View::saisieMatiere()
{
    string code, nom;

    cout << "Code matiere: ";
    cin >> code;
    cout << "Libelle: ";
    cin >> nom;

    return Matiere(code, nom);
}

EvaluationGenerale View::saisieEvaluationGenerale()
{
    string id, idMat, date, periode, type, annee;
    Matiere *matiere = nullptr;

    // Saisie des données
    cout << "Code de l'évaluation : ";
    cin >> id;

    do
    {
        cout << "ID de la matière : ";
        cin >> idMat;
        matiere = matS.searchMatiereById(idMat);
        if (matiere == nullptr)
        {
            cout << "Matière introuvable. Veuillez réessayer.\n";
        }
    } while (matiere == nullptr);

    cout << "Date de l'évaluation (jj/mm/aaaa) : ";
    cin >> date;

    do
    {
        cout << "Période (semestre1 ou semestre2) : ";
        cin >> periode;
    } while (periode != "semestre1" && periode != "semestre2");

    do
    {
        cout << "Type d'évaluation (examen ou devoir) : ";
        cin >> type;
    } while (type != "examen" && type != "devoir");

    cout << "Année académique (ex: 2024-2025) : ";
    cin >> annee;

    // Création de l'objet EvaluationGenerale
    return EvaluationGenerale(id, *matiere, date, periode, type, annee);
}

Classe View::saisieClasse()
{
    string code, nom, niveau;

    cout << "Code classe: ";
    cin >> code;
    cout << "Libelle: ";
    cin >> nom;
    cout << "Niveau: ";
    cin >> nom;

    return Classe(code, nom, niveau);
}

Module View::saisieModule()
{
    string id;
    cout << "ID du module : ";
    cin >> id;

    string matiereId, classeId;
    int duree;
    double coefficient;

    Matiere *matiere = nullptr;
    Classe *classe = nullptr;

    // Recherche de la matière
    do
    {
        cout << "ID de la matière : ";
        cin >> matiereId;
        matiere = matS.searchMatiereById(matiereId);
        if (matiere == nullptr)
        {
            cout << "Matière introuvable. Veuillez réessayer.\n";
        }
    } while (matiere == nullptr);

    // Recherche de la classe
    do
    {
        cout << "ID de la classe : ";
        cin >> classeId;
        classe = classeS.searchClasseById(classeId);
        if (classe == nullptr)
        {
            cout << "Classe introuvable. Veuillez réessayer.\n";
        }
    } while (classe == nullptr);

    // Saisie des autres données
    cout << "Durée (en heures) : ";
    cin >> duree;

    cout << "Coefficient : ";
    cin >> coefficient;

    // Création du module avec les données
    return Module(id, *matiere, *classe, duree, coefficient);
}

Enseignement View::saisieEnseignement()
{
    string code, classeId, matId, profId, annee;
    int volumeHoraire;
    double coefficient;

    Classe *classe = nullptr;
    Matiere *matiere = nullptr;
    Professeur *professeur = nullptr;

    cout << "Code enseignement: ";
    cin >> code;

    do
    {
        cout << "ID de la classe: ";
        cin >> classeId;
        classe = classeS.searchClasseById(classeId);
        if (classe == nullptr)
        {
            cout << "Classe introuvable. Veuillez réessayer.\n";
        }
    } while (classe == nullptr);

    do
    {
        cout << "ID de la matière: ";
        cin >> matId;
        matiere = matS.searchMatiereById(matId);
        if (matiere == nullptr)
        {
            cout << "Matière introuvable. Veuillez réessayer.\n";
        }
    } while (matiere == nullptr);

    do
    {
        cout << "ID du professeur: ";
        cin >> profId;
        professeur = profS.searchProfesseurById(profId);
        if (professeur == nullptr)
        {
            cout << "Professeur introuvable. Veuillez réessayer.\n";
        }
    } while (professeur == nullptr);

    cout << "Année scolaire (exemple: 2024): ";
    cin >> annee;

    cout << "Volume horaire: ";
    cin >> volumeHoraire;

    cout << "Coefficient: ";
    cin >> coefficient;

    return Enseignement(code, *classe, *matiere, volumeHoraire, coefficient, *professeur, annee);
}
