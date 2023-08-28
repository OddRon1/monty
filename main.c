#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - this is the monty code interpreter
* @argc: this is the number of arguments
* @argv: this points to the monty file location
* Return: this function returns 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	stack_t *stack = NULL;
	size_t size = 0;
	FILE *file;
	ssize_t read_line = 1;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
