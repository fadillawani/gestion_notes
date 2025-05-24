#include "Etudiant.h"

Etudiant::Etudiant() {}

Etudiant::Etudiant(std::string c, std::string n, std::string p, std::string dNaiss, std::string lNaiss, std::string adr)
    : code(c), nom(n), prenom(p), dateNaissance(dNaiss), lieuNaissance(lNaiss), adresse(adr) {}

std::string Etudiant::getCode() const {
    return code;
}

std::string Etudiant::getNom() const {
    return nom;
}

std::string Etudiant::getPrenom() const {
    return prenom;
}

std::string Etudiant::getDateNaissance() const {
    return dateNaissance;
}

std::string Etudiant::getLieuNaissance() const {
    return lieuNaissance;
}

std::string Etudiant::getAdresse() const {
    return adresse;
}

void Etudiant::setAdresse(std::string adr) {
    adresse = adr;
}
