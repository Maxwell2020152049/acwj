/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 20:23:02
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-08 10:32:29
 * @FilePath: /acwj/02_Parser/decl.h
 * @Description: 
 */

/**
 * declaration of functions in tree.c, scan.c and expr.c
*/

int scan(struct token* t);

struct ASTnode* make_ast_node(
    int op,
    int int_value,
    struct ASTnode* left,
    struct ASTnode* right
);

struct ASTnode* make_ast_leaf(int op, int int_value);

struct ASTnode* make_ast_unary(
    int op,
    int int_value,
    struct ASTnode* left
);

struct ASTnode* binary_expr();

int interpret_ast(struct ASTnode* n);
