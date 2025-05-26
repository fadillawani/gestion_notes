#ifndef EVALUATION_H
#define EVALUATION_H

#include <string>
#include "Etudiant.h"
#include "Matiere.h"
#include "Note.h"
using namespace std;

class Evaluation {
private:
    Matiere matiere;
    string date;
    string periode; // SEMESTRE 1 ou SEMESTRE 2
    string type;    // EXAMEN ou DEVOIR
    float note;

public:
    Evaluation();
    Evaluation(Matiere m, string d, string per, string t, float n);

    Matiere getMatiere() const;
    string getDate() const;
    string getPeriode() const;
    string getType() const;
    float getNote() const;

    void setMatiere(Matiere);
    void setDate(string);
    void setPeriode(string);
    void setType(string);
    void setNote(float);
};

#endif
