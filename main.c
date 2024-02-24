#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	char *x = "hello";
	//printf("%lu\n",LONG_MIN);
	//printf("%s",translate_to_hex(LONG_MIN));
	//ft_printf("%13p\n",(void *)13);
	//int a = printf("%13p\n",(void *)13);
	//printf("%p--------------\n", LONG_MIN);
	//printf(" %p \n", LONG_MIN);
	//ft_printf(" %p \n", LONG_MIN);
	int b = ft_printf("%#23x\n",1313);
	int a = printf("%#23x\n",1313);

	printf("a--------------%d\nb--------------%d\n",a,b);
	//printf("%p| %p|\n ",ULONG_MAX,-ULONG_MAX);
}