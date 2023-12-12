/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 14:26:07
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-12 15:25:28
 * @FilePath: /acwj/03_Precedence/main.c
 * @Description: 
 */

#include <stdio.h>
#include <stdlib.h>

#define extern_
#include "data.h"
#undef extern_

/**
 * note: the order of defs.h and decl.h can't be changed
 * warnings will happen if changed
*/
#include "defs.h"
#include "decl.h"

/**
 * initialize global variables
*/
static void init() {
    Line = 1;       // number of lines in input file is at least one
    PutBack = 0;    // no put back character at the beginning
}

void main(int argc, char* argv[]) {
    init();

    InFile = fopen(argv[1], "r");

    scan(&Token);
    // struct ASTnode *n = add_expr();
    struct ASTnode *n = binary_expr(0);

    printf("%d\n", interpret_ast(n));

    exit(0);
}
