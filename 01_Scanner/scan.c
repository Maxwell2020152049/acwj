/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 11:12:12
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-06 20:16:10
 * @FilePath: /acwj/01_Scanner/scan.c
 * @Description: 
 */
#include "data.h"
#include "defs.h"
#include "decl.h"
#include <stdlib.h>

static int next() {
    int c;  // the next character

    /**
     * return put-back character if exists
    */
    if (PutBack) {
        c = PutBack;
        PutBack = 0;
        return c;
    }

    // read a character from input file
    c = fgetc(InFile);

    /**
     * count the number of lines in input file
    */
    if ('\n' == c) {
        Line ++;
    }

    return c;
}

/**
 * put back the unwanted character
*/
static void put_back(int c) {
    PutBack = c;
}

/**
 * skip whitespaces and newlines
 * return next character
*/
static int skip() {
    int c;

    c = next();
    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
        c = next();
    }
    return c;
}

/**
 * return 1 if c is a digit of 0 ... 9
 * return 0 if not
*/
static int is_digit(int c) {
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}

/**
 * scan a int with highest digit c
*/
static int scan_int(int highest_digit) {
    int int_lit = highest_digit - '0';
    int c;

    while (is_digit(c = next())) {
        c -= '0';   // TODO: use function char_pos()
        int_lit = int_lit * 10 + c;
    }
    put_back(c);
    return int_lit;
}

/**
 * scan a token from input file
 * return 1 if find a valid token
 * return 0 if no token left
*/
int scan(struct token* t)
{
    int c;

    c = skip();

    switch (c) {
        case EOF:
            return 0;   // arrive the end of input file
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default:
            if (is_digit(c)) {
                t->token = T_INTLIT;
                t->int_value = scan_int(c);
                break;
            }

            printf("Unrecognized character %c in line %d\n", c, Line);
            exit(1);
    }

    return 1;   // find a token
}
