#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROC 3
int main (void){
	int pid=1;
	int i;
	for (i=0; i < NUM_PROC && pid!=0; i++){
		if ((pid=fork()) <0 ){
			printf("Error al emplear fork\n");
			exit(EXIT_FAILURE);
		}else if (pid ==0){
			printf("HIJO  %d y su padre es %d\n", getpid(), getppid()); 
		}
		else{
			printf ("PADRE %d\n",getppid());
		}
	}
	exit(EXIT_SUCCESS);
}


