/*
 * This code was generated with the assistance of an AI tool.
 * Original logic and design by Yi-Shou Lee.
 */

#include <stdio.h>
#include "cipher.h"

int main(void)
{
    // Create a cipher structure
    CIPHER cipher;
    
    // Generate a random key
    uint8_t key[KEYSIZE];
    generate_random_key(key);
    
    // Initialize the cipher with the generated key
    cipher_init(&cipher, key);
    
    // Example plaintext to encrypt
    uint8_t plaintext[BLOCKSIZE] = "Hello, World! This is a test.";
    uint8_t ciphertext[BLOCKSIZE];
    uint8_t decrypted[BLOCKSIZE];
    
    // Encrypt the plaintext
    cipher_encrypt(&cipher, plaintext, ciphertext);
    
    // Decrypt the ciphertext
    cipher_decrypt(&cipher, ciphertext, decrypted);
    
    // Print results
    printf("Original : %s\n", plaintext);
    printf("Encrypted: ");
    for (int i = 0; i < BLOCKSIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted: %s\n", decrypted);
    
    // Clean up
    cipher_cleanup(&cipher);
    
    return 0;
}