# Simple Shell Project

## Description
This new project involves rewriting a simple UNIX command interpreter, following the associated guidelines to complete the project. All the files are written in C Language. The shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.

### Environnement:

- Ubuntu 20.04 LTS
- GitHub

### Betty Style:

- the code use the Betty style. <br />
- https://github.com/hs-hq/Betty/blob/main/betty-doc.pl <br />

### Git Clone command:
```c
https://github.com/JoBEph/holbertonschool-simple_shell.git
```
### Compilation command:
```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Man command:
```c
man man_1_simple_shell
```

### Usage:

The Simple Shell should work like this in interactive mode (simple commands can be typed directly to the running shell).
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

And also in non-interactive mode (commands can be put into a file and the file can be executed directly).
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Requirements: 

- [x] Allowed editors : vi, vim, emacs <br />
- [x] All your files will be compiled on Ubuntu 20.04 LTS <br />
- [x] Your C programs and functions will be compiled with gcc command, using the options -Wall -Werror -Wextra -pedantic -std=gnu89 <br />
- [x] All your files should end with a new line <br />
- [x] README.md file, at the root of the folder of the project is mandatory <br />
- [x] Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl (see link above for the instructions) <br />
- [x] Your shell should not have any memory leaks <br />
- [x] No more than 5 functions per file <br />
- [x] All your header files should be include guarded <br />
- [x] Use system calls only when you need to (why?) <br />

### Resources:

* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)

### Files:

|  **Functions**  	   | **Description**                                       |
|:---------------:	   |-------------------------------------------------------|
| `print_env.c`        | Print environment variable                            |
| `_free.c`     	   | Free multiple buffers                                 |
| `_error.c`           | Error gestion                                         |
| `get_file.c`         | Executable PATH of the file and environnement         |
| `prompt.c`      	   | Fonction create prompt simple shell                   |
| `_getenv.c`          | Environnement function                                |
| `main.c`        	   | Main function                                         |
| `main.h`        	   | Header file with functions prototypes and libraries   |
| `man_1_simple_shell` | Man page Simple Shell                                 |

### Flowchart:
![Final shell](https://github.com/user-attachments/assets/cdacb858-a2b2-4e54-b416-b3cc8eeb4d17)


### Authors:

* Julie Tolve | [Github](https://github.com/JulieRaph)
* Jordan Baroux | [Github](https://github.com/JoBEph)

