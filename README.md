Projet 1 : une mini-bibliothèque de structures de données (2-3 semaines)
Un tableau dynamique (vec) puis une table de hachage, sur plusieurs fichiers .h/.c. Ça paraît banal, mais ça travaille tes trous :

malloc/realloc avec gestion d’erreurs (ton Q6)
ownership : qui alloue, qui libère
static/extern, séparation interface/implémentation
un Makefile propre et des tests

Ton travail
Implémente vec.c. Pour vec_push, la capacité double quand le tableau est plein (commence à 4, par exemple).
Utilise realloc avec un pointeur temporaire, pour répondre à ta Q6 par la pratique.
make test doit afficher OK sans aucun warning ni erreur d’ASan.
