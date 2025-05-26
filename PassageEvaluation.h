#ifndef PASSAGEEVALUATION_H_INCLUDED
#define PASSAGEEVALUATION_H_INCLUDED
#include <string>
#include "Classe.h"
#include "Evaluation.h"
using namespace std;

class PassageEvaluation
{
private:
    string id;
    Classe classe;
    Evaluation evaluation;
public:
    PassageEvaluation();
    PassageEvaluation(string, Classe, Evaluation);

    string getId();
    Classe getClasse();
    Evaluation getEvaluation();

    void setId(string);
    void setClasse(Classe);
    void setEvaluation(Evaluation);
};

#endif // PASSAGEEVALUATION_H_INCLUDED
