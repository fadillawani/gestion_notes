#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED

#include <string>
#include "Etudiant.h"
#include "Matiere.h"
using namespace std;

class Evaluation
{
private:
    string id;
    Etudiant etudiant;
    Matiere matiere;
    string date;
    string periode; // SEMESTRE 1 ou SEMESTRE 2
    string type;    // EXAMEN ou DEVOIR
    double note;
    string annee;

public:
    Evaluation();
    Evaluation(string id, Etudiant e, Matiere m, string d, string per, string t, double n, string a);

    string getId();
    Etudiant getEtudiant();
    Matiere getMatiere() const;
    string getDate() const;
    string getPeriode() const;
    string getType() const;
    double getNote();
    string getAnnee() const;

    void setId(string);
    void setEtudiant(Etudiant);
    void setMatiere(Matiere);
    void setDate(string);
    void setPeriode(string);
    void setType(string);
    void setNote(double);
    void setAnnee(string);

    string toString();
};

#endif // EVALUATION_H_INCLUDED
