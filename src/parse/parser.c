#include "../../include/header.h"

void parser(t_rdl *rdl)
{
    parser_arg(rdl);
    token_add_type(rdl, &rdl->token);
    
    rdl->token_len = token_size(rdl->token);
    printf("rdl->token_len %d\n", rdl->token_len);
    // token_add_end(rdl->token);
    keywords_id(rdl);
    token_add_keyword_id(rdl, &rdl->token);
    print_token(rdl->token);
}
