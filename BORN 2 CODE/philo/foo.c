/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:05:04 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/08 20:14:43 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(void){
    struct timeval tv;
    struct tm *ptm;

    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);

    printf("%d.%d\n", tv.tv_sec, tv.tv_usec);
    printf("%d05d-%02d-%02d %d02d:%02d:%02d.%06ld\n"
            , ptm->tm_year + 1900
            , ptm->tm_mon + 1
            , ptm->tm_mday
            , ptm->tm_hour
            , ptm->tm_min
            , ptm->tm_sec
            , tv.tv_usec);

    return 0;
}

// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <stdlib.h>

// void *pthread_ex(void *num);
// pthread_mutex_t m_mutex;
// int i = 0;

// int main(){
// 	int sts;
// 	int i = 0;
// 	pthread_t *thread_id;
// 	// void *t_return;
// 	thread_id = malloc(sizeof(pthread_t *) * 5);
// 	while (i < 5)
// 	{
// 		if ((sts=pthread_create(&(thread_id[i]),NULL,(void *)pthread_ex,(void *)i))!=0){
// 			perror("error\n\n");
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	pthread_mutex_init(&m_mutex,NULL);
// 	pthread_join(thread_id[0], NULL);
// 	pthread_join(thread_id[1], NULL);
// 	pthread_join(thread_id[2], NULL);
// 	pthread_join(thread_id[3], NULL);
// 	pthread_join(thread_id[4], NULL);
// 	return 0;
// }
// void *pthread_ex(void *num)
// {
// 	int j=0;
// 	sleep(3);
// 	// printf("thread id %lu \n", (int)num);
// 	pthread_mutex_lock(&m_mutex);
// 	while(j<5){
// 		sleep(1);
// 		printf("thread(%d).. %d\n",(int)num,i);
// 		i++;
// 		j++;
// 	}
// 	pthread_mutex_unlock(&m_mutex);
// 	return (0);
// }
