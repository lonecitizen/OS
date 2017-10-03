#include <string.h>
#include <stdio.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  if (chdir(argv[1]) < 0)
    return -1;// TODO: Fill it!
 
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char Buf[512];
  getcwd(Buf, 512);
  printf("%s\n", Buf);

  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc == 2 && strcmp(argv[0], "cd") == 0)
    return 1;
  else return 0;// TODO: Fill it!
}

int validate_pwd_argv(int argc, char** argv) {
  if (argc == 1 && strcmp(argv[0], "pwd") == 0)
  	return 1;
  else return 0;  // TODO: Fill it!
}
