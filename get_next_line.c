/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:49:34 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/08 14:17:23 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 42

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

    if (!s)
        return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			break ;
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static int	ft_fill_s1(char *s1, char *ret)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = malloc(i + j + 1);
	if (!ret)
		return (NULL);
	i = ft_fill_s1((char *)s1, ret);
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
    free(s1);
	return (ret);
}


char    *get_first_part(char *str)
{
    int     i = 0;
    char    *temp;

    if (!str || !str[0])
        return (NULL);

    while (str[i] && str[i] != '\n')
        i++;

    temp = malloc(i + 2);
    if (!temp)
        return (NULL);

    i = 0;
    while (str[i] && str[i] != '\n')
    {
        temp[i] = str[i];
        i++;
    }

    if (str[i] == '\n')
    {
        temp[i] = '\n';
        i++;
    }

    temp[i] = '\0';
    return (temp);
}


char    *get_second_part(char *str)
{
    int     i = 0;
    int     j = 0;
    char    *temp;

    if (!str)
        return (NULL);

    while (str[i] && str[i] != '\n')
        i++;

    if (!str[i])
    {
        free(str);
        return (NULL);
    }

    i++;

    j = 0;
    while (str[i + j])
        j++;

    temp = malloc(j + 1);
    if (!temp)
        return (NULL);

    j = 0;
    while (str[i])
    {
        temp[j] = str[i];
        j++;
        i++;
    }
    temp[j] = '\0';

    free(str);
    return (temp);
}


char *get_next_line(int fd)
{
    static char *str;
    char    *line;
    char    *temp;
    int bytes;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    if (!str)
        str = fr_strup("");
    temp = malloc(BUFFER_SIZE + 1);
    if (!temp)
        return (NULL);
    bytes = 1;
    while (bytes > 0 && !ft_strchr(str, '\n'))
    {
        bytes = read(fd, temp, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(temp);
            return (NULL);
        }
        temp[bytes] = '\0';
        str = ft_strjoin(str, temp);
    }
    free(temp);
    line = get_first_part(str);
    str = get_second_part(str);
    return (line);
}

int main(void)
{
    int fd = open("test_file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // line already has '\n' if it exists
        free(line);
    }

    close(fd);
    return 0;
}
