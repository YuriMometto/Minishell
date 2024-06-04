#include "minishell.h"

int ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int unset_search(char **env, char **find)
{
	int i;
	int counter;
	int	j;

	counter = 0;
	i = -1;
	while (env[++i])
	{
		j = -1;
		while (find[++j])
		{
			if (!ft_strncmp(env[i], find[j], ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '='))))
			{
				counter++;
				break;
			}
		}
	}
	return (counter);
}

void unset_run(char **token, char **env, char **new_env, int i, int j)
{
	int	k;
	int check;

	k = 0;
	check = 0;
	while (env[++i])
	{
		j = 0;
		check = 0;
		while (token[++j])
		{
			if (!ft_strncmp(env[i], token[j], ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '='))))
			{
				check = 1;
				break;
			}
		}
		if (!check)
			new_env[k++] = ft_strdup(env[i]);
	}
	new_env[k] = '\0';
}

int unset_cmd(char **token)
{
	int find;
	char **new_env;
	char **env;
	int	i;
	int j;

	i = -1;
	j = 0;
	env = static_env(NULL, 0);
	find = unset_search(env, token + 1);
	if (!find)
		return (1);
	new_env = malloc(sizeof(char *) * (ft_arrlen(env) - find) + 1);
	unset_run(token, env, new_env, i, j);
	static_env(new_env, 0);
	return (1);
}