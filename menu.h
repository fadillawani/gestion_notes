#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "EtudiantService.h"
#include "MatiereService.h"
#include "ModuleService.h"
#include "EnseignementService.h"
#include "ProfesseurService.h"
#include "EvaluationService.h"
#include "ClasseService.h"
#include "View.h"
class Menu
{
private:
    EtudiantService etudiantS;
    MatiereService matiereS;
    ModuleService moduleS;
    EnseignementService enseignementS;
    ProfesseurService professeurS;
    EvaluationService evaluationS;
    ClasseService classeS;
    View view;

public:
    Menu();
    Menu(EtudiantService);
    int validChoice(int maxOpts);
    void invalidChoice(int menu);
    void applyChoiceMenuPrincipal(int c);
    void applyChoiceMenuEtudiants(int c);
    void applyChoiceMenuProfs(int c);
    void applyChoiceMenuMatieres(int c);
    void applyChoiceMenuModules(int c);
    void applyChoiceMenuClasses(int c);
    void applyChoiceMenuEnseignements(int c);
    void applyChoiceMenuEvaluations(int c);
    void menuPrincipal();
    void menuEtudiants();
    void menuProfs();
    void menuMatieres();
    void menuModules();
    void menuClasses();
    void menuEnseignements();
    void menuEvaluations();
};

#endif // MENU_H_INCLUDED
