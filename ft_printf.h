#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct      s_config {
    int     width;
    int     width_len;
    char    width_char;
    int     precision;
    int     precision_len;
    char    flag;
    int     is_width_arg;
    int     is_precision_arg;
    int     is_minus;
    int     is_cero;
    int     is_width;
    int     is_precision;
}                   t_config;

typedef struct      s_data_config {
    int     len;
    char    *string_to_print;
    int     z;
    int     j;
}                   t_data_config;

#define t_config_default (t_config){0, 0,' ', -1, 0, 0, 0, 0 ,0, 0, 0, 0}
#define t_data_config_default (t_data_config) { -1, NULL, -1, -1 }

int ft_printf(const char *s1, ...);
int ft_transform_data(char *s1, t_config *config, va_list *args);
int ft_transform_arg(int *index, char *s1, t_config *config, va_list *args);
int regex_validate(int *index, char *s1, t_config *config);
void    is_numb_negative(unsigned long int *numb, int *is_negative);
void    print_arg_with_minus_true(t_config *config, t_data_config *data_config, int ceros); 
void    print_arg_with_minus_false(t_config *config, t_data_config *data_config, int ceros); 
int     arg_config_to_print(t_config *config, int is_negative, t_data_config *data_config);
char    *ft_strinv(char *s1);
char    *ft_utohex(unsigned long int numb, char flag);
void    printf_arg_width_is_high(t_config *config, t_data_config *data_config, int ceros);
void    printf_arg_width_is_low(t_config *config, t_data_config *data_config, int ceros);
void    printf_printing_arg(t_config *config, t_data_config *data_config, int ceros);
void    printf_arg_hex(t_config *config, va_list *args);
void    get_number_in_range(int *index, char *s1, int *property, int *property_len);
int     validate_cero_or_minus( int *index, char *s1, t_config *config);
int     validate_width(int *index, char *s1, t_config *config);
int     validate_precision(int *index, char *s1, t_config *config);
int     validate_flag(int *index, char *s1, t_config *config);

#endif

