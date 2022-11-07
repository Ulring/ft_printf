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
    hex_a = 696969;
    unsigned_a = -1;
    letter = 'I';
    word = "old";
    ptr = &age;

    ft_putchar('\n');
    ft_putstr("==>Testing formats specifications:\n");
    ft_printf("%c am %d years %s.\n", letter, age, word);
    printf(   "%c am %d years %s.\n", letter, age, word);
    ft_printf("The address of ptr is: %p.\n", ptr);
    printf(   "The address of ptr is: %p.\n", ptr);
    ft_printf("%%i of decimal:%i,%%i of octal:%i,%%i of hexadecimal:%i.\n",i_a,i_b,i_c);
    printf(   "%%i of decimal:%i,%%i of octal:%i,%%i of hexadecimal:%i.\n",i_a,i_b,i_c);
    ft_printf("%%u of unsigned decimal is:%u.\n",unsigned_a);
    printf(   "%%u of unsigned decimal is:%u.\n",unsigned_a);
    ft_printf("The hexadecimal of %d is:%x/%X\n",hex_a,hex_a,hex_a);
    printf(   "The hexadecimal of %d is:%x/%X\n",hex_a,hex_a,hex_a);

    ft_putchar('\n');
    ft_putstr("==>Testing escaping:\n");
    ft_printf("I \\ \' \" %%  am very old.\n");
    printf(   "I \\ \' \" %%  am very old.\n");

    ft_putchar('\n');
    ft_putstr("==>Testing special characters:\n");
    ft_printf("\a^\b^\f^\r^\t^\v^\n");
    printf(   "\a^\b^\f^\r^\t^\v^\n");

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
}

