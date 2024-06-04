/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 07:16:52 by ymometto          #+#    #+#             */
/*   Updated: 2024/06/04 07:18:35 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_cmd(char **token)
{
	char	*path;
	char	*new_path;
	char	new_pwd[1024];

	if (token[1] && token[2])
		return (1);
	if (!token[1] || token[1][0] == '\0' || ft_strcmp(token[1], "~") == 0)
	{
		if (!env_value("HOME"))
			return (1);
		path = env_value("HOME");
		chdir(path);
	}
	else if (token[1][0] == '~')
	{
		path = env_value("HOME");
		if (path == NULL)
		{
			printf("cd error:%s\n", "HOME is not set");
			return (1);
		}
		new_path = ft_strjoin(path, (token[1] + 1));
		chdir(new_path);
	}
	else
		chdir(token[1]);
	getcwd(new_pwd, sizeof(new_pwd));
	printf("%s\n", new_pwd);
	return (0);
}
