#ifndef MODULESERVICE_H_INCLUDED
#define MODULESERVICE_H_INCLUDED

#include <string>
#include "Module.h"
#include "MatiereService.h"
#include "ClasseService.h"

#define MAX_MODULES 100

class ModuleService {
private:
    Module modules[MAX_MODULES];
    int nbModules;

    MatiereService matiereService;
    ClasseService classeService;

public:
    ModuleService();
    ModuleService(MatiereService, ClasseService);

    void addModuleDansFichier(Module);
    bool ajouterModule(const Module& module);
    void listerModulesParClasseEtAnnee(const std::string& nomClasse, const std::string& anneeAcademique);
    Module *searchModuleById(string &idModule);
    Module *searchModuleByIdMatiere(string &idMatiere);

    void chargerModulesDepuisFichier();
    void sauvegarderModulesDansFichier();
};

#endif // MODULESERVICE_H_INCLUDED
