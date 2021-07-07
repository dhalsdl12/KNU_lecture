#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* src_file, * dst_file;
	char srcname[100] = { 0 };
	char dstname[100] = { 0 };
	char buffer[1024];
	int rd_count;
	int total_byte = 0;

	printf("�̹��� ���� �̸��� �Է��ϼ���: ");
	scanf("%s", srcname);

	printf("������ ���� �̸��� �Է��ϼ���: ");
	scanf("%s", dstname);

	src_file = fopen(srcname,"rb");
	dst_file = fopen(dstname,"wb");

	if(src_file == NULL || dst_file == NULL)
	{
		fprintf(stderr, "File open error\n");
		exit(1);
	}
	while ((rd_count = fread(buffer, 1, sizeof(buffer), src_file)) > 0)
	{
		total_byte += rd_count;
		int wr_count = fwrite(buffer, 1, rd_count, dst_file);

		if (wr_count < 0)
		{
			fprintf(stderr, "File write error\n");
			exit(1);
		}
		printf("rd_count = % d, wr_count = % d\n", 
			rd_count, wr_count);

		if (wr_count < rd_count)
		{
			fprintf(stderr, "�̵�� ���� ����\n");
			exit(1);
		}
	}
	printf("���� ���� �Ϸ� (%s to %s) File size= %d Bytes\n",
		srcname, dstname, total_byte);

	fclose(src_file);
	fclose(dst_file);

	return 0;
}