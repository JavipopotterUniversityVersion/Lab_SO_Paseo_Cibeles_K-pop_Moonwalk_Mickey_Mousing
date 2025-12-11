#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char *argv[]) {
  unsigned int id;

  struct utsname *info;
  int s = uname(info);
  
  if(!s) {
    printf("Papeado");
    return s;
  }

  printf("Nombre SO: %s\n", info->sysname);
  printf("Version SO: %s\n", info->version);
  printf("Nombre host: %s\n", info->machine);

  /* Gestionar el error de open */
  return 0;
}
