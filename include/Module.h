#ifndef MODULE_H
#define MODULE_H

#include "Matiere.h"
#include "Classe.h"

class Module {
private:
    Matiere matiere;
    Classe classe;
    int duree;
    float coefficient;

public:
    Module();
    Module(Matiere m, Classe c, int d, float coef);

    Matiere getMatiere() const;
    Classe getClasse() const;
    int getDuree() const;
    float getCoefficient() const;
};

#endif
