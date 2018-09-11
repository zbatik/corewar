/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:41:24 by mdilapi           #+#    #+#             */
/*   Updated: 2018/04/30 11:41:25 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
int is_in(char c, int str_base)
{
	char *set;
	int i;
	int result;

	set = "0123456789abcdef";
	i = 0;
	result = 0;
	while(i < str_base)
	{
		if (c == set[i++])
			result = 1;
	}
	return (result);

}
int recursive_power(int n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * recursive_power(n, pow -1));
}
int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int sign;
	int ret;
	int count;
	int val;
	int tmp;

	i = 0;
	while(str[i] <= 33 && str[i] != '\0')
		i++;
	if(str[i] == '\0')
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else
		sign = 1;
	ret = 0;
	count = i -1;
	while (is_in(to_lower(str[i]), str_base) == 1 && str[i] != '\0')
		i++;

	if (str[i] == '\0')
		i--;
	
	tmp = 0;
	while (i > count)
	{
		if (to_lower(str[i]) >= 'a' && to_lower(str[i]) <= 'f')
		{
			val = str[i] - 87;
		}
		else
			val = str[i] - '0';
		ret = ret + val*recursive_power(str_base,tmp);
		i--; 
		tmp ++;
	}
	return (ret * sign);
}
