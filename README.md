# Government Engineering College Kishanganj

## Department of Computer Science and Engineering

# Computer Networks

---

# LAB-03

## Text Transformer Application Using TCP Sockets

### Objective

The objective of this assignment is to implement a basic client-server application using TCP sockets in C.

### Problem Statement

Design and implement a **Text Transformer Application** using TCP sockets with the following specifications.

### Server Requirements

The server must:

- Use TCP (`SOCK_STREAM`) sockets.
- Listen for incoming connections on port `8081`.
- Accept client connections and process requests.
- Support the following text transformation commands:
  - `UP` — Convert text to uppercase.
  - `LOW` — Convert text to lowercase.
  - `REV` — Reverse the text.

### Client Requirements

The client must:

- Connect to the server using its IP address.
- Support both localhost and remote server connections.
- Send transformation requests in the following format:

```text
COMMAND|TEXT
```

### Supported Commands

| Command | Description |
|---|---|
| `UP` | Convert TEXT to uppercase |
| `LOW` | Convert TEXT to lowercase |
| `REV` | Reverse TEXT |

### Server Response

The server processes the request and sends back the transformed text.

### Example

**Request:**

```text
UP|Hello world
```

**Response:**

```text
HELLO WORLD
```

### Communication Rules

- The client and server should communicate continuously in a loop.
- The session ends when the client sends the message:

```text
bye
```

- Upon receiving `bye`, the server must gracefully terminate the connection.

### Additional Requirements

- Use standard C libraries such as `string.h` for string manipulation.
- Use TCP sockets (`SOCK_STREAM`).
- The program should work on the same machine using:
  - `localhost`
  - `127.0.0.1`
- The program should also work between different machines using their actual IP addresses.
- Properly parse the request using the `|` delimiter.
- Handle invalid commands appropriately.

---

# LAB-04

## Student Information Query Application Using TCP Sockets

### Objective

To implement a TCP-based client-server application in C that performs query-based retrieval of student information.

### Problem Statement

Design and implement a TCP client-server program in C with the following specifications.

### Server Requirements

The server maintains a text file containing student records.

Each record consists of the following fields:

- Registration Number
- First Name (`FName`)
- Branch
- College Name

### Client Requirements

The client sends a **Registration Number** as a query to the server.

### Server Operations

Upon receiving a registration number, the server must:

1. Search the database file for a matching Registration Number.
2. If a match is found, send the following information back to the client:
   - First Name
   - Branch
   - College Name
3. If no match is found, send:

```text
Data not found
```

### Communication Requirements

- The communication between client and server should be continuous.
- The client should be able to send multiple queries in a single session.
- The connection must remain persistent while the client sends queries.
- The session terminates only when the client sends:

```text
bye
```

- After receiving `bye`, both client and server should close the connection gracefully.

### Sample Input/Output

**Client Input:**

```text
1002
```

**Server Output:**

```text
Name: Amit, Branch: ECE, College: GEC Kishanganj
```

**Client Input:**

```text
9999
```

**Server Output:**

```text
Data not found
```

**Client Input:**

```text
bye
```

**Output:**

```text
Connection terminated
```

### Additional Requirements

- Use TCP sockets (`SOCK_STREAM`).
- The server should maintain the student records in a text file.
- The client should support multiple queries without reconnecting.
- The server should search the file for every registration number received.
- Handle missing or unavailable database files appropriately.
- Support localhost and remote server connections.
- Close sockets gracefully when the session ends.

---

# LAB-05

## Text Analyzer Application Using TCP Sockets

### Objective

To design and implement a client-server application using TCP sockets in C that performs basic text analysis.

### Problem Statement

Develop a TCP-based application where:

- The client sends a request in the following format:

```text
ANALYZE|TEXT
```

- The server processes the text and returns:
  - Number of characters
  - Number of words
  - Number of vowels

### Example

**Request:**

```text
ANALYZE|Hello World
```

**Response:**

```text
Chars=11, Words=2, Vowels=3
```

### Additional Requirements

1. Use TCP sockets (`SOCK_STREAM`).
2. The client and server should maintain a persistent connection.
3. The client should be able to send multiple requests in a single session.
4. The server should process each request and return the corresponding text analysis.
5. Properly parse input using the delimiter `|`.
6. The supported command is:

```text
ANALYZE
```

7. The server should calculate:
   - Number of characters
   - Number of words
   - Number of vowels
8. The session must continue until the client sends:

```text
bye
```

9. When `bye` is received, both the client and server should close the connection gracefully.
10. Handle invalid commands appropriately.
11. Use standard C libraries and TCP socket programming functions.
12. The application should support multiple text-analysis requests over the same TCP connection.

---

# General Instructions

- Implement each assignment using the C programming language.
- Use TCP sockets (`SOCK_STREAM`).
- Implement separate client and server programs.
- Test the applications using localhost (`127.0.0.1`).
- The applications should also support communication between different machines using their IP addresses.
- Maintain a persistent connection wherever specified.
- Handle connection errors and invalid requests appropriately.
- Close sockets gracefully after communication is completed.
