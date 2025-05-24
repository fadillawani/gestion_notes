#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string>

class Professeur {
private:
    std::string id;
    std::string nom;
    std::string prenom;

public:
    Professeur();
    Professeur(std::string i, std::string n, std::string p);
    std::string getId() const;
    std::string getNom() const;
    std::string getPrenom() const;
};

#endif
