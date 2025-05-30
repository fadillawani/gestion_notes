#include "MatiereService.h"
#include <fstream>
#include <iostream>
MatiereService::MatiereService()
{

}

void MatiereService::addMatiereDansFichier(Matiere mat)
{
    ofstream fichier("BD/matieres.txt", ios::app);
    fichier << mat.getId() << ";"
            << mat.getLibelle() << endl;

    fichier.close();
}

Matiere *MatiereService::searchMatiereById(string &idMatiere)
{
    chargerMatieresDepuisFichier();
    for (int i = 0; i < nbMatieres; ++i)
    {
        if (matieres[i].getId() == idMatiere)
        {
            return &matieres[i];
        }
    }
    return nullptr;
}

void MatiereService::chargerMatieresDepuisFichier()
{
    ifstream fichier("BD/matieres.txt");
    nbMatieres = 0;

    string id, libelle;
    Matiere mat;
    while (getline(fichier, id, ';') &&
           getline(fichier, libelle, '\n'))
    {
        Matiere mat;
        mat.setId(id);
        mat.setLibelle(libelle);

        matieres[nbMatieres++] = mat;
    }

    fichier.close();
}