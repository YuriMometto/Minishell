/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 07:13:16 by ymometto          #+#    #+#             */
/*   Updated: 2024/06/04 07:15:37 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	uptade_insert_env(char *exp, char *value)
{
	char	**env;
	char	**new_env;
	char	*cat;
	int		check;
	int		i;

	i = -1;
	check = 0;
	env = static_env(NULL, 0);
	if (catch_env(exp))
		check = 1;
	new_env = malloc(sizeof(char **) * (ft_arrlen(env)) + 1);
	if (!new_env)
		return (1);
	while (env[++i])
	{
		if (check && ft_strncmp(env[i], exp, ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '='))))
		{
			cat = ft_strjoin(exp, "=");
			new_env[i] = ft_join_free(cat, value);
		}
		else
			new_env[i] = env[i];
	}
	if (!check)
	{
		cat = ft_strjoin(exp, "=");
		new_env[i++] = ft_join_free(cat, value);
	}
	new_env[i] = NULL;
	static_env(new_env, 0);
	return (0);
}
