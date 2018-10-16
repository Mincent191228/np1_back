/* **************************************************
 *  * sh_cmd() - executes a command in the background
 *   * returns TRUE is command was executed  (not the result of the command though..)
 *    * NO GLOBALS
 *    */
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<string>
static int sh_cmd (char * path, char * cmd, char * args)
{
  char     cmd_line[256];
  char   **argv;
  int      argp;
  int      rc = 0;

  if (cmd == NULL)
    return FALSE;

  if (cmd[0] == '\0')
    return FALSE;

  if (path != NULL)
    chdir (path);

  snprintf (cmd_line, sizeof (cmd_line), "%s %s", cmd, args);

  rc = shell_parse_argv (cmd_line, &argp, &argv, NULL);
  if (!rc)
  {
    g_strfreev (argv);
    return rc;
  }

  rc = spawn_async (path, argv, NULL,
		      G_SPAWN_STDOUT_TO_DEV_NULL | G_SPAWN_SEARCH_PATH,
		      NULL, NULL, NULL, NULL);

  strfreev (argv);

  return rc;
}

int main(){
  char path[10] = "bin";
  char cmd[10] = "ls";  

  sh_cmd(path,cmd);





}
