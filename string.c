
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


typedef struct my_string
{
	uint8_t* data;
	uint8_t length;
	uint8_t how_much;
} str_t;


str_t* string(uint8_t length) 
{
	str_t* str = (str_t*)malloc(sizeof(str_t));
	str->data = (uint8_t*)malloc(length);
	str->length = length;
	str->how_much = 0;
	return str;
}


void string_free(str_t* str)
{
	//clear memory
	free(str->data); 
	free(str);
}


uint8_t string_lenght(str_t* str)
{
	//input length
	return str->length;
}


void print_string(str_t* str, FILE* file)
{
	//print string
	fwrite(str->data, sizeof(uint8_t), str->length, file);
}


str_t* string_dup(const char* str_p)
{
	//copy string
	str_t* string_p = string((uint8_t)strlen(str_p));
	memcpy(string_p->data, str_p, string_p->length);
	string_p->how_much = string_p->length;
	return string_p;
}


int main(int argc, char const *argv[])
{	
	printf("Your string: ");
	str_t* hello_world = string_dup("hello_world");
	print_string(hello_world, stdout);
	int a = string_lenght(hello_world);
	printf("\nlength: %d", a);
	return 0;
}