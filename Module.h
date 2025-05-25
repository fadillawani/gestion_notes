#ifndef MODULE_H
#define MODULE_H

#include "Matiere.h"
#include "Classe.h"
using namespace std;

class Module
{
private:
    Matiere matiere;
    Classe classe;
    int duree;
    float coefficient;

public:
    Module();
    Module(Matiere m, Classe c, int d, float coef);

    Matiere getMatiere();
    Classe getClasse();
    int getDuree();
    float getCoefficient();

    void setMatiere(Matiere);
    void setClasse(Classe);
    void setDuree(int);
    void setCoefficient(float);
};

#endif
