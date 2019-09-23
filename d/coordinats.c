//
//  coordinats.c
//  d
//
//  Created by Frost atronach Snow bear on 23/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

size_t arraySize(char **arr, int needfree) {
	size_t i = 0;
	
	if (!arr) {
		return -1;
	}
	
	while (arr[i] != 0) {
		i++;
	}
	
	if (needfree) {
		i = 0;
		while (arr[i] != 0) {
			free(arr[i]);
			i++;
		}
		free(arr);
		return i;
	}
	return i;
}

static	size_t		checkCountOfElements(t_list *head) {
	t_list *current = head->next;
	size_t desired = arraySize(ft_strsplit(head->content, ' '), 1);
	size_t verifiable = arraySize(ft_strsplit(current->content, ' '), 1);
	
	while (current) {
		if (desired != verifiable) {
			ft_putendl("Error: - Count of elements in row are different");
			return 0;
		}
		current = current->next;
		if (!current->content)
			break ;
		verifiable = arraySize(ft_strsplit(current->content, ' '), 1);;
	}
	ft_putendl("Count of elements in rows are valid");
	return desired;
}

t_cord		*getCordList(t_list *list, size_t lstsize) {
	
	size_t column = checkCountOfElements(list);
	t_cord *cord = (t_cord *)malloc(sizeof(t_cord) * (column * ft_lstsize(list)));
	t_list *currentList = list;
	int row = 0;
	int j = 0;
	while (currentList->next) {
		int i = -1;
		char **arr = ft_strsplit(currentList->content, ' ');
		while (++i != column - 1) {
			cord[j].x = (double)i;
			cord[j].y = (double)row;
			cord[j].z = (double)ft_atoi(arr[i]);
		}
	}
	return 0;
}
