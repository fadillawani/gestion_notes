#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <string>
#include "Classe.h"
using namespace std;

class Etudiant {
private:
    string code, nom, prenom, dateNaissance, lieuNaissance, adresse;
    Classe classe;

public:
    Etudiant();

    Etudiant(string c, string n, string p, string dNaiss, string lNaiss, string adr, Classe cls);

    string getCode();
    string getNom();
    string getPrenom();
    string getDateNaissance();
    string getLieuNaissance();
    string getAdresse();
    Classe getClasse();

    void setCode(string);
    void setNom(string);
    void setPrenom(string);
    void setDateNaissance(string);
    void setLieuNaissance(string);
    void setAdresse(string adr);
    void setClasse(Classe cls);

    string toString();
};

#endif
