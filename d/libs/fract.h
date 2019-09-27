//
//  fract.h
//  d
//
//  Created by Alexander Volkov on 19/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#ifndef fract_h
#define fract_h

#include <unistd.h>
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "cord.h"


typedef struct	s_img_size {
	int			width;
	int			height;
	int			bpp;
	int			endian;
	int			rows;
	int			colums;
}				t_img_size;

<<<<<<< HEAD
=======
typedef struct	s_cord {
	
	double		x;
	double		y;
	double		z;
	int			isNewLine;
	int			isBottomLine;
	struct		s_cord	*next;
}				t_cord;

typedef struct	s_line {
	double		dx;
	double		dy;
	double		error;
	int			sx;
	int			sy;
}				t_line;

typedef struct	s_x1_y1 {
	double		x0;
	double		x1;
	double		y0;
	double		y1;
}				t_xy;

>>>>>>> 323b9b4e0fe9c7062fc86667049adeaa28394741
int key_press(int keycode, void *param);


// MARK: - DATA FREE

void mainListRemover(t_list *mainList);
void ccordRemover(t_cord *cord);

//

// MARK: - READER

t_list	*readerFromFile(int fd);
int		openFile(const char *filename);
t_cord	*getCordList(t_list *list, size_t lstsize);


//

// MARK: - SANDBOX

void	checkReaderWork(t_list *head);
void	checkCord(t_cord *mainCoord);

//

#endif /* fract_h */
