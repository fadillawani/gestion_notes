#include "PassageEvaluation.h"
#include "Classe.h"
#include "Evaluation.h"
using namespace std;
#include <string>

PassageEvaluation::PassageEvaluation()
{

}

PassageEvaluation::PassageEvaluation(string id, Classe cls, Evaluation eval)
{
    this->id = id;
    classe = cls;
    evaluation = eval;
}

string PassageEvaluation::getId()
{
    return id;
}

Classe PassageEvaluation::getClasse()
{
    return classe;
}

Evaluation PassageEvaluation::getEvaluation()
{
    return evaluation;
}

void PassageEvaluation::setId(string id)
{
    this->id = id;
}

void PassageEvaluation::setClasse(Classe cls)
{
    classe = cls;
}

void PassageEvaluation::setEvaluation(Evaluation eval)
{
    evaluation = eval;
}
