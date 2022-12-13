#include "../../include/header.h"

// int static buf_count(int k, t_rdl *rdl)
// {
// 	int		i;
// 	int		j;
// 	char	c;
// 	int 	count;

// 	i = k;
// 	j = 0;
// 	c = 0;
// 	count = 0;
// 	if (rdl->main_str[i] <= 32)
// 	{
// 		while (rdl->main_str[i++] <= 32 && rdl->main_str[i]);
// 		i--;
// 	}
// 	if (is_quote(rdl->quote_list, rdl->main_str[i]))
// 	{
// 		c = rdl->main_str[i];
// 		while (rdl->main_str[i])
// 		{
// 			count++;
// 			i++;
// 			if (rdl->main_str[i] == c)
// 			{
// 				count++;
// 				i++;
// 				break;
// 			}
// 		}	
// 	}
// 	else
// 	{
// 		while (rdl->main_str[i] > 32 && rdl->main_str[i])
// 		{
// 			count++;
// 			i++;
// 		}
// 	}
// 	if (rdl->main_str[i] <= 32)
// 		while (rdl->main_str[i++] <= 32 && rdl->main_str[i]);
// 	return count;
// }


void parser_arg_keyword(int *k, t_rdl *rdl)
{
	int		i;
	int		j;
	char	c;
	int		len;

	len = 0;
	i = *k;
	j = 0;
	c = 0;
	// len = buf_count(i, rdl);
	// rdl->buffer = malloc(sizeof(char)*len + 1);
	if (rdl->main_str[i] <= 32)
	{
		while (rdl->main_str[i++] <= 32 && rdl->main_str[i]);
		i--;
	}
	if (is_quote(rdl->quote_list, rdl->main_str[i]))
	{
		c = rdl->main_str[i];
		while (rdl->main_str[i])
		{
			rdl->buffer[j++] = rdl->main_str[i];
			i++;
			if (rdl->main_str[i] == c)
			{
				rdl->buffer[j++] = rdl->main_str[i];
				i++;
				break;
			}
		}	
	}
	else
	{
		while (rdl->main_str[i] > 32 && rdl->main_str[i])
		{
			rdl->buffer[j++] = rdl->main_str[i];
			i++;
		}
	}
	if (rdl->main_str[i] <= 32)
		while (rdl->main_str[i++] <= 32 && rdl->main_str[i]);
	rdl->buffer[j] = '\0';
	*k = i;
}
