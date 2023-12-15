#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[0;34m"

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t		ft_read(int fd, const void *buf, size_t nbyte);
char		*ft_strdup(const char *str);

#endif
