#ifndef PASSAGEEVALUATION_H_INCLUDED
#define PASSAGEEVALUATION_H_INCLUDED
#include <string>
#include "Classe.h"
#include "EvaluationGenerale.h"
using namespace std;

class PassageEvaluation
{
private:
    string id;
    Classe classe;
    EvaluationGenerale evaluation;

public:
    PassageEvaluation();
    PassageEvaluation(string, Classe, EvaluationGenerale);

    string getId();
    Classe getClasse();
    EvaluationGenerale getEvaluation();

    void setId(string);
    void setClasse(Classe);
    void setEvaluation(EvaluationGenerale);
    
};

#endif // PASSAGEEVALUATION_H_INCLUDED
