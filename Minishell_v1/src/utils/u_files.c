/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_files.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:27:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 15:36:46 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <errno.h>
#include <string.h>

/*
** Ouvre un fichier en écriture, avec création et troncature.
**
** Paramètres :
**  - filename : nom du fichier à ouvrir
**  - access   : mode d’accès (permissions) du fichier créé
**
** Retour :
**  - descripteur de fichier en cas de succès (>= 0)
**  - 1 en cas d’erreur, et affiche un message d’erreur via perror
*/

int	open_file_wtc(char *filename, int access)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, access);
	if (fd < 0)
	{
		perror("heredoc: open");
		return (1);
	}
	return (fd);
}

/*
** Ouvre un fichier, le duplique sur le fd donné, et ferme.
** Quitte le programme en cas d’erreur.
*/
int	open_and_redirect(const char *filename, int flags, int dup_fd,
		const char *err_ctx)
{
	int	file;

	file = open(filename, flags, 0644);
	if (file == -1)
	{
		perror(filename);
		return (1);
	}
	if (dup2(file, dup_fd) == -1)
	{
		perror(err_ctx);
		return (1);
	}
	close(file);
	return (0);
}

int	get_infile(t_exec *exec, t_redirect *redirect)
{
	exec->error = acces_file(redirect->filename);
	if (exec->error)
		return (error_file(exec->error, redirect->filename), 0);
	redirect->file = open(redirect->filename, O_RDONLY);
	if (redirect->file == -1)
	{
		perror(redirect->filename);
		return (0);
	}
	if (dup2(redirect->file, STDIN_FILENO) == -1)
	{
		perror("dup2 stdin");
		close(redirect->file);
		return (0);
	}
	close(redirect->file);
	return (1);
}

char	*create_temp_filename(void)
{
	static int	counter = 0;
	char		*temp_name;
	char		*counter_str;

	counter_str = ft_itoa(counter);
	if (!counter_str)
		return (NULL);
	counter++;
	temp_name = ft_strjoin("/tmp/heredoc_", counter_str, 0, 1);
	if (!temp_name)
	{
		free(counter_str);
		return (NULL);
	}
	return (temp_name);
}
