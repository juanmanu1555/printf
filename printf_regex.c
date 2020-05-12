#include "ft_printf.h"

int    arg_config_to_print(t_config *config, int is_negative, t_data_config *data_config) {
    int     ceros;

    ceros = 0;
    if (config->width > config->precision && config->precision != -1)
        config->width_char = ' ';
    if (config->precision > data_config->len)
        ceros = config->precision - data_config->len;
    else if ((config->precision < data_config->len  && config->precision > 0) || (config->precision == -1 ))
        config->precision = data_config->len;
    if (is_negative && config->precision != 0)
    {    
        data_config->len += 1;
        config->precision += 1;
    }    
    if (config->is_minus == 1 && config->precision == 0)
        config->is_minus = 0;
    if ((config->width == 0) || (config->width < config->precision))   
        config->width = config->precision;
    else if (config->width < data_config->len)
        config->width = data_config->len;
    return (ceros);
}


void    printf_arg_width_is_high(t_config *config, t_data_config *data_config, int ceros) {
    if (config->is_minus)
        print_arg_with_minus_true(config, data_config, ceros);
    else
        print_arg_with_minus_false(config, data_config, ceros);
}

void    printf_arg_width_is_low(t_config *config, t_data_config *data_config, int ceros) {
    int j;

    j = 0;
    if (config->flag == 'p')
        ceros -= 2;
    while (ceros > 0)
    {
        ft_putchar('0');
        ceros--;
    }   
    if (config->precision > 0)
    {
        if (config->flag == 'p')
        {
            ft_putchar('0');
            ft_putchar('x');
        }
        while (j < data_config->len)
        {
            ft_putchar(data_config->string_to_print[j]);
            j++;
        }
    }
}

void    printf_printing_arg(t_config *config, t_data_config *data_config, int ceros) {
    if (config->width > config->precision)
        printf_arg_width_is_high(config, data_config, ceros);
    else 
        printf_arg_width_is_low(config, data_config, ceros);
}

void    printf_arg_hex(t_config *config, va_list *args)
{    
    t_data_config           data_config;
    unsigned long int       numb;
    int                     is_negative;
    //int                     len;
    //char                    *s1;

    data_config = t_data_config_default;
    is_negative = 0;
    numb =  va_arg(*args, unsigned int);
    is_numb_negative(&numb, &is_negative);  
    data_config.string_to_print = ft_utohex(numb, config->flag);
    data_config.len = ft_strlen(data_config.string_to_print);  
    //seguimos necesitando reducir la funcion pero nose como interesante.
    // este cambio importante
    // el retorno de este tiene que ir directamente en printf_printing arg para ahorrarnos una variable
    printf_printing_arg(config, &data_config, arg_config_to_print(config, is_negative, &data_config));
	free(data_config.string_to_print);
}

//lo suyo es cambiar todo lo que necesito para imprimir de variables por un objeto typedef.
