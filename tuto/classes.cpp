#include "classes.hpp"

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    if (m_vie < 0)
        m_vie = 0;
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_degatArme);
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100)
        m_vie = 100;
}

void    Personnage::changerArme(std::string nomNouvelleArme, int degatNouvelleArme)
{
    m_nomArme = nomNouvelleArme;
    m_degatArme = degatNouvelleArme;
}

bool    Personnage::estVivant()
{
    if (m_vie <= 0)
        return false;
    else
        return true;
}
Personnage::Personnage(std::string nomArme, int degatArme) : m_vie(100), m_mana(100),m_nomArme(nomArme), m_degatArme(degatArme)
{
}
Personnage::Personnage(): m_vie(100), m_mana(100), m_nomArme("shlash khene"), m_degatArme(10)
{
}
int main()
{
    Personnage iheb("shlas tout c morts", 100), mahdi;

    mahdi.attaquer(iheb);
    iheb.boirePotionDeVie(20);
    iheb.attaquer(mahdi);

	if (mahdi.estVivant())
		std::cout << "mahdi est vivant" << std::endl;
	else
		std::cout << "mahdi est mort" << std::endl;
    return (0);
}

