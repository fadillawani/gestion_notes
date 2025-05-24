#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <string>
using namespace std;

class Etudiant {
private:
    string code, nom, prenom, dateNaissance, lieuNaissance, adresse;

public:
    Etudiant();

    Etudiant(string c, string n, string p, string dNaiss, string lNaiss, string adr);

    string getCode();
    string getNom();
    string getPrenom();
    string getDateNaissance();
    string getLieuNaissance();
    string getAdresse();

    void setCode(string);
    void setNom(string);
    void setPrenom(string);
    void setDateNaissance(string);
    void setLieuNaissance(string);
    void setAdresse(string adr);
};

#endif
