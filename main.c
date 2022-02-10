<<<<<<< HEAD
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char** argv) {
    pid_t child_pid;
    int child_number;

    for(int i = 0; i < 5; i++){
        child_pid = fork();
        if(child_pid == 0){
            child_number = i;
            break;
        }
    }
    
    for(int i = 0; i < 5; i++){
        wait();
    }

    return 0;
=======
#include <fstream>
#include <iostream>

int main() {
	return(0);
>>>>>>> 849cd63472ed50b5b35718e40e83cc90c5293763
}