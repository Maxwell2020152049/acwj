/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-07 16:13:43
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-08 09:56:42
 * @FilePath: /acwj/02_Parser/expr.c
 * @Description: 
 */

#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "defs.h"
#include "decl.h"

/**
 * arithmetic operation
 * map the token to operation or int literal
*/
static int arithop(int token) {
    switch (token)
    {
        case T_PLUS:
            return A_ADD;
        case T_MINUS:
            return A_SUBTRACT;
        case T_STAR:
            return A_MULTIPLY;
        case T_SLASH:
            return A_DIVIDE;
        case T_INTLIT:
            return A_INTLIT;    
        default:
            fprintf(stderr, "unknown token in arithop() in Line %d\n", Line);
            exit(1);
    }
}

/**
 * build the AST left child
 * it is int literal
*/
static struct ASTnode* primary() {
    struct ASTnode* n;

    switch (Token.token)
    {
        case T_INTLIT:
            n = make_ast_leaf(arithop(T_INTLIT), Token.int_value);
            scan(&Token);
            return n;
        default:
            fprintf(stderr, "syntax error on line %d\n", Line);
            exit(1);
    }
}

/**
 * build an AST and return it
*/
struct ASTnode* binary_expr() {
    struct ASTnode *n, *left, *right;
    int node_type;

    left = primary();

    if (Token.token == T_EOF) {
        return left;
    }

    node_type = arithop(Token.token);

    scan(&Token);

    right = binary_expr();

    n = make_ast_node(node_type, 0, left, right);

    return n;
}
