#include "monty.h"

/**
 * _atoi -  a function that converts a string to integers
 * @str: the string to be converted
 *
 * Return: the resulting integer, if error return 0
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

/**
 * create_node - Creates a new node and adds it to the stack.
 * @head: Pointer to the top of the stack.
 * @n: Value to store in the new node.
 *
 * Return: Address of the newly created node, or NULL on failure.
 */
stack_t *create_node(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!head || !new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	char *op_arg = strtok(NULL, " \t\n");

	if (op_arg)
		value = _atoi(op_arg);
	if (op_arg == NULL || (value == 0 && strcmp(op_arg, "0") != 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	new_node = create_node(stack, value);
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node;
	(void)line_number; /* Unused variable */

	curr_node = *stack;
	while (curr_node != NULL)
	{
		printf("%d\n", curr_node->n);
		curr_node = curr_node->next;
	}
}
