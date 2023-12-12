/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-07 16:13:43
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-12 15:37:35
 * @FilePath: /acwj/03_Precedence/expr.c
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

static int op_precedence(int token_type) {
    static int OpPrec[] = {0, 10, 10, 20, 20, 0};

    int prec = OpPrec[token_type];

    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", Line, token_type);
        exit(1);
    }
    return prec;
}

/**
 * build an AST and return it
 * ptp: previous token precedence
*/
struct ASTnode* binary_expr(int ptp) {
    struct ASTnode *left, *right;
    int token_type, prec;

    left = primary();

    token_type = Token.token;
    if (token_type == T_EOF) {
        return left;
    }
    prec = op_precedence(Token.token);

    /**
     * left associative
     * right associative iff using >=
    */
    while (prec > ptp) {
        scan(&Token);
        right = binary_expr(prec);
        left = make_ast_node(arithop(token_type), 0, left, right);

        token_type = Token.token;

        if (token_type == T_EOF) {
            return left;
        }
        prec = op_precedence(token_type);
    }

    return left;
}
