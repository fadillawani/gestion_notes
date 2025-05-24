#include "Evaluation.h"

Evaluation::Evaluation(){}

Evaluation::Evaluation(Etudiant e, Matiere m, std::string d, std::string per, std::string t, float n)
    : etudiant(e), matiere(m), date(d), periode(per), type(t), note(n) {}

Etudiant Evaluation::getEtudiant() const {
    return etudiant;
}

Matiere Evaluation::getMatiere() const {
    return matiere;
}

std::string Evaluation::getDate() const {
    return date;
}

std::string Evaluation::getPeriode() const {
    return periode;
}

std::string Evaluation::getType() const {
    return type;
}

float Evaluation::getNote() const {
    return note;
}
