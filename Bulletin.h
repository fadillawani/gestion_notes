#ifndef BULLETIN_H
#define BULLETIN_H

#include <string>
#include "Etudiant.h"
using namespace std;

class Bulletin
{
    private:
        Etudiant etudiant;
        string semestre;
        float moyenne;
        int rang;
    public:
        Bulletin();
        Bulletin(Etudiant, string, float, int);

        Etudiant getEtudiant();
        string getSemestre();
        float getMoyenne();
        int getRang();

        void setEtudiant(Etudiant);
        void setSemestre(string);
        void setMoyenne(float);
        void setRang(int);
};

#endif // BULLETIN_H
