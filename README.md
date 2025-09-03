# Minishell

A simple shell implementation in C that mimics basic functionality of bash.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Operators and Redirections](#operators-and-redirections)
- [Environment Variables](#environment-variables)
- [Signal Handling](#signal-handling)
- [Examples](#examples)
- [Testing](#testing)
- [Technical Details](#technical-details)
- [Known Issues](#known-issues)

## About

Minishell is a project that challenges you to create your own shell, similar to bash. This project teaches you about processes, file descriptors, pipes, redirections, and signal handling in Unix-like systems.

## Features

- **Command execution**: Execute commands with arguments
- **Built-in commands**: Implementation of essential shell built-ins
- **Pipes**: Support for command chaining with `|`
- **Redirections**: Input/output redirections (`<`, `>`, `>>`)
- **Here documents**: Support for `<<` operator
- **Environment variables**: Variable expansion and manipulation
- **Signal handling**: Proper handling of Ctrl+C, Ctrl+D, and Ctrl+\
- **Command history**: Navigate through command history with arrow keys
- **Quote handling**: Support for single and double quotes
- **Error handling**: Comprehensive error messages and exit codes

## Installation

### Prerequisites

- GCC compiler
- Make
- Readline library (`libreadline-dev` on Ubuntu/Debian)

### Build

```bash
# Clone the repository
git clone https://github.com/rustc0/minishell.git
cd minishell

# Compile the project
make

# Clean object files
make clean

# Clean everything including executable
make fclean

# Recompile everything
make re
```

## Usage

```bash
# Run minishell
./minishell
```

Once running, you can use it like any other shell:

```bash
minishell$ echo "Hello, World!"
Hello, World!
minishell$ ls -la
minishell$ pwd
minishell$ exit
```

## Built-in Commands

| Command | Description | Usage |
|---------|-------------|--------|
| `echo` | Display text with optional `-n` flag | `echo [-n] [text...]` |
| `cd` | Change directory | `cd [path]` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variables | `export [VAR=value]` |
| `unset` | Unset environment variables | `unset [VAR]` |
| `env` | Display environment variables | `env` |
| `exit` | Exit the shell | `exit [code]` |

### Built-in Command Details

#### echo
```bash
echo "Hello World"           # Hello World
echo -n "No newline"         # No newline (without trailing newline)
echo $HOME                   # /home/username
```

#### cd
```bash
cd                          # Go to home directory
cd /path/to/directory       # Go to specific directory
cd ..                       # Go to parent directory
```

#### export
```bash
export VAR=value            # Set variable
export                      # List all exported variables
```

## Operators and Redirections

### Pipes
```bash
ls | grep minishell         # Pipe output of ls to grep
cat file.txt | wc -l        # Count lines in file
```

### Input/Output Redirections
```bash
echo "Hello" > file.txt      # Redirect output to file (overwrite)
echo " World!" >> file.txt     # Redirect output to file (append)
cat < file.txt              # Redirect input from file
```

### Here Documents
```bash
cat << EOF
This is a here document
It continues until EOF
EOF
```

## Environment Variables

Minishell supports environment variable expansion:

```bash
echo $HOME                  # Print home directory
echo $PATH                  # Print PATH variable
echo $?                     # Print exit status of last command
```

### Special Variables

- `$?`: Exit status of the last executed command
- `$HOME`: Home directory
- `$PATH`: Executable search path
- `$PWD`: Current working directory

## Signal Handling

- **Ctrl+C (SIGINT)**: Interrupts the current command and shows a new prompt
- **Ctrl+D (EOF)**: Exits the shell when pressed at an empty prompt
- **Ctrl+\ (SIGQUIT)**: Does nothing in interactive mode

## Examples

### Basic Commands
```bash
minishell$ echo "Welcome to minishell"
Welcome to minishell
minishell$ pwd
/home/user/minishell
minishell$ ls -l
total 48
-rw-r--r-- 1 user user  1234 Jan  1 12:00 minishell.c
-rw-r--r-- 1 user user   567 Jan  1 12:00 Makefile
```

### Pipes and Redirections
```bash
minishell$ ls | grep ".c" > c_files.txt
minishell$ cat c_files.txt
minishell.c
parser.c
executor.c
minishell$ wc -l < c_files.txt
3
```

### Environment Variables
```bash
minishell$ export MY_VAR="Hello"
minishell$ echo $MY_VAR
Hello
minishell$ env | grep MY_VAR
MY_VAR=Hello
```

## Testing

### Manual Testing
```bash
# Test basic commands
./minishell
echo "test"
pwd
ls -la
exit

# Test pipes
ls | grep minishell
cat /etc/passwd | head -5 | tail -2

# Test redirections
echo "hello" > test.txt
cat < test.txt
echo "world" >> test.txt
cat test.txt
```

## Technical Details

### Architecture
```
┌─────────────────┐
│    Readline     │  ← Input handling
├─────────────────┤
│     Lexer       │  ← Tokenization
├─────────────────┤
│     Parser      │  ← Syntax analysis
├─────────────────┤
│    Executor     │  ← Command execution
├─────────────────┤
│   Built-ins     │  ← Built-in commands
└─────────────────┘
```

### Key Components

- **Lexer**: Tokenizes input into words, operators, and special characters
- **Parser**: Builds command structure and handles syntax validation
- **Executor**: Manages process creation, pipes, and redirections
- **Built-ins**: Implements shell built-in commands
- **Environment**: Manages environment variables and expansions
- **Signals**: Handles signal processing and cleanup

### Memory Management

- All heap allocations are properly freed
- No memory leaks in normal operation
- Cleanup on exit and signal interruption

## Known Issues

- Some advanced bash features are not implemented
- Performance may be slower than optimized shells

### Coding Standards

- Follow 42 School norm guidelines
- Use consistent indentation (tabs)
- Include proper error handling
- Write clear, documented code

**Note**: This minishell implementation is created for educational purposes as part of the 42 School curriculum. It demonstrates fundamental concepts of shell programming and Unix system calls.
