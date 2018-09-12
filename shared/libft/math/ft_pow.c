unsigned int ft_pow(unsigned int n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_pow(n, pow -1));
}