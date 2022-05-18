// Fork System Call
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main(void) {
  pid_t pid = fork();
 
  if(pid == 0) {
    printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
    exit(EXIT_SUCCESS);
  }
  else if(pid > 0) {
    printf("Parent => PID: %d\n", getpid());
    printf("Waiting for child process to finish.\n");
    wait(NULL);
    printf("Child process finished.\n");
  }
  else {
    printf("Unable to create child process.\n");
  }
 
  return EXIT_SUCCESS;
}

// Sleep System Call

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main() {
pid_t forkStatus;

forkStatus = fork();

/* Child... */
if        (forkStatus == 0) {
printf("Child is running, processing.\n");
sleep(5);
printf("Child is done, exiting.\n");

/* Parent... */
} else if (forkStatus != -1) {
printf("Parent is waiting...\n");

wait(NULL);
printf("Parent is exiting...\n");

} else {
perror("Error while calling the fork function");

}

return 0;

}