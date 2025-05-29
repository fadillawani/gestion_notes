#ifndef EVALUATIONSERVICE_H_INCLUDED
#define EVALUATIONSERVICE_H_INCLUDED

#include <string>
#include "MatiereService.h"
#include "EnseignementService.h"
#include "ModuleService.h"
#include "Evaluation.h"
#include "EvaluationGenerale.h" // Doit contenir Etudiant, Matiere, note, date, type, p�riode

#define MAX_EVALUATIONS_GENERALES 500

class EvaluationService
{
private:
    EvaluationGenerale evaluationsGenerales[MAX_EVALUATIONS_GENERALES];
    int nbEvaluationsGenerales;

    Evaluation evaluations[MAX_EVALUATIONS_GENERALES];
    int nbEvaluations;

    MatiereService matiereService;
    EnseignementService enseignementService;
    ModuleService moduleService;

public:
    EvaluationService();               // Charge les �valuations depuis le fichier au d�marrage
    EvaluationService(MatiereService, EnseignementService, ModuleService); // Charge les �valuations depuis le fichier au d�marrage

    // Ajouter une �valuation
    bool ajouterEvaluationGenerale(const EvaluationGenerale &eval);

    // Modifier une �valuation (recherche par code �tudiant + mati�re + date)
    bool modifierEvaluationGenerale(const std::string &codeEtudiant, const std::string &idMatiere, const std::string &dateEval, const EvaluationGenerale &nouvelleEval);

    // Supprimer une �valuation
    bool supprimerEvaluationGenerale(const std::string &codeEtudiant, const std::string &idMatiere, const std::string &dateEval);

    EvaluationGenerale *searchEvaluationGeneraleById(string &idEvaluationGenerale);

    // Lister toutes les �valuations d'une ann�e acad�mique
    void listeEvaluationsGeneralesParAnnee(const std::string &annee);

    // Voir toutes les notes d�un �tudiant pour une p�riode donn�e (SEMESTRE 1 ou 2)
    void listerNotesEtudiantParPeriode(const std::string &codeEtudiant, const std::string &periode);

    void afficheEvaluations();

    void listerToutesLesEvaluationsGeneralesDeAnnee(string annee);
    void trierEvaluationsGeneralesByAnnee(string annee);
    void chargerEvaluationsGeneralesDepuisFichier();
    void sauvegarderEvaluationsGeneralesDansFichier();

    void listerEvaluationsEtudiantPeriode(Etudiant, string);
    void chargerEvaluationsOfEtudiant(Etudiant, string);
    void trierEvaluationsEtudiantByPeriode(string);

    double moyenneEtudiantPeriode(Etudiant etu, string periode);

private:
};

#endif // EVALUATIONSERVICE_H_INCLUDED
