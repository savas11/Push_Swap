/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <savas11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:12:10 by savas11           #+#    #+#             */
/*   Updated: 2022/09/08 22:12:13 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_validation, kullanıcı girişini kabul eden bir işlevdir
** verileri ve verileri diğer işlevlere göndererek doğrular.
*/

int	ft_validation(int argc, char **argv)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_number_availability(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

/*
** ft_number_availability - Sayılar için dizeyi kontrol edin,
** bu nedenle toplu hatları işliyoruz.
** Örneğin: yalnızca boşluk içeren dizeler
** ve yalnızca '+' veya '-'den oluşan sekmeler ve satırlar.
*/

void	ft_number_availability(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

/*
** ft_valid_str - Dizenin geçerliliğini kontrol edin.
** Her şey doğru yazılmış mı ve fazladan karakter var mı?
**		Çizgide. Sadece numaralara ihtiyacımız var
** boşluk ve sekmelerle ayrılmalıdır. Sayılar olabilir
** olumlu veya olumsuz işaretler.
*/

void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') && (sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

/*
** ft_duplicate_check - Veri doğrulama sürecini başlat
** kopyalar için.
*/

void	ft_duplicate_check(t_data *new, t_stacks *stacks)
{
	int	*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (new->count_element))))
		exit(1);
	dup = ft_intcpy(dup, new->a, new->count_element);
	ft_quick_sort(dup, 0, new->count_element - 1);
	ft_search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

/*
** ft_search_duplicate - Bir dizi sayıyı kontrol edin
** kopyaların varlığı.
*/

void	ft_search_duplicate(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}
