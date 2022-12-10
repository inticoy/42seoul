/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:15 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 19:12:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft;
	int	or;

	ft_printf("hello world!\n");
	ft_printf("%c\n", '&');
	ft_printf("%.4s\n", "testing %s");
	ft_printf("%p\n", &ft);
	ft_printf("%.d\n", 123);
	ft_printf("%i\n", -123);
	ft_printf("%u\n", -123);
	ft_printf("%x\n", 123);
	ft_printf("%X\n", 123);
	ft_printf("%%\n");
	ft_printf(":::%10s\n", NULL);
	ft_printf("----- ----- ----- -----\n");
	printf("hello world!\n");
	printf("%c\n", '&');
	printf("%.4s\n", "testing %s");
	printf("%p\n", &ft);
	printf("%.d\n", 123);
	printf("%i\n", -123);
	printf("%u\n", -123);
	printf("%x\n", 123);
	printf("%X\n", 123);
	printf("%%\n");
	printf(":::%10s\n", NULL);
	printf("----- ----- ----- -----\n");
	printf(" %p \n", -1);
	ft_printf(" %p \n", -1);

	/* printf("%c\n", 0);
    ft_printf("%c %c ",  0, '1');
    printf(" %c %c %c ", ' ', ' ', ' ');
    ft_printf(" %c %c %c ", ' ', ' ', ' ');
    printf("%d : \n\n", ft_printf("ft :%-5dE\n", -3));
    printf("%d : \n\n", printf("pr :%-5dE\n", -3));
    printf("%d : \n\n", ft_printf("ft :%-.5dE\n", -3));
    printf("%d : \n\n", printf("pr :%.5dE\n", -3));
    ft_printf("ft :%+.5dE\n", 3, 12);
    printf("pr :%+.5dE\n", 3);
    ft_printf("ft :%+ 8.4d\n", 5);
    //printf("pr :%+ 8.4d\n", 5);
    //ft_printf("ft :% 08.4d\n", 5);
    printf("pr :% 08.4d\n", 5);
    ft_printf("ft :% 08d\n", 5);
    printf("pr :% 08d\n", 5);
    ft_printf("ft :% 08.2d\n", 123);
    printf("pr :% 08.2d\n", 123);
    ft_printf("ft :%-.5dE\n", 3);
    printf("pr :%.5dE\n", 3);
    printf("%10cE\n", 'a');
    ft_printf("%10cE\n", 'a');
    printf("%-10cE\n", 'a');
    ft_printf("%-10cE\n", 'a');
    printf("%5sE\n", "abcd");
    ft_printf("%5sE\n", "abcd");
    printf("%2sE\n", "abcd");
    ft_printf("%2sE\n", "abcd");
    printf("%.5sE\n", "abcdefg");
    ft_printf("%.5sE\n", "abcdefg");
    printf("%-5sE\n", "abcd");
    ft_printf("%-5sE\n", "abcd");
    printf("%-.5sE\n", "abcdefg");
    ft_printf("%-.5sE\n", "abcdefg");
    printf("%u\n", 123);
    ft_printf("%u\n", 123);
    printf("%10u\n", 123);
    ft_printf("%10u\n", 123);
    printf("%.5u\n", 123);
    ft_printf("%.5u\n", 123);
    printf("%-10.5u\n", 123);
    ft_printf("%-10.5u\n", 123);
    int a_num = 3;
    int *a = &a_num;
    char *b = "123";
    printf("%30p\n", a);
    ft_printf("%30p\n", a);
    printf("%-10p\n", b);
    ft_printf("%-10p\n", b);
    printf("%10xE\n", -28);
    ft_printf("%10xE\n", -28);
    printf("%#10x\n", 28);
    ft_printf("%#10x\n", 28);
    printf("%#X\n", 28);
    ft_printf("%#X\n", 28);
    printf("%#10X\n", -200000);
    ft_printf("%#10X\n", -200000);
    printf("%#015X\n", 28);
    ft_printf("%#015X\n", 28);
    printf("%#015X\n", 0);
    ft_printf("%#015X\n", 0);
    printf("%#15X\n", 0);
    ft_printf("%#15X\n", 0);
    printf("%#15X\n", -12);
    ft_printf("%#15X\n", -12);
    printf("%#15X\n", 3);
    ft_printf("%#15X\n", 3);
    unsigned int au = 2147483649;
    ft_printf("%x\n", au);
    printf("%x\n", au); */

	return (0);
}
