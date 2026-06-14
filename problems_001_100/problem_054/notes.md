# Project Euler Problem 54: Poker Hands

## Problem Statement

The file `p054_poker.txt` contains one-thousand random hands dealt to two players. Each line contains ten cards (separated by spaces): the first five are Player 1's hand, the last five are Player 2's hand. Cards are given as a value (2-9, T, J, Q, K, A) followed by a suit (C, D, H, S).

**Goal**: How many hands does Player 1 win?

## Data File

Download `p054_poker.txt` from https://projecteuler.net/resources/documents/0054_poker.txt and place it alongside the solution or in the repository root.

## Algorithmic Approach

1. **Parse Input**: Read each line, split into 10 cards, assign first 5 to Player 1 and last 5 to Player 2.
2. **Hand Evaluation**: Convert each hand into a rank tuple for lexicographic comparison:
   - **Straight Flush (8)**: Five consecutive values, all same suit. Special case: A-2-3-4-5 (wheel) with high card 5.
   - **Four of a Kind (7)**: Four cards of same value.
   - **Full House (6)**: Three of a kind plus a pair.
   - **Flush (5)**: All same suit.
   - **Straight (4)**: Five consecutive values.
   - **Three of a Kind (3)**: Three cards of same value.
   - **Two Pairs (2)**: Two different pairs.
   - **One Pair (1)**: Exactly one pair.
   - **High Card (0)**: None of the above.
3. **Tie-Breaking**: Each hand type includes kicker values in descending order within the rank tuple. Lexicographic comparison of the tuples resolves all ties.
4. **Count Wins**: Compare rank tuples for each deal and count Player 1 victories.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(H)$ where $H = 1000$ hands. Each hand is evaluated in $\mathcal{O}(1)$ time (sorting 5 cards and counting values).
- **Space Complexity**: $\mathcal{O}(1)$ per hand evaluation.

## Answer

376
