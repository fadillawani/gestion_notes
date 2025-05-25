#ifndef MODULESERVICE_H_INCLUDED
#define MODULESERVICE_H_INCLUDED

#include <string>
#include "Module.h"

#define MAX_MODULES 100

class ModuleService {
private:
    Module modules[MAX_MODULES];
    int nbModules;

public:
    ModuleService();

    bool ajouterModule(const Module& module);
    void listerMatieresParClasseEtAnnee(const std::string& nomClasse, const std::string& anneeAcademique);

    void chargerModulesDepuisFichier();
    void sauvegarderModulesDansFichier();
};

#endif // MODULESERVICE_H_INCLUDED
