#ifndef EVALUATIONSERVICE_H_INCLUDED
#define EVALUATIONSERVICE_H_INCLUDED

#include <string>
#include "Evaluation.h" // Doit contenir Etudiant, Matiere, note, date, type, période

#define MAX_EVALUATIONS 500

class EvaluationService {
private:
    Evaluation evaluations[MAX_EVALUATIONS];
    int nbEvaluations;

public:
    EvaluationService(); // Charge les évaluations depuis le fichier au démarrage

    // Ajouter une évaluation
    bool ajouterEvaluation(const Evaluation& eval);

    // Modifier une évaluation (recherche par code étudiant + matière + date)
    bool modifierEvaluation(const std::string& codeEtudiant, const std::string& idMatiere, const std::string& dateEval, const Evaluation& nouvelleEval);

    // Supprimer une évaluation
    bool supprimerEvaluation(const std::string& codeEtudiant, const std::string& idMatiere, const std::string& dateEval);

    // Lister toutes les évaluations d'une année académique
    void listerEvaluationsParAnnee(const std::string& annee);

    // Voir toutes les notes d’un étudiant pour une période donnée (SEMESTRE 1 ou 2)
    void listerNotesEtudiantParPeriode(const std::string& codeEtudiant, const std::string& periode);

private:
    void chargerEvaluationsDepuisFichier();
    void sauvegarderEvaluationsDansFichier();
};

#endif // EVALUATIONSERVICE_H_INCLUDED
