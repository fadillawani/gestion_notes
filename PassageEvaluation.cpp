#include "PassageEvaluation.h"
#include "Classe.h"
#include "Evaluation.h"
using namespace std;
#include <string>

PassageEvaluation::PassageEvaluation()
{

}

PassageEvaluation::PassageEvaluation(string id, Classe cls, EvaluationGenerale eval)
{
    this->id = id;
    classe = cls;
    evaluation = eval;
}

string PassageEvaluation::getId()
{
    return id;
}

Classe PassageEvaluation::getClasse()
{
    return classe;
}

EvaluationGenerale PassageEvaluation::getEvaluation()
{
    return evaluation;
}

void PassageEvaluation::setId(string id)
{
    this->id = id;
}

void PassageEvaluation::setClasse(Classe cls)
{
    classe = cls;
}

void PassageEvaluation::setEvaluation(EvaluationGenerale eval)
{
    evaluation = eval;
}

/*void EvaluationService::chargerPassageEvaluationsDeClasseDepuisFichier(string idClasse)
{
    ifstream fichier("passageEvals.txt");
    nbEvaluationsGenerales = 0;

    string id, clsId, evalId;
    EvaluationGenerale mat;
    while (getline(fichier, id, ';') &&
           getline(fichier, clsId, ';') &&
           getline(fichier, evalId, '\n'))
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
}*/