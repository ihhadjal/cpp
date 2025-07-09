#include "phonebook.hpp"

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
    if (m_vie < 0)
        return false;
    else
        return true;
}
int main()
{
    Personnage iheb, mahdi;

    mahdi.attaquer(iheb);
    iheb.boirePotionDeVie(20);
    iheb.attaquer(mahdi);
    iheb.changerArme("ak 47", 100);
    iheb.attaquer(mahdi);
    return (0);
}

