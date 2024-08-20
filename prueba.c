#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv, char **env) 
{

	int i;
	i = 0;
	char *path;

	while(env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
		{
			path = &env[i][5];
		}
		i++;
	}
	char **paths = ft_split(path, ":");
	

	printf("%s\n", env[i]);
	return (0);
	
	
	
	/*int pid;
	pid = fork();

	printf("Hola mundo\n");
	if (pid == 0) 
	{
		printf("Soy el hijo\n");
		excve("/bin/ls", argv, envp);
	} 
	else 
	{
		printf("Soy el padre\n");
	}
	return (0);*/
}