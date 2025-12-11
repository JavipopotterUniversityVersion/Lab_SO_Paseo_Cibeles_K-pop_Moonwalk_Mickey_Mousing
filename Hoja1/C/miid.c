#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  unsigned int id;
  if (argc == 1) {
    id = getuid();
  } else {
    id = atoi(argv[1]);
  }
  struct passwd *info = getpwuid(id);
  if (!info) {
    perror("Error using getpwuid");
    return errno;
  }

  printf("Nombre de usuario: %s\n", info->pw_name);
  printf("ID de usuario: %i, ", info->pw_uid);
  printf("grupo: %i\n", info->pw_gid);
  printf("Directorio home: %s\n", info->pw_dir);

  /* Gestionar el error de open */
  return 0;
}
