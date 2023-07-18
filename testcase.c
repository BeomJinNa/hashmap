/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:39:33 by bena              #+#    #+#             */
/*   Updated: 2023/07/18 22:10:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash.h"

#include <stdio.h>

int	main(void)
{
	t_hashtable	*hash = init_hashtable(16);
	char		str[256][3];
	char		*temp;

	if (hash == NULL)
	{
		printf("hashtable allocation failed.\n");
		return (1);
	}
	printf("hashtable malloced.\n");
	remove_hashtable(hash);
	printf("hashtable removed.\n");
	hash = init_hashtable(16);
	if (hash == NULL)
	{
		printf("hashtable allocation failed.\n");
		return (1);
	}
	printf("hashtable realloced.\n");
	int i = 0;
	while (i < 64)
	{
		str[i][0] = i / 10 + '0';
		str[i][1] = i % 10 + '0';
		str[i][2] = '\0';
		hashtable_addkey(str[i], str[i], hash);
		printf("addkey %s address %d\n", str[i], djb2(str[i], 16));
		i++;
	}
	i = 16;
	while (i < 48)
	{
		hashtable_removekey(str[i], hash);
		printf("remove key : %s\n", str[i]);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		printf("start get value i : %d\n", i);
		temp = hashtable_get(str[i], hash);
		printf("got %d\n", i);
		printf("key %s, value %s\n", str[i], temp);
		i++;
	}
	printf("start extension\n");
	hash = extend_hashtable(hash, 32);
	printf("hashtable extended.\n");
	hashtable_addkey("123", "456", hash);
	hashtable_addkey("abc", "def", hash);
	printf("%s %s %s %s\n", "123", hashtable_get("123", hash), "abc", hashtable_get("abc", hash));
	i = 0;
	while (i < 64)
	{
		temp = hashtable_get(str[i], hash);
		if (temp == NULL)
			printf("value is NULL, key %s\n", str[i]);
		else
			printf("key %s, value %s\n", str[i], temp);
		i++;
	}
	printf("start removal\n");
	remove_hashtable(hash);
	printf("hashtable removed.\n");
	system("leaks testhashmap");
	return (0);
}

