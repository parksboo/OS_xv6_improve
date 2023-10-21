#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int n, pid;
  int k, x, z;
  int child_process = 10; // Create 10 child processes for testing

  x = 0;
  z = 0;
  for (k = 0; k < child_process; k++) {
    pid = fork();
    if (pid < 0) {
      printf(1, "%d failed in fork!\n", getpid());
      exit();
    } else if (pid == 0) {
      // child
      printf(1, "Child %d created\n", getpid());
      for (n = 0; n < 1000.0; n++)
        x = x + 3.14 * 89.64;   // Useless calculations to consume CPU time
      printf(1, "Child %d finished with x = %d\n", getpid(), x);
      exit();
    }
  }

  while ((pid = wait()) >= 0) {
    z++;
    printf(1, "z = %d\n", z);
  }

  printf(1, "All children finished executing.\n");
  exit();
}
