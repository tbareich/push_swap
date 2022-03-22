/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:00:16 by tbareich          #+#    #+#             */
/*   Updated: 2019/09/26 12:33:30 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	error_handler(t_bst *root, int fd, char **line)
{
	ft_strdel(line);
	bst_deletenode(root, fd);
	return (-1);
}

static int	reading_error_handler(char **line, int read_size, char **endl)
{
	if (**line == 0 || read_size < 0)
	{
		if (read_size == 0)
		{
			ft_strdel(line);
			return (0);
		}
		return (-1);
	}
	if (*endl)
		*(*endl)++ = 0;
	return (1);
}

static int	readline(const int fd, char **line, t_bst *root, char **endl)
{
	char			buf[BUFF_SIZE + 1];
	int				read_size;

	read_size = 0;
	*endl = ft_strchr(*line, '\n');
	if (*endl == NULL)
		read_size = read(fd, buf, BUFF_SIZE);
	while (*endl == NULL && read_size > 0)
	{
		buf[read_size] = 0;
		*line = ft_strjoin_free(*line, buf, 1);
		if (*line == NULL)
			return (error_handler(root, fd, line));
		*endl = ft_strchr(*line, '\n');
		if (*endl == NULL)
			read_size = read(fd, buf, BUFF_SIZE);
	}
	return (reading_error_handler(line, read_size, endl));
}

static int	file_search(int fd, t_bst **root, char **line, t_bst **node)
{
	*node = bst_find(*root, fd);
	if (*node != NULL)
	{
		*line = ft_strjoin_free(*line, (*node)->content, 1);
		if (*line == NULL)
			return (-1);
		return (1);
	}
	else
	{
		*node = bst_newnode(fd, NULL, 0);
		if (*node == NULL)
			return (-1);
		*root = bst_insert(*root, *node);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_bst	*root;
	int				is_read;
	char			*endl;
	t_bst			*node;

	*line = ft_strnew(0);
	if (line == NULL || fd < 0 || *line == NULL)
		return (error_handler(root, fd, line));
	if (file_search(fd, &root, line, &node) < 0)
		return (error_handler(root, fd, line));
	is_read = readline(fd, line, root, &endl);
	if (is_read < 0)
		return (error_handler(root, fd, line));
	else if (is_read == 0)
		return (0);
	if (endl || bst_modify_addr(node, NULL, 0))
		if (bst_modify_addr(node, endl, ft_strlen(endl) + 1) < 0)
			return (error_handler(root, fd, line));
	*line = ft_strdup_free(line);
	if (*line == NULL)
		return (error_handler(root, fd, line));
	return (1);
}
