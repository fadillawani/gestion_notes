#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "Etudiant.h"
#include "Professeur.h"
#include "Matiere.h"
#include "Enseignement.h"
#include "ClasseService.h"
#include "ProfesseurService.h"
#include "MatiereService.h"
#include "EvaluationService.h"
#include "Classe.h"
#include "Module.h"
using namespace std;
class View
{
private:
    /* data */

    ClasseService classeS;
    ProfesseurService profS;
    MatiereService matS;
public:
    View();
//    View(/* args */);
    void appuyerPourContinuer();
    Etudiant saisieEtudiant();
    Professeur saisieProfesseur();
    Matiere saisieMatiere();
    Enseignement saisieEnseignement();
    Evaluation saisieEvaluation();
    EvaluationGenerale saisieEvaluationGenerale();
    Classe saisieClasse();
    Module saisieModule();
};


#endif
