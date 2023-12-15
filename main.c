#include "libasm.h"

void	check_ft_strlen(const char *s)
{
	size_t	my;
	size_t	or;

	or = strlen(s);
	my = ft_strlen(s);
	if (or == my)
		printf(GREEN "[OK] ");
	else
		printf(RED "[FAIL]");
	printf (BLUE "\nlibc: %zu\n", or);
	printf (BLUE "my libasm: %zu\n", my);
}

void	check_ft_strcpy(const char *s)
{
	char	*buf_libc;
	char	*buf_asm;

	buf_asm = malloc(strlen(s));
	buf_libc = malloc(strlen(s));
	ft_strcpy(buf_asm, s);
	strcpy(buf_libc, s);
	if (ft_strcmp(buf_asm, buf_libc) == 0)
		printf(GREEN "[OK] ");
	else
		printf(RED "[FAIL] ");
	printf (BLUE "\nlibc: [%s]\n", buf_libc);
	printf (BLUE "my libasm: [%s]\n", buf_asm);
	free(buf_libc);
	free(buf_asm);
}

void	check_ft_strcmp(const char *s)
{
	const char	*a1;
	int			r1;
	int			r2;
	
	a1 = "Hello!";
	r1 = strcmp(s, a1);
	r2 = ft_strcmp(s, a1);	
	if (strcmp(s, a1) == ft_strcmp(s, a1))
		printf(GREEN "[OK] ");
	else
		printf(RED "[FAIL] ");
	printf (BLUE "\nlibc: %i\n", r1);
	printf (BLUE "my libasm: %i\n", r2);
}

void	check_ft_write(const char *s)
{
	int fd = 1;
	write(fd, s, ft_strlen(s));
	printf("\n");
	ft_write(fd, s, ft_strlen(s));
	printf("\n");
}

void	check_ft_read(const char *s)
{
	char	*buf_or;
	char	*buf_my;
	int		fd1;
	int		or_read;
	int		my_read;

	buf_my = malloc(ft_strlen(s) + 1);
	buf_or = malloc(ft_strlen(s) + 1);
	fd1 = open("file1", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd1, s, ft_strlen(s));
	close(fd1);
	fd1 = open("file1", O_RDONLY);
	or_read = read(fd1, buf_or, 90);
	close(fd1);
	fd1 = open("file1", O_RDONLY);
	my_read = ft_read(fd1, buf_my, 90);
	close(fd1);
	if (or_read == my_read)
		printf(GREEN "[OK] ");
	else
		printf(RED "[FAIL] ");
	printf (BLUE "\nlibc: %i\n", or_read);
	printf (BLUE "my libasm: %i\n", my_read);
	/*              read from stdin             */
	//read(1, buf_or, ft_strlen(s));
	//ft_read(1, buf_or, ft_strlen(s));
	free(buf_or);
	free(buf_my);
}

void	check_ft_strdup(const char *s)
{
	char	*d1;
	char	*d2;

	d1 = strdup(s);
	d2 = ft_strdup(s);
	if (strcmp(d1, d2) == 0)
		printf(GREEN "[OK] ");
	else
		printf(RED "[FAIL] ");
	printf (BLUE "\nlibc: [%s]\n", d1);
	printf (BLUE "my libasm: [%s]\n", d2);
	free(d1);
	free(d2);
}

int	main(void)
{
	char	*s1 = "";
	char	*s2 = "Hello!";
	char	*s3 = "21school";
	char	*s4 = 
	"Here is libasm! Here is libasm! Here is libasm! Here is libasm! Here is libasm! Here is libasm! Here is libasm! Here is libasm!";
	
	/**************ft_strlen*************/
	printf(YELLOW "**********ft_strlen***********\n");
	check_ft_strlen(s1);
	check_ft_strlen(s2);
	check_ft_strlen(s3);
	check_ft_strlen(s4);
	/****************ft_strcpy*****************/
	printf(YELLOW "\n**********ft_strcpy***********\n");
	check_ft_strcpy(s4);
	check_ft_strcpy(s1);
	check_ft_strcpy(s2);
	check_ft_strcpy(s3);
	/****************ft_strcmp****************/
	printf(YELLOW "\n**********ft_strcmp***********\n");
	check_ft_strcmp(s1);
	check_ft_strcmp(s2);
	check_ft_strcmp(s3);
	check_ft_strcmp(s4);
	/****************ft_read******************/
	printf(YELLOW "\n**********ft_read*************\n");
	check_ft_read(s1);
	check_ft_read(s2);
	check_ft_read(s3);
	check_ft_read(s4);
	/****************ft_strdup****************/
	printf(YELLOW "\n**********ft_strdup***********\n");
	check_ft_strdup(s1);
	check_ft_strdup(s2);
	check_ft_strdup(s3);
	check_ft_strdup(s4);
	/****************ft_write******************/
	printf(YELLOW "\n**********ft_write************\n");
	printf(GREEN "Test 1: empty string\n");
	check_ft_write(s1);
	printf(GREEN "Test 2: string \"Hello!\" = \n");
	check_ft_write(s2);
	printf(GREEN "Test 3: string \"21school\" = \n");
	check_ft_write(s3);
	printf(GREEN "Test 4: long string = \n");
	check_ft_write(s4);
}
