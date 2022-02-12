#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CHILDREN 25

int main (int argc, char** argv) {

    pid_t child_pid;
    pid_t pid_list[MAX_CHILDREN];
    int num_children;

    // Check if number of arguments is correct
    if(argc != 2){
        fprintf(stderr, "ERROR: Invalid number of arguments.\n");
	    return 1;
    }

    // Check if argument between 0 and the maximum ammount of children allowed.
    if(atoi(argv[1]) <= MAX_CHILDREN || atoi(argv[1]) >= 0){
        num_children = atoi(argv[1]);
    }
    else{
        fprintf(stderr, "ERROR: Number of children must be between %d and 0\n", MAX_CHILDREN);
        return 1;
    }
    
    // Print parent PID
    printf("Parent pid is %d\n", getpid());

    // Loop to create children processes
    for(int i = 0; i < num_children; i++){

	    // Create new child process
        child_pid = fork();

	    // If the process is a child process, execute a test program based on the order of its creation
        if(child_pid == 0){
            switch(i % 5) {
                case 0:
                    execlp("./test1", NULL);
                    break;

                case 1:
                    execlp("./test2", NULL);
                    break;

                case 2:
                    execlp("./test3", NULL);
                    break;

                case 3:
                    execlp("./test4", NULL);
                    break;

                case 4:
                    execlp("./test5", NULL);
                    break;
            }
	        break;
        }

	    // If process is the parent process, add the newly created child's pid to the child pid list
        else {
            pid_list[i] = child_pid;
        }
    }

    // Loop to wait for all children processes to finish execution
    for(int i = 0; i < num_children; i++){

	    child_pid = wait(NULL);

	    // Once child has completed it's execution, loop through pid list to find what # child it is and print that it has finished
        for(int j = 0; j < num_children; j++){
            if(pid_list[j] == child_pid){
	            printf("Child %d (PID = %d) finished \n", j + 1, child_pid);
	        }
	    }
    }  
    return 0;
}
