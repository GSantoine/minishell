# Minishell - A simple shell inspired by Bash in C

## 8t

Minishell is a simplified shell implementation, providing a command-line interface where users can interact with the operating system by executing various commands.
The command line parsing is made recursively using a lexer parsing the line into tokens, building an AST. 


|    Project Name    |                                                                       minishell                                                                      |
| :----------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------: |
|    Description     |                                             An implementation of C-based shell capable of handling redirections, pipes, environment variables, and various built-in functionalities.                                             |
|    Technologies    | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries |     readline(), rl_clear_history(), rl_on_new_line(), rl_replace_line(), rl_redisplay(), add_history(), printf(), malloc(), free(), write(), access(), open(), read(), close(), fork(), wait(), waitpid(), wait3(), wait4(), signal(), sigaction(), sigemptyset(), sigaddset(), kill(), exit(), getcwd(), chdir(), stat(), lstat(), fstat(), unlink(), execve(), dup(), dup2(), pipe(), opendir(), readdir(), closedir(), strerror(), perror(), isatty(), ttyname(), ttyslot(), ioctl(), getenv(), tcsetattr(), tcgetattr(), tgetent(), tgetflag(), tgetnum(), tgetstr(), tgoto(), tputs()      |

## Features

- Executables search from PATH and launch: executes a wide range of commands, including both built-in commands and external commands available in the system.
- Built-in commands: custom implementation of common binaries such as cd, echo, pwd, exit, export, env, and unset.
- Redirection and Pipes: supports input/output redirection and pipes, allowing users to redirect command input and output streams.
- Signal Handling: handles various signals such as Ctrl-C, Ctrl-D and Ctrl-\, providing a graceful termination of running commands.
- Env management: manage environment variables, set new variables, and modify existing ones using the built-in commands.
- Environment variables expansion
- heredoc
- double quotes and single quotes
- interactive mode
- Command History
- $?

## Usage

```bash
  gcl https://github.com/GSantoine/minishell.git
  cd minishell
  make
  ./minishell
```

## Comments

The use of readline() cause memory leaks.
