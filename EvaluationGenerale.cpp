#include "EvaluationGenerale.h"
#include "Note.h"
using namespace std;

EvaluationGenerale::EvaluationGenerale() {}

EvaluationGenerale::EvaluationGenerale(string id, Matiere m, string d, string per, string t, float n, string a)
{
    this->id = id;
    matiere = m;
    date = d;
    periode = per;
    type = t;
    note = n;
    annee = a;
}

string EvaluationGenerale::getId()
{
    return id;
}

Matiere EvaluationGenerale::getMatiere() const
{
    return matiere;
}

string EvaluationGenerale::getDate() const
{
    return date;
}

string EvaluationGenerale::getPeriode() const
{
    return periode;
}

string EvaluationGenerale::getType() const
{
    return type;
}

float EvaluationGenerale::getNote() const
{
    return note;
}

string EvaluationGenerale::getAnnee() const
{
    return annee;
}

void EvaluationGenerale::setId(string i)
{
    id = i;
}

void EvaluationGenerale::setMatiere(Matiere m)
{
    matiere = m;
}

void EvaluationGenerale::setDate(string d)
{
    date = d;
}

void EvaluationGenerale::setPeriode(string per)
{
    periode = per;
}

void EvaluationGenerale::setType(string t)
{
    type = t;
}

void EvaluationGenerale::setNote(float n)
{
    note = n;
}

void EvaluationGenerale::setAnnee(string a)
{
    annee = a;
}

string EvaluationGenerale::toString()
{
    return id + ", " + matiere.getLibelle() + ", " + date + ", " + periode + ", " + type + ", " + annee;
}
