/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <savas11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:06:20 by savas11           #+#    #+#             */
/*   Updated: 2022/09/08 22:06:22 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_quick_sort - Bir dizi sayı üzerinde hızlı bir sıralama çalıştırın,
** özyinelemeli çalışır.
*/

void	ft_quick_sort(int *array, int start, int end)
{
	int	q;

	if (start < end)
	{
		q = ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
}

/*
** ft_partition - Dizi bölümü ve ana
** sıralama işlemi bu fonksiyonda gerçekleşir.
*/

int	ft_partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	temp;
	int	j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}
