# BALANON-S13-x86-to-C-Interface-Programming

This is a machine project on x86-64 to C interface programming with C and ASM kernels.

Kernel Specifications: Perform a dot product between vector A and vector B (double-precision floats), then place the result in sdot.
Initializations: 
Vector A = 0.001 and Vector B = 0.1 for their first elements. Add 0.001 and 0.1 to Vector A and B to get succeeding elements, respectively.
(Vector A = {0.001, 0.002, 0.003,...} and Vector B = {0.1, 0.2, 0.3,...})
Variable n determines up to which vector element position to perform the dot product with, effectively making n the vector size.
(If n = 3, dotProduct = (0.001*0.1)+(0.002*0.2)+(0.003*0.3))

Below is an overview of the comparative execution time of the C and x86-64 kernels on debug and release modes, with a short analysis of each performance.


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
This is because C, a high-level language, requires additional memory and space usage to provide features that can simplify programming. On the other hand, a low-level language like Assembly grants direct access to the CPU which reduces and minimizes execution time and abstraction overhead, effectively cutting out the middleman.

However, C is generally faster than ASM in Release mode, which is unexpected.
ASM should be especially faster than C in Release mode, where speed and efficiency are prioritized. It is plausible that the ASM function is not optimized enough to outperform the C function. It is also important to remember that the ASM execution times for both modes are very close to each other, which could mean that the ASM function does not fully benefit from the execution speed increase that C had from Release mode.

Order of Execution Speed (fastest > slowest):
C release > ASM debug/release > C debug



# Output Screenshots w/ Correctness Check (C):


## 2^20

### C Debug
![2^20 C Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/f3b2825e-0444-4eb9-b7e8-384c81ed0229)
### C Release
![2^20 C Release](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/305aed76-61ad-4de3-a445-c06d7e623cd0)
### ASM Debug
![2^20 ASM Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/93661099-29a5-4cf0-bc8b-048b059e3767)
### ASM Release
![2^20 ASM Release](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/a5688a8d-6922-4754-8be2-b6beb69967a8)


## 2^24

### C Debug
![2^24 C Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/6f4279df-5a56-42af-8c69-d2bb37574c79)
### C Release
![2^24 C Release](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/f808e1c3-de86-480a-8930-c2240085fa72)
### ASM Debug
![2^24 ASM Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/8b9eda05-4323-4daa-b4e4-958665ef1f66)
### ASM Release
![2^24 ASM Release](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/05309e92-bc18-4f53-9240-b0868e0a7297)


## 2^24

### C Debug
![2^30 C Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/4891dd10-fbe8-4c84-b618-307e8357f7d1)
### C Release
![2^30 C Release](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/37b156ca-a40e-4c7d-b40b-694d0a4295a2)
### ASM Debug
![2^30 ASM Debug](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/586b1c35-9369-4c13-9a6d-13dfc898f80a)
### ASM Release
![2^30 ASM Release](https://github.com/RovicBalanon/BALANON-S13-x86-to-C-Interface-Programming/assets/134363083/1a5a8327-e1de-4442-992e-56008c8a879d)
