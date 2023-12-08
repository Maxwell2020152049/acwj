/*
 * @Author: wanfeng 1505991024@qq.com
 * @Date: 2023-12-06 11:12:20
 * @LastEditors: wanfeng 1505991024@qq.com
 * @LastEditTime: 2023-12-07 18:09:26
 * @FilePath: /acwj/02_Parser/data.h
 * @Description: 
 */
#include <stdio.h>

#ifndef extern_
    #define extern_ extern
#endif

/**
 * global variables
*/
extern_ int Line;           // number of lines in input file
extern_ int PutBack;        // put-back chatacter
extern_ FILE *InFile;       // input file
extern_ struct token Token; // scan token for parser
