/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:00 by jikoo             #+#    #+#             */
/*   Updated: 2023/05/23 14:39:30 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*lexical_analysis(t_info *info, char *input)
{
	t_token	*token_list;

	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	handle_heredoc_limiter(info, token_list);
	handle_quotes(info, token_list);
	handle_environment_variables(info, token_list);
	seperate_token_by_arg(token_list, " ");
	seperate_token_by_arg(token_list, "|");
	seperate_token_by_arg(token_list, "<<");
	seperate_token_by_arg(token_list, ">>");
	seperate_token_by_arg(token_list, "<");
	seperate_token_by_arg(token_list, ">");
	handle_chunk(&token_list);
	merge_continuous_argv_token(&token_list);
	remove_space_token(&token_list);
	return (token_list);
}

// t_token	*lexical_analysis(t_info *info, char *input)
// {
// 	t_token	*token_list;

// 	// 1. input -> chunk
// 	token_list = create_token(input, TOKEN_TYPE_CHUNK);
// 	printf("=== 1 최초의 CHUNK가 있었도다 ===================\n");
// 	print_token_list(token_list);

// 	// 2. handle heredoc limiter
// 	handle_heredoc_limiter(info, token_list);
// 	printf("=== 2 heredoc limiter 처리 ======================\n");
// 	print_token_list(token_list);

// 	// 3. handle quotes
// 	handle_quotes(info, token_list);
// 	printf("=== 3 따옴표 처리 ===============================\n");
// 	print_token_list(token_list);

// 	// 4. handle environment variables
// 	handle_environment_variables(info, token_list);
// 	printf("=== 4 환경 변수 처리 ============================\n");
// 	print_token_list(token_list);
	
// 	// 5. seperate space token
// 	seperate_token_by_arg(token_list, " ");
// 	printf("=== 5 SPACE 분리 ================================\n");
// 	print_token_list(token_list);

// 	// 6. seperate pipeline token
// 	seperate_token_by_arg(token_list, "|");
// 	printf("=== 6 PIPELINE 분리 =============================\n");
// 	print_token_list(token_list);

// 	// 7. seperate redirection toekn
// 	seperate_token_by_arg(token_list, "<<");
// 	seperate_token_by_arg(token_list, ">>");
// 	seperate_token_by_arg(token_list, "<");
// 	seperate_token_by_arg(token_list, ">");
// 	printf("=== 7 REDIRECTION 분리 ==========================\n");
// 	print_token_list(token_list);

// 	// 8. remove empty chunk & change chunk to argv
// 	handle_chunk(&token_list);
// 	// printf("=== 8 CHUNK 처리 ================================\n");
// 	// print_token_list(token_list);
	
// 	// 9. merge continuous argv token
// 	merge_continuous_argv_token(&token_list);
// 	// printf("=== 9 연속된 ARGV 병합 ==========================\n");
// 	// print_token_list(token_list);

// 	// 10. remove space token
// 	remove_space_token(&token_list);
// 	// printf("=== 10 SPACE 지우기 =============================\n");
// 	// print_token_list(token_list);

// 	return (token_list);
// }
