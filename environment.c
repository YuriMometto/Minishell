#include "minishell.h"

char *catch_env(char *find)
{
        int i;
        char **env;

        env = static_env(NULL, 0);
        i = -1;
        while (env[++i])
        {
                if (!ft_strncmp(env[i], find, ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '='))))
                        return (env[i]);
        }
        return (NULL);
}

char *env_value(char *find)
{
        char *env;

        env = catch_env(find);
        if (!env)
                return (NULL);
        return (env + ft_strlen(find) + 1);
}

char **static_env(char **new_envp, int clear)
{
        //| Static para poder acessar em outras partes do programa.
        static char **env;

        //| Caso tenha um novo ENV, limpa o antigo.
        if (new_envp && env)
                free_matrix(&env);
        //| Atualiza o antigo ENV para o novo.
        if (new_envp)
                env = new_envp;
        //| Caso precise limpar o ENV.
        if (env && clear)
                free_matrix(&env);
        return (env);
}

void start_env(char **envp)
{
        int i;
        char **new_envp;

        i = 0;
        while (envp[i])
                i++;
        new_envp = malloc(sizeof(char *) * (i + 1));
        i = -1;
        while (envp[++i])
                new_envp[i] = ft_strdup(envp[i]);
        new_envp[i] = NULL;
        static_env(new_envp, NOFREE);
}