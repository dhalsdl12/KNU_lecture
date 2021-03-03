/****************************************************************************
 * subject: introduction
 * author : name
 ****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

 /****************************************************************************
  * global variables
  ****************************************************************************/

  /****************************************************************************
   * function declarations
   ****************************************************************************/
int read_data(char infile[], int list[]);
int make_sum(int list[], int size);

/****************************************************************************
 * main function definition
 ****************************************************************************/
int main(int argc, char** argv) {
	int input_data[MAX_INPUT_SIZE];
	int input_size = 0;
	int sum;

	// 1. check arguments
	if (argc != 2) {
		fprintf(stderr, " E usage : [program] [file name]\n");
		exit(EXIT_FAILURE);
	}

	// 2. read input data
	input_size = read_data(argv[1], input_data);

	// 3. do the task
	sum = make_sum(input_data, input_size);

	// 4. print result
	// notice: print only the answer
	// (if the answer contains several data, print with only one ' ')
	printf("%d ", sum);

	// 5. terminate
	// free(something);
	system("pause");    // remove before upload to the judge system
	return EXIT_SUCCESS;
}

/****************************************************************************
 * other function definitions
 ****************************************************************************/
int make_sum(int list[], int size) {
	int i;
	int sum = 0;
	for (i = 0; i < size; i++) {
		sum += list[i];
	}
	return sum;
}

int read_data(char infile[], int list[]) {
	FILE* fp;
	int size = 0;

	// 1. open file
	if (!(fp = fopen(infile, "r"))) {
		fprintf(stderr, "failed to open file\n");
		exit(EXIT_FAILURE);
	}

	// 2. read input data
	while (!feof(fp)) {
		fscanf(fp, "%d ", &(list[size]));
		size++;
	}
	fclose(fp);

	return size;
}