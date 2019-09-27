//
//  main.c
//  d
//
//  Created by Alexander Volkov on 18/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

#define UNIQ_BPP 4

<<<<<<< HEAD
void printTab(t_cord *cord, t_lim *lim) {
	
	int xLim = (int)lim->x;
	int yLim = (int)lim->y;
	
	int row = -1;
	int elem = -1;
	
	while (++row < yLim - 1) {
		elem = -1;
		while (++elem < xLim) {
			t_cord new = cord[(elem + (row * xLim))];
			
			printf("%3.0f", new.z);
		}
		printf("\n");
=======
static double abs_double(double a) {
	int i = -1;
	
	return (a < 0 ? (a * i) : (a));
}

void addPixel(double x, double y, char *addr, t_img_size *imgSize) {
	
	int i = (x * 10 * 4) + (y * 10 * imgSize->width);
	
	addr[i] = 255;
	addr[++i] = 0;
	addr[++i] = 0;
	addr[++i] = 0;
}

void addline(t_cord *move, t_cord *to, char *addr, t_img_size *imgSize) {
	
	t_line calc;
	t_xy xy = (t_xy){move->x, to->x, move->y, to->y};
	int e2;

	calc.dx = abs_double(to->x - move->x);
	calc.sx = move->x < to->x ? (1) : (0);
	calc.dy = abs_double(to->y - move->y) * -1;
	calc.sy = move->y < to->y ? (1) : (-1);
	calc.error = calc.dx + calc.dy;
	
	while (42) {
		if (xy.x0 == xy.x1 && xy.y0 == xy.y1)
			break ;
		e2 = 2 * calc.error;
		if (e2 >= calc.dy) {
			calc.error += calc.dy;
			xy.x0 += calc.sx;
		}
		if (e2 <= calc.dx) {
			calc.error += calc.dx;
			xy.y0 += calc.sy;
		}
		addPixel(xy.x0, xy.y0, addr, imgSize);
>>>>>>> 323b9b4e0fe9c7062fc86667049adeaa28394741
	}
	
}


void *getImage(t_img_size *imgSize, void *mlx, void *win, t_cord *ccord) {
	t_cord *current = ccord;
	void *img = mlx_new_image(mlx, imgSize->width, imgSize->height);
	char *addr = mlx_get_data_addr(img, &imgSize->bpp, &imgSize->width, &imgSize->endian);
	
<<<<<<< HEAD
=======
	while (current->next) {
		double x = current->x;
		double y = current->y;
		
		if (current->next && current->y == current->next->y) {
			addline(current, current->next, addr, imgSize);
		}
		current = current->next;
	}
>>>>>>> 323b9b4e0fe9c7062fc86667049adeaa28394741
	return img;
}

void mainGraphicsFunc(t_list *mainList, const char *title) {
	
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1280, 720, (char *)title);
	
	t_lim *lim = malloc(sizeof(t_lim));
	t_img_size imgSize = (t_img_size){720, 480, 4 * 8, 0, 0};
	
<<<<<<< HEAD
	
	t_cord *cord = getCordArray(mainList, lim);
	mainListRemover(mainList);
	printTab(cord, lim);
	
//	t_cord *cord = getCordList(mainList, ft_lstsize(mainList));
=======
	t_cord *cord = getCordList(mainList, ft_lstsize(mainList));
>>>>>>> 323b9b4e0fe9c7062fc86667049adeaa28394741
//	imgSize.lineString = mainList->content_size;
//	mainListRemover(mainList);
//	void *img = getImage(&imgSize, mlx, win, cord);
//
//	mlx_put_image_to_window(mlx, win, img, (1280 - 720) / 2, (720 - 480) / 2);
	
	
	mlx_hook(win, 3, 0, key_press, cord);
	mlx_loop(mlx);
}

int main(int argc, const char **argv) {
	
	if (argc != 2) {
		ft_putendl("To many/not arguments");
		exit(EXIT_FAILURE);
	}
	
	int fd = openFile(argv[1]);
	t_list *mainList = readerFromFile(fd);
//	checkReaderWork(mainList);
	mainGraphicsFunc(mainList, argv[1]);
	
	
	return 42;
}
