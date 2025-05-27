#include "EtudiantService.h"
#include "Etudiant.h"
#include "Classe.h"
#include <fstream>
#include <iostream>
#include <map>
//#include <boost/algorithm/string.hpp>
#define MAX_PASSAGEEVAL 500
using namespace std;

EtudiantService::EtudiantService()
{
    nbEtudiants = 0;
    chargerEtudiantsDepuisFichier();
}

EtudiantService::EtudiantService(ClasseService clsService)
{
    nbEtudiants = 0;
    chargerEtudiantsDepuisFichier();
    classeService = clsService;
}

void EtudiantService::afficheEtudiants()
{
    chargerEtudiantsDepuisFichier();
    for (int i = 0; i < nbEtudiants; ++i) {
        cout << etudiants[i].toString() << endl;
    }
}
int EtudiantService::getNbEtudiants()
{
    return nbEtudiants;
}

bool EtudiantService::ajouterEtudiant(Etudiant &etu)
{
    if (nbEtudiants >= MAX_ETUDIANTS)
    {
        cout << "Nombre maximal d'�tudiants atteint." << endl;
        return false;
    }

    if (searchEtudiantByCode(etu.getCode()) == nullptr)
    {
        etudiants[nbEtudiants++] = etu;
        sauvegarderEtudiantsDansFichier();
        cout << "�tudiant ajout� avec succ�s." << endl;
        return true;
    }
    else
    {
        cout << "Un �tudiant avec ce code existe d�j�." << endl;
        return false;
    }

    /*// V�rifier que le code n'existe pas d�j�
    for (int i = 0; i < nbEtudiants; ++i) {
        if (etudiants[i].getCode() == etu.getCode()) {
        }
    }*/
}

Etudiant *EtudiantService::searchEtudiantByCode(const string &codeEtudiant)
{
    for (int i = 0; i < nbEtudiants; ++i)
    {
        if (etudiants[i].getCode() == codeEtudiant)
        {
            return &etudiants[i]; // Retourne un pointeur vers l'étudiant trouvé
        }
    }
    return nullptr; // Aucun étudiant trouvé avec ce code
}

void EtudiantService::addEtudiantDansFichier(Etudiant e)
{
    ofstream fichier("etudiants.txt", ios::app);
    fichier << e.getCode() << ";"
            << e.getNom() << ";"
            << e.getPrenom() << ";"
            << e.getDateNaissance() << ";"
            << e.getLieuNaissance() << ";"
            << e.getAdresse() << ";"
            << e.getClasse().getId() << endl;

    fichier.close();
}

void EtudiantService::sauvegarderEtudiantsDansFichier()
{
    /*ofstream fichier("etudiants.txt");
    for (int i = 0; i < nbEtudiants; ++i)
    {
        fichier << etudiants[i].getCode() << ";"
                << etudiants[i].getNom() << ";"
                << etudiants[i].getPrenom() << ";"
                << etudiants[i].getDateNaissance() << ";"
                << etudiants[i].getLieuNaissance() << ";"
                << etudiants[i].getAdresse() << endl;
    }*/
    ofstream fichier("etudiants.txt");
    Classe cls = Classe("c1", "GLRS-A", "L2");
    Etudiant e = Etudiant("co3", "Sadjo", "Ousman", "26/10/2007", "Maroua", "Colobane", cls);
        fichier << e.getCode() << ";"
                << e.getNom() << ";"
                << e.getPrenom() << ";"
                << e.getDateNaissance() << ";"
                << e.getLieuNaissance() << ";"
                << e.getAdresse() << ";"
                << e.getClasse().getId() << endl;

    fichier.close();
}

void EtudiantService::chargerEtudiantsDepuisFichier()
{
    ifstream fichier("etudiants.txt");
    nbEtudiants = 0;

    string code, nom, prenom, dateNaiss, lieuNaiss, adresse, clsId;
    Classe cls;
    while (getline(fichier, code, ';') &&
           getline(fichier, nom, ';') &&
           getline(fichier, prenom, ';') &&
           getline(fichier, dateNaiss, ';') &&
           getline(fichier, lieuNaiss, ';') &&
           getline(fichier, adresse, ';') &&
           getline(fichier, clsId, '\n'))
    {
        Etudiant etu;
        etu.setCode(code);
        etu.setNom(nom);
        etu.setPrenom(prenom);
        etu.setDateNaissance(dateNaiss);
        etu.setLieuNaissance(lieuNaiss);
        etu.setAdresse(adresse);
        /*Classe *cls = classeService.searchClasseById(clsId);
        etu.setClasse(*cls);*/

        etudiants[nbEtudiants++] = etu;
    }

    fichier.close();
}

void EtudiantService::chargerEtudiantsDesClassesDepuisFichier(string idClasses[], int& nbClasses)
{
    ifstream fichier("etudiants.txt");
    nbEtudiants = 0;

    string code, nom, prenom, dateNaiss, lieuNaiss, adresse, clsId;
    Classe cls;
    while (getline(fichier, code, ';') &&
           getline(fichier, nom, ';') &&
           getline(fichier, prenom, ';') &&
           getline(fichier, dateNaiss, ';') &&
           getline(fichier, lieuNaiss, ';') &&
           getline(fichier, adresse, ';') &&
           getline(fichier, clsId, '\n'))
    {

        for(int i = 0; i < nbClasses; i++)
        {
            if(clsId == idClasses[i])
            {
                Etudiant etu;
                etu.setCode(code);
                etu.setNom(nom);
                etu.setPrenom(prenom);
                etu.setDateNaissance(dateNaiss);
                etu.setLieuNaissance(lieuNaiss);
                etu.setAdresse(adresse);
                /*Classe *cls = classeService.searchClasseById(clsId);
                etu.setClasse(*cls);*/

                etudiants[nbEtudiants++] = etu;
            }
        }

    }
    fichier.close();
}

void EtudiantService::chargerIdClassesPassageEvalDepuisFichier(string idClasses[], int& nbIdClasses)
{
    ifstream fichier("passageEvals.txt");
    int nbPassages = 0;

    string id, idClasse, idEval;
    while (getline(fichier, id, ';') &&
           getline(fichier, idClasse, ';') &&
           getline(fichier, idEval))
    {

        idClasses[nbPassages++] = idClasse;
    }
    nbIdClasses = nbPassages;
    fichier.close();
}

void EtudiantService::classesAvec2EvalMinimum(string classes2evalMininum[], int& nbClasses)
{
    string idClasses[MAX_PASSAGEEVAL];
    int nbPassages = 0;
    chargerIdClassesPassageEvalDepuisFichier(idClasses, nbPassages);
    map<string, int> occurrences;

    // Comptage
    for (int i = 0; i < nbPassages; ++i) {
        occurrences[idClasses[i]]++;
    }

    cout << "Classes avec plus de 2 évluations :" << endl;
    for (const auto& paire : occurrences) {
        if (paire.second >= 2) {
            cout << "- " << paire.first << " : " << paire.second << " fois" << endl;
            classes2evalMininum[nbClasses++] = paire.first;
        }
    }
}

void EtudiantService::listerEtudiantsAvecMinEvaluations()
{

    string classes2evalMininum[100];
    int nbClasses2evalMininum = 0;
    classesAvec2EvalMinimum(classes2evalMininum, nbClasses2evalMininum);
    chargerEtudiantsDesClassesDepuisFichier(classes2evalMininum, nbClasses2evalMininum);
    for (int i = 0; i < 2; ++i) {
        cout << etudiants[i].toString() << endl;
    }
}
