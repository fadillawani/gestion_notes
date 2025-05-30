#include "ModuleService.h"
#include <fstream>
#include <iostream>
using namespace std;
ModuleService::ModuleService()
{
}

void ModuleService::addModuleDansFichier(Module module)
{
    ofstream fichier("BD/modules.txt", ios::app);
    fichier << module.getId() << ";"
            << module.getMatiere().getId() << ";"
            << module.getClasse().getId() << ";"
            << module.getCoefficient() << ";"
            << module.getDuree() << endl;

    fichier.close();
}

Module *ModuleService::searchModuleById(string &idModule)
{
    chargerModulesDepuisFichier();
    for (int i = 0; i < nbModules; ++i)
    {
        if (modules[i].getId() == idModule)
        {
            return &modules[i];
        }
    }
    return nullptr;
}

Module *ModuleService::searchModuleByIdMatiere(string &idMatiere)
{
    chargerModulesDepuisFichier();
    for (int i = 0; i < nbModules; ++i)
    {
        if (modules[i].getMatiere().getId() == idMatiere)
        {
            return &modules[i];
        }
    }
    return nullptr;
}

void ModuleService::chargerModulesDepuisFichier()
{
    ifstream fichier("BD/modules.txt");
    nbModules = 0;

    string id, matId, clsId, duree, coef;
    Module mat;
    while (getline(fichier, id, ';') &&
           getline(fichier, matId, ';') &&
           getline(fichier, clsId, ';') &&
           getline(fichier, duree, ';') &&
           getline(fichier, coef, '\n'))
    {
        Module mat;
        mat.setId(id);
        mat.setMatiere(*matiereService.searchMatiereById(matId));
        mat.setClasse(*classeService.searchClasseById(clsId));
        mat.setDuree(stoi(duree));
        mat.setCoefficient(stod(coef));

        modules[nbModules++] = mat;
    }

    fichier.close();
}