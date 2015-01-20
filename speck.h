// ===========================================================================
// SPECK implementation
// =========================================================================
// Copyright (c) 2014 Ralph Ankele

// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#ifndef _SPECK_H_
#define _SPECK_H_

#include <cstdint>

//Definitions
//16 (4), 24 (3,4), 32 (3,4), 48 (2,3), 64 (2,3,4)
#define WORD_SIZE 64
#define KEY_WORDS 4

#if (WORD_SIZE == 64)
    #define WORD_MASK (0xffffffffffffffffull)
#else
    #define WORD_MASK ((0x1ull << (WORD_SIZE&63)) - 1)
#endif

#if (WORD_SIZE == 16)
    #define ROUNDS (22)
    #define CONST_ALPHA (7)
    #define CONST_BETHA (2)
#elif (WORD_SIZE == 24)
    #define CONST_ALPHA (8)
    #define CONST_BETHA (3)
    #if (KEY_WORDS == 3)
        #define ROUNDS (22)
    #elif (KEY_WORDS == 4)
        #define ROUNDS (23)
    #endif
#elif (WORD_SIZE == 32)
    #define CONST_ALPHA (8)
    #define CONST_BETHA (3)
    #if (KEY_WORDS == 3)
        #define ROUNDS (26)
    #elif (KEY_WORDS == 4)
        #define ROUNDS (27)
    #endif
#elif (WORD_SIZE == 48)
    #define CONST_ALPHA (8)
    #define CONST_BETHA (3)
    #if (KEY_WORDS == 2)
        #define ROUNDS (28)
    #elif (KEY_WORDS == 3)
        #define ROUNDS (29)
    #endif
#elif (WORD_SIZE == 64)
    #define CONST_ALPHA (8)
    #define CONST_BETHA (3)
    #if (KEY_WORDS == 2)
        #define ROUNDS (32)
    #elif (KEY_WORDS == 3)
        #define ROUNDS (33)
    #elif (KEY_WORDS == 4)
        #define ROUNDS (34)
    #endif
#endif

//Functions
void keySchedule();
void encrypt(uint64_t &left, uint64_t &right);
void encrypt(uint64_t &left, uint64_t &right, int rounds);
void decrypt(uint64_t &left, uint64_t &right);
void decrypt(uint64_t &left, uint64_t &right, int rounds);

//Helper Functions
uint64_t S(uint64_t state, int distance);
void generateKey();

//Test-Functions
int test_vectors();

#endif
