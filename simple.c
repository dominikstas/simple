#include "simple.h"

void execute(char *command) {
    if (strncmp(command, "echo ", 5) == 0) {
        char *text = command + 5; 
        if (strlen(text) > 0) {
            echo(text);
        } else {
            printf("Usage: echo [text]\n");
        }
    } else if (strcmp(command, "exit") == 0) {
        exitS();
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strncmp(command, "cd ", 3) == 0) {
        char *dir = command + 3;
        if(chdir(dir) != 0) {
            perror("cd");
        }
    } else if (strcmp(command, "ls") == 0) {
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        }
    } else if (strncmp(command, "mkdir ", 6) == 0) {
        char *dir = command + 6;
        if(mkdir(dir, 0777) != 0) {
            perror("mkdir");
        }
    } else if (strcmp(command, "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("pwd");
        }
    } else if (strncmp(command, "rm ", 3) == 0) {
        char *file = command + 3;
        if(remove(file) != 0) {
            perror("rm");
        }
    } else if (strncmp(command, "touch ", 6) == 0) {
        char *file = command + 6;
        FILE *fp = fopen(file, "w");
        if (fp == NULL) {
            perror("touch");
        } else {
            fclose(fp);
        }
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void echo(char *text) {
    printf("%s\n", text);
}

void exitS() {
    printf("Thanks for using\n");
    exit(0);
}

void help() {
    printf("--------------------------------------\n");
    printf("All commands:\n");
    printf("help - show all commands\n");
    printf("echo [text] - write a text\n");
    printf("cd [directory] - change directory\n");
    printf("ls - list directory contents\n");
    printf("mkdir [directory] - create a directory\n");
    printf("pwd - print working directory\n");
    printf("rm [file] - remove a file\n");
    printf("touch [file] - create an empty file\n");
    printf("exit - exit the terminal\n");
    printf("--------------------------------------\n");
}

void init(){
    system("clear");
    printf("Welcome!\n");
}

char* getInput(){
    char *input = NULL;
    size_t bufferSize = 0;

    getline(&input, &bufferSize, stdin);
    input[strcspn(input, "\n")] = '\0';

    return input;
}
