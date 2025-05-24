#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <string>

class Etudiant {
private:
    std::string code;
    std::string nom;
    std::string prenom;
    std::string dateNaissance;
    std::string lieuNaissance;
    std::string adresse;

public:
    Etudiant();

    Etudiant(std::string c, std::string n, std::string p, std::string dNaiss, std::string lNaiss, std::string adr);

    std::string getCode() const;
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getDateNaissance() const;
    std::string getLieuNaissance() const;
    std::string getAdresse() const;

    void setAdresse(std::string adr);
};

#endif
