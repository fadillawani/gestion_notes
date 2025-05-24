#ifndef MATIERE_H
#define MATIERE_H

#include <string>

class Matiere {
private:
    std::string id;
    std::string libelle;

public:
    Matiere();
    Matiere(std::string i, std::string l);
    std::string getId() const;
    std::string getLibelle() const;
};

#endif
