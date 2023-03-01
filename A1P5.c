#include <stdio.h>
#include <unistd.h>

int var=50;

int main() {
	pid_t pidc;
	printf("** Proceso PID = %d conmienza **\n", getpid());
	pidc fork();
	printf("Proceso PID = %d, pidC = %d ejecutándose \n",getpid(),pidC);
	if(pidc > 0) {
		var = 60;
	}
	else if(pidC == 0){
		var = 40;
	}
	while(1) {
		sleep(2);
		printf("Procedimiento PID %d, var = %d ejecutandose\n",getpid(),var);
	}
}
