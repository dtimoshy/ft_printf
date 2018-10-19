
#include "../inc/ft_printf.h"

static int	wchar_bytes(wchar_t value)
{
	int res;
	int temp;

	temp = (int)value;
	if (temp == 0)
		return (1);
	res = 0;
	while (temp)
	{
		temp /= 2;
		res++;
	}
	if (res > 16 && MB_CUR_MAX >= 4)
		return (4);
	else if (res > 11 && res <= 16 && MB_CUR_MAX >= 3)
		return (3);
	else if(res > 7 && res <= 11 && MB_CUR_MAX >= 2)
		return (2);
	else
		return (1);
}

char		*get_wchar(wchar_t value)
{
	char	*ret;
	int		bytes;

	if (value == 0)
		return (ft_strdup("\0"));
	bytes = wchar_bytes(value);
	ret = ft_memalloc(bytes + 1);
	if (bytes == 1)
		ret[0] = (char)value;
	else
		ret[0] = (char)(((value) & 63) + 128);
	if (bytes == 2)
		ret[1] = (char)((value >> 6) + 192);
	else if (bytes == 3)
	{
		ret[1] = (char)(((value >> 6) & 63) + 128);
		ret[2] = (char)((value >> 12) + 224);
	}
	else if (bytes == 4)
	{
		ret[1] = (char)(((value >> 6) & 63) + 128);
		ret[2] = (char)(((value >> 12) & 63) + 128);
		ret[3] = (char)((value >> 18) + 240);
	}
	return (ft_strrev((char *)ret));
}

char		*printf_strjoin(char *s1, char *s2)
{
	char *ret;

	if (!(s1 && s2))
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ret = ft_strcat(ft_strcat(ret, s1), s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}

char		*get_wstr(wchar_t *value, int prec)
{
	char *res;
	char *wchar;

	if (value == NULL)
		return (ft_strdup("(null)"));
	res = ft_strnew(0);
	while (*value)
	{
		wchar = get_wchar(*value);
		if (prec != -1 && prec < (int)(ft_strlen(wchar) + ft_strlen(res)))
		{
			ft_strdel(&wchar);
			return (res);
		}
		res = printf_strjoin(res, wchar);
		value++;
	}
	return (res);
}
