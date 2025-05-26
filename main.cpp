#include <iostream>
#include "EtudiantService.h"
#include "ClasseService.h"
#include "Classe.h"
using namespace std;

int main()
{
    EtudiantService es = EtudiantService();
    ClasseService clsS = ClasseService();
    clsS.addClasseDansFichier(Classe());
    es.sauvegarderEtudiantsDansFichier();
    /*es.chargerEtudiantsDepuisFichier();
    cout << es.getNbEtudiants() << endl;
    es.afficheEtudiants();
    cout << "Hello world!" << endl;*/
    return 0;
}
