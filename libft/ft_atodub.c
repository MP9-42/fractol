/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:56:28 by MP9               #+#    #+#             */
/*   Updated: 2025/10/13 15:39:50 by MP9              ###   ########.fr       */
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
	atodub_support(&str[i], &num, &pnum);
	return (prepoc * num / pnum);
}

void	atodub_support(char *str, double *num, double *pnum)
{
	while (ft_isdigit(*str))
	{
		*num = *num * 10 + (*str - '0');
		if (!ft_isdigit(*str))
			return ;
		str++;
	}
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		*num = *num * 10.0 + (*str - '0');
		if (!ft_isdigit(*str))
			return ;
		*pnum *= 10.0;
		str++;
	}
}
