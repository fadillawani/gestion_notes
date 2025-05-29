#include "EvaluationService.h"
#include "EvaluationGenerale.h"
#include "Evaluation.h"
#include "Module.h"
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
EvaluationService::EvaluationService()
{
}

EvaluationService::EvaluationService(MatiereService matS, EnseignementService ensS, ModuleService modS)
{
    matiereService = matS;
    enseignementService = ensS;
    moduleService = modS;
}

void EvaluationService::afficheEvaluations()
{
    for (int i = 0; i < nbEvaluations; ++i)
    {
        cout << evaluations[i].toString() << endl;
    }
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
    ifstream fichier("BD/evaluationsGenerales.txt");
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
        eval.setMatiere(*matiereService.searchMatiereById(matiereId));
        eval.setDate(date);
        eval.setPeriode(periode);
        eval.setType(type);
        eval.setAnnee(annee);

        evaluationsGenerales[nbEvaluationsGenerales++] = eval;
    }

    fichier.close();
}

void EvaluationService::listerToutesLesEvaluationsGeneralesDeAnnee(string annee)
{
    chargerEvaluationsGeneralesDepuisFichier();

    trierEvaluationsGeneralesByAnnee(annee);
    for (int i = 0; i < nbEvaluationsGenerales; i++)
    {
        cout << evaluationsGenerales[i].toString() << endl;
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

void EvaluationService::trierEvaluationsGeneralesByAnnee(string annee)
{
    int nbNewEvals = 0;
    EvaluationGenerale evalsGen[nbEvaluations];
    for (int i = 0; i < nbEvaluations; ++i)
    {
        if (evaluations[i].getAnnee() == annee)
        {
            evalsGen[i] = evaluationsGenerales[i];
            nbNewEvals++;
        }
    }
    nbEvaluations = nbNewEvals;
    for (int i = 0; i < nbEvaluations; i++)
    {
        evaluationsGenerales[i] = evalsGen[i];
    }
}

void EvaluationService::chargerEvaluationsOfEtudiant(Etudiant etu, string periode)
{
    ifstream fichier("BD/etudiants/" + etu.getCode() + "/evals.txt");
    nbEvaluationsGenerales = 0;

    string id, etuId, matiereId, date, per, type, note, annee;
    while (getline(fichier, id, ';') &&
           getline(fichier, etuId, ';') &&
           getline(fichier, matiereId, ';') &&
           getline(fichier, date, ';') &&
           getline(fichier, per, ';') &&
           getline(fichier, type, ';') &&
           getline(fichier, note, ';') &&
           getline(fichier, annee, '\n'))
    {
        Evaluation eval;
        eval.setId(id);
        eval.setEtudiant(etu);
        eval.setMatiere(*matiereService.searchMatiereById(matiereId));
        eval.setDate(date);
        eval.setPeriode(per);
        eval.setType(type);
        eval.setNote(stod(note));
        eval.setAnnee(annee);

        evaluations[nbEvaluations++] = eval;
    }

    fichier.close();
}

void EvaluationService::trierEvaluationsEtudiantByPeriode(string periode)
{
    int nbNewEvals = 0;
    Evaluation evals[nbEvaluations];
    for (int i = 0; i < nbEvaluations; ++i)
    {
        if (evaluations[i].getPeriode() == periode)
        {
            evals[nbNewEvals] = evaluations[i];
            nbNewEvals++;
        }
    }
    nbEvaluations = nbNewEvals;
    for(int i = 0; i < nbEvaluations; i++)
    {
        evaluations[i] = evals[i];
    }
    //evaluations = evals;
    
}

void EvaluationService::listerEvaluationsEtudiantPeriode(Etudiant etu, string periode)
{
    chargerEvaluationsOfEtudiant(etu, periode);

    trierEvaluationsEtudiantByPeriode(periode);
    for (int i = 0; i < nbEvaluations; i++)
    {
        cout << evaluations[i].toString() << endl;
    }
}

double EvaluationService::moyenneEtudiantPeriode(Etudiant etu, string periode)
{
    chargerEvaluationsOfEtudiant(etu, periode);
    trierEvaluationsEtudiantByPeriode(periode);
    double sumCoef = 0;
    double sumNotexCoef = 0;
    for (int i = 0; i < nbEvaluations; i++)
    {
        Evaluation eval = evaluations[i];
        string modId = eval.getMatiere().getId();
        Module moduleRelatif = *moduleService.searchModuleByIdMatiere(modId);
        double coefMatiere = moduleRelatif.getCoefficient();
        double note = evaluations[i].getNote();
        sumCoef += coefMatiere;
        sumNotexCoef += note * coefMatiere;
    }
    return sumNotexCoef / sumCoef;
}

void listerEvaluationsGeneralesParAnnee(const std::string &annee);
