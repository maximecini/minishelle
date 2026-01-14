/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:39:36 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:22:36 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	ft_array_len(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

/*
** Affiche la liste chaînée d'environnement `lst_env`
** au format de la commande `export` shell.
**
** Exemple de sortie : export KEY="VALUE"
**
** Paramètre :
**  - lst_env : liste chaînée contenant des noeuds t_env
*/
void	print_lst_env(t_list *lst_env)
{
	t_env	*node_env;

	while (lst_env)
	{
		node_env = (t_env *)lst_env->content;
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
void	ft_sort_lst(t_list *head, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*next_node;
	void	*temp_content;

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
