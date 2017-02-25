#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>

int main (void){
	int pid;
	char* buff= (char*) malloc (80 * sizeof(buff[0]));
			if (buff==NULL) exit (EXIT_FAILURE);
		pid=fork();
		if (pid < 0){
			printf("Error al emplear fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid !=0){
			printf("Escribe un nombre: "); 
			scanf ("%s", buff);   
		}
	free(buff);
	
	exit(EXIT_SUCCESS);
}


