#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  pid = fork();


  switch (pid) {
    case -1:
      perror("fork:");
      break;

    case 0:
      execvp(argv[1], &argv[1]);
      break;
  
   default:
      int status;
      pid_t terminate = waitpid(pid, &status, WUNTRACED);

      if(terminate == -1) printf("Child was papped"); 
      else if (WIFEXITED(status)) printf("Child terminated with exit code %i", WEXITSTATUS(status));
      else printf("Child is not a valid process");
      break;
  }
}
