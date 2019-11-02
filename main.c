#include <stdio.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	t_format_list	*format_list;

	format_list = get_format_list("sfsdf%#020.45ldffs%020%.77hlhhlhlLlllhhhLsfdgdfg%%sf");
	int		i = 1;
	while (format_list)
	{
		printf("ELEM %d\n", i);
		printf("conv: %c\n", format_list->conv);
		printf("flags: %c %c %c %c\n", (format_list->flags)[0],
				(format_list->flags)[1],
				(format_list->flags)[2],
				(format_list->flags)[3]);
		printf("mod: %c %c %c %c %c\n", (format_list->mod)[0],
				(format_list->mod)[1],
				(format_list->mod)[2],
				(format_list->mod)[3],
				(format_list->mod)[4]);
		printf("position: %d\n", format_list->position);
		printf("len: %d\n", format_list->len);
		printf("width: %d\n", format_list->width);
		printf("precision: %d\n\n", format_list->precision);
		format_list = format_list->next;
		i++;
	}
	return (0);
}
