#include <iostream>
#include "EtudiantService.h"
#include "EnseignementService.h"
#include "EvaluationService.h"
#include "ClasseService.h"
#include "Classe.h"
using namespace std;

int main()
{
    /*ClasseService clsS = ClasseService();
    MatiereService matS = MatiereService();
    ProfesseurService profS = ProfesseurService();
    EnseignementService ensS = EnseignementService(clsS, matS, profS);*/
    EvaluationService evalS = EvaluationService();

    /*ensS.listerTousLesEnseignementsDeClasse("c1", "2024-2025");
    cout << endl;

    profS.listerToutesLesProfesseursDeClasseEtAnnee(ensS.enseignements, ensS.getNbEnseignements(),"c1", "2024-2025");*/
    //evalS.listerToutesLesEvaluationsGeneralesDeAnnee("2024-2025");
    // es.afficheEtudiants();
    // es.listerEtudiantsAvecMinEvaluations();
    /*ClasseService clsS = ClasseService();
    clsS.addClasseDansFichier(Classe());
    es.sauvegarderEtudiantsDansFichier();*/
    EtudiantService es = EtudiantService();
    es.chargerEtudiantsDepuisFichier();
    es.afficheEtudiants();

    //evalS.chargerEvaluationsOfEtudiant(*es.searchEtudiantByCode("co3"), "semestre2");
    evalS.listerEvaluationsEtudiantPeriode(*es.searchEtudiantByCode("co3"), "semestre2");
    //evalS.afficheEvaluations();
    /*cout << es.getNbEtudiants() << endl;
    cout << "Hello world!" << endl;*/
    return 0;
}
