/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:45:37 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/31 19:45:35 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

/*
** Vérifie la validité de la clé `key` pour une commande export.
** La clé ne doit pas commencer par un chiffre ni se terminer par '$',
** et ne doit contenir que des caractères alphanumériques ou '_'.
** En cas d'erreur, affiche un message, libère `key` et retourne 1.
**
** Paramètres :
**  - cmd     : commande export complète (pour affichage d'erreur)
**  - key     : clé extraite de la commande
**  - siz_key : taille de la clé
**
** Retour :
**  - 1 si la clé est invalide
**  - 0 sinon
*/
int	export_no_valide(char *cmd, char *key, size_t siz_key)
{
	int	i;

	if (ft_isdigit(key[0]) || key[siz_key - 1] == '$')
	{
		print_syntax_error_export(cmd, EXPORT_NO_VALID);
		free(key);
		return (1);
	}
	i = 0;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			print_syntax_error_export(cmd, EXPORT_NO_VALID);
			free(key);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Analyse la commande `cmd` pour vérifier la validité de la clé
** utilisée dans un export. Retourne 1 en cas d'erreur.
**
** Paramètre :
**  - cmd : chaîne de commande export, typiquement "KEY=VALUE"
**
** Retour :
**  - 0 si tout est valide
**  - 1 si une erreur de syntaxe est détectée
*/
int	get_error_export(char *cmd)
{
	char	*key;
	size_t	siz_key;

	if (!cmd || !cmd[0])
		return (0);
	key = get_key(cmd);
	if (!key || !key[0])
		return (free(key), (print_syntax_error_export(cmd, EXPORT_NO_VALID),
				1));
	siz_key = ft_strlen(key);
	if (export_no_valide(cmd, key, siz_key))
		return (1);
	free(key);
	return (0);
}

/*
** Copie un tableau de chaînes `env` dans une liste chaînée `lst_env`
** en ajoutant chaque élément avec `add_back_nodes_env`.
**
** Paramètres :
**  - lst_env : adresse du pointeur vers la liste chaînée à remplir
**  - env     : tableau de chaînes à copier
**
** Retour :
**  - 1 toujours (à améliorer si gestion d'erreurs)
*/
int	cpy_tab_to_lst(t_element **lst_env, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		add_back_nodes_env(lst_env, env[i], 0);
		i++;
	}
	return (1);
}

/*
** Recherche dans la liste chaînée `lst_env` le noeud dont la clé
** correspond à `key`. Retourne un pointeur vers le pointeur du noeud.
**
** Paramètres :
**  - lst_env : liste chaînée d’environnement
**  - key     : clé recherchée
**
** Retour :
**  - adresse du pointeur vers l'élément correspondant
**  - NULL si non trouvé ou erreur
*/
t_element	**get_lst_key(t_element **lst_env, char *key)
{
	t_node_env	*node;

	if (!key || !lst_env)
		return (NULL);
	while (*lst_env)
	{
		node = (t_node_env *)(*lst_env)->content;
		if (node->key && !ft_strcmp(node->key, key))
			return (lst_env);
		lst_env = &(*lst_env)->next;
	}
	return (NULL);
}

/*
** Met à jour la valeur du noeud environnement identifié par `key`
** dans la liste `lst_env`. La nouvelle valeur peut être NULL ou vide.
**
** Paramètres :
**  - lst_env   : liste chaînée d’environnement
**  - key       : clé du noeud à mettre à jour
**  - new_value : nouvelle valeur à affecter (peut être NULL)
**  - equal     : présence éventuelle du signe '=' dans la commande
**
** Retour :
**  - 0 en cas de succès
**  - -1 en cas d’erreur (clé non trouvée, échec allocation)
*/
int	update_nodes_env(t_element *lst_env, char *key, char *new_value,
		char *equal)
{
	t_element	**target;
	t_node_env	*node;
	char		*dup_value;
	char		*trimmed_value;

	dup_value = NULL;
	target = get_lst_key(&lst_env, key);
	if (!target || !*target || !(*target)->content)
		return (-1);
	node = (t_node_env *)(*target)->content;
	if (new_value)
	{
		trimmed_value = ft_strtrim(new_value, " \t\n\r\f\v");
		if (!trimmed_value)
			return (-1);
		dup_value = trimmed_value;
	}
	else if (equal)
		dup_value = ft_strdup("");
	if (!dup_value)
		return (-1);
	free(node->value);
	node->value = dup_value;
	return (0);
}
