#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	system("clear");
	fprintf(stderr, "Inicia el programacon Proceso Padre: %ld", (long) getpid());

	if(fork() == 0){
		fprintf(stderr, "\nInicia el hijo con PID: %ld y Padre PID: %ld",(long)getpid(), (long)getppid());
		sleep (1);
		fprintf(stderr, "\nNuevamente el hijo con PID: %ld y Padre PID: %ld",(long)getpid(), (long)getppid());
	}
	else{
		fprintf(stderr, "\nContinua el padre PID: %ld\n",(long)getpid());
		sleep (1);
		fprintf(stderr,"\nAhora finalizara el padre con PID: %ld\n",(long)getpid());
		exit(0);
	}
	exit(0);
}
