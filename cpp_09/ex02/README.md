ÉTAPE 1 : Créer des paires

On commence par créer un vecteur de paires qui prend en paramètre le type de données du conteneur.

    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairs;

Ensuite, on crée une variable pour stocker un élément impair s'il y en a un, ainsi qu'un drapeau ou une variable booléenne pour indiquer sa présence.

    typename Container::value_type odd_element;

    bool has_odd_element = false;

Après, on parcourt le conteneur d'origine par incréments de deux. Pour chaque paire, on compare les deux éléments et on crée une paire avec le plus petit en premier.

    On utilise la fonction std::make_pair() pour créer chaque paire.

    Si le nombre total d'éléments est impair, le dernier élément n'aura pas de paire. On l'assigne alors à la variable odd_element et on met le drapeau has_odd_element à true.

ÉTAPE 2 : Créer un conteneur avec les éléments les plus grands et le trier récursivement

On crée un nouveau conteneur du même type que le conteneur d'origine.

    Container largest_elements;

Ensuite, on parcourt le vecteur de paires et on insère l'élément le plus grand de chaque paire dans ce nouveau conteneur.

    Par exemple, si les paires sont [[0, 1], [4, 2], [10, 7]], le nouveau conteneur contiendra les éléments les plus grands, soit [1, 4, 10].

Ce conteneur des éléments les plus grands est ensuite trié récursivement en utilisant la même logique.

ÉTAPE 3 : Créer le conteneur final et insérer les éléments restants

On crée un conteneur final pour le résultat trié.

    Container final_sorted_container;

On insère le plus petit élément du conteneur d'origine (qui est le premier élément de la première paire) dans ce conteneur final. Ensuite, on insère tous les éléments les plus grands, qui sont maintenant triés.

    Le tri se fait en insérant les éléments les plus petits de chaque paire restante (les "éléments mineurs") un par un dans le conteneur final trié, en utilisant une stratégie d'insertion optimisée.

Pour déterminer dans quel ordre insérer les éléments restants, on utilise la suite de Jacobsthal. Cette suite donne une séquence d'indices qui optimise les insertions dans le conteneur final en minimisant le nombre de comparaisons. On insère les éléments mineurs à l'aide d'une recherche binaire pour trouver leur position correcte.

Si le conteneur des éléments mineurs est vide, ou si la suite de Jacobsthal n'est pas suffisante, on insère les éléments restants, y compris l'éventuel élément impair, dans le conteneur final trié en utilisant une recherche binaire.

