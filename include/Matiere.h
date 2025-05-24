#ifndef MATIERE_H
#define MATIERE_H

#include <string>
using namespace std;

class Matiere {
private:
    string id, libelle;

public:
    Matiere();
    Matiere(string i, string l);
    string getId() const;
    string getLibelle() const;

    void setId(string);
    void setLibelle(string);
};

#endif
