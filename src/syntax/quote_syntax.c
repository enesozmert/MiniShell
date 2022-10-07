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
	if (rdl->token->id != 0)
		return (0);
	token = get_token_id(rdl->token, 0);
	while(i < (int)ft_strlen(token->context))
	{
	    if(token->context[i] == '\"' )
	    {
	        d_q++;
	        i++;
	        while(token->context[i] != '\"')
	        {
                if(token->context[i] == '\0')
                    break;
				i++;
	        }
	        if(token->context[i] == '\"')
	            d_q++;
	    }
	    else if(token->context[i] == '\'')
	    {
	        s_q++;
	        i++;
	        while(token->context[i] != '\'' )
	        {
                if(token->context[i] == '\0')
                    break;
				i++;
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

int quote_syntax(t_rdl *rdl)
{
	rdl->quote->sq = 0;
	rdl->quote->dq = 0;
	if(rdl->token->len == 1 && rdl->token->id != 0)
	{
		if (ft_strncmp(rdl->token->context, "\'", rdl->token->len) == 0)
			rdl->quote->sq++;
		else if (ft_strncmp(rdl->token->context, "\"", rdl->token->len) == 0)
			rdl->quote->dq++;
		//printf("%s %d\n",rdl->token->context, rdl->token->id);
	}
	//printf("sq %d dq %d \n", rdl->sq, rdl->dq);
	// printf("%s %d\n",rdl->token->context, rdl->token->id);
	if ((rdl->quote->sq %2 != 0 || rdl->quote->dq %2 != 0) && rdl->token->id == token_size(rdl->token) - 1)		
		return (102);
	return (0);
}