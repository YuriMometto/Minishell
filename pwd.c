#include "minishell.h"

void	pwd_cmd(void)
{
	char	*pwd;

	pwd = env_value("PWD");
	if (!pwd)
		return ;
	printf("%s\n", pwd);
}