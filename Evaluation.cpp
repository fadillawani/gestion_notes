#include "Evaluation.h"
#include "Note.h"
using namespace std;

Evaluation::Evaluation() {}

Evaluation::Evaluation(Matiere m, string d, string per, string t, float n)
{
    matiere = m;
    date = d;
    periode = per;
    type = t;
    note = n;
}

Matiere Evaluation::getMatiere() const
{
    return matiere;
}

string Evaluation::getDate() const
{
    return date;
}

string Evaluation::getPeriode() const
{
    return periode;
}

string Evaluation::getType() const
{
    return type;
}

float Evaluation::getNote() const
{
    return note;
}

void Evaluation::setMatiere(Matiere m)
{
    matiere = m;
}

void Evaluation::setDate(string d)
{
    date = d;
}

void Evaluation::setPeriode(string per)
{
    periode = per;
}

void Evaluation::setType(string t)
{
    type = t;
}

void Evaluation::setNote(float n)
{
    note = n;
}
