#ifndef EVALUATION_H
#define EVALUATION_H

#include <string>
#include "Etudiant.h"
#include "Matiere.h"

class Evaluation {
private:
    Etudiant etudiant;
    Matiere matiere;
    std::string date;
    std::string periode; // SEMESTRE 1 ou SEMESTRE 2
    std::string type;    // EXAMEN ou DEVOIR
    float note;

public:
    Evaluation();
    Evaluation(Etudiant e, Matiere m, std::string d, std::string per, std::string t, float n);

    Etudiant getEtudiant() const;
    Matiere getMatiere() const;
    std::string getDate() const;
    std::string getPeriode() const;
    std::string getType() const;
    float getNote() const;
};

#endif
