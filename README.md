# Computer Networks Lab — C Socket Programming

<p align="center">
  <strong>Government Engineering College, Kishanganj, Bihar</strong><br>
  Department of Computer Science and Engineering
</p>

---

## Student Information

| Field | Details |
| --- | --- |
| Student Name | Prem Prakash |
| Registration / Roll Number | 24157142024 |
| Branch | Computer Science and Engineering (CSE) |
| Specialization | Artificial Intelligence and Machine Learning (AI & ML) |
| Semester | 3rd Semester |
| Subject | Computer Networks |
| Programming Language | C |
| Operating System | Linux |

## 1. Aim

To practise computer networking by building small client-server programs in
C. The programs use UDP or TCP to send requests and return useful results.

## 2. Examples in This Project

| Folder | Network protocol | What it does | Port |
| --- | --- | --- | --- |
| [`udp-text-conversion/`](./udp-text-conversion/) | UDP | Changes text to uppercase, lowercase, or reverse order. | 30024 |
| [`tcp-text-conversion/`](./tcp-text-conversion/) | TCP | Changes text to uppercase, lowercase, or reverse order. | 8081 |
| [`student-lookup/`](./student-lookup/) | TCP | Looks up a student in a data file by ID. | 8080 |
| [`lab-06-record-search/`](./lab-06-record-search/) | TCP | Searches a data file sent by the client. | 8082 |
| [`text-analysis/`](./text-analysis/) | TCP | Counts the characters, words, and vowels in text. | 8083 |

## 3. Main Concepts

- Creating client and server sockets.
- Binding a server to a port and listening for clients.
- Sending and receiving data.
- Understanding the difference between connectionless UDP and connection-based
  TCP.
- Checking commands, IDs, and input files.
- Returning a result to the client.

## 4. Project Structure

```text
computer_network/
├── README.md
├── udp-text-conversion/
├── tcp-text-conversion/
├── student-lookup/
├── lab-06-record-search/
└── text-analysis/
```

Each example has its own C source files, Makefile, README, and data file if it
needs one. Open its README for full aims, objectives, build instructions,
sample output, and results.

## 5. Requirements

- Linux or Ubuntu on WSL.
- GCC compiler.
- `make`.
- Two terminal windows for each client-server example.

On Ubuntu or Debian, install the tools with:

```sh
sudo apt update
sudo apt install build-essential
```

## 6. Build and Run

For example, to build the UDP text transformer:

```sh
cd udp-text-conversion
make
```

Start `./server` in one terminal. Open a second terminal in the same folder
and follow that example's README to start its client. The examples use
`127.0.0.1`, so both programs can run on one Linux computer. Use the server's
LAN IP instead if the client runs on another computer.

Remove generated programs with:

```sh
make clean
```

Each example has its own Makefile. Build and clean it from that example's
folder.

## 7. Results

The UDP and TCP text services transform client text. The student and record
search services return matching records. The text analysis service reports
character, word, and vowel counts. Each example prints its result in the
client terminal.

---

**Submitted by:** Prem Prakash  
**Department:** Computer Science and Engineering  
**College:** Government Engineering College, Kishanganj, Bihar
