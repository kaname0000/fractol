/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:45:11 by okaname           #+#    #+#             */
/*   Updated: 2025/02/23 14:48:59 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void	sample_function(void)
{
	// 適当な処理
}

int	main(void)
{
	double	elapsed;
	double	x;
	double	y;

	x = 1.23445;
	struct timeval start, end;
	gettimeofday(&start, NULL); // 計測開始
	pow(x, 2);                  // 測定したい関数
	gettimeofday(&end, NULL);   // 計測終了
	elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)
		/ 1000000.0;
	printf("Execution time: %f seconds\n", elapsed);
	return (0);
}
