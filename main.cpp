#include <iostream>
#include "EtudiantService.h"
#include "EnseignementService.h"
#include "ClasseService.h"
#include "Classe.h"
using namespace std;

int main()
{
    ClasseService clsS = ClasseService();
    MatiereService matS = MatiereService();
    ProfesseurService profS = ProfesseurService();
    EtudiantService es = EtudiantService();
    EnseignementService ensS = EnseignementService(clsS, matS, profS);

    ensS.listerTousLesEnseignementsDeClasse("c1", "2024-2025");
    cout << endl;

    profS.listerToutesLesProfesseursDeClasseEtAnnee(ensS.enseignements, ensS.getNbEnseignements(),"c1", "2024-2025");
    //es.afficheEtudiants();
    //es.listerEtudiantsAvecMinEvaluations();
    /*ClasseService clsS = ClasseService();
    clsS.addClasseDansFichier(Classe());
    es.sauvegarderEtudiantsDansFichier();*/
    /*es.chargerEtudiantsDepuisFichier();
    cout << es.getNbEtudiants() << endl;
    es.afficheEtudiants();
    cout << "Hello world!" << endl;*/
    return 0;
}
