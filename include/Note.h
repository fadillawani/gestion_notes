#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#include <string>
#include "Evaluation.h"
using namespace std;

class Note {
private:
    Evaluation evaluation;
    float valeur;

public:
    Note();
    Note(Evaluation eval, float val);
    Evaluation getEvaluation();
    float getValeur();

    void setEvaluation(string);
    void setValeur(string);
};

#endif // NOTE_H_INCLUDED
