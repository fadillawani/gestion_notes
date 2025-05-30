#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "View.h"
#include "Etudiant.h"
#include "EtudiantService.h"
#include "EvaluationService.h"
using namespace std;

Menu::Menu() {}
Menu::Menu(EtudiantService etuS)
{
    etudiantS = etuS;
}

int Menu::validChoice(int maxOpts)
{
    int choice;
    cout << endl << "Faites votre choix entre 1 et " << maxOpts << ": ";
    cin >> choice;
    if (choice > maxOpts || choice < 1)
    {
        choice = 0;
    }
    return choice;
}

void Menu::invalidChoice(int menu)
{
    system("cls");
    cout << "CHOIX NON VALIDE";
    switch (menu)
    {
    case 1:
        menuPrincipal();
        break;
    case 2:
        menuEtudiants();
        break;
    case 3:
        menuProfs();
        break;
    case 4:
        menuMatieres();
        break;
    case 5:
        menuModules();
        break;
    case 6:
        menuClasses();
        break;

    case 7:
        menuEnseignements();
        break;

    case 8:
        menuEvaluations();
        break;
    }
}

void Menu::applyChoiceMenuPrincipal(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(1);
        break;
    case 1:
        menuEtudiants();
        break;
    case 2:
        menuProfs();
        break;
    case 3:
        menuMatieres();
        break;
    case 4:
        menuModules();
        break;
    case 5:
        menuClasses();
        break;
    case 6:
        menuEnseignements();
        break;
        case 7:
        menuEvaluations();
        break;
    case 8:
        exit(0);
        break;
    }
}

void Menu::applyChoiceMenuEtudiants(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(2);
        break;

    case 1:
    {
        Etudiant e;
        e = view.saisieEtudiant();
        etudiantS.addEtudiantDansFichier(e);
        view.appuyerPourContinuer();
        menuEtudiants();
        break;
    }

    case 2:
        etudiantS.listerEtudiantsAvecMinEvaluations();
        view.appuyerPourContinuer();
        menuEtudiants();
        break;

    case 3:
    {
        string id, per;

        cout << "Entrez le code de l'étudiant: ";
        cin >> id;

        Etudiant *ef = etudiantS.searchEtudiantByCode(id);

        if (ef == nullptr)
        {
            cout << "Étudiant introuvable." << endl;
        }
        else
        {
            cout << "Entrez la période: ";
            cin >> per;

             evaluationS.listerNotesEtudiantParPeriode(ef->getCode(), per);
        }
        view.appuyerPourContinuer();
        menuEtudiants();
        break;
    }

    case 4:
        menuPrincipal();
        break;
    }
}

void Menu::applyChoiceMenuProfs(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(3);
        break;

    case 1:
    {
        Professeur p = view.saisieProfesseur();
        professeurS.addProfesseurDansFichier(p);
        view.appuyerPourContinuer();
        menuProfs();
        break;
    }

    case 2:
    {
        string classeId, annee;
        Classe *classe = nullptr;

        cout << "Année: ";
        cin >> annee;

        do
        {
            cout << "ID de la classe: ";
            cin >> classeId;
            classe = classeS.searchClasseById(classeId);
            if (classe == nullptr)
            {
                cout << "Classe introuvable. Veuillez réessayer.\n";
            }
        } while (classe == nullptr);

        enseignementS.chargerEnseignementsDepuisFichierDeClasseEtAnnee(classeId, annee);
        professeurS.listerToutesLesProfesseursDeClasseEtAnnee(
            enseignementS.enseignements,
            enseignementS.getNbEnseignements(),
            classeId,
            annee);
        view.appuyerPourContinuer();
        menuProfs();
        break;
    }

    case 3:
        menuPrincipal();
        break;

    default:
        cout << "Choix invalide. Veuillez réessayer." << endl;
        break;
    }
}

void Menu::applyChoiceMenuMatieres(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(4);
        break;

    case 1:
    {
        Matiere m = view.saisieMatiere();
        matiereS.addMatiereDansFichier(m);
        view.appuyerPourContinuer();
        menuMatieres();
        break;
    }

    case 2:
    {
        string classeId, annee;
        Classe *classe = nullptr;

        cout << "Année: ";
        cin >> annee;

        do
        {
            cout << "ID de la classe: ";
            cin >> classeId;
            classe = classeS.searchClasseById(classeId);
            if (classe == nullptr)
            {
                cout << "Classe introuvable. Veuillez réessayer.\n";
            }
        } while (classe == nullptr);

        enseignementS.chargerEnseignementsDepuisFichierDeClasseEtAnnee(classeId, annee);
        view.appuyerPourContinuer();
        menuMatieres();
        break;
    }

    case 3:
        menuPrincipal();
        break;
    }
}

void Menu::applyChoiceMenuModules(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(5);
        break;
    case 1:
    {
        Module m = view.saisieModule();
        moduleS.addModuleDansFichier(m);
        view.appuyerPourContinuer();
        menuModules();
        break;
    }
    case 2:
        menuPrincipal();
        break;
    }
}

void Menu::applyChoiceMenuClasses(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(6);
        break;
    case 1:
    {
        Classe c = view.saisieClasse();
        classeS.addClasseDansFichier(c);
        view.appuyerPourContinuer();
        menuClasses();
        break;
    }
    case 2:
        classeS.chargerClassesDepuisFichier();
        classeS.afficheClasses();
        view.appuyerPourContinuer();
        menuClasses();
        break;
    case 3:
        menuPrincipal();
        break;
    }
}

