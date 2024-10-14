#ifndef CIPHER_H
#define CIPHER_H

#include <stdint.h>

// This header file defines constants, structures, and function prototypes for a simple cipher

#define BLOCKSIZE 32
#define KEYSIZE 32

typedef uint32_t FIXEDPOINT_T;

typedef struct 
{
    FIXEDPOINT_T ENCRYPT;
    FIXEDPOINT_T DECRYPT;
} CIPHER;

// Initialize the cipher with a given key
void cipher_init(CIPHER *cipher, const uint8_t *key);

// Encrypt a block of data
void cipher_encrypt(const CIPHER *cipher, const uint8_t *plaintext, uint8_t *ciphertext);

// Decrypt a block of data
void cipher_decrypt(const CIPHER *cipher, const uint8_t *ciphertext, uint8_t *plaintext);

// Generate a random key
void generate_random_key(uint8_t *key);

// Cleanup and free any resources used by the cipher
void cipher_cleanup(CIPHER *cipher);

#endif // CIPHER_H