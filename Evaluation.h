#ifndef EVALUATION_H
#define EVALUATION_H

#include <string>
#include "Etudiant.h"
#include "Matiere.h"
#include "Note.h"
using namespace std;

class Evaluation {
private:
    Etudiant etudiant;
    Matiere matiere;
    string date;
    string periode; // SEMESTRE 1 ou SEMESTRE 2
    string type;    // EXAMEN ou DEVOIR
//    Note note;

public:
    Evaluation();
    Evaluation(Etudiant e, Matiere m, string d, string per, string t);

    Etudiant getEtudiant() const;
    Matiere getMatiere() const;
    string getDate() const;
    string getPeriode() const;
    string getType() const;
//    Note getNote() const;

    void setEtudiant(Etudiant);
    void setMatiere(Matiere);
    void setDate(string);
    void setPeriode(string);
    void setType(string);
//    void setNote(Note);
};

#endif
