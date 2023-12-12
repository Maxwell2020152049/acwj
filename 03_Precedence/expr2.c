/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-12 10:45:47
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-12 14:29:47
 * @FilePath: /acwj/03_Precedence/expr2.c
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
 * build an AST tree
 * until finding ADD (+), SUB (-) or EOF
*/
struct ASTnode* mul_expr() {
    struct ASTnode *left, *right;
    int node_type;

    left = primary();
    node_type = Token.token;

    if (node_type == T_EOF || node_type == T_PLUS || node_type == T_MINUS) {
        return left;
    }

    while (1) {
        scan(&Token);
        right = primary();
        left = make_ast_node(arithop(node_type), 0, left, right);

        node_type = Token.token;
        if (node_type == T_EOF || node_type == T_PLUS || node_type == T_MINUS) {
            return left;
        }
    }
}

/**
 * build an AST tree
 * until finding EOF
*/
struct ASTnode* add_expr() {
    struct ASTnode *left, *right;
    int node_type;

    left = mul_expr();
    node_type = Token.token;

    if (node_type == T_EOF) {
        return left;
    }

    while (1) {
        scan(&Token);
        right = mul_expr();
        left = make_ast_node(arithop(node_type), 0, left, right);

        node_type = Token.token;
        if (node_type == T_EOF) {
            return left;
        }
    }
}
