/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <savas11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:23:46 by savas11           #+#    #+#             */
/*   Updated: 2022/09/08 21:23:50 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sa: takas a - ilk 2 öğeyi değiştirin
** üst yığın a. varsa hiçbir şey yapma
** yalnızca bir öğe veya hiç öğe yok.
*/

void	ft_sa(t_stack *a, int i)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->data;
	a->data = a->next->data;
	a->next->data = buff;
	if (i == 1)
		write(1, "sa\n", 3);
}

/*
** sb: b'yi değiştir - içindeki ilk 2 öğeyi değiştir
** üst yığın b. varsa hiçbir şey yapma
** yalnızca bir öğe veya hiç öğe yok.
*/

void	ft_sb(t_stack *b, int i)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
	if (i == 1)
		write(1, "sb\n", 3);
}

/*
** 	ss: sa ve sb aynı anda.
*/

void	ft_ss(t_stacks *s, int i)
{
	ft_sa(s->a, 0);
	ft_sb(s->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

/*
** pa: a'ya basın - en üstteki ilk öğeyi alın
** b ve a'nın üzerine yerleştirin. Hiçbirşey yapma,
** b boşsa.
*/

void	ft_pa(t_stacks *s, int i)
{
	t_stack	*buff;

	if (s->b == NULL)
		return ;
	s->count_a += 1;
	s->count_b -= 1;
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
	if (i == 1)
		write(1, "pa\n", 3);
}

/*
** pb: b'ye basın - en üstteki ilk öğeyi alın
** a ve b'nin üstüne yerleştirin.
** a boşsa hiçbir şey yapmayın.
*/

void	ft_pb(t_stacks *s, int i)
{
	t_stack	*buff;

	if (s->a == NULL)
		return ;
	s->count_a -= 1;
	s->count_b += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
	if (i == 1)
		write(1, "pb\n", 3);
}
