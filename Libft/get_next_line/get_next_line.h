/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:05:40 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/25 17:19:15 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../libft.h"

size_t	ft_strlen_m(char *str);
char	*ft_substr_m(char *str, int start, int end);
char	*ft_newline(char *str, int index);
int		ft_strchr_m(char *str, char c);
void	ft_free(char *str);
char	*get_next_line(int fd);

#endif
