#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void shell_loop(void)
{
  char *line;
  char **args;
  int status;
  
  do{
    printf("$");
    line = shell_read_line();
    args = shell_split_line(line);
    status - shell_execute(args);

    free(line);
    free(args);
  }while(status);
}

int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  shell_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
