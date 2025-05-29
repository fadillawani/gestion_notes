#include "Evaluation.h"
#include "Note.h"
using namespace std;

Evaluation::Evaluation() {}

Evaluation::Evaluation(string id, Etudiant e, Matiere m, string d, string per, string t, double n, string a)
{
    this->id = id;
    etudiant = e;
    matiere = m;
    date = d;
    periode = per;
    type = t;
    note = n;
    annee = a;
}

string Evaluation::getId()
{
    return id;
}

Etudiant Evaluation::getEtudiant()
{
    return etudiant;
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

double Evaluation::getNote()
{
    return note;
}

string Evaluation::getAnnee() const
{
    return annee;
}

void Evaluation::setId(string i)
{
    id = i;
}

void Evaluation::setEtudiant(Etudiant e)
{
    etudiant = e;
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

void Evaluation::setNote(double n)
{
    note = n;
}

void Evaluation::setAnnee(string a)
{
    annee = a;
}

string Evaluation::toString()
{
    return id + ", " + to_string(note) + ", " + matiere.getLibelle() + ", " + date + ", " + periode + ", " + type + ", " + annee;
}
