#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_CHILDREN 25

int main (int argc, char** argv) {
    pid_t child_pid;
    int child_number, num_children;
    pid_t pid_list[MAX_CHILDREN];

    if(argc != 2){
        printf("ERROR: Invalid number of arguments.\n");
	return -1;
    }

    if(atoi(argv[1]) <= MAX_CHILDREN){
        num_children = atoi(argv[1]);
    }
    else{
        printf("ERROR: Number of children must be %d or less\n", MAX_CHILDREN);
        return -1;
    }
    
    printf("Parent pid is %d\n", getpid());

    for(int i = 0; i < num_children; i++){
        child_pid = fork();
        if(child_pid == 0){
            child_number = i;
            switch(child_number % 5) {
                case 0:
                    fflush(stdout);
                    execlp("./test1", "");
                    break;

                case 1:
                    fflush(stdout);
                    execlp("./test2", "");
                    break;

                case 2:
                    fflush(stdout);                   
                    execlp("./test3", "");
                    break;

                case 3:
                    fflush(stdout);                    
                    execlp("./test4", "");
                    break;

                case 4:
                    fflush(stdout);
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
			fflush(stdout);
            child_pid = wait();
            for(int j = 0; j < num_children; j++){
                fflush(stdout);
                if(pid_list[j] == child_pid){
                    printf("Child %d (PID = %d) finished \n", j + 1, child_pid);
                }
            }
        }  
    }

    return 0;
}
