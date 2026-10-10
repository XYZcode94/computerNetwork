# Computer Networks Lab Programs

This repository contains a collection of C socket programming exercises for Computer Networks, implemented using both TCP and UDP. The projects cover text transformation, student record lookup, text analysis, and network communication basics.

## Repository Overview

The repository includes:

- TCP client-server applications
- UDP client-server communication
- Student database queries using socket communication
- Network lab assignments in C

## Project Structure

- `tcp_server.c` — TCP server for text transformation (`UP`, `LOW`, `REV`)
- `tcp_client.c` — TCP client for sending transform commands
- `server_query.c` — TCP server for searching student information by registration number
- `client_query.c` — TCP client for student queries
- `server_counting.c` — TCP server for text analysis (`ANALYZE`)
- `client_counting.c` — TCP client for text analysis requests
- `Lab-06-server.c` — server for searching records from a file using a custom request structure
- `Lab-06-client.c` — client for the above file-search application
- `udp_server.c` — UDP server with roll-based authentication and commands
- `udp_client.c` — UDP client for sending commands to the UDP server
- `students.txt` — student database file used by query programs
- `computer_network_assignment.pdf` — assignment document

## Lab Assignments Covered

### 1. Text Transformer Using TCP Sockets

Files:
- `tcp_server.c`
- `tcp_client.c`

Features:
- Client sends messages in format: `COMMAND|TEXT`
- Supported commands:
  - `UP` — convert to uppercase
  - `LOW` — convert to lowercase
  - `REV` — reverse the text
- Uses TCP (`SOCK_STREAM`)
- Stops when client sends `bye`

Example:

```text
Request: UP|Hello world
Response: HELLO WORLD
```

### 2. Student Information Query Application

Files:
- `server_query.c`
- `client_query.c`
- `students.txt`

Features:
- Client sends a registration number
- Server searches the student data file
- Returns a record in the format:

```text
Name: Amit, Branch: ECE, College: GEC Kishanganj
```

If not found:

```text
Data not found
```

### 3. Text Analyzer Using TCP Sockets

Files:
- `server_counting.c`
- `client_counting.c`

Features:
- Client sends: `ANALYZE|TEXT`
- Server returns:
  - number of characters
  - number of words
  - number of vowels

Example:

```text
Request: ANALYZE|Hello World
Response: Chars = 11, Words = 2, Vowels = 3
```

### 4. UDP Communication Program

Files:
- `udp_server.c`
- `udp_client.c`

Features:
- Uses UDP sockets
- Requires a valid roll number for access
- Commands supported:
  - `UP|text`
  - `LOW|text`
  - `REV|text`
- Server can exit with `EXIT`

## How to Compile

Use GCC to compile the C programs.

### TCP Text Transformer

```bash
gcc tcp_server.c -o tcp_server
gcc tcp_client.c -o tcp_client
```

### Student Query Application

```bash
gcc server_query.c -o server_query
gcc client_query.c -o client_query
```

### Text Analyzer Application

```bash
gcc server_counting.c -o server_counting
gcc client_counting.c -o client_counting
```

### UDP Program

```bash
gcc udp_server.c -o udp_server
gcc udp_client.c -o udp_client
```

## How to Run

### TCP Server and Client

Start the server first:

```bash
./tcp_server
```

Then run the client:

```bash
./tcp_client
```

### Student Query Example

```bash
./server_query
./client_query
```

### Text Analyzer Example

```bash
./server_counting
./client_counting
```

### UDP Example

```bash
./udp_server
./udp_client 127.0.0.1 24157142024
```

## Notes

- Most programs are designed for local testing with `127.0.0.1`.
- Some programs can be updated to use other machine IPs by changing the address used in the client.
- The student query server reads data from `students.txt`.
- Ensure that the compiled binary and the data file are in the same working directory when needed.

## Technologies Used

- C Programming Language
- Linux/Unix socket APIs
- TCP sockets (`SOCK_STREAM`)
- UDP sockets (`SOCK_DGRAM`)
- Standard C libraries like `stdio.h`, `stdlib.h`, `string.h`, `unistd.h`, and `arpa/inet.h`

## Author

Government Engineering College Kishanganj
Department of Computer Science and Engineering

## License

This project is intended for academic learning and lab practice purposes.
