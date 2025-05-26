#ifndef CLASSE_H
#define CLASSE_H

#include <string>
using namespace std;

class Classe {
private:
    string id, nom, niveau;

public:
    Classe();
    Classe(string i, string n, string niveau);
    string getId();
    string getNom();
    string getNiveau();

    void setId(string);
    void setNom(string);
    void setNiveau(string);

    string toString();
};

#endif
