#include "libftprintf.h"

void get_number_in_range(int *index, char *s1, int *property, int *property_len)
{
    // printf("entra en get number\n");
    // printf("index:%d\n", *index);   
    // printf("Entrada Desde get number:%d\n", *property_len);
    while (s1[*index] && (s1[*index] >= '0' && s1[*index] <= '9'))
    {
        if (*property == 0)
            *property += (s1[*index] - '0');
        else
            *property = (s1[*index] - '0') + 10 * (*property);
        *index += 1;
        *property_len += 1;
    }
    // printf("Salida Desde get number:%d\n", *property_len);
}

int validate_cero_or_minus( int *index, char *s1, t_config *config)
{       
    if (!(s1[*index] || s1[*index] == '0' || s1[*index] == '-'))
        return (0);
    while (s1[*index] == '0' || s1[*index] == '-')
    {
        if (s1[*index] == '0' && config->is_minus == 0 && config->width_char == ' ')
        {
            config->width_char = '0';
            config->is_cero = 1;
        }
        if (s1[*index] == '-' && config->is_minus == 0) 
        {
            config->width_char = ' ';
             config->is_minus = 1;
        }
        *index += 1;
    }
    return (1);   
}

int validate_width(int *index, char *s1, t_config *config)
{   
    if (!(s1[*index] && (s1[*index] >= '1' && s1[*index] <= '9')))
        return (0);
    get_number_in_range(index, s1, &config->width, &config->width_len);
    return (1);
}

int validate_precision(int *index, char *s1, t_config *config)
{
    // printf("entra en precision\n");
    // printf("%d\n", *index);
    
    while (s1[*index] == '0')
        *index += 1;
    if (s1[*index] && (s1[*index] >= '1' && s1[*index] <= '9'))
        get_number_in_range(index, s1, &config->precision, &config->precision_len);
    // if (!(s1[*index] && (s1[*index] >= '1' && s1[*index] <= '9')))
    //     return (0);
    // get_number_in_range(index, s1, &config->precision, &config->precision_len);
    return (1);
}


int validate_flag(int *index, char *s1, t_config *config)
{
    // printf("entra en flag\n");
    // printf("%d\n", *index);
    if (!s1[*index])
        return (0);
    if (s1[*index] != 'c' && s1[*index] != 's' && s1[*index] != 'p' && 
    s1[*index] != 'd' && s1[*index] != 'i' && s1[*index] != 'i' && s1[*index] != 'u' && 
    s1[*index] != 'x' && s1[*index] != 'X')
        return (0);
    config->flag = s1[*index];
    return (1);
}