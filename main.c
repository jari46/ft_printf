#include <stdio.h> //real printf
int	ft_printf(const char *format, ...);

void	test_c(int c)
{
	printf(c); printf("\n"); ft_printf(c); printf("\n");
}

int	main()
{
	/* %와 가변인자 개수가 다르면 어떻게 될까?
	** -> warning은 뜨지만 컴파일은 된다. %가 모자라면 나머지 인자는 사용 안 함, %가 많으면 쓰레기값 출력 */
	printf("%d %d %d\n", 1, 2);
	printf("%d %d %d\n", 1, 2, 3, 4);

	/* c */
	test('A');

	/* % */
	/* s */
	/* p */
	/* d */
	/* i */
	/* u */
	/* x */
	/* X */