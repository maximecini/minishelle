/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_env_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:09:19 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 14:38:43 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Compare les clés de deux noeuds d'environnement.
**
** Paramètres :
**  - a : pointeur vers un t_node_env
**  - b : pointeur vers un autre t_node_env
**
** Retour :
**  - résultat de strcmp entre les clés
**  - 0 si l’un des pointeurs est NULL ou si les clés sont NULL
*/
int	cmp_key(void *a, void *b)
{
	t_node_env	*env_a;
	t_node_env	*env_b;

	env_a = (t_node_env *)a;
	env_b = (t_node_env *)b;
	if (!env_a || !env_b)
		return (0);
	if (!env_a->key || !env_b->key)
		return (0);
	return (ft_strcmp(env_a->key, env_b->key));
}

/*
** Ajoute un nouveau noeud environnement (`t_node_env`) à la liste `lst_env`.
** Le noeud est construit à partir de la chaîne `cmd`, avec un flag `add`.
**
** Paramètres :
**  - lst_env : pointeur vers la liste chaînée d'environnement
**  - cmd     : chaîne de la forme "KEY=VALUE"
**  - add     : entier indiquant un flag (usage interne)
**
** Retour :
**  - 0 en cas de succès
**  - 0 en cas d’erreur d’allocation (à améliorer,
	typiquement 1 ou autre code d’erreur)
*/
int	add_back_nodes_env(t_element **lst_env, char *cmd, int add)
{
	t_node_env	*node_env;
	t_element	*new_node;
	char		*trimmed_value;

	node_env = malloc(sizeof(t_node_env));
	if (!node_env)
		return (0);
	node_env->key = get_key(cmd);
	node_env->value = get_value(cmd);
	if (node_env->value)
	{
		trimmed_value = ft_strtrim(node_env->value, " \t\n\r\f\v");
		if (trimmed_value)
		{
			free(node_env->value);
			node_env->value = trimmed_value;
		}
	}
	node_env->add = add;
	new_node = ft_lstnew(node_env);
	if (!new_node)
		return (free(node_env), (0));
	ft_lstadd_back(lst_env, new_node);
	return (0);
}
