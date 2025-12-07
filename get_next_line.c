/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:25:50 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/06 14:39:48 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *get_next_line(int fd)
{
	static char *str;
	char *temp;

	if (fd < 0 || BUFFER_size <= 0)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	
}
