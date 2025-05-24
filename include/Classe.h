#ifndef CLASSE_H
#define CLASSE_H

#include <string>

class Classe {
private:
    std::string id;
    std::string nom;

public:
    Classe();
    Classe(std::string i, std::string n);
    std::string getId() const;
    std::string getNom() const;
};

#endif
