#include "../includes/asm.h"

void	input_del(t_input **ahead)
{
	t_input	*tmp;
	t_input	*prev;

	if (ahead != NULL && (tmp = *ahead) != NULL)
	{
		while(tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev->line);
			free(prev);
		}
		*ahead = NULL;
		free(ahead);
	}
}