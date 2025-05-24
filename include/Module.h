#ifndef MODULE_H
#define MODULE_H

#include "Matiere.h"
#include "Classe.h"
using namespace std;

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

    void setMatiere(Matiere);
    void setClasse(Classe);
    void setDuree(int);
    void setCoefficient(float);
};

#endif
