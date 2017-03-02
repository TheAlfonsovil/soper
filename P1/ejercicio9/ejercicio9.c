#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int fa[2],fb[2],fc[2],fd[2], i, a, b, size, nbytes;
    int pipe_status;
	pid_t childpid=1;
	char resultado[300];
    char readbuffer[300];

	pipe_status=pipe(fa);
	if(pipe_status==-1) {
	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
	}	
	pipe_status=pipe(fb);

	if(pipe_status==-1) {
	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
	}	
	pipe_status=pipe(fc);

	if(pipe_status==-1) {
	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
	}	
	pipe_status=pipe(fd);

	if(pipe_status==-1) {
	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
	}	
    pipe_status=pipe(fe);

	if(pipe_status==-1) {
	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
	}		
    
	printf("Escribe el valor de los operandos: ");
    scanf("%d %d", &a, &b);

	for(i=0; i<4 && childpid!=0;i++){
		if ((childpid=fork()) <0 ){
			printf("Error al emplear fork\n");
			exit(EXIT_FAILURE);
		}
		switch (i){
			case 0:
				if(childpid==0){
					/*Cierre del descriptor de salida*/
						close(fe[1]);
					/* Cierre del descriptor de entrada en el hijo */
						close(fa[0]);
					/*Recoger datos de fe*/
						nbytes=read(fe[0],readbuffer, sizeof(readbuffer));
					/* Enviar el saludo vía descriptor de salida */
				size=sprintf(resultado,"Datos enviados a través de la tubería por el proceso PID = %d. 				   Operando 1: %d . Operando 2: %d . Suma: %d\n", i, a, b, a+b);

				write(fa[1], resultado, size+1);
                close(fa[1]);
                close(fe[0]);
				exit(0);
				}else{
					/* Cierre del descriptor de salida en el padre */
				close(fa[1]);
					/* Leer algo de la tubería... el saludo! */
				nbytes = read(fa[0], readbuffer, sizeof(readbuffer));
				printf("He recibido el string: %s", readbuffer);				  
				
				}
				break;
			case 1:
				if(childpid==0){
					/* Cierre del descriptor de entrada en el hijo */
				close(fb[0]);
					/* Enviar el saludo vía descriptor de salida */
				size=sprintf(resultado,"Datos enviados a través de la tubería por el proceso PID = %d. 				   Operando 1: %d . Operando 2: %d . Resta: %d\n", i, a, b, a-b);

				write(fb[1], resultado, size+1);
                close(fb[1]);
				exit(0);
				}else{
					/* Cierre del descriptor de salida en el padre */
				close(fb[1]);
					/* Leer algo de la tubería... el saludo! */
				nbytes = read(fb[0], readbuffer, sizeof(readbuffer));
				printf("He recibido el string: %s", readbuffer);				  
				
				}
				break;
			case 2:
				if(childpid==0){
					/* Cierre del descriptor de entrada en el hijo */
				close(fc[0]);
					/* Enviar el saludo vía descriptor de salida */
				size=sprintf(resultado,"Datos enviados a través de la tubería por el proceso PID = %d. 				   Operando 1: %d . Operando 2: %d . Producto: %d\n", i, a, b, a*b);

				write(fc[1], resultado, size+1);
                close(fc[1]);
				exit(0);
				}else{
					/* Cierre del descriptor de salida en el padre */
				close(fc[1]);
					/* Leer algo de la tubería... el saludo! */
				nbytes = read(fc[0], readbuffer, sizeof(readbuffer));
				printf("He recibido el string: %s", readbuffer);				  
				
				}
				break;	
			case 3:
				if(childpid==0){
					/* Cierre del descriptor de entrada en el hijo */
				close(fd[0]);
					/* Enviar el saludo vía descriptor de salida */
				size=sprintf(resultado,"Datos enviados a través de la tubería por el proceso PID = %d. 				   Operando 1: %d . Operando 2: %d . Cociente: %d\n", i, a, b, a/b);

				write(fd[1], resultado, size+1);
                close(fd[1]);
				exit(0);
				}else{
					/* Cierre del descriptor de salida en el padre */
				close(fd[1]);
					/* Leer algo de la tubería... el saludo! */
				nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
				printf("He recibido el string: %s", readbuffer);				  
				
				}
			/*default:
					printf("Error en el switch\n");*/
							
				
			}
		}

	}

































