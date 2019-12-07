#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  char *proc[] = {
    "hw5testproc1",
    "hw5testproc2"
  };
  char *emptyargv[] = {0};
  int len = sizeof(proc) / sizeof(proc[0]);

  for (int i = 0; i < len; i++) {
    int pid = fork();
    if (pid < 0) {
      printf("hw5test forking failed i = %d\n", i);
      exit(1);
    }
    else if (pid == 0) {
      printf("forking %s\n", proc[i]);
      exec(proc[i], emptyargv);
    }
  }
  for (int i = 0; i < 1; i++) {
    if(wait(0) < 0){
      printf("hw5test wait failed\n");
      exit(1);
    }
  }

  exit(0);
}