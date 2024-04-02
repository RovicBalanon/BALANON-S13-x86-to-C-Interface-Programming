# BALANON-S13-x86-to-C-Interface-Programming

This is a machine project on x86-64 to C interface programming.

This document is an overview of the comparative execution time of C and x86-64 kernels on both debug and release mode, with a short analysis of their performance.



# Average Execution Times of C and ASM kernels on Debug and Release Modes (tested 30 times each):

| n = 2^20     | C kernel  | ASM kernel | FASTER KERNEL |
| ------------ | :-------: | :--------: | :-----------: |
| Debug Mode   | 0.0083667 | 0.0075     | ASM           |
| Release Mode | 0.0038333 | 0.0074333  | C             |
| FASTER MODE  | Release   | Release    |_______________|


| n = 2^24     | C kernel  | ASM kernel | FASTER KERNEL |
| ------------ | :-------: | :--------: | :-----------: |
| Debug Mode   | 0.1263667 | 0.122      | ASM           |
| Release Mode | 0.0562    | 0.1262     | C             |
| FASTER MODE  | Release   | Debug      |_______________|

| n = 2^30     | C kernel  | ASM kernel | FASTER KERNEL |
| ------------ | :-------: | :--------: | :-----------: |
| Debug Mode   | 8.0889667 | 7.555      | ASM           |
| Release Mode | 3.6650333 | 7.5949667  | C             |
| FASTER MODE  | Release   | Debug      |_______________|

Generally, Debug mode is slower than Release mode with the C kernel. 

On the ASM kernel however, Debug mode is faster than Release mode on all vector sizes except 2^20.

Generally, C is slower than ASM on Debug mode.

However, C is generally faster than ASM on Release mode.







Screenshots:
C
ASM
