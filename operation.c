#include "main.h"
#include "handlers.h"

typedef struct formatmapping{
	char specifier;
	int (*print_func)(va_list list);
} formatmapping;


formatmapping format_mappings[] = {
	{'s', handle_string},
	{'c', handle_char},
	{'%', handle_percent},
	{'d', handle_decimal},
	{'i', handle_integer}
};

int (*get_handle(char specifier))(va_list)
{
	int i;
	int num_mapping = sizeof(format_mappings) / sizeof(format_mappings[0]);

	for (i = 0; i < num_mapping; i++)
		{
			if (format_mappings[i].specifier == specifier)
			{
				return (format_mappings[i].print_func);
			}
		}

	/* if no match found */
	return (NULL);
}

