/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:05:04 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/06 21:34:22 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *pthread_ex(void);
int main(){
	int sts;
	pthread_t thread_id;
	// void *t_return;
	if((sts=pthread_create((&thread_id),NULL,(void *)pthread_ex,NULL))!=0){
		perror("error\n\n");
		exit(1);
	}
	printf("thread id %lu \n", pthread_self());
	pthread_join(thread_id, NULL);
	return 0;
}
void *pthread_ex(void)
{
	int i=0;
	sleep(3);
	printf("thread id %lu \n", pthread_self());
	while(i<10){
		sleep(1);
		printf("thread.. %d\n",i);
		i++;
	}
	return (0);
}
