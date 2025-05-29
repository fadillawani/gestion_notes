#ifndef MODULE_H
#define MODULE_H

#include "Matiere.h"
#include "Classe.h"
using namespace std;

class Module
{
private:
    string id;
    Matiere matiere;
    Classe classe;
    int duree;
    double coefficient;

    

public:
    Module();
    Module(Matiere m, Classe c, int d, double coef);

    string getId();
    Matiere getMatiere();
    Classe getClasse();
    int getDuree();
    double getCoefficient();

    void setId(string);
    void setMatiere(Matiere);
    void setClasse(Classe);
    void setDuree(int);
    void setCoefficient(double);
};

#endif
