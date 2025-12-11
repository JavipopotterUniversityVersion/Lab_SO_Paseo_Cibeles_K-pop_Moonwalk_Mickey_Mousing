#include <errno.h>
#include <fcntl.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Program needs an argument");
    return 42;
  }

  struct stat buf;
  int fd = stat(argv[1], &buf);

  if(fd < 0) {
    perror("Error using stat");
    return errno;
  }

  printf("Inode: %i\n", buf.st_ino);
  printf("Dev: %i\n", buf.st_dev);

  printf("Filetype: ");
  if(S_ISDIR(buf.st_mode)) {
    printf("directory");
  }
  else if(S_ISREG(buf.st_mode)) {
    printf("regular file");
  }
  else if(S_ISLNK(buf.st_mode)) {
    printf("sym-zelda");
  }

  return 0;
}
