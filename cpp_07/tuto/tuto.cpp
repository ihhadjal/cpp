#include <iostream>

//UTILITE DES TEMPLATES => POUR NE PAS REECRIRE A CHAQUE FOIS LA MEME FONCTION MAIS 
//QUI PRENDS DES TYPES DE PARAMETRES DIFFERENTS, ON CREE UN TEMPLATE QUI PRENDS PLUSIEURS TYPES

template <typename T>

//on prend la classe par reference et pas par copie
//pour ne pas copier une fois par parametre mais on prend directement
//l'adresse ce qui nous permet de gagner de la place en memoire
//
//void f1(int v) => va creer une copie de l'argument (argument lourd = bcp de place en memoire)

//void f2(int &v) => on copie pas la valeur, on utilise directement la variable d'origine



T   const &max(T const &x, T const &y) {
    return (x>=y ? x : y);
}


int main()
{
    int a = 21;
    int b = 42;

    std::cout << "max of " << a << "and " << b << '\n';
    std::cout << max<int>(a, b) << '\n'; //instanciation explicite (on dit clairement au template que T=int)
    
    std::cout << "max of " << a << "and " << b << '\n';
    std::cout << max(a,b) << '\n'; //instanciation implicite (template/compilateur comprends tout seul que T=int (PAS PRATIQUE EN CAS REEL))

}