void Menu::applyChoiceMenuEnseignements(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(7);
        break;
    case 1:
    {
        Enseignement e = view.saisieEnseignement();
        enseignementS.addEnseignementDansFichier(e);
        view.appuyerPourContinuer();
        menuEnseignements();
        break;
    }
    case 2:
        enseignementS.chargerEnseignementsDepuisFichier();
        enseignementS.afficheEnseignements();
        view.appuyerPourContinuer();
        menuEnseignements();
        break;
    case 3:
        menuPrincipal();
        break;
    }
}

void Menu::applyChoiceMenuEvaluations(int c)
{
    switch (c)
    {
    case 0:
        invalidChoice(8);
        break;
    case 1:
    {
        EvaluationGenerale eval = view.saisieEvaluationGenerale();
        evaluationS.addEvaluationGeneraleDansFichier(eval);
        view.appuyerPourContinuer();
        menuEvaluations();
        break;
    }
    case 2:
    {
        string annee;
        cout << "Saisir l'année: ";
        cin >> annee;
        evaluationS.listerToutesLesEvaluationsGeneralesDeAnnee(annee);
        view.appuyerPourContinuer();
        menuEvaluations();
        break;
    }
    case 3:
        menuPrincipal();
        break;
    }
}

void Menu::menuPrincipal()
{
    string separator = "\n-----------------------------------------------------------\n";
    string header = "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\nGESTION DE NOTES\n";
    system("cls");
    cout << header;
    cout << separator;
    cout << "1 - Gerer Etudiants";
    cout << separator;
    cout << "2 - Gerer Profs";
    cout << separator;
    cout << "3 - Gerer Matieres";
    cout << separator;
    cout << "4 - Gerer Modules";
    cout << separator;
    cout << "5 - Gerer Classes";
    cout << separator;
    cout << "6 - Gerer Enseignements";
    cout << separator;
    cout << "7 - Gerer Evaluations";
    cout << separator;
    cout << "8 - QUITTER";
    applyChoiceMenuPrincipal(validChoice(8));
}

void Menu::menuEtudiants()
{
    string separator = "\n-----------------------------------------------------------\n";
    system("cls");
    cout << "MENU ETUDIANTS" << endl;
    cout << separator;
    cout << "1 - Ajouter un etudiant";
    cout << separator;
    cout << "2 - Lister les etudiants ayant participé à au moins 2 évaluations, sur une année";
    cout << separator;
    cout << "3 - Lister les notes obtenues par un etudiant sur une période";
    cout << separator;
    cout << "4 - Retour";
    applyChoiceMenuEtudiants(validChoice(4));
}

void Menu::menuProfs()
{
    string separator = "\n-----------------------------------------------------------\n";system("cls");
    cout << "MENU PROFS" << endl;
    cout << separator;
    cout << "1 - Ajouter un prof";
    cout << separator;
    cout << "2 - Lister les profs d'une classe, sur une année";
    cout << separator;
    cout << "3 - QUITTER";
    applyChoiceMenuProfs(validChoice(3));
}

void Menu::menuMatieres()
{
    string separator = "\n-----------------------------------------------------------\n";
    cout << "MENU MATIERES" << endl;
    cout << separator;
    cout << "1 - Ajouter une matiere";
    cout << separator;
    cout << "2 - Lister les matieres d'une classe, sur une année";
    cout << separator;
    cout << "3 - QUITTER";
    applyChoiceMenuMatieres(validChoice(3));
}

void Menu::menuModules()
{
    string separator = "\n-----------------------------------------------------------\n";system("cls");
    cout << "MENU MODULES" << endl;
    cout << separator;
    cout << "1 - Ajouter un module";
    cout << separator;
    cout << "2 - QUITTER";
    applyChoiceMenuModules(validChoice(2));
}

void Menu::menuClasses()
{
    string separator = "\n-----------------------------------------------------------\n";
    system("cls");
    cout << "MENU CLASSES" << endl;
    cout << separator;
    cout << "1 - Ajouter une classe";
    cout << separator;
    cout << "2 - Lister les classes";
    cout << separator;
    cout << "3 - QUITTER";
    applyChoiceMenuClasses(validChoice(3));
}

void Menu::menuEnseignements()
{
    string separator = "\n-----------------------------------------------------------\n";
    system("cls");
    cout << "MENU ENSEIGNEMENTS" << endl;
    cout << separator;
    cout << "1 - Ajouter un enseignement";
    cout << separator;
    cout << "2 - Lister les enseignements";
    cout << separator;
    cout << "3 - QUITTER";
    applyChoiceMenuEnseignements(validChoice(3));
}

void Menu::menuEvaluations()
{
    string separator = "\n-----------------------------------------------------------\n";
    system("cls");
    cout << "MENU EVALUATIONS" << endl;
    cout << separator;
    cout << "1 - Ajouter une evlauation";
    cout << separator;
    cout << "2 - Lister les organisées pour une année académique";
    cout << separator;
    cout << "3 - QUITTER";
    applyChoiceMenuEvaluations(validChoice(3));
}
