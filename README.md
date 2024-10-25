# Cryptographic Algorithm in Bit-Acccurate Model

This project implements a simple XOR cipher for encrypting and decrypting data. The project is written in C and includes a Makefile for building the executable.

## Project Structure

- **main.c**: The main entry point of the application. It demonstrates the usage of the cipher by encrypting and decrypting a sample plaintext.
- **cipher.c**: Contains the implementation of the cipher functions, including initialization, encryption, decryption, key generation, and cleanup.
- **cipher.h**: Header file defining constants, structures, and function prototypes for the cipher.
- **Makefile**: Used to compile the project.

## Features

- **XOR Encryption/Decryption**: Uses a simple XOR operation for encrypting and decrypting data.
- **Random Key Generation**: Generates a random key for encryption.
- **Block Size**: Supports a block size of 32 bytes.
- **Key Size**: Uses a key size of 32 bytes.

## Usage

1. **Build the Project**: Use the Makefile to compile the project.
   ```bash
   make
   ```

2. **Run the Executable**: After building, run the `main` executable.
   ```bash
   ./main
   ```

3. **Clean the Build**: To clean up the compiled files, use:
   ```bash
   make clean
   ```

## Code Overview

- **main.c**: Demonstrates the encryption and decryption process.
  ```c:main.c
  startLine: 9
  endLine: 44
  ```

- **cipher.c**: Implements the core functionality of the cipher.
  ```c:cipher.c
  startLine: 22
  endLine: 55
  ```

- **cipher.h**: Provides the necessary declarations for the cipher.
  ```cipher.h
  startLine: 8
  endLine: 32
  ```

## Dependencies

- **C Compiler**: Ensure you have a C compiler like `gcc` installed on your system.

## Acknowledgments

- Original logic and design by Yi-Shou Lee.
