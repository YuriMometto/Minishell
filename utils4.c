#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int 	i;
	int 	j;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (*s1)
			str[i++] = *s1++;
	}
	j = -1;
	if (s2)
	{
		while (s2[++j])
			str[i + j] = s2[j];
	}
	str[i + j] = '\0';
	return (str);
}