
# 🚰 42 Paris - Pipex: Mastering the Shell, One Pipe at a Time 🔗💻

## 🚀 Project overview

Pipex is a project that replicates the behavior of a Unix shell's pipe (|) mechanism. It allows you to execute two commands in sequence, where the output of the first command becomes the input of the second, just like the shell does with piping.

The program is executed like this: `$> ./pipex file1 cmd1 cmd2 file2`

Equivalent to the shell command: `$> < file1 cmd1 | cmd2 > file2`



## 🗝️ Key concepts

**Pipes**: Used to redirect the output of cmd1 as the input for cmd2.

**File Redirection**: Input comes from file1, and the final output is written to file2.

**Process Management**: Each command is executed in its own process, ensuring proper use of fork and execve to handle multiple processes.
## ⚙️ Program execution

The program takes four arguments:

- **file1**: Input file.

- **cmd1**: First shell command with its parameters (e.g., "ls -l").

- **cmd2**: Second shell command with its parameters (e.g., "wc -l").

- **file2**: Output file.

**Example Usage**: `$> ./pipex infile "ls -l" "wc -l" outfile`

**This is equivalent to**: `$> < infile ls -l | wc -l > outfile`

## 🖥️ Project requirements

- Written in C and compiled with a Makefile.

- Use only allowed system functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.

- No use of global variables.

- Ensure proper memory management with no leaks.
