// Compile: gcc -g -Wall -std=c99 example_strings.c -o example_strings.exe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 20;
void printArrayByIndex(char array[], size_t array_size); // Print array one index at a time
void countWordsInArray(char array[], size_t array_size); // Count the number of words in a sentence, delineated by space
void countNumber(int number, char array[], size_t array_size); // Count occurrences of a number in a string
void findSubstringBeginning(char array[], char key[], size_t array_size, size_t key_size); // Find a substring, only if it starts at the beginning of the array

int main(void)
{
	char first[SIZE];
	char last[SIZE];
	char full[SIZE];
	
	char sentence[SIZE];
	
	char source[SIZE];
	char key[SIZE];
	
	char number_source[SIZE];
	char number_key_temp[SIZE];
	int number_key;

	// Ask for name
	printf("First Name: ");
	fgets(first,sizeof(first),stdin);
	if(!strchr(first, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline

	printf("Last Name: ");
	fgets(last,sizeof(last),stdin);
	if(!strchr(last, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline
		
	// Ask for a sentence
	printf("Sentence: ");
	fgets(sentence,sizeof(sentence),stdin);
	if(!strchr(sentence, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline
	
	// Ask for two random strings
	printf("Substring Source: ");
	fgets(source,sizeof(source),stdin);
	if(!strchr(source, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline
		
	printf("Substring Key: ");
	fgets(key,sizeof(key),stdin);
	if(!strchr(key, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline
	
	// Ask for two random number strings
	printf("Number Source: ");
	fgets(number_source, sizeof(number_source), stdin);
	if(!strchr(number_source, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline	
	
	printf("Number Key: ");
	fgets(number_key_temp, sizeof(number_key_temp), stdin);
	sscanf(number_key_temp, "%d", &number_key);
	if(!strchr(number_key_temp, '\n'))     //newline does not exist
		while(fgetc(stdin)!='\n'); //discard until newline	
		
	// Combine both into full name
	strcpy(full,first);
	strcat(full," ");
	strcat(full,last);

	// Print full name
	printf("\nName: %s\n", full);
	
	// Print sentence
	printf("Sentence: %s\n", sentence);
	
	// Print size of strings
	printf("main() - SizeOf (FIRST): %ld\n", sizeof(first));
	printf("main() - SizeOf (LAST): %ld\n", sizeof(last));
	printf("main() - SizeOf (SENTENCE): %ld\n\n", sizeof(sentence));

	// Print length of strings
    printf("main() - StrLen (FIRST): %zu\n", strlen(first));
    printf("main() - StrLen (LAST): %zu\n", strlen(last));
	printf("main() - StrLen (SENTENCE): %zu\n\n", strlen(sentence));

	// DEGUB Print each index 
	printArrayByIndex(first, SIZE);
	printf("\n");
	printArrayByIndex(last, SIZE);
	printf("\n");
	printArrayByIndex(sentence, SIZE);

	// Remove carriage return from last element on both strings
	first[(strlen(first)-1)]='\0';
	last[(strlen(last)-1)]='\0';

	// Now recombine the strings into full
    strcpy(full,first);
	strcat(full," ");
	strcat(full,last);

	printf("Name: %s\n\n", full);
	
	countWordsInArray(sentence, strlen(sentence));

	findSubstringBeginning(source, key, strlen(source), strlen(key));
	
	countNumber(number_key, number_source, strlen(number_source));
	
	return 0;
}

void printArrayByIndex(char array[], size_t array_size)
{
	printf("printArrayByIndex() - SizeOf: %ld\n", array_size);
	
	for (int i=0; i<array_size+1; i++)
		{
			if (array[i] == '\n')
			{
				printf("[%d] = \\n\n", i);
			}
			else if (array[i] == '\0')
			{
				printf("[%d] = NULL\n", i);
			}
			else
			{
				printf("[%d] = %c\n", i, array[i]);
			}
	}
}

void countWordsInArray(char array[], size_t array_size)
{
	int space_count = 0;
	
	if (array_size != 1)
	{
		space_count = 1;
		
		for (int i=0; i<array_size; i++)
		{
			if (array[i] == ' ')
				space_count++;
		}
	}
	
	printf("Number of words: %d\n", space_count);
}

void countNumber(int number, char array[], size_t array_size)
{
	int count = 0;
	int intconv;
	char charconv;
	
	//printArrayByIndex(array, array_size);
	
	for (int i=0; i<array_size; i++)
	{
		charconv = array[i];
		intconv = atoi (&charconv);
		if (number == intconv)
			count++;
	}
	
	printf("Number Occurrence: %d\n", count);
}

void findSubstringBeginning(char array[], char key[], size_t array_size, size_t key_size)
{
	char *position;
		
	//printArrayByIndex(array, array_size);
	//printArrayByIndex(key, key_size);
	
	array[array_size-1]='\0';
	key[key_size-1]='\0';
	
	//printArrayByIndex(array, array_size);
	//printArrayByIndex(key, key_size);
	
	position = strstr(array, key);
	
	printf("Position = %p\n", position);
	printf("ARR = %p\n", array);
	printf("KEY = %p\n", key);
	//printf("Position D'Ref = %c\n", *position);
	
	if (position == NULL)
		printf("Substring NOT found.\n\n");
	else
	{
		if (position == array)
			printf("Substring found at beginning!\n\n");
		else
			printf("Substring found but NOT at beginning.\n\n");
	}
}