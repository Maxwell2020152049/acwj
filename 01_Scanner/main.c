/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 14:26:07
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-06 20:36:03
 * @FilePath: /acwj/01_Scanner/main.c
 * @Description: 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * note: the order of defs.h and decl.h can't be change
 * warnings will happen if changed
*/
#include "defs.h"
#include "decl.h"

#define extern_
#include "data.h"
#undef extern_

/**
 * initialize global variables
*/
static void init() {
    Line = 1;       // number of lines in input file is at least one
    PutBack = 0;    // no put back character at the beginning
}

/**
 * scan all tokens from input file
*/
static void scan_file() {
    struct token t;

    // list of printable tokens
    char* token_str[] = {"+", "-", "*", "/", "INTLIT"};

    while (scan(&t)) {
        printf("Token %s", token_str[t.token]);

        if (t.token == T_INTLIT) {
            printf(", value %d", t.int_value);
        }
        printf("\n");
    }
    printf("Line is %d\n", Line);
}

void main(int argc, char* argv[]) {
    init();

    InFile = fopen(argv[1], "r");

    scan_file();

    exit(0);
}
