//
//  main.c
//  d
//
//  Created by Alexander Volkov on 18/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

#define UNIQ_BPP 4


int		checkCountOfElements(t_list *head) {
	t_list *current = head->next;
	size_t desired = head->content_size;
	size_t verifiable = current->content_size;
	
	while (current->next) {
		if (desired != verifiable) {
			ft_putendl("Error: - Count of elements in row are different");
			return 0;
		}
		current = current->next;
		verifiable = current->content_size;
	}
	ft_putendl("Count of elements in rows are valid");
	return 1;
}

t_cord *getCordList(t_list *list, size_t lstsize) {
	t_cord	*head;
	t_cord	*current;
	t_list	*mainList = list;
	char	**arr;
	int		i = -1;
	int		row = 0;
	
	if ((head = (t_cord *)malloc(sizeof(t_cord))) == 0) {
		ft_putendl("Error malloc in getCordList");
		exit(EXIT_FAILURE);
	}
	head->next = 0;
	current = head;
	
	while (mainList->next) {
		arr = ft_strsplit(mainList->content, ' ');
		while (arr[++i] != 0) {
			current->x = (double)i;
			current->y = (double)row;
			current->z = (double)ft_atoi(arr[i]);
			current->isBottomLine = 0;
			current->isNewLine = 0;
			current->next = (t_cord *)malloc(sizeof(t_cord));
			current = current->next;
			current->next = 0;
		}
		mainList->content_size = (size_t)(i + 1);
		row++;
		i = -1;
		mainList = mainList->next;
	}
	
	if (checkCountOfElements(list) == 0) {
		ccordRemover(head);
		exit(EXIT_FAILURE);
	}
	return head;
}

void *getImage(t_img_size *imgSize, void *mlx, void *win, t_cord *ccord) {
	
	t_cord *current = ccord;
	void *img = mlx_new_image(mlx, imgSize->width, imgSize->height);
	char *addr = mlx_get_data_addr(img, &imgSize->bpp, &imgSize->width, &imgSize->endian);
	int spaceX = (imgSize->width - 20 * 2) / (int)imgSize->lineString;
	int spaceY = (imgSize->height - 20 * 2) / 20;
	
	while (current->next) {
		double x = current->x;
		double y = current->y;
		int i = ((x * spaceX) * imgSize->bpp / 8) + (y * spaceY * imgSize->width);
		addr[i] = 255;
		addr[++i] = 0;
		addr[++i] = 0;
		addr[++i] = 0;
		current = current->next;
	}
	
	return img;
}

void mainGraphicsFunc(t_list *mainList, const char *title) {
	
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1280, 720, (char *)title);
	t_img_size imgSize = (t_img_size){720, 480, 4 * 8, 0, 0};
	
	t_cord *cord = getCordList(mainList, ft_lstsize(mainList));
	imgSize.lineString = mainList->content_size;
	mainListRemover(mainList);
	void *img = getImage(&imgSize, mlx, win, cord);
	
	mlx_put_image_to_window(mlx, win, img, (1280 - 720) / 2, (720 - 480) / 2);
	
	
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
