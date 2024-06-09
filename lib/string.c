/*
 *  linux/lib/string.c
 *
 *  (C) 1991  Linus Torvalds
 */

#ifndef __GNUC__
#error I want gcc!
#endif

/*
* 将关键字inline和static定义为空
* 则实际上内核函数库中又包含了string.h文件中所有被static和inline关键字定义的函数(eg:strcpy()函数)的一个副本
* 即又对这些函数重新定义了一遍，且“消除”了这两个关键字的作用
*   linux内核完全剖析 page：53-54
*/
#define extern
#define inline
#define __LIBRARY__
#include <string.h>
