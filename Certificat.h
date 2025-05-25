#ifndef CERTIFICAT_H
#define CERTIFICAT_H

#include <string>
#include "Etudiant.h"
using namespace std;

class Certificat
{
    private:
        string type, contenu;
        Etudiant etudiant;
    public:
        Certificat();
        Certificat(string t, string c, Etudiant e);

        string getType();
        string getContenu();
        Etudiant getEtudiant();

        void setType(string);
        void setContenu(string);
        void setEtudiant(Etudiant);
};

#endif // CERTIFICAT_H
