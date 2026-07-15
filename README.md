# minitalk

A client-server program in C that uses UNIX signals (`SIGUSR1` / `SIGUSR2`) to transmit strings between two independent processes — no sockets, no pipes, no shared memory, only signals.

## About

`minitalk` is a 42 School project focused on inter-process communication (IPC) at the lowest level available on UNIX: signals. The server prints its PID on startup and waits for the client to send it a message. The client, given the server's PID and a string, encodes each character bit by bit and sends it over using `SIGUSR1` (bit `0`) and `SIGUSR2` (bit `1`), one signal per bit.

The project also reuses a previously built 42 library — `ft_printf` (for formatted output) — included as a subdirectory.

## Project structure

| Path | Description |
|---|---|
| `server.c` | Server process — receives signals, decodes bits into characters, and prints the message |
| `client.c` | Client process — encodes a string into bits and sends it to the server via signals |
| `minitalk.h` | Shared header with function prototypes and definitions |
| `ft_printf/` | Custom `printf` implementation |
| `Makefile` | Build rules for the project |

## Compilation

```bash
make        # builds the server and client executables
make clean  # removes object files
make fclean # removes object files and the executables
make re     # rebuilds everything from scratch
```

## Usage

1. Start the server in one terminal — it will print its PID:

```bash
./server
```

2. In another terminal, send a message using the client:

```bash
./client <server_pid> "your message here"
```

The server will print the received message to the terminal.

## How it works

- Each character of the message is broken down into 8 bits.
- For every bit, the client sends `SIGUSR1` (bit = 0) or `SIGUSR2` (bit = 1) to the server's PID.
- The server's signal handler reconstructs each character bit by bit and prints it once a full byte is received.
- A null terminator signals the end of the message.

## Resources

While building and debugging this project, the following resources were especially helpful:

- **[Bash Reference Manual / GNU User Manuals](https://www.gnu.org/software/bash/manual/)** — used for understanding process IDs, signal handling concepts, and how the shell manages background processes.
- **[Stack Overflow](https://stackoverflow.com/)** — used to research signal handler safety (async-signal-safe functions), `sigaction` vs `signal`, race conditions between sender and receiver, and reliable signal delivery.

## Author

[bckblt](https://github.com/bckblt) — 42 School
