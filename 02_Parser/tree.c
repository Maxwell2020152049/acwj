/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-07 16:13:14
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-07 17:12:20
 * @FilePath: /acwj/02_Parser/tree.c
 * @Description: 
 */

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"

/**
 * make an AST node
 * using malloc()
*/
struct ASTnode* make_ast_node(
    int op,
    int int_value,
    struct ASTnode* left,
    struct ASTnode* right
) {
    struct ASTnode* n;

    n = (struct ASTnode*) malloc(sizeof (struct ASTnode));

    if (n == NULL) {
        fprintf(stderr, "No more memory to make an ASTnode in make_ast_node()\n");
        exit(1);
    }

    n->op = op;
    n->int_value = int_value;
    n->left = left;
    n->right = right;

    return n;
}

/**
 * make an AST leaf
 * using make_ast_node()
*/
struct ASTnode* make_ast_leaf(int op, int int_value) {
    return make_ast_node(op, int_value, NULL, NULL);
}

/**
 * make an AST unary node
 * using make_ast_node()
*/
struct ASTnode* make_ast_unary(
    int op,
    int int_value,
    struct ASTnode* left
) {
    return make_ast_node(op, int_value, left, NULL);
}
