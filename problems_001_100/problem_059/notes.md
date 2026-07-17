# Project Euler Problem 59: XOR Decryption

## Problem Statement

The encrypted file contains ASCII codes produced by XORing English text with a repeated three-letter lowercase key.

**Goal**: Decrypt the message and find the sum of the ASCII values in the original plaintext.

## Algorithmic Approach

1. Load the comma-separated cipher values from `p059_cipher.txt`.
2. Try every three-letter lowercase key from `aaa` to `zzz`.
3. Decrypt the text with repeated-key XOR.
4. Reject keys that create non-printable plaintext.
5. Score the remaining plaintext candidates using common English letters and words.
6. Keep the best-scoring plaintext and print its ASCII sum.

The winning key decrypts the full text cleanly, and the required output is only the sum.

## Complexity Analysis

- **Time Complexity**: `O(26^3 * N)` where `N` is the cipher length.
- **Space Complexity**: `O(N)` for the cipher and plaintext candidate.

## Answer

129448
