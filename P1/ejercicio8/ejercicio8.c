#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char*argv[]){
	int pid=1;
	int i;
	for (i=1; i < argc-1 && pid!=0; i++){
		if ((pid=fork()) <0 ){
			printf("Error al emplear fork\n");
			exit(EXIT_FAILURE);
		}else if (pid ==0){

			char *stat[]={argv[i], NULL};

			printf("Ejecutando el programa %d\n",i);
		    if (!strcmp("-l",argv[argc-1])){
     			execl(argv[i],argv[i],NULL);
    		}else if(!strcmp("-lp",argv[argc-1])){
     			execlp(argv[i],argv[i],NULL);
			}else if(!strcmp("-v",argv[argc-1])){
     			execv(argv[i],stat);
			}else if(!strcmp("-vp",argv[argc-1])){
     			execvp(argv[i],stat);
			}else{
				printf("Error en los argumentos de entrada\n");
			}	
			perror("fallo en exec");
		}else{
			wait(NULL);
		}
	}
	exit(EXIT_SUCCESS);
}


