#include "libasm.h"
#include "stdlib.h"

void		test_strlen(void)
{
	printf(CYAN "\n#### Testing ft_strlen ####\n" COLOR_OFF);
	clock_t start, end, asm_start, asm_end;
    double cpu_time_used, cpu_time_used_asm;

	char	*array[] = 
	{
		"123453242324",
		"42",
		"testaz",
		"",
		"\n",
		"This is a bigger test just to make sure things work with bigger things This is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger things",
	};

	int	size = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < size; i++)
	{
  		
		start = clock();
		int	expected = strlen(array[i]);
		end = clock();
		
		asm_start = clock();
		int	result = ft_strlen(array[i]);
		asm_end = clock();

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		cpu_time_used_asm = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC;
		
		printf(expected == result ? GREEN "OK" COLOR_OFF : RED "KO" COLOR_OFF);
		printf("\t Expected: %d\tResult: %d\n", expected, result);
		printf("\t tnormal: %f\ttasm: %f\n", cpu_time_used, cpu_time_used_asm);
	}
}

void	test_strcpy(void)
{
	printf(CYAN "\n#### Testing ft_strcpy ####\n" COLOR_OFF);
	clock_t start, end, asm_start, asm_end;
    double cpu_time_used, cpu_time_used_asm;

	char	*array[] = 
	{
		"123453242324",
		"42",
		"testaz",
		"",
		"\n",
		"This is a bigger test just to make sure things work with bigger things This is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger things",
	};

	int	size = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < size; i++)
	{
		char	*test;

		start = clock();
		test = (char *) malloc (sizeof(char) * (ft_strlen(array[i]) +1));
		void	*ref_ptr = strcpy(test, array[i]);
		end = clock();
		
		asm_start = clock();
		void	*test_ptr = ft_strcpy(test, array[i]);
		asm_end = clock();
		
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		cpu_time_used_asm = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC;
		
		printf(ref_ptr == test_ptr ? GREEN "POINTER OK" COLOR_OFF : RED "POINTER KO" COLOR_OFF);
		printf("\tExpected: %p\tResult: %p\n", ref_ptr, test_ptr);
		printf("\t tnormal: %f\ttasm: %f\n", cpu_time_used, cpu_time_used_asm);

		char	*ref = (char *) malloc (sizeof(char) * (ft_strlen(array[i]) +1));;
		char	*dest =(char *) malloc (sizeof(char) * (ft_strlen(array[i]) +1));;

		start = clock();
		strcpy(ref, array[i]);
		end = clock();

		asm_start = clock();
		ft_strcpy(dest, array[i]);
		asm_end = clock();
		
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		cpu_time_used_asm = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC;

		printf(strcmp(ref, dest) == 0 ? GREEN "COPY OK" COLOR_OFF : RED "COPY KO" COLOR_OFF);
		printf("\t\tExpected: %s\tResult: %s\n", ref, dest);
		printf("\t tnormal: %f\ttasm: %f\n", cpu_time_used, cpu_time_used_asm);
		free(ref);
		free(dest);
		free(test);
	}
}

void	test_strcmp(void)
{
	printf(CYAN "\n#### Testing ft_strcmp ####\n" COLOR_OFF);
	clock_t start, end, asm_start, asm_end;
    double cpu_time_used, cpu_time_used_asm;

	char	*array1[] = {
		"123453242324",
		"42",
		"testaz",
		"",
		"This is a bigger test just to make sure things work with bigger things This is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger things",
	};

	char	*array2[] = 
	{
		"48129739047182934879",
		"2",
		"testaz",
		"",
		"This is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger things",
	};

	int	numarray = sizeof(array1) / sizeof(array1[0]);

	for (int i = 0; i < numarray; i++) {
		start = clock();
		int	expected = ft_strcmp(array1[i], array2[i]);
		end = clock();
		
		asm_start = clock();
		int	result = ft_strcmp(array1[i], array2[i]);
		asm_end = clock();

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		cpu_time_used_asm = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC;

		printf(CYAN "%s" COLOR_OFF " vs "CYAN "%s" COLOR_OFF"\n", array1[i], array2[i]);
		printf(expected == result ? GREEN "OK" COLOR_OFF : RED "KO" COLOR_OFF);
		printf("\t Expected: %d\tResult: %d\n\n", expected, result);
		printf("\t tnormal: %f\ttasm: %f\n", cpu_time_used, cpu_time_used_asm);
	}
}

