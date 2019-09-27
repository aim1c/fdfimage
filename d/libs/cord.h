//
//  cord.h
//  d
//
//  Created by Alexander Volkov on 26/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#ifndef cord_h
#define cord_h

#include "fract.h"

typedef struct	s_lim {
	size_t		x;
	size_t		y;
}				t_lim;

typedef struct	s_cord {
	
	double		x;
	double		y;
	double		z;
}				t_cord;

t_cord *getCordArray(t_list *main, t_lim *lim);
size_t		checkCountOfElements(t_list *head);

#endif /* cord_h */
