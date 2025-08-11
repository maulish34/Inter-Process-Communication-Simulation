# Inter-Process Communication Simulation

## Project Overview

This project implements a simulation of inter-process communication (IPC) mechanisms using job queues in C. It demonstrates concepts related to process synchronization, job management, and queue-based IPC. The codebase is modular, includes unit tests, and supports building and running on Unix-like systems (Linux, macOS) and Windows via WSL (Windows Subsystem for Linux).

### Key Features

- **Job Management:** Creation, manipulation, and string representation of jobs.
- **Priority Job Queues:** Implementation of priority-based job queues.
- **IPC Job Queues:** Wrappers for job queues to simulate inter-process communication.
- **Semaphore-based Job Queues:** Further abstraction using semaphores for synchronization.
- **Comprehensive Unit Tests:** Provided for all modules to ensure correctness.
- **Makefile-based Build System:** Simplifies compilation and testing.

## Significance

Understanding IPC and job queue management is fundamental in systems programming and operating system design. This project provides hands-on experience with:

- Structs and memory management in C
- String manipulation and parsing
- Synchronization primitives (semaphores)
- Modular programming and unit testing
- Cross-platform development practices

## Getting Started

### Prerequisites

- **C Compiler:** `gcc` or `clang`
- **Make:** GNU Make
- **Git:** For cloning the repository
- **WSL (Windows only):** Recommended for Windows users to provide a Unix-like environment

### Cloning the Repository

```sh
git clone <repository-url>
cd Inter-Process-Communication-Simulation
```

Replace `<repository-url>` with the actual URL of your repository.

---

## Building and Running the Project

### On Mac/Linux

1. **Open a terminal and navigate to the project directory:**
    ```sh
    cd Inter-Process-Communication-Simulation
    ```

2. **Build the project:**
    ```sh
    make
    ```

3. **Run all tests:**
    ```sh
    ./runtests.sh
    ```

4. **Run individual tests (optional):**
    ```sh
    ./bin/test/test_<module_name>
    ```
    Replace `<module_name>` with the desired module (e.g., `joblog`).

---

### On Windows (Using WSL - Recommended)

1. **Install WSL and a Linux distribution (e.g., Ubuntu) if not already installed.**
   - [Microsoft WSL Installation Guide](https://docs.microsoft.com/en-us/windows/wsl/install)

2. **Open your WSL terminal.**

3. **Clone the repository inside your WSL home directory:**
    ```sh
    git clone <repository-url>
    cd Inter-Process-Communication-Simulation
    ```

4. **Install required packages (if not already installed):**
    ```sh
    sudo apt update
    sudo apt install build-essential git
    ```

5. **Build and run the project as described for Mac/Linux:**
    ```sh
    make
    ./runtests.sh
    ```

---

## Additional Notes

- **Cleaning the Build:**
    ```sh
    make clean
    ```

- **Rebuilding Dependencies:**
    ```sh
    make clean_depend
    make depend
    ```

- **Troubleshooting:**
    - If a test hangs, use `CTRL+C` to terminate.
    - Compiler warnings should be fixed.

- **Further Documentation:**
    - See `README01.txt` and `README02.txt` for detailed instructions and guidance.
    - Review header files (`.h`) for function documentation.

---

## License

This project is for educational purposes only. Credits for the boilerplate code go to Newcastle University.

