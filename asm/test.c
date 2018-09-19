#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	FILE *ptr;
	int	fd;
	unsigned char	c;
	unsigned char	b;

	ptr = fopen("test.cor", "wb");
	fd = fileno(ptr);

	c = 255;
	b = 11;
	for (int i = 0; i < 12; i++)
	{
		//fwrite(&c,sizeof(unsigned char), 1, ptr);
		//fwrite(&b, sizeof(unsigned char), 1, ptr);
		write(fd, &c, sizeof(unsigned char));
		write(fd, &b, sizeof(unsigned char));
	}
	fclose(ptr);
}