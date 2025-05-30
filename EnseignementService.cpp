#include "EnseignementService.h"
#include "ClasseService.h"
#include "ProfesseurService.h"
#include "MatiereService.h"
#include <fstream>
#include <iostream>

EnseignementService::EnseignementService()
{
}

EnseignementService::EnseignementService(ClasseService clsS, MatiereService matS, ProfesseurService profS)
{
    classeService = clsS;
    matiereService = matS;
    professeurService = profS;
}

void EnseignementService::addEnseignementDansFichier(Enseignement ens)
{
    ofstream fichier("BD/enseignements.txt", ios::app);
    fichier << ens.getId() << ";"
            << ens.getClasse().getId() << ";"
            << ens.getMatiere().getId() << ";"
            << ens.getVolumeHoraire() << ";"
            << ens.getCoefficient() << ";"
            << ens.getProfesseur().getId() << ";"
            << ens.getAnnee() << endl;

    fichier.close();
}

int EnseignementService::getNbEnseignements()
{
    return nbEnseignements;
}

void EnseignementService::setNbEnseignements(int nb)
{
    nbEnseignements = nb;
}

void EnseignementService::afficheEnseignements()
{
    for (int i = 0; i < nbEnseignements; ++i)
    {
        cout << enseignements[i].toString() << endl;
    }
}

void EnseignementService::chargerEnseignementsDepuisFichier()
{
    ifstream fichier("BD/enseignements.txt");
    nbEnseignements = 0;

    string clsId, matiereId, vhStr, coefStr, idProf, annee;
    while (getline(fichier, clsId, ';') &&
           getline(fichier, matiereId, ';') &&
           getline(fichier, vhStr, ';') &&
           getline(fichier, coefStr, ';') &&
           getline(fichier, idProf, ';') &&
           getline(fichier, annee, '\n'))
    {
        Enseignement ens;
        ens.setClasse(*ClasseService().searchClasseById(clsId));
        ens.setMatiere(*MatiereService().searchMatiereById(matiereId));
        ens.setVolumeHoraire(stoi(vhStr));
        ens.setCoefficient(stod(coefStr));
        ens.setProf(*ProfesseurService().searchProfesseurById(idProf));
        ens.setAnnee(annee);

        enseignements[nbEnseignements++] = ens;
    }

    fichier.close();
}

void EnseignementService::chargerEnseignementsDepuisFichierDeClasseEtAnnee(string idClasse, string annee)
{
    ifstream fichier("BD/enseignements.txt");
    nbEnseignements = 0;

    string clsId, matiereId, vhStr, coefStr, idProf, ann;
    while (getline(fichier, clsId, ';') &&
           getline(fichier, matiereId, ';') &&
           getline(fichier, vhStr, ';') &&
           getline(fichier, coefStr, ';') &&
           getline(fichier, idProf, ';') &&
           getline(fichier, ann, '\n'))
    {
        if (idClasse == clsId)
        {
            Enseignement ens;

            ens.setClasse(*classeService.searchClasseById(clsId));
            ens.setMatiere(*matiereService.searchMatiereById(matiereId));
            ens.setVolumeHoraire(stoi(vhStr));
            ens.setCoefficient(stod(coefStr));
            ens.setProf(*professeurService.searchProfesseurById(idProf));
            ens.setAnnee(ann);

            enseignements[nbEnseignements++] = ens;
        }
    }
    fichier.close();
}

void EnseignementService::listerTousLesEnseignementsDeClasse(string idClasse, string annee)
{
    chargerEnseignementsDepuisFichierDeClasseEtAnnee(idClasse, annee);
    afficheEnseignements();
}
