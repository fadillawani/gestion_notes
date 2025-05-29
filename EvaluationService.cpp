#include "EvaluationService.h"
#include "EvaluationGenerale.h"
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
EvaluationService::EvaluationService()
{
}

EvaluationService::EvaluationService(MatiereService matS)
{
    matiereService = matS;
}

EvaluationGenerale *EvaluationService::searchEvaluationGeneraleById(string &idEvaluationGenerale)
{
    chargerEvaluationsGeneralesDepuisFichier();
    for (int i = 0; i < nbEvaluationsGenerales; ++i)
    {
        if (evaluationsGenerales[i].getId() == idEvaluationGenerale)
        {
            return &evaluationsGenerales[i];
        }
    }
    return nullptr;
}

void EvaluationService::chargerEvaluationsGeneralesDepuisFichier()
{
    ifstream fichier("evaluationsGenerales.txt");
    nbEvaluationsGenerales = 0;

    string id, matiereId, date, periode, type, annee;
    while (getline(fichier, id, ';') &&
           getline(fichier, matiereId, ';') &&
           getline(fichier, date, ';') &&
           getline(fichier, periode, ';') &&
           getline(fichier, type, ';') &&
           getline(fichier, annee, '\n'))
    {
        EvaluationGenerale eval;
        eval.setId(id);
        //eval.setMatiere(*matiereService.searchMatiereById(matiereId));
        eval.setDate(date);
        eval.setPeriode(periode);
        eval.setType(type);
        eval.setAnnee(annee);

        evaluationsGenerales[nbEvaluationsGenerales++] = eval;
        cout << "fyhnkl,j";
    }

    fichier.close();
}

void EvaluationService::listerToutesLesEvaluationsGeneralesDeAnnee(string annee)
{
    chargerEvaluationsGeneralesDepuisFichier();
    
    trierEvaluationsGeneralesByAnnee(evaluationsGenerales, nbEvaluationsGenerales, annee);
    for (int i = 0; i < nbEvaluationsGenerales; i++)
    {
        cout << evaluationsGenerales[i].toString();
    }
    /*for (string idProf : idProfsUniques)
    {
        EvaluationGenerale *prof = searchEvaluationGeneraleById(idProf);
        if (prof != nullptr)
        {
            cout << prof->toString() << endl;
        }
    }*/
}

void EvaluationService::trierEvaluationsGeneralesByAnnee(EvaluationGenerale evaluationsGenerales[], int nbEvaluations, string annee)
{
    
    EvaluationGenerale evalsGen[nbEvaluations];
    for (int i = 0; i < nbEvaluations; ++i)
    {
        evalsGen[i] = evaluationsGenerales[i];
    }
    evaluationsGenerales = evalsGen;
}

void listerEvaluationsGeneralesParAnnee(const std::string &annee);
