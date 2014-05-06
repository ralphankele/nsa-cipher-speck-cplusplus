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

#include "speck.h"
#include <iostream>
#include <time.h>

uint64_t key[ROUNDS] = { 0 };

uint64_t S(uint64_t state, int distance){
    if(distance > WORD_SIZE || distance < - WORD_SIZE)
        return -1;

    return (distance > 0) ? 
    ((state << distance) | (state >> (WORD_SIZE-distance))) & WORD_MASK : 
    ((state >> (-distance)) | (state << (WORD_SIZE+distance))) & WORD_MASK;
}

void keySchedule(){
    
    /*for(int i = KEY_WORDS; i < ROUNDS; ++i){

    }*/
    
    /*for (int i = 0; i < ROUNDS; ++i)
        printf("%llx\n", key[i]);
    printf("\n\n");*/
}

void encrypt(uint64_t &left, uint64_t &right){
    encrypt(left, right, ROUNDS);
}

void encrypt(uint64_t &left, uint64_t &right, int rounds){
    
    /*for(int i = 0; i < rounds; ++i){
        //printf("K: %.4llx, L: %.4llx, R: %.4llx \n",key[i], left, right);
    }*/
}

void decrypt(uint64_t &left, uint64_t &right){
    decrypt(left, right, ROUNDS);
}

void decrypt(uint64_t &left, uint64_t &right, int rounds){

    /*for(int i = 0; i < rounds; ++i){

    }*/
}

void generateKey(){
    
    /*srand (time(NULL));
    for(int i = 0; i < KEY_WORDS; i++){
        key[i] = rand() & WORD_MASK;
    }*/

    //keySchedule();
    
    /*for(int i = 0; i < ROUNDS; i++){
        printf("key: %llx \n", key[i]);
    }*/
}

int test_vectors(){
    uint64_t R, L, ENC_R, ENC_L;

    // Speck32/64
    /*if (WORD_SIZE == 16 && KEY_WORDS == 4) {
        key[3] = 0x0000;
        key[2] = 0x0000;
        key[1] = 0x0000;
        key[0] = 0x0000;
        L = 0x0000;
        R = 0x0000;
        ENC_L = 0x4637;
        ENC_R = 0x22f5;
    }*/
    
    // Speck48/72
    /*if (WORD_SIZE == 24 && KEY_WORDS == 3) {
        key[2] = 0x121110;
        key[1] = 0x0a0908;
        key[0] = 0x020100;
        L = 0x612067;
        R = 0x6e696c;
        ENC_L = 0xdae5ac;
        ENC_R = 0x292cac;
    }*/

    // Speck48/96
    /*if (WORD_SIZE == 24 && KEY_WORDS == 4) {
        key[3] = 0x1a1918;
        key[2] = 0x121110;
        key[1] = 0x0a0908;
        key[0] = 0x020100;
        L = 0x726963;
        R = 0x20646e;
        ENC_L = 0x6e06a5;
        ENC_R = 0xacf156;
    }*/

    // Speck64/96
    /*if (WORD_SIZE == 32 && KEY_WORDS == 3) {
        key[2] = 0x13121110;
        key[1] = 0x0b0a0908;
        key[0] = 0x03020100;
        L = 0x6f722067;
        R = 0x6e696c63;
        ENC_L = 0x5ca2e27f;
        ENC_R = 0x111a8fc8;
    }*/

    // Speck64/128
    /*if (WORD_SIZE == 32 && KEY_WORDS == 4) {
        key[3] = 0x1b1a1918;
        key[2] = 0x13121110;
        key[1] = 0x0b0a0908;
        key[0] = 0x03020100;
        L = 0x656b696c;
        R = 0x20646e75;
        ENC_L = 0x44c8fc20;
        ENC_R = 0xb9dfa07a;
    }*/

    // Speck96/96
    /*if (WORD_SIZE == 48 && KEY_WORDS == 2) {
        key[1] = 0x0d0c0b0a0908;
        key[0] = 0x050403020100;
        L = 0x2072616c6c69;
        R = 0x702065687420;
        ENC_L = 0x602807a462b4;
        ENC_R = 0x69063d8ff082;
    }*/

    // Speck96/144
    /*if (WORD_SIZE == 48 && KEY_WORDS == 3) {
        key[2] = 0x151413121110;
        key[1] = 0x0d0c0b0a0908;
        key[0] = 0x050403020100;
        L = 0x746168742074;
        R = 0x73756420666f;
        ENC_L = 0xecad1c6c451e;
        ENC_R = 0x3f59c5db1ae9;
    }*/

    // Speck128/128
    /*if (WORD_SIZE == 64 && KEY_WORDS == 2) {
        key[1] = 0x0f0e0d0c0b0a0908;
        key[0] = 0x0706050403020100;
        L = 0x6373656420737265;
        R = 0x6c6c657661727420;
        ENC_L = 0x49681b1e1e54fe3f;
        ENC_R = 0x65aa832af84e0bbc;
    }*/

    // Speck128/192
    /*if (WORD_SIZE == 64 && KEY_WORDS == 3) {
        key[2] = 0x1716151413121110;
        key[1] = 0x0f0e0d0c0b0a0908;
        key[0] = 0x0706050403020100;
        L = 0x206572656874206e;
        R = 0x6568772065626972;
        ENC_L = 0xc4ac61effcdc0d4f;
        ENC_R = 0x6c9c8d6e2597b85b;
    }*/

    // Speck128/256
    /*if (WORD_SIZE == 64 && KEY_WORDS == 4) {
        key[3] = 0x1f1e1d1c1b1a1918; 
        key[2] = 0x1716151413121110; 
        key[1] = 0x0f0e0d0c0b0a0908; 
        key[0] = 0x0706050403020100; 
        L = 0x74206e69206d6f6f; 
        R = 0x6d69732061207369; 
        ENC_L = 0x8d2b5579afc8a3a0; 
        ENC_R = 0x3bf72a87efe7b868;
    }*/

    /*keySchedule();
    
    printf("K: XXXX, L: %.4llx, R: %.4llx \n", L, R);
    encrypt(L, R);

    if(L != ENC_L || R != ENC_R)
        return -1;*/
    return 0;
}
