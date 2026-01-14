/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:06:50 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:19:43 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/*
** Compare les clés de deux noeuds d'environnement.
**
** Paramètres :
**  - a : pointeur vers un t_env
**  - b : pointeur vers un autre t_env
**
** Retour :
**  - résultat de strcmp entre les clés
**  - 0 si l’un des pointeurs est NULL ou si les clés sont NULL
*/
int	cmp_key(void *a, void *b)
{
	t_env	*env_a;
	t_env	*env_b;

	env_a = (t_env *)a;
	env_b = (t_env *)b;
	if (!env_a || !env_b)
		return (0);
	if (!env_a->key || !env_b->key)
		return (0);
	return (ft_strcmp(env_a->key, env_b->key));
}

/*
** Ajoute un nouveau noeud environnement (`t_env`) à la liste `lst_env`.
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
static int	prepare_value(t_env *node_env)
{
	char	*trimmed_value;

	if (!node_env->value)
		return (1);
	trimmed_value = ft_strtrim(node_env->value, " \t\n\r\f\v");
	free(node_env->value);
	if (!trimmed_value)
	{
		free(node_env->key);
		free(node_env);
		return (0);
	}
	node_env->value = trimmed_value;
	return (1);
}

static t_env	*create_env_node(char *cmd, int add)
{
	t_env	*node_env;

	node_env = malloc(sizeof(t_env));
	if (!node_env)
		return (NULL);
	node_env->key = get_key(cmd);
	if (!node_env->key)
	{
		free(node_env);
		return (NULL);
	}
	node_env->value = get_value(cmd);
	if (!prepare_value(node_env))
		return (NULL);
	node_env->add = add;
	return (node_env);
}

static int	append_env_node(t_list **lst_env, t_env *node_env)
{
	t_list	*new_node;

	new_node = ft_lstnew(node_env);
	if (!new_node)
	{
		free(node_env->key);
		if (node_env->value)
			free(node_env->value);
		free(node_env);
		return (0);
	}
	ft_lstadd_back(lst_env, new_node);
	return (1);
}

int	add_back_nodes_env(t_list **lst_env, char *cmd, int add)
{
	t_env	*node_env;

	node_env = create_env_node(cmd, add);
	if (!node_env)
		return (0);
	if (!append_env_node(lst_env, node_env))
		return (0);
	return (0);
}
