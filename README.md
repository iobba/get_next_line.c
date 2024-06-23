# README.md

## Introduction

In the quest to simplify file reading in C, I embarked on the development of `get_next_line`, a function designed to elegantly extract lines from a file descriptor. This project not only challenged me to master the intricacies of file I/O and memory management but also pushed me to innovate within the constraints of C programming.

## Understanding `get_next_line`

`get_next_line` is a custom function I developed to streamline the process of reading text files line by line. It leverages the power of file descriptors to efficiently read content from a file, returning one line at a time until the end of the file is reached or an error occurs.

### Key Concepts

- **File Descriptors**: A unique identifier used by the operating system to access files or other I/O devices.
- **Buffer Management**: Managing small blocks of memory (buffers) to optimize data processing and reduce overhead.
- **Static Variables**: Persistent variables that retain their values between function calls, crucial for maintaining state across reads.

## Project Overview

### Function Prototype

- c char *get_next_line(int fd);
  
### Parameters

- `fd`: The file descriptor to read from.

### Return Value

- A line read from the file descriptor (`correct behavior`)
- `NULL`: Indicates there is nothing else to read or an error occurred.

### External Functions

- `read`
- `malloc`
- `free`

### Requirements

- Implement a function that reads a line from a file descriptor, returning it upon each call.
- Ensure the function handles errors gracefully, returning `NULL` when appropriate.
- The returned line should include the terminating `\n` character, except at EOF.
- Include the prototype of `get_next_line()` in `get_next_line.h`.
- Helper functions should be placed in `get_next_line_utils.c`.

### Compilation

Compile your code with the `-D BUFFER_SIZE=n` flag to define the buffer size for `read()`. For example:
 - ``` bash cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line ```

### Considerations

- Undefined behavior if the file descriptor changes between calls without reaching EOF.
- Undefined behavior when reading binary files. Optional optimizations may be applied.
- Efficiency: Try to read as little as possible each time `get_next_line()` is called.

### Forbidden Practices

- Use of `libft`.
- Use of `lseek()`.
- Use of global variables.

## Bonus Part

- Developing `get_next_line()` using only one static variable.
- Managing multiple file descriptors simultaneously without losing the reading thread of each.

### Submission Files

- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

## Conclusion

The development of `get_next_line` has been a journey of discovery and innovation, pushing the boundaries of what is possible with C programming. Through this project, I've gained a great understanding of file I/O.
