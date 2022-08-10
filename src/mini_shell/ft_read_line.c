#include "../../include/header.h"

char *ft_read_line(void)
{

	int size;
	t_token *token;
	char *str;

	token = NULL;
	str = NULL;
	
	str = readline("->");
	//cagirilan yerde free'lenecek
	return str;
}