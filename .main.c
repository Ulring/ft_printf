#include "include/ft_printf.h"
#include <stdio.h>
# include <assert.h>
#include <string.h>

int main(void)
{
    int i,age,i_a,i_b,i_c;
    unsigned int unsigned_a;
    int hex_a;
    char letter;
    char *word;
    void *ptr;

    i = 0;
    age = 21;
    i_a = 12;
    i_b = 012;
    i_c = 0x12;
    hex_a = 700;
    unsigned_a = -1;
    letter = 'I';
    word = "old";
    ptr = &age;

	/*
	ft_putstr("==>Printing a string:\n");
    printf(	  "printf:		test.\n");
    ft_printf("ft_prinft:	test.\n");

	ft_putstr("\n==>Testing %%c, %%d and %%s:\n");
    printf(   "printf:		%c am %d years %s.\n", letter, age, word);
    ft_printf("ft_printf:	%c am %d years %s.\n", letter, age, word);
	
	ft_putstr("\n==>Testing %%p:\n");
    printf(   "printf:		The address of ptr is: %p.\n", ptr);
	ft_printf("ft_printf:	The address of ptr is: %p.\n", ptr);
    
	ft_putstr("\n==>Testing %%i:\n");
    printf(   "printf:		%%i of decimal:%i,%%i of octal:%i,%%i of hexadecimal:%i.\n",i_a,i_b,i_c);
	ft_printf("ft_printf:	%%i of decimal:%i,%%i of octal:%i,%%i of hexadecimal:%i.\n",i_a,i_b,i_c);
    
	ft_putstr("\n==>Testing %%u:\n");
    printf(   "printf:		%%u of unsigned decimal is:%u.\n",unsigned_a);
	ft_printf("ft_printf:	%%u of unsigned decimal is:%u.\n",unsigned_a);
    
	ft_putstr("\n==>Testing %%x and %%X:\n");
    printf(   "printf:		The hexadecimal of %d is: %x / %X \n",hex_a,hex_a,hex_a);
	ft_printf("ft_printf:	The hexadecimal of %d is: %x / %X \n",hex_a,hex_a,hex_a);

    ft_putstr("\n==>Testing escaping:\n");
    printf(   "printf:		I \\ \' \" %%  am very old.\n");
    ft_printf("ft_printf:	I \\ \' \" %%  am very old.\n");

    ft_putstr("\n==>Testing special characters:\n");
    printf(   "printf:		\a^\b^\f^\r^\t^\v^\n");
    ft_printf("ft_printf:	\a^\b^\f^\r^\t^\v^\n");
	*/
    
	ft_putstr("\n==>%%c francinette:\n");
    printf(   "%c<=printf", '0');
	fflush(stdout);
    ft_putstr("\n");
    ft_printf("%c<=ft_printf", '0');
    fflush(stdout);
	ft_putstr("\n");
    ft_putstr("\n");
	printf(   "printf:%c",'0');
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:%c", '0');
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
	printf(   "%c<=printf", '0' - 256);
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("%c<=ft_printf", '0' -  256);
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
	printf(   "printf:		%c", '0' + 256);
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:	%c", '0' + 256);
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
	printf(   "printf:		 %c %c %c ", '0', 0, '1');
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:	 %c %c %c ", '0', 0, '1');
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
    printf(   "printf:		 %c %c %c ", ' ', ' ', ' ');
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:	 %c %c %c ", ' ', ' ', ' ');
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
    printf(   "printf:		 %c %c %c ", '1', '2', '3');
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:	 %c %c %c ", '1', '2', '3');
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
    printf(   "printf:		 %c %c %c ", '2', '1', '0');
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:	 %c %c %c ", '2', '1', '0');
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
    printf(   "printf:		 %c %c %c ", '0', '1', '2');
    fflush(stdout);
    ft_putstr("\n");
    ft_printf("ft_printf:	 %c %c %c ", '0', '1', '2');
    fflush(stdout);
    ft_putstr("\n");
    ft_putstr("\n");
	
	/*
	ft_putchar('\n');
    ft_putstr("==>Testing the width option:\n");
    char **test = ft_split("abcd%+-0123d%-+02d\n");
    printf("test[0]:\%s,test[1]:%s\n",test[0],test[1]);
    struct s_flags *to_be_cut;
    to_be_cut = ft_param_to_tab(test);
    while(to_be_cut[i].plus != -1)
    {
        printf("===========\n");
        printf("plus:  %d\n",to_be_cut[i].plus);
        printf("minus: %d\n",to_be_cut[i].minus);
        printf("space: %d\n",to_be_cut[i].space);
        printf("zero:  %d\n",to_be_cut[i].zero);
        printf("number:%d\n",to_be_cut[i].number);
        printf("format:%c\n",to_be_cut[i].format);
        i++;
    }
    //PLAN(Anass) : Fix All flags bugs,combine test_ft_printf with ft_printf,
    //Treat floating numbers, Add bonus part
    ft_putstr("It should print:\n");
    printf("%05d\n",age);
    ft_putstr("It is printing:\n");
    test_ft_printf("%05d\n",age);
	*/
	setbuf(stdout, NULL);
}

