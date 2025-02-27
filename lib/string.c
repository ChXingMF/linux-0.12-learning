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
*char * strcpy(char * dest,const char *src)
// {
// __asm__("cld\n"								// 清方向位
// 	"1:\tlodsb\n\t"							// 加载DS:[esi]处1字节->al,并更新esi
// 	"stosb\n\t"								// 存储字节al->ES[edi],并更新edi
// 	"testb %%al,%%al\n\t"					// 刚刚储存的字节是否为0？
// 	"jne 1b"								// 不是，则向后跳转到标号1处，否则结束
// 	::"S" (src),"D" (dest):"si","di","ax");
// return dest;								// // 返回目的字符串
// }
* 即又对这些函数重新定义了一遍，且“消除”了这两个关键字的作用
*   linux内核完全剖析 page：53-54
*/
#define extern
#define inline
#define __LIBRARY__
#include <string.h>
