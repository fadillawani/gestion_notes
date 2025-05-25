#include "Note.h"
//#include "Evaluation.h"

Note::Note()
{
}

/*Note::Note(Evaluation eval, float val)
{
    evaluation = eval;
    valeur = val;
}*/

/*Evaluation Note::getEvaluation()
{
    return evaluation;
}*/

float Note::getValeur()
{
    return valeur;
}

/*void Note::setEvaluation(Evaluation eval)
{
    evaluation = eval;
}*/

void Note::setValeur(float val)
{
    valeur = val;
}
