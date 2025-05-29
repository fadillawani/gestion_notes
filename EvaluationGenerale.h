#ifndef EVALUATIONGENERALE_H
#define EVALUATIONGENERALE_H

#include <string>
#include "Etudiant.h"
#include "Matiere.h"
using namespace std;

class EvaluationGenerale {
private:
    string id;
    Matiere matiere;
    string date;
    string periode; // SEMESTRE 1 ou SEMESTRE 2
    string type;    // EXAMEN ou DEVOIR
    string annee;

public:
    EvaluationGenerale();
    EvaluationGenerale(string id, Matiere m, string d, string per, string t, string a);

    string getId();
    Matiere getMatiere() const;
    string getDate() const;
    string getPeriode() const;
    string getType() const;
    string getAnnee() const;

    void setId(string);
    void setMatiere(Matiere);
    void setDate(string);
    void setPeriode(string);
    void setType(string);
    void setAnnee(string);

    string toString();
};

#endif
