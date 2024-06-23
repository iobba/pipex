# README.md

## Introduction

As I delved into the world of inter-process communication through pipes in C, I found myself intrigued by the potential of `pipex`. This project, named `pipex`, is a reflection of my exploration into the complexities and beauties of Unix-style pipelines, where data flows seamlessly between processes.

## Understanding Pipex

`pipex` is a custom program I developed to emulate the behavior of Unix pipelines, allowing data to flow from one process to another via pipes. It takes two filenames and two commands as arguments, executing the commands on the input file and redirecting the output to the second file.

### Key Concepts

- **Inter-Process Communication (IPC)**: The mechanism by which processes communicate with each other, often through pipes or sockets.
- **Pipes**: A form of IPC that allows data to be transferred between processes.
- **Forking**: Creating a new process by duplicating the existing process.
- **Command Execution**: Running shell commands programmatically within a C application.

## Project Overview

### Functionality

`pipex` executes as follows:

 - bash ./pipex file1 cmd1 cmd2 file2

Where:
- `file1` and `file2` are file names.
- `cmd1` and `cmd2` are shell commands with their parameters.

It behaves identically to the shell command:

 - bash < file1 cmd1 | cmd2 > file2

### Examples

- `$>./pipex infile "ls -l" "wc -l" outfile`
- `$>./pipex infile "grep a1" "wc -w" outfile`

### Requirements

- Implement a `Makefile` for compiling source files without relinking.
- Thoroughly handle errors to prevent unexpected program termination.
- Ensure no memory leaks occur during execution.
- Emulate shell command behavior, including error handling.

### Compilation

Compile your code using the provided `Makefile`, ensuring thorough error checking and no memory leaks.

### Bonus Part

Extra points can be earned by:
- Supporting multiple pipes.
- Allowing the use of "here_doc" syntax for input redirection.

## Development Journey

Developing `pipex` was a journey of discovery, pushing the boundaries of my understanding of Unix systems, process management, and inter-process communication. Each challenge faced—whether it was handling errors gracefully or optimizing memory usage—served as a stepping stone towards a more robust and reliable implementation.

## Conclusion

The completion of `pipex` marks a significant achievement in my journey with C programming and system-level programming.
