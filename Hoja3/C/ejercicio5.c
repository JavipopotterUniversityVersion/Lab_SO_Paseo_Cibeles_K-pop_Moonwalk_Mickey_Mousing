#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  pid_t pid = fork();
  
  switch (pid) {
    case -1:
      perror("fork:");
      break;

    case 0:
      printf("I am the child, PID: %i, PPID: %i, PGID: %i, SID: %i", pid, getppid(), getpgid(pid), getsid(pid));
      sleep((int)*argv[2]);
      break;
  
   default:
      printf("I am the parent, PID: %i, PPID: %i, PGID: %i, SID: %i", pid, getppid(), getpgid(pid), getsid(pid));
      sleep((int)*argv[1]);
      break;
}
  return 0;
}
