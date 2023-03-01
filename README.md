# Process Management in C

## Description
This project contains a series of C programs that demonstrate various aspects of process management in Unix-like operating systems. These programs illustrate the use of system calls such as `fork`, `getpid`, and `getppid` to create and manage processes. Each file showcases different aspects of process creation, process hierarchy, and inter-process communication.

### Key Features
- **Process Creation**: Examples of creating new processes using the `fork` system call.
- **Process Hierarchy**: Demonstrations of parent-child relationships between processes.
- **Process Identification**: Usage of process identifiers (`PID`) to manage and track processes.
- **Process Synchronization**: Basic examples of synchronizing processes using sleep and exit functions.

### Files
1. **A1P5.c**
    - Demonstrates process creation and variable sharing between parent and child processes.
    - **Key Code Snippet**:
        ```c
        #include <stdio.h>
        #include <unistd.h>

        int var = 50;

        int main() {
            pid_t pidc;
            printf("** Proceso PID = %d comienza **\n", getpid());
            pidc = fork();
            printf("Proceso PID = %d, pidC = %d ejecutándose\n", getpid(), pidc);
            if(pidc > 0) {
                var = 60;
            }
            else if(pidc == 0) {
                var = 40;
            }
            while(1) {
                sleep(2);
                printf("Procedimiento PID %d, var = %d ejecutándose\n", getpid(), var);
            }
        }
        ```
        This code creates a child process and demonstrates how the parent and child processes can modify a shared variable differently.

2. **A2P5.c**
    - Illustrates basic process creation and differentiation between parent and child processes.
    - **Key Code Snippet**:
        ```c
        #include <stdio.h>
        #include <unistd.h>

        int main() {
            switch(fork()) {
                case -1:
                    printf("Error\n"); break;
                case 0:
                    printf("Proceso hijo\n"); break;
                default:
                    printf("El proceso padre\n");
            }
        }
        ```
        This code uses a `switch` statement to differentiate actions between the parent and child processes created by `fork`.

3. **A3P5.c**
    - Demonstrates process creation and hierarchical relationship between parent and child processes.
    - **Key Code Snippet**:
        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <sys/types.h>
        #include <unistd.h>

        int main() {
            system("clear");
            fprintf(stderr, "Inicia el programa con Proceso Padre: %ld\n", (long)getpid());

            if(fork() == 0) {
                fprintf(stderr, "\nInicia el hijo con PID: %ld y Padre PID: %ld\n", (long)getpid(), (long)getppid());
                sleep(1);
                fprintf(stderr, "\nNuevamente el hijo con PID: %ld y Padre PID: %ld\n", (long)getpid(), (long)getppid());
            } else {
                fprintf(stderr, "\nContinua el padre PID: %ld\n", (long)getpid());
                sleep(1);
                fprintf(stderr, "\nAhora finalizará el padre con PID: %ld\n", (long)getpid());
                exit(0);
            }
            exit(0);
        }
        ```
        This code shows how the child process gets the PID of its parent and demonstrates the hierarchical relationship between them.

4. **A4P5.c**
    - Demonstrates process creation and termination, and printing process details.
    - **Key Code Snippet**:
        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <sys/types.h>
        #include <unistd.h>

        int main() {
            int i;

            system("clear");
            for (i = 0; i < 4; i++) {
                if(fork())
                    break;
                fprintf(stderr, "\nProceso %i con PID: %ld\tPadre PID: %ld", i, (long)getpid(), (long)getppid());
            }
            fprintf(stderr, "\n\nFinalizado Proceso PID: %ld\n", (long)getpid());
            sleep(1);
            exit(0);
        }
        ```
        This code creates multiple child processes and prints their PIDs along with their parent's PID.

## How to Use
1. **Compilation**: Each C file can be compiled using a C compiler such as `gcc`.
    ```bash
    gcc A1P5.c -o A1P5
    gcc A2P5.c -o A2P5
    gcc A3P5.c -o A3P5
    gcc A4P5.c -o A4P5
    ```

2. **Execution**: Run the compiled programs to see the output of process management operations.
    ```bash
    ./A1P5
    ./A2P5
    ./A3P5
    ./A4P5
    ```
