# 🚀 Description

> A minimal and efficient implementation of a line-by-line file reader in C.

## 📌 Overview

`get_next_line` is a function that reads from a file descriptor and returns one line at a time, including the trailing newline character (`\n`) if present.

It is part of the 42 school curriculum and focuses on:
- Efficient memory management
- Reading from file descriptors with various `BUFFER_SIZE`s
- Handling multiple file descriptors (bonus)
  
## ⚙️ Implementation Highlights
- Static stash buffer to retain leftover data between calls
- Efficient reading loop until a newline or EOF
- No memory leaks: verified using leaks

In the bonus version:

- Handles multiple FDs using a static array of stashes (indexed by fd)

## 🔍 Edge Cases Covered
Files with:
- No trailing newline
- Empty lines (\n\n)
- Only newline characters
- BUFFER_SIZE = 1, BUFFER_SIZE = 1024, etc.
- Alternating calls between different FDs

## 🚫 Forbidden

- Not allowed to use libft in this project.
- lseek() is forbidden.
- Global variables are forbidden.

## 🌟 Bonus part

- The get_next_line() can handle multiple file descriptors a the same time.

> Files related to the bonus should be named the same way as the mandatory part but with `_bonus[.c/.h]` appended at the end.

## 🧪 Testing
To run the tests, make sure you're inside the directory containing test_gnl.c and run the test script.

🔹 **Mandatory tests**  
```bash
test_script.sh
```  
🔸 **Bonus tests (multi-FD support)**  
```bash
BONUS=1 ./test_script.sh
```
> The BONUS environment variable will trigger compilation using the bonus source files.

## Final note

This project was done with all bonuses and will be included in my libft.
