#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t i = 0;
	while (s[i]) i++;
	return i;
}

static char	*ft_strchr(char *s, char c)
{
	while (*s && *s != c) s++;
	return (*s == c ? s : NULL);
}

/* append n bytes of src to *dst (malloc'd); frees old *dst */
static int	append_n(char **dst, char *src, size_t n)
{
	size_t	l = *dst ? ft_strlen(*dst) : 0;
	char	*tmp = malloc(l + n + 1);
	size_t	i;

	if (!tmp) return 0;
	i = 0; while (i < l) { tmp[i] = (*dst)[i]; i++; }
	i = 0; while (i < n) { tmp[l + i] = src[i]; i++; }
	tmp[l + n] = '\0';
	free(*dst);
	*dst = tmp;
	return 1;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	char		*ret = NULL;
	char		*nl;
	int			r;
	size_t		len;
	size_t		i;

	nl = ft_strchr(buf, '\n');
	while (!nl)
	{
		if (!append_n(&ret, buf, ft_strlen(buf)))
			return (free(ret), NULL);
		buf[0] = '\0';
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(ret), NULL);
		if (r == 0)
			break ;
		buf[r] = '\0';
		nl = ft_strchr(buf, '\n');
	}
	if (nl)
	{
		if (!append_n(&ret, buf, nl - buf + 1))
			return (free(ret), NULL);
		len = ft_strlen(nl + 1);
		i = 0;
		while (i <= len) { buf[i] = nl[1 + i]; i++; }
	}
	else if (!ret || !*ret)
		return (free(ret), NULL);
	return ret;
}
