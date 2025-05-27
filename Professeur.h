#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string>
using namespace std;

class Professeur {
private:
    string id, nom, prenom, spec;

public:
    Professeur();
    Professeur(string i, string n, string p, string spec);
    string getId() ;
    string getNom() ;
    string getPrenom() ;
    string getSpec();

    void setId(string);
    void setNom(string);
    void setPrenom(string);
    void setSpec(string);

    string toString();
};

#endif
