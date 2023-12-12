/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 10:24:19
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-08 09:33:07
 * @FilePath: /acwj/02_Parser/defs.h
 * @Description: 
 */

/**
 * Token structure
 * token: type of token
 * int_value: 
 *  store int value having one or more digits of 0 ... 9
 *  iff token is T_INTLIT
*/
struct token {
    int token;
    int int_value;
};

/**
 * AST node
 * op: operation of expression
 * int_value: int literal iff op is A_INTLIT
 * left: left child of node
 * right: right child of node
*/
struct ASTnode {
    int op;
    int int_value;
    struct ASTnode* left;
    struct ASTnode* right;
};

/**
 * Token type
 * T_EOF:   EOF (end of file)
 * T_PLUS:  +
 * T_MINUS: -
 * T_STAR： *
 * T_SLASH: /
 * T_INTLIT: int literal
*/
enum {
    T_EOF,
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT
};

/**
 * AST node type
 * A_ADD:       +
 * A_SUBTRACT:  -
 * A_MULTIPLY： *
 * A_DIVIDE:    /
 * A_INTLIT:    int literal
*/
enum {
    A_ADD,
    A_SUBTRACT,
    A_MULTIPLY,
    A_DIVIDE,
    A_INTLIT
};
