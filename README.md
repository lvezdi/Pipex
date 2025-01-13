<div align="center">
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<img src="https://img.shields.io/badge/leaks-none-success" />
  	<img src="https://img.shields.io/badge/-100%2F100-success?logo=42&logoColor=fff" />
	<a href="https://github.com/lvezdi/Pipex/blob/main/Documentation/README.md" >
   	<img src="https://img.shields.io/badge/Cambiar_Idioma-Español-blue" align="right"></a>
</div>

# Pipex
Pipex is a project that recreates in C the way two commands are connected by a pipeline (`|`) in the shell.

## Processes and Functions

### Main Process
`Pipex` allows two commands to be executed in sequence, where the output of the first command becomes the input of the second command. This is achieved using pipes (`pipes`), child processes (`fork`), and file descriptor duplication (`dup2`).

### Key functions

- `pipe()`: creates a one-way channel of `communication between two processes`, allowing data written to one end of the pipe to be read from the other end. Returns an array of two file descriptors: the first fd is for reading and the second fd is for writing.
- `fork()`: creates a new process called `child process`, which is a copy of the parent process. This function returns the `PID` of the child to the parent process, and 0 to the child process. This is fundamental for Unix process creation.
- `dup2()`: duplicates a file descriptor. Makes one of the file descriptors refer to the same file as the other descriptor.
- `execve()`: replaces the program in the current process with a new program. It takes as arguments the name of the file containing the program to execute, an array of arguments and an array of environment variables.
- `access()`: checks the `access permission` to a file. Checks whether the process has permission to `read`, `write` or `execute` a specified file. Returns 0 if access is allowed, and -1 if it is not.

### Using the PATH
To execute commands, pipex must look for executables in the paths specified in the `PATH` environment variable. The `PATH` variable is a list of separate directories where the system looks for executable files.

### Example Usage
````bash
./pipex infile cmd1 cmd2 outfile

pipe()
 |
 |-- fork()
      |
      |-- first child // cmd1
      : |--dup2() // Redirect cmd1 command entry from infile
      : |--close end[0] // Close read end of pipe
      : |--execve(cmd1) // Execute cmd1
      :
      |-- second child // cmd2
            |--dup2() // Redirect output of cmd2 command to outfile
            |--close end[1] // Close the write end of the pipe
            |--execve(cmd2) // Execute cmd2
