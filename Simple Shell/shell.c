#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

char prompt[] = "shell > ";
char delimiters[] = " \t\r\n";
char **environ;

int main() {
    // Stores the string typed into the command line.
    char command_line[MAX_COMMAND_LINE_LEN];

    // Stores the tokenized command line input.
    char *arguments[MAX_COMMAND_LINE_ARGS];
    
    while (true) {
        // Print the shell prompt.
        printf("%s", prompt);
        fflush(stdout);
        
        // Read input from stdin and store it in command_line. If there's an
        // error, exit immediately. (If you want to learn more about this line,
        // you can Google "man fgets")
        if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
            fprintf(stderr, "fgets error");
            exit(0);
        }
        
        // If the user input was EOF (ctrl+d), exit the shell.
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            return 0;
        }

        // TODO:
        // 1. Tokenize the command line input (split it on whitespace)
        int i = 0;  
        char *command;
        char *arg;
        command = strtok(command_line,delimiters);
        arg = strtok(NULL,delimiters);
        while (arg != NULL)
        {
          arguments[i] = arg;
          i+=1;
          arg = strtok(NULL,delimiters);
        }
        // 2. Create a child process which will execute the command line input
        pid_t child_pid, wpid;
        child_pid = fork();
 
        if (child_pid == 0)
        {
            execve(arguments[0], arguments, environ);
            //execve("hello", arguments, environ);
            exit(0);
        }
        else 
        {
          wait(NULL);
        }
        // 3. The parent process should wait for the child to complete
        for (int pid=0; pid<n; pid++) 
        {
          if ((child_pid = fork()) == 0) 
          {
            exit(0);
          }
        }
        while ((wpid = wait(&status)) > 0);
        
        // Hints (put these into Google):
        // man fork
        // man execve
        // man wait
        // man strtok
    }
    
    // This should never be reached.
    return -1;
}

