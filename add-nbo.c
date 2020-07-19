#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	
	uint32_t a;
	uint32_t b;

	FILE *fp, *fp2;

	if(argc != 3){
		printf("please write the file\n");
		return 0;
	}

	fp = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");

	if(fp == NULL){
		printf("%s is not exist \n", argv[1]);
		return 0;
	}
	if(fp2 == NULL){
		printf("%s is not exist \n", argv[2]);
		return 0;
	}
	
	fread(&a, 4, 1, fp); // file1 contents read
	fread(&b, 4, 1, fp2); // file2 contents read

	uint32_t change_a = ntohl(a);
	uint32_t change_b = ntohl(b);
	uint32_t result = change_a + change_b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", change_a, change_a, change_b, change_b, result, result);
}
