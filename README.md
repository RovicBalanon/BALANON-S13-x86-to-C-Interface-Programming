# BALANON-S13-x86-to-C-Interface-Programming

This is a machine project on x86-64 to C interface programming.

This document is an overview of the comparative execution time of C and x86-64 kernels on debug and release modes, with a short analysis of each of their performance.


# Average Execution Times of C and ASM kernels on Debug and Release Modes (tested 30 times each):

| n = 2^20     | C kernel  | ASM kernel | FASTER KERNEL |
| ------------ | :-------: | :--------: | :-----------: |
| Debug Mode   | 0.0083667 | 0.0075     | ASM           |
| Release Mode | 0.0038333 | 0.0074333  | C             |
| FASTER MODE  | Release   | Release    |XXXXXXXXXXXXXXX|


| n = 2^24     | C kernel  | ASM kernel | FASTER KERNEL |
| ------------ | :-------: | :--------: | :-----------: |
| Debug Mode   | 0.1263667 | 0.122      | ASM           |
| Release Mode | 0.0562    | 0.1262     | C             |
| FASTER MODE  | Release   | Debug      |XXXXXXXXXXXXXXX|

| n = 2^30     | C kernel  | ASM kernel | FASTER KERNEL |
| ------------ | :-------: | :--------: | :-----------: |
| Debug Mode   | 8.0889667 | 7.555      | ASM           |
| Release Mode | 3.6650333 | 7.5949667  | C             |
| FASTER MODE  | Release   | Debug      |XXXXXXXXXXXXXXX|


Generally, Debug mode is slower than Release mode with the C kernel. 
This is due to how Debug mode prioritizes error-checking over performance to facilitate ease of debugging, which 
contributes to its lack of speed. Release mode focuses more on optimizing the C program code for speed and efficiency, which
explains the significant difference between the two when running C kernels.

However, Debug mode is faster than Release mode with the ASM kernel except for the vector size 2^20. 
(why)
It is important to note that both of their execution times with the ASM kernel are very close to each other, unlike when 
using a C kernel, which suggests that there is a small difference in choosing either mode when running ASM kernels.

Generally, C is slower than ASM in Debug mode. 
This is because 
ASM goes directly into the CPU so that 

However, C is generally faster than ASM in Release mode.







Screenshots:
C
ASM
