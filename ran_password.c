#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_password(char *password, size_t length)
{
	const char charset[] =  "abcdefghijklmnopqrstuvwxyz"
							"0123456789"
							"!@#$^&*()_+[]{}|;:,.<>?";

	size_t charset_size = sizeof(charset) - 1; 

	for (size_t i = 0; i < length; i++) {
		int key = rand() % charset_size;
		password[i] = charset[key];
	}
	password[length] = '\0';
}
int main() 
{
	size_t password_length = 12;
	char password[password_length + 1]; 
	
	srand((unsigned int)time(NULL));

	generate_random_password(password, password_length);
	printf("Generated Password: %s\n", password);

	return 0;
}