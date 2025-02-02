# Get Next Line

Ce projet consiste à créer une fonction qui permet de lire une ligne depuis un descripteur de fichier.

## Description

La fonction `get_next_line` lit une ligne à la fois depuis un descripteur de fichier. Une ligne est une suite de caractères terminée par un retour à la ligne (`\n`) ou par la fin du fichier (EOF).

### Version Standard (get_next_line)
- Gère la lecture depuis un seul descripteur de fichier
- Retourne une ligne à chaque appel
- Gestion de la mémoire optimisée
- Utilisation d'un buffer statique pour conserver les données entre les appels

### Version Bonus (get_next_line_bonus)
- Gère la lecture depuis plusieurs descripteurs de fichiers simultanément
- Peut alterner entre différents descripteurs de fichiers sans perdre le fil de la lecture
- Utilise un buffer statique pour chaque descripteur de fichier
- Parfait pour gérer plusieurs flux de données en parallèle

## Prototype des fonctions

```c
// Version Standard
char *get_next_line(int fd);

// Version Bonus
char *get_next_line_bonus(int fd);
```

## Paramètres

- `fd` : Le descripteur de fichier depuis lequel lire

## Valeur de retour

- La ligne lue : une chaîne de caractères incluant le `\n` sauf pour la dernière ligne
- `NULL` : si la lecture est terminée ou si une erreur survient

## Compilation

```bash
# Version Standard
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Version Bonus
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Utilisation

```c
int fd = open("exemple.txt", O_RDONLY);
char *line;

// Lecture ligne par ligne
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Notes importantes

- La taille du buffer peut être modifiée lors de la compilation via `BUFFER_SIZE`
- La gestion de la mémoire est cruciale : chaque ligne retournée doit être libérée
- Les fonctions gèrent correctement les erreurs de lecture et les cas limites
- Le code respecte la norme de 42