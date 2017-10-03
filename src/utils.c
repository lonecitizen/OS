#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	*argv = (char**)malloc(8096);
	*argc = 0;
	(*argv)[*argc] = strtok(command, " \n");

	while((*argv)[*argc] != NULL)
	{
		(*argc)++;
		(*argv)[*argc] = strtok(NULL, " \n");
	}
  // TODO: Fill this!
}
