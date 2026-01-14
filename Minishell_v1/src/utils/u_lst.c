/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_lst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:45:42 by thodavid          #+#    #+#             */
/*   Updated: 2025/07/26 19:47:53 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

/*
** Affiche la liste chaînée d'environnement `lst_env`
** au format de la commande `export` shell.
**
** Exemple de sortie : export KEY="VALUE"
**
** Paramètre :
**  - lst_env : liste chaînée contenant des noeuds t_node_env
*/
void	print_lst_env(t_element *lst_env)
{
	t_node_env	*node_env;

	while (lst_env)
	{
		node_env = (t_node_env *)lst_env->content;
		printf("export %s", node_env->key);
		if (node_env->value)
			printf("=");
		if (node_env->value)
			printf("\"%s\"", node_env->value);
		printf("\n");
		lst_env = lst_env->next;
	}
}

/*
** Trie une liste chaînée `head` en place selon une fonction de.
**  comparaison `cmp` Le tri est un tri par échange simple
**  (bubble sort-like) des contenus.
** Paramètres :
**  - head : tête de la liste à trier
**  - cmp  : fonction de comparaison retournant >0 si premier élément > second
** Remarque :
**  - Le tri se fait uniquement en échangeant le contenu des noeuds,
**    pas les pointeurs de la liste.
**  - Les `printf` sont probablement des traces de debug à retirer.
*/
void	ft_sort_lst(t_element *head, int (*cmp)(void *, void *))
{
	t_element	*current;
	t_element	*next_node;
	void		*temp_content;

	if (!head || !cmp)
		return ;
	current = head;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (cmp(current->content, next_node->content) > 0)
			{
				temp_content = current->content;
				current->content = next_node->content;
				next_node->content = temp_content;
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}

int	count_lst(t_element *lst_cmd)
{
	int	i;

	i = 0;
	while (lst_cmd)
	{
		i++;
		lst_cmd = lst_cmd->next;
	}
	return (i);
}

int	count_lst_valide(t_element *lst_cmd)
{
	int			i;
	int			nb;
	t_node_env	*node_env;

	i = 0;
	nb = 0;
	while (lst_cmd)
	{
		node_env = (t_node_env *)lst_cmd->content;
		if (node_env->value)
			nb++;
		i++;
		lst_cmd = lst_cmd->next;
	}
	return (nb);
}
