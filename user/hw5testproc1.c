#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  for(int i = 0; i < 30; i++) {
    int fd = open("junk", O_CREATE|O_WRONLY);
    if(fd < 0) {
      printf("open junk failed\n");
      exit(1);
    }

    for (int j = 0; j < 100; j++)
      write(fd, (char*)0xffffffffffL, 1);

    close(fd);
  }
  printf("finished testproc1\n");
  exit(0);
}