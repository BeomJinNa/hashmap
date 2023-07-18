/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:39:33 by bena              #+#    #+#             */
/*   Updated: 2023/07/18 19:00:11 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash.h"

#include <stdio.h>

int	main(void)
{
	t_hashtable	*hash = init_hashtable(1024);

	if (hash == NULL)
	{
		printf("hashtable allocation failed.\n");
		return (1);
	}
	printf("hashtable malloced.\n");
	remove_hashtable(hash);
	printf("hashtable removed.\n");
	hash = init_hashtable(1024);
	if (hash == NULL)
	{
		printf("hashtable allocation failed.\n");
		return (1);
	}
	printf("hashtable realloced.\n");
	hash = extend_hashtable(hash, 2048);
	printf("hashtable extended.\n");
	hashtable_addkey("123", "456", hash);
	hashtable_addkey("abc", "def", hash);
	printf("123 :%s, abc :%s\n", hashtable_get("123", hash), hashtable_get("abc", hash));
	hashtable_removekey("abc", hash);
	printf("key abc removed.\n");
	hashtable_removekey("123", hash);
	printf("key 123 removed.\n");
	remove_hashtable(hash);
	printf("hashtable removed.\n");
	system("leaks testhashmap");
	return (0);
}
