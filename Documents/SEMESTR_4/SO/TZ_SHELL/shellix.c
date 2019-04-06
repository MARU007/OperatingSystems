#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include<sys/wait.h> 


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
	perror("Problem with reading your task");
        return 1; 
    } 
}   

void clearScreen(){
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

/*
GETOPT może się przydać do poleceń pwd lub cd
*/

void parseSpace(char *task, char* parsed[]){
    int count=0;
    char *duplicate = strdup(task);	// Dzięki temu nie tracimy dostępu do oryginalnej linii wejściowej
    char *word;
    while((parsed[count]=strsep(&duplicate," ")) != NULL){
	count++;
    }
}


void execTask(char** arg_list){
 
  pid_t child_pid; 

  child_pid = fork (); 


  if (child_pid == 0) {
	execvp (arg_list[0],  arg_list); 
    	exit(0);
  }
  
  else {
	wait(NULL);  	
	return;
  }

} 


int main(){

    char input[12];
    char exit[] = "exit";
    char *parsed[100];	/* Tablica parametrów linii wejściowej, parsed[0] - nazwa programu */

    clearScreen();
    hello();

    while(strcmp(input,exit)!=0){
	readTask(input);
	parseSpace(input,parsed);
	execTask(parsed); 
        

}

return 0;
}
