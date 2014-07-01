#include <stdio.h>

int main()
{
	FILE *fp1, *fp2, *newfp;
	int op1, op2;
	char buf[16] = {0};
	int i,j;
	
	fp1 = fopen("text1.txt", "r");
	if (NULL == fopen)
	{
		perror("fopen");
		return -1;
	}
	
	fp2 = fopen("text2.txt", "r");
	if (NULL == fopen)
	{
		perror("fopen");
		return -1;
	}
	
	newfp = fopen("text3.txt", "w");
	if (NULL == fopen)
	{
		perror("fopen");
		return -1;
	}
	
	fprintf(newfp, "%s\n", "begin");
	
	fgets(buf, sizeof(buf), fp1);
	fgets(buf, sizeof(buf), fp2);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fscanf(fp1, "%d", &op1);
			fscanf(fp2, "%d", &op2);
			fprintf(newfp, "%d", op1+op2);
			fputc(' ', newfp);
		}
		fputc('\n', newfp);
	}
	fprintf(newfp, "%s\n", "end");

	return 0;
}
