Title: Project 1
Names: Sage Lyon, Matthew Sylvester

Description:
- This program generates multiple child processes (up to 25) using the fork() function. 
- Each child process will be assigned a number based on the order that it is created. The program will keep track of these numbers using an array of pid values.
- Each child will execute one of the five test program executables depending on their child number modulo five.
- After the program is done creating child processes it will wait for each child to finish execution using the wait() function.
- When a child process returns, the program will print a message that includes the child number and pid which states that the child process has finished. 

Instructions:
- To compile the program, run the command: make
- This will generate an executable file named project1, as well as the executables for the test programs.
- To run the program, run the command: ./project1 <number of child processes (0-25)>
