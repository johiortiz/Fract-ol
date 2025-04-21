/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:37:41 by johyorti          #+#    #+#             */
/*   Updated: 2025/04/21 07:33:45 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * I HAVE  2 KINDA PROMPTS
 *      ~./fractol mandelbrot
 *      ~./fractol julia <real> <i>
 * 
 * The main function is a RL,DR
 * of your application
 * 
 */ 

int main(int ac, char **av)
{
    if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10) // TODO
        || 4 == ac && ft_strncmp(av[1], "julia", 5))
    {
        //Prompt correct, kick off the applicacion
        
    }
    
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO); // TODO 
        exit(EXIT_FAILURE);
    }
}

