# Simple Shell Project

## Description
This new project involves rewriting a simple UNIX command interpreter, following the associated guidelines to complete the project. All the files are written in C Language. The shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.

### Environnement:

- Ubuntu 20.04 LTS
- GitHub

### Betty Style:

- the code use the Betty style. <br />
- https://github.com/hs-hq/Betty/blob/main/betty-doc.pl <br />

### Compilation command:
```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
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

* Allowed editors : vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS
* Your C programs and functions will be compiled with gcc command, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl (see link above for the instructions)
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

### Resources:

* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)

### Files:

|  **Functions**  	| **Description**                                     	|
|:---------------:	|-----------------------------------------------------	|
| `read_prompt.c` 	| Read and print an user command                      	|
| `_strcmp.c`     	| Compares 2 strings                                  	|
| `_strcpy.c`     	| Copy 2 strings                                      	|
| `_strlen.c`     	| To print a string                                   	|
| `_strtok.c`     	| Count arguments and break them into tokens          	|
| `_error.c`      	| Message failure                                     	|
| `execmd.c`      	| Execute processes                                   	|
| `main.c`        	| Main function                                       	|
| `main.h`        	| Header file with functions prototypes and libraries 	|

### Authors:

* Julie Tolve | [Github](https://github.com/JulieRaph)
* Jordan Baroux | [Github](https://github.com/JoBEph)


![Holberton School](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAJwAAAFDCAMAAAD4eZcxAAAAk1BMVEX////gFD3gDjrjKE3fAC/yqbXfADLfAC3fADHfADXeACrfADbeACjeACbgCzn//P3eACP+9/n409n1vcb3zdT75enzsrztiZj52d786u398fPmVm363uPukJ7re4z51tzxpbDhGkPvmqfjMlLoX3XlRWDoZ3vvlKL2w8vzucDpcILmTWfkQl3rfo/mVGznY3bdABHL7TGjAAAL6UlEQVR4nO2daXfiOgyGG2NiEkPYwhYoDXvY7///dRfaToGSxIskMx/m/XDnnjmnp8/YsSXLsvT29k//lKNeJ86ybT+t9rdZPBy9GudL7dE2ne5nXFwUCvH55+UPv7Ked3vtV5L1+rtKXfAgYt5vMVkTjdl5EzdfQjZKF0IEz1i/COWu63wAO+eQR2VgP4BByHaxU7ZjI9Ah+8MnZqnD4TtJfbZPPuHNneGNDeEueJylfy3cdfQq278WzvOicOxie95rrdRnBUGXHm5lCeexcEAOd7CF8zwxTojhFqWWoVz+gphuBoDz5KxHydYGwV3oKMduZLWT3NFVCOmGHAbn+Us6uDgEwnnhhgyuL6BwnuhQwQ18MBzzqHzkNXBBXMWJTEUTsgff6CYkcG3wergqOJPAxXUMOK81pIBLodvclyTJZmfnaj5LUHx1HsZ6uMgnWLAf8C34WwE+3Bznk7soxHfasT65y8jtsNlGaLPqsRn2SRvB6v8oxI6iWJ+8coS9XnuIA+dFK1w4vLV6VQPVccLxSH6E+9FlDUw2j1cx4WyjJAVC3ek6uAPnRQdEuLVBuFVHmNvwEMUHvpfEC00s0czqH4VoPl2nhc3mCTTHBHmpXsVTJLY+zsHmQf47DlvbfzAOkc99+Ehimf7dfRCCicOg+r4SUGMWTFHYsvtthAXZ118yIJ1EOVq3H85ctY/vv54Ad77ohAG3vp/U2u0zfq/B4PYIbNWHEfJvWyfQ+cQwrh8PBp/Nbj5iuwL66tgCzJY8hs8f4GDeJ6tA2ZqLXzY1uJnrBGZu4XDL32HWO6NThX1zYLj10+9n7M/QJeU5CORwu5yxiSpf63WyAFowINzzuH3SNXbVrLprQa0rDC6f7aJACA532iFw7T3qGRoVbrSAX4dQwWUB+pkBDW5eRw09YMKN9ujnQDS4fkQ+pbZwo6WDKbWDa84lctgBD27rcTfDZg6XHRzNqDlcdyHwj/UocKN5pW6BxqJA5iSVYsI142Vg8a3JmvBW0/V+Jqy2Hh24djyY1c3TCYNQjDcfX/G/eNmwGXUNuPg/33TQIs4rx+w+MNlZmLswWtNaMftXR7y+mj/H/fKcZgS4rkEkOuJiMc8Plx5N6fQWxFLTJlzGbJ8zZn90MjQtenCjUOOju45ZWhpi7plmEOttJZkqbhnxcF9OdpVhKpHuJpyWfXYRbyjG7Fsjs6C2toWoFsUpI8FPqW6Kr1lUW998xUHOnES8dagaJB9vjAJ2Boa/PRWPqy0S/r5qlsNods1u5JVMdq3Ql9dIL2NStPYmY/Yls7REQ3+umb0vFzMmZ5WT4Zh9wxndVticIZLRKLG8z+vSTStcZAsCQ2Z5627hqDZhFE3NLL9TuA9Df9MpnGkY1iXc2DSe5xCOyE1H0bt50MwZXGpxze4KzioFwBGcXXqCG7iqXZDWCdzGMgPLBdzANrjtAG5qHXinhzvb37lSw4Hux4jhEtD9GC3c0ANdppDCxTVYfJsSrg+9FiCES8GpiHRwA3i2HxncFCETkQpuiZHfTwQ3RklNIIFrnmB5c5Rw7RVS2gQBXLLAuizGh2sf0C6y0eGaWHNKAbdHTNPBhlvirFMSOIDbSw43QGXDhZsjP8LBhEN+WYUKN0TPhsGDa87Qc07w4Mb4GU5ocBvchYoKF+O/XUKDS2C1Z2jhnhLU/yK4LsWkIsHRTCoS3BTTFUGG+6CZVBw4zPfx2HBdsnxmBDjDBDancFuC55locNC3LJRwZskYjuEIHgSjwX1gu+aYcIb5Dk7hEqxiQhRwmJVd0OHOpC9KYHAJ7UscGBydWUWAI12rUDgiDxgFrkf8ng8ER2lXwXAIhSHp4Gh3ORhcE/ZKnxauTfv2NuItQO2IHqG7JIW/0k7Hz1NGZR8iEZ6qwMpCNC6JNE/HzxNSSc1Hstqyj1I/fY4cIrmM2biPVYYZFS4K5RqNDBcuik4Zbv1FxDp9p3m3XzVV+lECh7ggIl9wY7X6buCsJLK/GK60JiLtuVADrsyIbF8NV8KGUL4dpPIioZReiYZqpYXpcQp9W6teWiMU2GwBKFUtScrAoVKq4nQ7VxUu8qSq/Gr2/g1XyiJmZH66hkJVVdoJdXmhYmmUVn3dchWpiu11K0KnvcXLTH+9zJX71uhFBkyvGCLZVWu5Qq2OKsBalZbiRx22t+ErPrpIt4gk4YVmoYRuS5DU/dA1tCuWJ87hhEGpXOKriCcFJvVeO26HzrAdGF4vDQ1FM7P4GEHV72K2wLRYuW51H7gsGtCBW6PpKjCc008d3fictZVNbDExrsZlo7plNybLV8kmYnXrxnN76u0kkPZl+3t0yVZXsfAECWVXKel8CWxOMiXbT2S4A98AEKX4ycYYoeHMBFivOk+sxpc4/RczZBvLgkblHa0piU1djXxFAQ+5N0XtnW5d6eA32/KYZug9Zs84Szbak3RwNa6Cky/JKVouNpEeaDKfotc81hNN1qJo4do+4MzsreA/ppp7nPBJNKNoMNs84axZf00AV1LB30z1lIRuh2MrBEoOx5NwbIVEaYPzrGoLw0cJtzR0mUTw78haQk88hO1YzGng3pIVfEthHlkTd4RFy+napKfg8vR0jcgvywLcqkFoXNXYqlcB+gGoXSF/q3kG7seiLJsKrAHsfoyiX/WdtqBGeKxCtySu6oCKbjUoPPY7JRD3mHheL8ti/PcWoXsD1bfyKU4Tj7KvyCGIHKd79XXq/ecJqWllubqWlha7mXa+OpYhPEHmN91raOce1ylO/8+aWNHhNtMu1lBazCz5NvxDZ2FoUZqRaik2txVs5grurW++G0tax+Re5uGAGr0B+9HZ1EcRbvaSTzVNb3tUuaOoMk33cGH6b5qb0bnahb9llp/FqUIm+ZoYDR1Wj3RdGWVU+HrJfGhKTFqTBzu3cG8bgwCZc7i2wdBJmqh/iQweZEvXI/fW059X59Nq8tTDyfnrUfq5485c4Zv0S3Y4thCf0k6odGv4v6SdOy5cukzf0n5xx00zNRHU012uAe6jYT0t9IyE47Zf3zrprQgk69Xu9Ktpta/7dlvzCQ/GTpKke1EXnIvLf08l7T5v0nzOXv7iUUfNjbzrdiy5GKvPc5o2gkPXQzz7HQSRrakqrqb3tBgcKpmHOduC7ymuhvSeA0It6yA/sS8qfcyuCwe0D5uiX8LK30BpwbEI9Mn1ixMiWQB+zg7b5XplcejSVylaqxWWv1Ge+90ouWrW2edgs6roE132gkzHQoBc9KbqjWu9eMXqvFQExeaU303xP12n6JT2071cKfuKMlb0ozqvnkNIdsRQHX5uFe0mGkXYYHklGud2UfTO4qheDzBvSSMKWBiXVH9yzIPsI4mGo10U+tOovArLAtN581XkVai/CAbLeNUx3QUjp9wggUv12jFdDcfT3B9VW33oFbVOgaGC1aoOMrWA6fM6I9fKzaiNlcuBQ2NLOvtovgFSWpZoAb0r7KgXRC13PaiHHDqpF0dTfWbPTahRF0kOEU7Syv0gyPWy16o9DiVtfq2yj7lmv6/6GiKUrDlVReEwzfkh5T0/kygROUWRAX7O+ZmR8n6kVX7e1VZpkQGel5efVFSrCGi2birbTMJxzpfTXqjYWnjB88KYuBR5O9xkphw3xMB+QdMP2TrlfdSZr7AMrLSSobF2z3uWFLVT3pGueVQ94oiQn6Ml0d0vlGG90aot09xDTbZQOTGBh/2Q7y4BSK4nw2FBzHCybKiMvdjjB/XXt5hHbV1wQo+XoWolsBbF7WDzbneQ4WI++bWDtDtTTyhdBClprrhG0d2EMd6onI9pN+5cFfcHY6+uka0pFlSXSBPv4XNi0uciFFeFwtfJNozqhLkjEw55SsXEgvRiUL3zF8uX1Le9vZld6j7zwx3No8J7tc8WCd6MyyM92lWpbzi1sr6YO0mfvqp3yLvJKSIT/hjJqdRU99DQuqeMRDjGqUFupHgdiFK/iMnatW67e7JPtePjoXEBfF4eLAp4Y3bexK+4tP9Rs9cf7Bm/WAjuX1W7/q/gbHWsTl4KdlMyjLPq+2AweJ+n27jz2x/4p3/K1/+LuuKkg5Ay0gAAAABJRU5ErkJggg==)
