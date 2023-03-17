/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:46:12 by ncornacc      #+#    #+#                 */
/*   Updated: 2023/01/17 15:52:48 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_next_line(char *buff)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		buff[0] = '\0';
		return ;
	}
	i++;
	while (buff[i])
	{
		buff[k] = buff[i];
		k++;
		i++;
	}
	buff[k] = '\0';
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (free(buff), NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(buff), NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	free(buff);
	return (line);
}

char	*file_read(int fd, char *buffer, char *line)
{
	int		n_byte;

	if (*buffer != '\0')
		line = ft_strjoin(line, buffer);
	if (!line)
		return (0);
	n_byte = 1;
	if (ft_strchr(buffer, '\n'))
		return (line);
	while (n_byte > 0)
	{
		n_byte = read(fd, buffer, BUFFER_SIZE);
		if (n_byte == -1)
			return (free(line), NULL);
		buffer[n_byte] = 0;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer[0] = '\0';
		return (0);
	}
	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	line = file_read(fd, buffer, line);
	if (!line)
	{
		buffer[0] = '\0';
		return (0);
	}
	line = ft_get_line(line);
	if (!line)
	{
		buffer[0] = '\0';
		return (0);
	}
	ft_next_line(buffer);
	return (line);
}
/* #include <stdio.h>
#include <fcntl.h>

int main()
{
    int     test;
    char    *line = 0x1;
    test = open("test.txt", O_RDONLY);
    while (line)
    {
        line = get_next_line(test);
        if (line)
            printf("%s", line);
        free(line);
    }
return (0);
}
*/