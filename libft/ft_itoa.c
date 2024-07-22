/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:43:48 by msoklova          #+#    #+#             */
/*   Updated: 2024/03/18 16:15:39 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*ft_negative(int num)
{
	char	*str;
	int		temp;
	int		i;
	int		n;

	temp = num;
	i = num_count(num) -1;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (num_count(num) + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		temp *= -1;
	}
	while (temp > 0)
	{
		n = temp % 10;
		str[i--] = n + '0';
		temp /= 10;
	}
	str[num_count(num)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		i;
	int		num;

	temp = n;
	if (n < 0)
		return (ft_negative(n));
	else if (n == 0)
		return (ft_strdup("0"));
	i = num_count(n) -1;
	str = (char *)malloc(sizeof(char) * (num_count(n) + 1));
	if (!str)
		return (NULL);
	while (temp > 0)
	{
		num = temp % 10;
		str[i--] = num + '0';
		temp /= 10;
	}
	str[num_count(n)] = '\0';
	return (str);
}
