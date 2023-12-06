/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 10:24:19
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-06 10:50:32
 * @FilePath: /acwj/defs.h
 * @Description: 
 */

/**
 * Token structure
 * token: type of token
 * int_value: 
 *  store int value having one or more digits of 0 ... 9
 *  iff token is T_INTLIT
*/
struct token
{
    int token;
    int int_value;
};

/**
 * Token type
 * T_PLUS:  +
 * T_MINUS: -
 * T_STAR： *
 * T_SLASH: /
 * T_INTLIT: int literal
*/
enum {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT
};
