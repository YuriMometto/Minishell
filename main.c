#include "minishell.h"

char	*user_input(void)
{
	char	*input;

	input = readline("MINISHELL>");
	if (!input)
		input = ft_strdup("exit");
	if (!*input)
		return (input);
	if (ft_strcmp(input, ""))
		add_history(input);
	return (input);
}

void	parser(char *user_input)
{
	//(void)user_input;
	char	**token;
 
	if (!user_input || !*user_input)
		return ;
	token = ft_split(user_input, ' ');
	if (!token || !*token)
		return ;
	controller(token); //| PROVISÓRIO.
	//| Criar uma lista de tokens.
	//| Checar a gramática desses tokens.
	//| Ver se tem algum Heredoc
	//| Construir a árvore.
	//| Executar a árvore.
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != 1)
		return (error_argc());

	//| Start Signals
	start_signals();
	start_env(envp); //| Para pegar o ENV atual, só chamar 'static_env(NULL, NOFREE);'
	//| -> Fazer o 'pwd' com uma static. Para sempre saber aonde estamos.

	//| The While True
	while (1)
		parser(user_input()); //| PARSER: NOT CREATED.

	return (0);
}

/*
	BUILTINS:
- echo (with option '-n')
- cd
- pwd
- export
- unset
- env -> Já dá pra fazer esse porque já temos o ENV estático.
- exit
*/
