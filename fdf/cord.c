//
//  cord.c
//  d
//
//  Created by Alexander Volkov on 26/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

size_t		r(char **a) {
	int i = -1;
	
	while(a[++i] != 0) {
		
	}
	ft_memdel((void **)a);
	return ((size_t)i);
}

size_t		checkCountOfElements(t_list *head) {
	t_list *current = head->next;
	size_t desired = r(ft_strsplit(head->content, ' '));
	size_t verifiable = r(ft_strsplit(current->content, ' '));
	
	while (current->next) {
		verifiable = r(ft_strsplit(current->content, ' '));
		if (desired != verifiable) {
			ft_putendl("Error: - desired and verifiable are different");
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	return desired;
}

t_cord *getCordArray(t_list *main, t_lim *lim) {
	size_t rowsValue = ft_lstsize(main);
	size_t elementsValue = checkCountOfElements(main);
	lim->x = elementsValue;
	lim->y = rowsValue;
	t_cord *newArray = (t_cord *)malloc(sizeof(t_cord) * ((int)rowsValue * (int)elementsValue + 1));
	t_list *current = main;
	
	int row = -1;
	
		while (++row < (int)rowsValue - 1) {
			char **arr = ft_strsplit(current->content, ' ');
			int elem = -1;
			while (++elem < (int)elementsValue) {
				newArray[(elem + (row * (int)elementsValue))].x = (double)elem;
				newArray[(elem + (row * (int)elementsValue))].y = (double)row;
				newArray[(elem + (row * (int)elementsValue))].z = (double)ft_atoi(arr[elem]);
			}
			ft_memdel((void **)arr);
			current = current->next;
		}
	return newArray;
}
