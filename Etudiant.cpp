#include "Etudiant.h"
#include "Classe.h"
using namespace std;
Etudiant::Etudiant() {}

Etudiant::Etudiant(string c, string n, string p, string dNaiss, string lNaiss, string adr, Classe cls)
{
    code = c;
    nom = n;
    prenom = p;
    dateNaissance = dNaiss;
    lieuNaissance = lNaiss;
    adresse = adr;
    classe = cls;
}

string Etudiant::getCode()
{
    return code;
}

string Etudiant::getNom()
{
    return nom;
}

string Etudiant::getPrenom()
{
    return prenom;
}

string Etudiant::getDateNaissance()
{
    return dateNaissance;
}

string Etudiant::getLieuNaissance()
{
    return lieuNaissance;
}

string Etudiant::getAdresse()
{
    return adresse;
}

Classe Etudiant::getClasse()
{
    return classe;
}


void Etudiant::setCode(string c)
{
    code = c;
}

void Etudiant::setNom(string n)
{
    nom = n;
}

void Etudiant::setPrenom(string p)
{
    prenom = p;
}

void Etudiant::setDateNaissance(string dNaiss)
{
    dateNaissance = dNaiss;
}

void Etudiant::setLieuNaissance(string lNaiss)
{
    lieuNaissance = lNaiss;
}

void Etudiant::setAdresse(string adr)
{
    adresse = adr;
}

void Etudiant::setClasse(Classe cls)
{
    classe = cls;
}

string Etudiant::toString()
{
    return code + ", " + nom + ", " + prenom + ", " + dateNaissance + ", " + lieuNaissance + ", " + adresse;
}
