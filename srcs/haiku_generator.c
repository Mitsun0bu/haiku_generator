/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haiku_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:18:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/21 22:34:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/haiku_generator.h"

int	main (int ac, char ** av)
{
	t_file	*file;
	
	(void)ac;
	(void)av;
	file = malloc(sizeof(t_file) * N_FILE);
	get_file_path(&file);
	open_all_files(&file);
	srand(time(NULL));
	get_random_number(&file, 0, 10);
}

void	get_file_path(t_file **file)
{
	file[0]->path = "./dictionaries/articles.txt";
	file[1]->path = "./dictionaries/aux_conjug.txt";
	file[2]->path = "./dictionaries/aux_modalite.txt";
	file[3]->path = "./dictionaries/noms_feminins.txt";
	file[4]->path = "./dictionaries/noms_masculins.txt";
	file[5]->path = "./dictionaries/pronoms_pers.txt";
	file[6]->path = "./dictionaries/verbes_impersonnels.txt";
	file[7]->path = "./dictionaries/verbes_intransitifs.txt";
	file[8]->path = "./dictionaries/verbes_pronominaux.txt";
	file[9]->path = "./dictionaries/verbes_transitifs.txt";
}

int	open_all_files(t_file **file)
{
	int	i;
	
	i = -1;
	while(++i < N_FILE)
	{
		file[i]->fd = open(file[i]->path, O_RDONLY);
		if (file[i]->fd < 0)
		{
			printf("Error ! Opening of .txt file failed.\n");
			exit (0);
		}
	}
	return (0);
}

void	get_random_number (t_file **file, int min, int max)
{
	int	i;
	
	i = -1;
	while(++i < N_FILE)
		file[i]->line_to_read = rand() % (max - min + 1) + min;
}