void	test_write(void)
{
	printf(CYAN "\n#### Testing ft_write ####\n" COLOR_OFF);
	clock_t start, end, asm_start, asm_end;
    double cpu_time_used, cpu_time_used_asm;

	char	*array[] = {
		"123453242324",
		"42",
		"testaz",
		"",
		"\n",
		"This is a bigger test just to make sure things work with bigger things This is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger things",
	};


	int fds[] = {
		-1,
		open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644),
		42
	};

	int	numarray = sizeof(array) / sizeof(array[0]);
	int	numFds = sizeof(fds) / sizeof(fds[0]);

	for (int i = 0; i < numarray; i++)
	{
		printf(CYAN "\"%s\"\n" COLOR_OFF, array[i]);
		for (int j = 0; j < numFds; j++) {
			errno = 0;

			start = clock();
			int	ref_ret = write(fds[j], array[i], strlen(array[i]));
			end = clock();
			int	ref_errno = errno;
			
			errno = 0;
			asm_start = clock();
			int	test_ret = ft_write(fds[j], array[i], strlen(array[i]));
			asm_end = clock();
			int	test_errno = errno;

			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			cpu_time_used_asm = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC;

			printf("fd: %d\t", fds[j]);
			printf(ref_ret == test_ret ? GREEN "RETURN OK" COLOR_OFF : RED "RETURN KO" COLOR_OFF);
			printf("\tExpected: %d\tResult: %d\n", ref_ret, test_ret);
			printf("\tExpected: %d\tResult: %d\n", ref_errno, test_errno);
			printf("\t tnormal: %f\ttasm: %f\n", cpu_time_used, cpu_time_used_asm);
		}
		printf("\n");
	}

	printf(CYAN "NULL string\n\n" COLOR_OFF);
	for (int j = 0; j < numFds; j++)
	{
		errno = 0;
		
		start = clock();
		int	ref_ret = write(fds[j], NULL, 0);
		end = clock();
		int	ref_errno = errno;
		errno = 0;

		asm_start = clock();
		int	test_ret = ft_write(fds[j], NULL, 0);
		asm_end = clock();
		int	test_errno = errno;

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		cpu_time_used_asm = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC;

		printf("fd: %d\t", fds[j]);
		printf(ref_ret == test_ret ? GREEN "RETURN OK" COLOR_OFF : RED "RETURN KO" COLOR_OFF);
		printf("\tExpected: %d\tResult: %d\n", ref_ret, test_ret);
		printf(ref_errno == test_errno ? GREEN "\tERRNO OK" COLOR_OFF : RED "\tERRNO KO" COLOR_OFF);
		printf("\tExpected: %d\tResult: %d\n", ref_errno, test_errno);
		printf("\t tnormal: %f\ttasm: %f\n", cpu_time_used, cpu_time_used_asm);

	}
}

void	test_read(void)
{
	printf(CYAN "\n#### Testing ft_read ####\n" COLOR_OFF);

	int fds[] =
	{
		-1,
		open("read.txt", O_RDONLY, 0644),
		10
	};

	int	numFds = sizeof(fds) / sizeof(fds[0]);

	for (int j = 0; j < numFds; j++)
	{
		errno = 0;
		char	ref_buf[10];
		int	ref_ret = read(fds[j], ref_buf, 10);
		ref_buf[ref_ret == -1 ? 0 : ref_ret] = '\0';
		int	ref_errno = errno;
		lseek(fds[j], 0, SEEK_SET);
		errno = 0;
		char	test_buf[10];
		int	test_ret = ft_read(fds[j], test_buf, 10);
		test_buf[test_ret == -1 ? 0 : test_ret] = '\0';
		int	test_errno = errno;

		printf("\nfd: %d\t", fds[j]);
		printf(ref_ret == test_ret ? GREEN "RETURN OK" COLOR_OFF : RED "RETURN KO" COLOR_OFF);
		printf("\tExpected: %d\tResult: %d\n\t", ref_ret, test_ret);
		printf(ref_errno == test_errno ? GREEN "ERRNO OK" COLOR_OFF : RED "ERRNO KO" COLOR_OFF);
		printf("\tExpected: %d\tResult: %d\n\t", ref_errno, test_errno);
		printf(strcmp(ref_buf, test_buf) == 0 ? GREEN "COPY OK" COLOR_OFF : RED "COPY KO" COLOR_OFF);
		printf("\t\tExpected: %s\tResult: %s\n", ref_buf, test_buf);
	}
	printf("\n");
}

void	test_strdup(void)
{
	printf(CYAN "\n#### Testing ft_strdup ####\n" COLOR_OFF);

	char	*array[] =
	{
		"123453242324",
		"42",
		"testaz",
		"",
		"\n",
		"This is a bigger test just to make sure things work with bigger things This is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger thingsThis is a bigger test just to make sure things work with bigger things",
	};

	int	numarray = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < numarray; i++) {
		char	*ref_ptr = strdup(array[i]);
		char	*test_ptr = ft_strdup(array[i]);

		printf(strcmp(ref_ptr, test_ptr) == 0 ? GREEN "COPY OK" COLOR_OFF : RED "COPY KO" COLOR_OFF);
		printf("\t\tExpected: %s\n\nResult: %s\n", ref_ptr, test_ptr);
	}
}

int	main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return (0);
}