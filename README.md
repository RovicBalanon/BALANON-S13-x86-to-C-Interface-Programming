# BALANON-S13-x86-to-C-Interface-Programming

This is a machine project on x86-64 to C interface programming, where C and ASM kernels are 




This document is an overview of the comparative execution time of C and x86-64 kernels on debug and release modes, with a short analysis of each performance.


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

# Analysis of Execution Times

Generally, Debug mode is slower than Release mode with the C kernel. 
This is due to how Debug mode prioritizes error-checking over performance to facilitate ease of debugging, which contributes to its lack of speed. Release mode focuses more on optimizing the C program code for speed and efficiency, which explains the significant difference between the two modes when running C kernels.

However, Debug mode is faster than Release mode with the ASM kernel, except for vector size 2^20 which is faster. 
This is unexpected because Release mode should be generally faster than Debug mode. Possible explanations could be in the compiler settings or optimization levels of the release mode. It is important to note that both of their execution times with the ASM kernel are very close to each other, unlike when using a C kernel. This suggests that there is a small difference in choosing either mode when running ASM kernels.

Generally, C is slower than ASM in Debug mode. 
This is because C, a high-level language, requires additional memory and space usage to provide features that can simplify programming. On the other hand, a low-level language like Assembly grants direct access to the CPU which reduces and minimizes runtime and abstraction overhead, effectively cutting out the middleman.

However, C is generally faster than ASM in Release mode, which is unexpected.
ASM should be especially faster than C in Release mode, where speed and efficiency are prioritized. It is plausible that the ASM function is not optimized enough to outperform the C function. It is also important to remember that the ASM execution times for both modes are very close to each other, which could mean that the ASM function does not fully benefit from the execution speed increase that C had from Release mode.

Order of Execution Speed (fastest > slowest):
C release > ASM debug/release > C debug






Screenshots:

![2^20 C Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/f3b2825e-0444-4eb9-b7e8-384c81ed0229)
