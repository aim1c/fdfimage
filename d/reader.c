//
//  reader.c
//  d
//
//  Created by Alexander Volkov on 21/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

int openFile(const char *filename) {
	int fd = open(filename, O_RDONLY);
	
	if (fd <= 0) {
		ft_putendl("Can't open file");
		exit(EXIT_FAILURE);
	}
	return fd;
}


t_list *readerFromFile(int fd) {
	
	t_list	*head;
	t_list	*current;
	char	*line;
	int		res;
	
	if ((head = (t_list *)malloc(sizeof(t_list))) == 0) {
		ft_putendl("Error while malloc head of list in func: t_list *readerFromFile");
		exit(EXIT_FAILURE);
	}
	head->next = 0;
	current = head;
	
	while ((res = ft_gnl(fd, &line)) > 0) {
		current->content = ft_strdup(line);
		free(line);
		if ((current->next = (t_list *)malloc(sizeof(t_list))) == 0) {
			ft_putendl("Error while malloc current of list in func: t_list *readerFromFile");
			exit(EXIT_FAILURE);
		}
		current = current->next;
		current->next = 0;
	}
	return head;
}

//	MARK : SANDBOX

void checkReaderWork(t_list *head) {
	t_list *current = head;
	
	while (current->next) {
		ft_putendl(current->content);
		current = current->next;
	}
}

void checkCord(t_cord *mainCoord) {
	int oldRow = 0;
	t_cord *cor = mainCoord;
	
	while (cor->next) {
		if (oldRow < cor->y) {
			printf("\n");
			oldRow = cor->y;
		}
		printf("%2.0f ", cor->z);
		cor = cor->next;
	}
}
//
