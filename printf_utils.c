#include "ft_printf.h"

char    *ft_strinv(char *s1)
{
    long long int len;
    char *s2;
    size_t j;

    j = 0;
    len = ft_strlen(s1);
    //printf("\n%llu\n", len);
    //printf("\n%s\n", s1);
    if (!(s2 = malloc(sizeof(char) * (len + 1))))
      return (NULL);
    while (len > 0)
    {
        //printf("\n%c\n", *s1++);
        s2[j] = s1[len - 1];
        j++;
        len--;
    }
    s2[j] = 0;
    //printf("\n%s\n", s2);
    return (s2);
}

char    *ft_utohex(unsigned long int numb, char flag)
{
    char *s1;
    char *s2;
    unsigned long int res;
    unsigned long int div;
    char *hexa_array;
    int j;

    
    if (numb == 0)
    {
        s1  = malloc(2);
        s1[0] = '0';
        s1[1] = '\0';
        return (s1);
    }
    s1  = malloc(4000);
    res = numb;
    div = 0;
    j = 0;
    //printf("\n%lu\n", res);

    if (flag == 'x')
        hexa_array = ft_strdup("0123456789abcdef");
    else if (flag == 'X')
        hexa_array = ft_strdup("0123456789ABCDEF");
    while (res > 0)
    {
            if (numb > 15)
            {
                div = numb % 16;
                numb /= 16;
                s1[j] = hexa_array[div];
                res = numb;
            }
            else 
            {
                div = numb;
                s1[j ] = hexa_array[div];
                res = 0;
                // numb = 0;
            }
            // // if (numb > 15)
            
            // //printf("\n%lu\n", div);
            // //printf("\n%lu\n", numb);
            // // numb = res;
          
            // if (numb > 15)
                
            // else 
               
            // div = 0;
            // // printf("\n%lu\n", numb);
            j++;
        
    }
    //printf("\n%lu\n", res);
    s2 = ft_strinv(s1);
    //printf("\n%s\n", s1);
    return (s2);
}

void print_arg_with_minus_true(t_config *config, t_data_config *data_config, int ceros) {
    int z;
    int j;

    j = 0;
    z = 0;
    z += data_config->len;          
    while (ceros > 0)
    {
        ft_putchar('0');
        ceros--;
        z++;
    }
    if (config->precision > 0)
    {
        if (config->flag == 'p')
        {
            ft_putchar('0');
            ft_putchar('x');
            config->width += 2;
        }
        while (j < data_config->len)
        {
            ft_putchar(data_config->string_to_print[j]);
            j++;
        }
    }         
    while (z < config->width)
    {
        ft_putchar(config->width_char);
        z++;
    }
}

void print_arg_with_minus_false(t_config *config, t_data_config *data_config, int ceros) {
    int z;
    int j;

    j = 0;
    z = 0;
    if (config->flag == 'p')
        config->width -= 2;
    while (z < config->width - config->precision)
    {
        ft_putchar(config->width_char);
        z++;
    }
    z = 0;
    if (config->flag == 'p')
    {
        ft_putchar('0');
        ft_putchar('x');
        config->width += 2;
    }
    while (ceros > 0)
    {
        ft_putchar('0');
        ceros--;
    }   
    if (config->precision > 0)
    {
        while (j < data_config->len)
        {
            ft_putchar(data_config->string_to_print[j]);
            j++;
                    
        }
    }
}


void is_numb_negative(unsigned long int *numb, int *is_negative) {
    if (*numb < 0)
    {
        *numb *= -1;
        *is_negative = 1;
    }
}