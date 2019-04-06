#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void hello(){

printf("\n\tWelcome to shellix shell stranger\n");

}

int readTask(char *task){

    char* buf; 
    buf = readline("\nsx>> "); /* Czytanie do bufera */
    if (strlen(buf) != 0) { 
        add_history(buf);
        strcpy(task, buf);     /* Funkcja kończąc działanie zmieni "task" */       
	return 0; 
    } else { 
        return 1; 
    } 
}   

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}





int main(){

    char input[12];
    char exit[] = "exit";


    clearScreen();
    hello();

    while(strcmp(input,exit)!=0){
	readTask(input);
        //sleep(1);

}

return 0;
}
