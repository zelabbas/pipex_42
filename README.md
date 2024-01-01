# pipex_42
The "pipex" project, commonly found in systems programming or Unix-related courses, involves creating a simplified version of a shell command that uses pipes to redirect the output of one command as the input of another.

## Obective of pipe
The objective is to replicate the behavior of the shell command:
```
shell$ < infile cmd1 | cmd2 > outfile
```

## Project Overview:
The "pipex" project typically requires students to implement a program that can take a set of command-line arguments and execute a series of shell commands with I/O redirection using pipes. The project helps students gain a deeper understanding of process communication, file descriptors, and system calls.

## Key Components:

#### 1 Input and Output Files:
	``` The program should accept input and output file names as command-line arguments. ```
#### 2 Command Execution:
	```Execute two given commands in sequence, where the output of the first command serves as the input for the second command.```
#### 3 Pipes:
	```Use pipes to establish communication between the two commands. The output of the first command should be connected to the input of the second command.```
#### 4 Redirection:
	```Implement file I/O redirection to read input from the specified input file and write output to the specified output file.```
#### 5 Error Handling:
	```Handle errors gracefully, including issues related to file opening, command execution, and system calls.```

## Example Usage:
	```
		shell$ ./pipex infile "cmd1 arg1 arg2" "cmd2 arg3 arg4" outfile
	```

## Expected Behavior:
```
	.Read input from the file "infile."
	.Execute "cmd1" with the specified arguments.
	.Use a pipe to redirect the output of "cmd1" to the input of "cmd2."
	.Execute "cmd2" with the specified arguments.
	.Write the final output to the file "outfile."
```
## Additional Requirements (Bonus):
```
	Handling multiple pipes for more than two commands.
	Supporting "here_doc" (here document) using "<< LIMITER."
```
## Learning Objectives:
```
	Understanding process communication through pipes.
	Working with file descriptors for I/O redirection.
	Implementing basic shell-like functionality.
```

# Run the program :
```
for Mandatory part : 
	```shell$ make ```
```
<p style="color: red;">usage:</p>
	./pipex infile "ls -l" "cat -e" outfile
<br>

```
for Bonus part : 
	```shell$ make bonus ```
```
<p style="color: red;">multiple pipe usage:</p>
	./pipex_bonus infile ls "cat -e"  "grep $" outfile
	
<br>

<p style="color: red;">here_doc usage:</p>
	./pipex_bonus infile here_doc LIMITER ls "cat -e"  "grep $" outfile
