/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-07 16:13:31
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-08 10:41:39
 * @FilePath: /acwj/02_Parser/interp.c
 * @Description: 
 */
#include <stdio.h>
#include <stdlib.h>

#include "defs.h"

int interpret_ast(struct ASTnode* n) {
    int left_value, right_value;

    if (n->left) {
        left_value = interpret_ast(n->left);
    }
    if (n->right) {
        right_value = interpret_ast(n->right);
    }

    switch (n->op)
    {
        case A_ADD:
            printf("%d + %d\n", left_value, right_value);
            return left_value + right_value;
        case A_SUBTRACT:
            printf("%d - %d\n", left_value, right_value);
            return left_value - right_value;
        case A_MULTIPLY:
            printf("%d * %d\n", left_value, right_value);
            return left_value * right_value;
        case A_DIVIDE:
            printf("%d / %d\n", left_value, right_value);
            return left_value / right_value;
        case A_INTLIT:
            printf("int literal %d\n", n->int_value);
            return n->int_value;
        default:
            fprintf(stderr, "calculate error in interpret_ast()\n");
            exit(1);
    }
}
