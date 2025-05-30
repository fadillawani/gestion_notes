#include "ProfesseurService.h"
#include "Professeur.h"
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
ProfesseurService::ProfesseurService()
{
}

void ProfesseurService::addProfesseurDansFichier(Professeur prof)
{
    ofstream fichier("BD/professeurs.txt", ios::app);
    fichier << prof.getId() << ";"
            << prof.getNom() << ";"
            << prof.getPrenom() << ";"
            << prof.getSpec() << endl;

    fichier.close();
}

Professeur *ProfesseurService::searchProfesseurById(string &idProfesseur)
{
    chargerProfesseursDepuisFichier();
    for (int i = 0; i < nbProfesseurs; ++i)
    {
        if (professeurs[i].getId() == idProfesseur)
        {
            return &professeurs[i];
        }
    }
    return nullptr;
}

void ProfesseurService::chargerProfesseursDepuisFichier()
{
    ifstream fichier("BD/professeurs.txt");
    nbProfesseurs = 0;

    string id, nom, prenom, spec;
    Professeur mat;
    while (getline(fichier, id, ';') &&
           getline(fichier, nom, ';') &&
           getline(fichier, prenom, ';') &&
           getline(fichier, spec, '\n'))
    {
        Professeur prof;
        prof.setId(id);
        prof.setNom(nom);
        prof.setPrenom(prenom);
        prof.setSpec(spec);

        professeurs[nbProfesseurs++] = prof;
    }

    fichier.close();
}

void ProfesseurService::listerToutesLesProfesseursDeClasseEtAnnee(Enseignement enseignements[], int nbEnseignements, string idClasse, string annee)
{
    chargerProfesseursDepuisFichier();
    trierEnseignementsEnSetIdProfs(enseignements, nbEnseignements);
    /*for(int i = 0; i < nbEnseignements; i++)
    {
        string idProf = enseignements[i].getProfesseur().getId();
        Professeur* prof;
        prof = searchProfesseurById(idProf);
        cout << prof->toString() << endl;
    }*/
    for ( string idProf : idProfsUniques) {
        Professeur* prof = searchProfesseurById(idProf);
        if (prof != nullptr) {
            cout << prof->toString() << endl;
        }
    }
}

void ProfesseurService::trierEnseignementsEnSetIdProfs(Enseignement enseignements[], int nbEnseignements)
{
    for (int i = 0; i < nbEnseignements; ++i) {
        idProfsUniques.insert(enseignements[i].getProfesseur().getId());  // insertion automatique sans doublons
    }
}
