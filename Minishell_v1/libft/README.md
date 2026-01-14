
# **Libft - Une Bibliothèque C Personnalisée**

## **Description**
Le projet **Libft** consiste à réimplémenter des fonctions standard de la bibliothèque C et à ajouter des fonctionnalités supplémentaires. Cette bibliothèque personnalisée est conçue pour être réutilisable dans vos futurs projets en C. L'objectif est de comprendre en profondeur ces fonctions et leur fonctionnement interne, tout en respectant les bonnes pratiques de programmation.

---

## **Fonctionnalités Principales**

### **Partie 1 - Fonctions de la libc**
Ces fonctions ont été recodées pour reproduire le comportement de leurs équivalents standards :
- **Vérifications de caractères** : `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `ft_islowercase`,`ft_istouppercase`.
- **Manipulation de chaînes** : `strlen`, `strlcpy`, `strlcat`.
- **Manipulation de mémoire** : `memset`, `bzero`, `memcpy`, `memmove`.
- **Autres utilitaires** : `toupper`, `tolower`, `strchr`, `strrchr`, `strncmp`, `memchr`, `memcmp`, `strnstr`, `atoi`.
- **Fonctions utilisant `malloc`** : `calloc`, `strdup`.

### **Partie 2 - Fonctions supplémentaires**
Ajout de nouvelles fonctions utiles, comme :
- Manipulation de chaînes : `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`.
- Iteration et transformation : `ft_strmapi`, `ft_striteri`.
- Écriture sur fichiers : `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.
- Manipulation des chiffres  : `ft_putnbr_base`, `ft_base_power`, `ft_digitlen` .

### **Partie Bonus - Manipulation de listes**
Ajout de fonctions pour travailler avec des listes chaînées :
- Création et ajout : `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`.
- Manipulation : `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

---

## **Installation**

### **Prérequis**
- Un compilateur C (comme GCC).
- Utilitaire `make`.

### **Étapes**
1. Clonez le dépôt Git :
   ```bash
   git clone https://github.com/maximecini/libft.git
   cd libft
   ```

2. Compilez la bibliothèque avec Make :
   ```bash
   make
   ```

3. Une bibliothèque statique nommée `libft.a` sera générée.

---

## **Utilisation**

1. **Incluez la bibliothèque** dans votre projet :
   ```c
   #include "libft.h"
   ```

2. **Compilez le projet** avec `libft.a` :
   ```bash
   #gcc -Wall -Wextra -Werror main.c -L. -lft
   ```

3. **Exécutez votre programme** :
   ```bash
   ./votre_programme
   ```

---

## **Structure du Projet**

```
/libft
├── src/          # Fichiers source des fonctions
├── include/      # Fichiers d'en-tête
│   └── libft.h
├── lib/          # Contient la bibliothèque statique générée
│   └── libft.a
├── bonus/        # Fonctions bonus
├── Makefile      # Automatisation de la compilation
└── README.md     # Documentation
```

---

## **Règles**
- **Norme** : Le code doit respecter les règles strictes de la norme C définie par le projet.
- **Tests** : Les tests sont fortement conseillés mais non requis dans la soumission.
- **Mémoire** : Toute mémoire allouée doit être libérée correctement, aucun "leak" ne sera toléré.
- **Makefile** : Doit inclure les règles standards (`all`, `clean`, `fclean`, `re`) et ne pas relinker.

---

## **Contribution**
Les contributions sont bienvenues ! Voici comment proposer une amélioration :
1. **Forkez** le dépôt.
2. **Créez une branche** pour vos modifications :
   ```bash
   git checkout -b ma-branche
   ```
3. **Apportez vos modifications** et commitez-les :
   ```bash
   git commit -m "Ajout de nouvelles fonctionnalités"
   ```
4. **Poussez vos modifications** :
   ```bash
   git push origin ma-branche
   ```
5. **Créez une Pull Request**.


## **Contact**
Pour toute question ou suggestion, contactez :
- **Email** : maximecini@gmail.com
- **GitHub** : [maximecini](https://github.com/maximecini)

---
