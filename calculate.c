/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:38:31 by okaname           #+#    #+#             */
/*   Updated: 2025/02/28 13:06:22 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_isvalid(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = ft_skip_space(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] != '\0' || str[i - 1] == '.')
		return (0);
	if (str[i - 1] == '-' || str[i - 1] == '+')
		return (0);
	return (1);
}

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;
	int		index;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	i = ft_skip_space(str) - 1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
	{
		if (str[++i] == '-')
			sign = -1;
	}
	while (isdigit(str[++i]))
		result = result * 10.0 + (str[i] - '0');
	if (str[i] == '.')
	{
		index = i;
		while (isdigit(str[++i]))
			result += (str[i] - '0') / pow(10.0, (i - index));
	}
	return (sign * result);
}

// int	main(void)
// {
// 	printf("%f\n", ft_atof("		123.456")); // 123.456000
// 	printf("%f\n", ft_atof("  -0.789"));        // -0.789000
// 	printf("%f\n", ft_atof("\r+42"));           // 42.000000
// 	printf("%f\n", ft_atof("\t3.14"));          // 3.140000
// 	printf("%f\n", ft_atof("\n0.00123"));       // 0.001230
// 	printf("%f\n", ft_atof(""));                //
// 	return (0);
// }

// int	main(void)
// {
// 	printf("%d\n", ft_isvalid("		123.456")); // 123.456000
// 	printf("%d\n", ft_isvalid("  -0.789"));     // -0.789000
// 	printf("%d\n", ft_isvalid("\r+42"));        // 42.000000
// 	printf("%d\n", ft_isvalid("\t3.14"));       // 3.140000
// 	printf("%d\n", ft_isvalid("\n0.00123"));    // 0.001230
// 	printf("%d\n", ft_isvalid("+"));            //
// 	printf("%d\n", ft_isvalid("-"));            //
// 	printf("%d\n", ft_isvalid("."));            //
// 	printf("%d\n", ft_isvalid("+."));           //
// 	printf("%d\n", ft_isvalid("-."));           //
// 	printf("%d\n", ft_isvalid("--"));           //
// 	printf("%d\n", ft_isvalid("++"));           //
// 	return (0);
// }
