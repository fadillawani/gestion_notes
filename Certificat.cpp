#include "Certificat.h"
#include "Etudiant.h"

Certificat::Certificat()
{
}

Certificat::Certificat(string t, string c, Etudiant e)
{
    type = t;
    contenu = c;
    etudiant = e;
}

string Certificat::getType()
{
    return type;
}

string Certificat::getContenu()
{
    return contenu;
}

Etudiant Certificat::getEtudiant()
{
    return etudiant;
}

void Certificat::setType(string t)
{
    this->type = t;
}

void Certificat::setContenu(string c)
{
    this->contenu = c;
}

void Certificat::setEtudiant(Etudiant e)
{
    this->etudiant = e;
}
