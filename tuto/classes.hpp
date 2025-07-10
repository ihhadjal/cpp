#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE


#include <iostream>
#include <string>

class Personnage
{
    public:
	Personnage();
	Personnage(std::string nomArme, int degatArme);
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nouvelleArme, int degatsNouvelleArme);
    bool estVivant();

    private :
    int m_vie;
    int m_mana;
    std::string m_nomArme;
    int m_degatArme;
};

#endif