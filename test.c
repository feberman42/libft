/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:32:28 by feberman          #+#    #+#             */
/*   Updated: 2023/05/07 17:07:12 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	ft_testchar(unsigned int i, char c);
void	ft_testchar2(unsigned int i, char *c);

void	part_one(void)
{
	printf("\n################\n### PART ONE ###\n################\n");
	printf("\nISALPHA\nD is alpha (%i), 7 is not (%i).\n",
		ft_isalpha('D'), ft_isalpha('7'));
	printf("\nISDIGIT\n6 is a digit (%i), V is not (%i).\n",
		ft_isdigit('6'), ft_isdigit('V'));
	printf("\nISALNUM\n7 is alnum (%i), G too (%i), but ; is not (%i)\n",
		ft_isalnum('7'), ft_isalnum('G'), ft_isalnum(';'));
	printf("\nISASCII\n32 is an ascii char (%i), 763 is not (%i)\n",
		ft_isascii(32), ft_isascii(763));
	printf("\nISPRINT\nk is printable (%i), (tab) is not(%i)\n",
		ft_isprint('k'), ft_isprint('\t'));
	printf("\nSTRLEN\nFreddy has %i characters.\n",
		ft_strlen("Freddy"));
	char	str[] = "abcdefghijklmnop...";
	printf("\nMEMSET\nReplace the first 3 Chars of the alphabet with $: %s\n",
		(unsigned char *) ft_memset(str, '$', 3));
	ft_bzero(str, 3);
	printf("\nBZERO\nDelete the $: %s%s\n",
		str, str + 3);
	printf("\nMEMCPY\nPut the first 3 characters back in: %s\n",
		(unsigned char *) ft_memcpy(str, "abcdefg", 3));
	printf("\nMEMMOVE\nOffset the first 3 characters by 1: %s\n",
		(unsigned char *) ft_memmove(str + 1, str, 3) - 1);
	char	test[20];
	ft_memset(test, '$', 19);
	ft_strlcpy(test, str, 6);
	printf("\nSTRLCPY\nExtract the first 5 characters from the previous output: %s\n",
		test);
	ft_bzero(test, 20);
	ft_strlcpy(test, "Hello ", 7);
	int	lcat = ft_strlcat(test, "world.........", 12);
	printf("\nSTRLCAT\nHello world 20?: %s %i\n",
		test, lcat);
	printf("\nTOUPPER\nTest n: %c\nTest @: %c\nTest N: %c\n",
		ft_toupper('n'), ft_toupper('@'), ft_toupper('N'));
	printf("\nTOLOWER\nTest n: %c\nTest @: %c\nTest N: %c\n",
		ft_tolower('n'), ft_tolower('@'), ft_tolower('N'));
	printf("\nSTRCHR\nFirst l in Hello: %s\n", ft_strchr("Hello", 'l'));
	printf("Test for null: %s\n", ft_strchr("Hello", 'k'));
	printf("\nSTRRCHR\nLast l in Hello: %s\n", ft_strrchr("Hello", 'l'));
	printf("Test for null: %s\n", ft_strrchr("Hello", 'k'));
	printf("\nSTRNCMP\nHello | Hallo 10: %i\nHello | Hella 4: %i\nHelloo | Hello 5: %i\nHello | Hello 12: %i\n",
		ft_strncmp("Hello", "Hallo", 10), ft_strncmp("Hello", "Hella", 4),
		ft_strncmp("Helloo", "Hello", 5), ft_strncmp("Hello", "Hello", 12));
	printf("\nMEMCHR\nFist l in Hello: %s\nTest for null: %s\n",
		(char *) ft_memchr("Hello", 'l', 8), (char *) ft_memchr("Hello", 'l', 2));
	printf("\nMEMCMP\nHello | Hello 6: %i\nHella | Hello 5: %i\n",
		ft_memcmp("Hello", "Hello", 6), ft_memcmp("Hella", "Hello", 5));
	printf("\nSTRNSTR\nFind me in Hello it's me (20): %s\nFind me in Hello it's me (12): %s\n",
		ft_strnstr("Hello it's me", "me", 20), ft_strnstr("Hello it's me", "me", 12));
	printf("\nATOI\n  \t  34 4jj3: %i\n  - 643: %i\n  -2147483648abc: %i\n",
		ft_atoi("  \t  34 4jj3"), ft_atoi("  - 643"), ft_atoi("  -2147483648abc"));
	printf("\nCALLOC\nTest for overflow detection: %s\n",
		(char *)ft_calloc(10, 2147483640));
	char	*dup = ft_strdup("Hello");
	printf("\nSTRDUP\nCreate copy of Hello: %s\n", dup);
	free(dup);
}

void	part_two(void)
{
	printf("\n################\n### PART two ###\n################\n");
	char	*str = ft_substr("abcdefghijklmnop", 2, 4);
	printf("\nSUBSTR\nThe fist 4 letters of the alphabet from the third on are: %s\n",
		str);
	free(str);
	str = ft_strjoin("abc", "def");
	printf("\nSTRJOIN\nabc + def = %s\n", str);
	free(str);
	str = ft_strtrim("abcdefghijklmnopqrstuvwxyz", "axbycz");
	printf("\nSTRTRIM\nStrip the first and last 3 letters of the alphabet: %s\n", str);
	free(str);
	str = ft_strtrim("abcdefghijklmnopqrstuvwxyz", "abcfhgjxyz");
	printf("Again, but with more set: %s\n", str);
	free(str);
	str = ft_strtrim("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
	printf("Remove the whole alphabet: %s\n", str);
	free(str);
	printf("\nSPLIT\nThe third word in this sentence is: %s\n",
		(ft_split("  The third   word in this   sentence is  ", ' '))[2]);
	str = ft_itoa(12345);
	printf("\nITOA\nOutput 12345: %s\n", str);
	free(str);
	str = ft_itoa(-2147483648);
	printf("Output -2147483648: %s\n", str);
	free(str);
	printf("\nSTRMAPI\nCapitalize the word: %s\n",
		ft_strmapi("hello", ft_testchar));
	char	test[] = "Hello";
	ft_striteri(test, ft_testchar2);
	printf("\nSTRITERI\nCapitalize the word: %s\n", test);
	ft_putstr_fd("\nPUTCHAR\nOutput c to terminal: ", 1);
	ft_putchar_fd('c', 1);
	ft_putstr_fd("\n\nPUTSTR\nOutput Hello to terminal: ", 1);
	ft_putstr_fd("Hello", 1);
	ft_putstr_fd("\n\nPUTENDL\nOutput a new line: ", 1);
	ft_putendl_fd("", 1);
	ft_putstr_fd("\nPUTNBR\nOutput the following numbers: 56, -123, -2147483648\n", 1);
	ft_putnbr_fd(56, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
}



int	main(void)
{
	part_one();
	part_two();
}

char	ft_testchar(unsigned int i, char c)
{
	i++;
	return (ft_toupper(c));
}

void	ft_testchar2(unsigned int i, char *c)
{
	i++;
	*c = ft_toupper(*c);
}
