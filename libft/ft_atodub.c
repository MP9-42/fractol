/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:56:28 by MP9               #+#    #+#             */
/*   Updated: 2025/10/02 19:19:03 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodub(char *str)
{
	double	num;
	double	pnum;
	int		prepoc;
	int		i;

	i = 0;
	pnum = 1.0;
	num = 0;
	prepoc = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			prepoc = prepoc * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	atodub_support(&str[i], &num, &pnum);
	return (prepoc * num / pnum);
}

void	atodub_support(char *str, double *num, double *pnum)
{
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		*num = *num * 10.0 + (*str - '0');
		*pnum *= 10.0;
		str++;
	}
}
