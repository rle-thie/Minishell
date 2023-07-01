# Minishell 

Minishell est un projet passionnant que j'ai développé dans le cadre de mes études. Il s'agit d'un programme entièrement codé en langage C qui vise à re-implementer un shell de A à Z.

Ce projet peut être syndiqué en deux grosses parties distinctes : le **parsing** et l'**exécution**. 

**Le Parsing :** Cette première partie est la plus longue, mais elle ne doit pas être négligée. En effet, une grande partie de la gestion des erreurs passe par cette étape cruciale. Nous avons développé un parsing très élaboré en utilisant un systeme lexer/parser afin de traiter toutes les possibilités d'input et d'erreurs de manière optimale. Cette partie nous a permis d'apprendre et de comprendre la rigueur nessecaire pour ce type de projet en terme de gestions d'erreurs.

**L'Exécution :** La deuxième partie du projet, l'exécution, prend en input le résultat du parsing si aucune erreur n'a été trouvée lors de la première partie. Cette partie du projet est beaucoup plus complexe. Nous avons appris comment bash fonctionne et exécute les commandes de l'utilisateur grâce au système de fork. Cette étape nous a permis de comprendre en détail le mécanisme d'exécution des commandes et d'assurer un fonctionnement cohérent et simillaire de notre shell à celui de Bash.

Pour assurer une gestion optimale de la mémoire allouée en langage C, bien que celui-ci soit connu pour être moins pratique à cet égard, nous avons développé notre propre garbage collector (ramasse-miettes) pour éviter toute fuite de mémoire.

Ce projet a été l'un des projets les plus passionnants que j'ai pu réaliser à l'école. Non seulement il m'a permis de consolider mes connaissances en langage C, mais il m'a également donné une compréhension approfondie du fonctionnement d'un shell et des systèmes d'exploitation. De plus, j'ai acquis des compétences précieuses en matière de gestion des erreurs et de conception de projets robustes.

## Compréhension des termes techniques :

Un shell, ou interpréteur de commandes, est un programme qui permet à l'utilisateur d'interagir avec un système d'exploitation en utilisant des lignes de commandes.

- **Shell** : Un shell, ou interpréteur de commandes, est un programme qui permet à l'utilisateur d'interagir avec un système d'exploitation en utilisant des lignes de commandes. Un exemple connu de shell est le Terminal sur macOS ou Linux, où l'utilisateur peut exécuter des commandes telles que `ls`, `cd`, `mkdir`, etc., pour manipuler les fichiers et les dossiers.

- **Garbage Collector en C** : En langage C, la gestion de la mémoire allouée est souvent laissée à la charge du programmeur, ce qui peut entraîner des fuites de mémoire. Un garbage collector est un mécanisme qui identifie automatiquement les blocs de mémoire qui ne sont plus utilisés par le programme et les libère pour éviter les fuites. Nous avons implémenté notre propre garbage collector en utilisant une liste chaînée pour stocker des pointeurs et ainsi garantir que la mémoire est correctement libérée lorsque cela est nécessaire.

- **Lexer et Parser en C** : Un lexer et un parser sont deux composants essentiels pour analyser et comprendre les commandes saisies par l'utilisateur. Le lexer (analyseur lexical) analyse le flux de caractères et les transforme en "jetons" significatifs (mots-clés, symboles, etc.). Le parser (analyseur syntaxique) prend ensuite ces jetons et construit une structure arborescente (arbre syntaxique) qui représente la commande dans un format compréhensible pour l'ordinateur. Cette approche nous permet de traiter toutes les variations possibles de commandes et de gérer efficacement les erreurs de syntaxe.

Note : Certaines fonctions en C, comme `readline` et `add_history`, ne sont pas sécurisées et peuvent entraîner des fuites de mémoire. Le fichier "ignoreleak" est donc inclus pour exclure les erreurs de fuite de mémoire liées à ces fonctions.

## Essayer le programme :

Pour compiler le projet, exécutez la commande suivante dans votre terminal :

```
make
```

Une fois la compilation réussie, vous pouvez l

lancer le programme en utilisant la commande suivante :

```
./minishell
```

**Note :** Assurez-vous d'avoir un environnement de développement C approprié et les dépendances nécessaires avant de compiler et d'exécuter le programme Minishell.
