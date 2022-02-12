#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CHILDREN 25

int main (int argc, char** argv) {
    pid_t child_pid;
    int child_number, num_children;
    pid_t pid_list[MAX_CHILDREN];

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
    
    printf("Parent pid is %d\n", getpid());

    for(int i = 0; i < num_children; i++){
        child_pid = fork();
        if(child_pid == 0){
            child_number = i;
            switch(child_number % 5) {
                case 0:
                    execlp("./test1", "");
                    break;

                case 1:
                    execlp("./test2", "");
                    break;

                case 2:
                    execlp("./test3", "");
                    break;

                case 3:
                    execlp("./test4", "");
                    break;

                case 4:
                    execlp("./test5", "");
                    break;
            }
            break;
        }
        else {
            pid_list[i] = child_pid;
        }
    }
    if(child_pid != 0){
        for(int i = 0; i < num_children; i++){
            child_pid = wait(NULL);
            for(int j = 0; j < num_children; j++){
                if(pid_list[j] == child_pid){
                    printf("Child %d (PID = %d) finished \n", j + 1, child_pid);
                }
            }
        }  
    }

    return 0;
}
