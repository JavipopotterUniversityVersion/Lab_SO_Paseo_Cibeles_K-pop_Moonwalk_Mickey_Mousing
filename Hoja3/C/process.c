#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  gid_t pid = getpid(); 

  printf("PID: %i, PPID: %i, PGID: %i, SID: %i", pid, getppid(), getpgid(pid), getsid(pid));
}
