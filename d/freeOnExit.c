//
//  freeOnExit.c
//  d
//
//  Created by Alexander Volkov on 21/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

void mainListRemover(t_list *mainList) {
	t_list *current = mainList->next;
	
	int count = 0;
	while (current) {
		free(mainList->content);
		free(mainList);
		count++;
		mainList = current;
		current = current->next;
	}
	ft_putendl("LOG: - mainList has been deleted successfull");
}

void ccordRemover(t_cord *cord) {
	free(cord);
	ft_putendl("LOG: - Coordinats has been deleted successfull");
}
