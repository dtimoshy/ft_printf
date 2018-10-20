
#include "../inc/ft_printf.h"

static int	count_bytes(wchar_t val)
{
	int res;
	int temp;

	temp = (int)val;
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

char		*wchar_get(wchar_t val)
{
	char	*ret;
	int		bytes;

	if (val == 0)
		return (ft_strdup("\0"));
	bytes = count_bytes(val);
	ret = ft_memalloc(bytes + 1);
	if (bytes == 1)
		ret[0] = (char)val;
	else
		ret[0] = (char)(((val) & 63) + 128);
	if (bytes == 2)
		ret[1] = (char)((val >> 6) + 192);
	else if (bytes == 3)
	{
		ret[1] = (char)(((val >> 6) & 63) + 128);
		ret[2] = (char)((val >> 12) + 224);
	}
	else if (bytes == 4)
	{
		ret[1] = (char)(((val >> 6) & 63) + 128);
		ret[2] = (char)(((val >> 12) & 63) + 128);
		ret[3] = (char)((val >> 18) + 240);
	}
	return (ft_strrev((char *)ret));
}

static char		*joinstr(char *s1, char *s2)
{
	char 	*result;
	size_t	temp;

	temp = ft_strlen(s1) + ft_strlen(s2);
	if ((result = ft_strnew(temp)))
	{
		result = ft_strcat(result, s1);
		result = ft_strcat(result, s2);
	}
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (result);
}

char		*wstr_get(wchar_t *val, int prec)
{
	char *res;
	char *wchar;

	if (val == NULL)
		return (ft_strdup("(null)"));
	res = ft_strnew(0);
	while (*val)
	{
		wchar = wchar_get(*val);
		if (prec != -1 && prec < (int)(ft_strlen(wchar) + ft_strlen(res)))
		{
			ft_strdel(&wchar);
			return (res);
		}
		if (!(res && wchar))
			res = NULL;
		res = joinstr(res, wchar);
		val++;
	}
	return (res);
}
