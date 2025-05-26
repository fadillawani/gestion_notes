#include "ClasseService.h"
#include "Classe.h"
#include "Classe.h"
#include <fstream>
#include <iostream>
using namespace std;

ClasseService::ClasseService()
{
    nbClasses = 0;
    chargerClassesDepuisFichier();
}

void ClasseService::afficheClasses()
{
    for (int i = 0; i < nbClasses; ++i)
    {
        cout << classes[i].toString() << endl;
    }
}
int ClasseService::getNbClasses()
{
    return nbClasses;
}

bool ClasseService::ajouterClasse(Classe &cls)
{
    if (nbClasses >= MAX_CLASSES)
    {
        cout << "Nombre maximal d'�tudiants atteint." << endl;
        return false;
    }

    if (searchClasseById(cls.getId()) == nullptr)
    {
        classes[nbClasses++] = cls;
        sauvegarderClassesDansFichier();
        cout << "�tudiant ajout� avec succ�s." << endl;
        return true;
    }
    else
    {
        cout << "Un �tudiant avec ce code existe d�j�." << endl;
        return false;
    }

    /*// V�rifier que le code n'existe pas d�j�
    for (int i = 0; i < nbClasses; ++i) {
        if (classes[i].getCode() == etu.getCode()) {
        }
    }*/
}

Classe *ClasseService::searchClasseById(const string &idClasse)
{
    for (int i = 0; i < nbClasses; ++i)
    {
        if (classes[i].getId() == idClasse)
        {
            return &classes[i]; // Retourne un pointeur vers l'étudiant trouvé
        }
    }
    return nullptr; // Aucun étudiant trouvé avec ce code
}

void ClasseService::addClasseDansFichier(Classe cls1)
{
    ofstream fichier("classes.txt", ios::app);
    Classe cls = Classe("c1", "GLRS-A", "L2");
    fichier << cls.getId() << ";"
            << cls.getNom() << ";"
            << cls.getNiveau() << endl;

    fichier.close();
}

void ClasseService::sauvegarderClassesDansFichier()
{
    /*ofstream fichier("classes.txt");
    for (int i = 0; i < nbClasses; ++i)
    {
        fichier << classes[i].getCode() << ";"
                << classes[i].getNom() << ";"
                << classes[i].getPrenom() << ";"
                << classes[i].getDateNaissance() << ";"
                << classes[i].getLieuNaissance() << ";"
                << classes[i].getAdresse() << endl;
    }*/
    ofstream fichier("classes.txt");
    Classe cls = Classe("c1", "GLRS-A", "L2");
    //Classe e = Classe("co3", "Sadjo", "Ousman", "26/10/2007", "Maroua", "Colobane", cls);
    fichier << cls.getId() << ";"
            << cls.getNom() << ";"
            << cls.getNiveau() << endl;

    fichier.close();
}

void ClasseService::chargerClassesDepuisFichier()
{
    ifstream fichier("classes.txt");
    nbClasses = 0;

    string id, nom, niveau;
    Classe cls;
    while (getline(fichier, id, ';') &&
           getline(fichier, nom, ';') &&
           getline(fichier, niveau))
    {
        Classe cls;
        cls.setId(id);
        cls.setNom(nom);
        cls.setNiveau(niveau);
        // etu.setClasse();

        classes[nbClasses++] = cls;
    }

    fichier.close();
}
