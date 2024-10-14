#ifndef CIPHER_H
#define CIPHER_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// This header file defines constants, structures, and function implementations for a simple XOR cipher

#define BLOCKSIZE 32
#define KEYSIZE 32

typedef uint32_t FIXEDPOINT_T;

typedef struct 
{
    FIXEDPOINT_T ENCRYPT;
    FIXEDPOINT_T DECRYPT;
} CIPHER;

// Initialize the cipher with a given key
void cipher_init(CIPHER *cipher, const uint8_t *key) {
    memcpy(&cipher->ENCRYPT, key, sizeof(FIXEDPOINT_T));
    cipher->DECRYPT = cipher->ENCRYPT; // For XOR, encrypt and decrypt keys are the same
}

// Encrypt a block of data using XOR
void cipher_encrypt(const CIPHER *cipher, const uint8_t *plaintext, uint8_t *ciphertext) {
    for (int i = 0; i < BLOCKSIZE; i++) {
        ciphertext[i] = plaintext[i] ^ ((uint8_t*)&cipher->ENCRYPT)[i % sizeof(FIXEDPOINT_T)];
    }
}

// Decrypt a block of data using XOR
void cipher_decrypt(const CIPHER *cipher, const uint8_t *ciphertext, uint8_t *plaintext) {
    for (int i = 0; i < BLOCKSIZE; i++) {
        plaintext[i] = ciphertext[i] ^ ((uint8_t*)&cipher->DECRYPT)[i % sizeof(FIXEDPOINT_T)];
    }
}

// Generate a random key
void generate_random_key(uint8_t *key) {
    srand(time(NULL));
    for (int i = 0; i < KEYSIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Cleanup and free any resources used by the cipher
void cipher_cleanup(CIPHER *cipher) {
    // For this simple implementation, we don't need to free any resources
    // But we'll zero out the cipher structure for security
    memset(cipher, 0, sizeof(CIPHER));
}

#endif 