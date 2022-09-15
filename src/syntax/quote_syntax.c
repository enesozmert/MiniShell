#include "../../include/header.h"

int keyword_quoute_syntax(t_rdl *rdl)
{
	int i;
	int d_q;
	int s_q;
	t_token *token;

	d_q = 0;
	s_q = 0;
	i = 0;
	token = get_token_id(rdl->token, 0);
	printf("token context : %s\n", token->context);
	while(i < (int)ft_strlen(token->context))
	{
	    if(token->context[i] == '\"' )
	    {
	        d_q++;
	        i++;
	        while(token->context[i++] != '\"')
	        {
                if(token->context[i] == '\0')
                    break;
	        }
	        if(token->context[i] == '\"')
	            d_q++;
	    }
	    else if(token->context[i] == '\'')
	    {
	        s_q++;
	        i++;
	        while(token->context[i++] != '\'' )
	        {
                if(token->context[i] == '\0')
                    break;
	        }
	        if(token->context[i] == '\'')
	            s_q++;
	    }
	    i++;
	}
	if (d_q % 2 != 0 || s_q % 2 != 0)
		return(100);
	return (0);
}
