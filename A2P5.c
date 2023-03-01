#include <stdio.h>
#include <unistd.h>

int main() {
	switch(fork()){
	case -1:
		printf("error"); break;
	case 0:
		printf("Proceso hijo\n"); break;
	default:{
	printf("EL proceso padre\n");
	}
	}
}
