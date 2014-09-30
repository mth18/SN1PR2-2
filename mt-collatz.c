/*
	mt-collatz.c 
	by David Hunt & Mark Humes
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include "mt-collatz.h"

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
int COUNTER = 2;

int main(int argc, char ** argv)
{
	if(argc < 3)
	{
		fprintf(stderr, "Inproper arguements sent to the program\n");
		return (-1);
	}
	int num = atoi(argv[1]);
	int threadNums = atoi(argv[2])
	//int ret = startRun(num, threadNums);
	val * values = createVal(num);
	destroyVal(values);

	return 0;
}

void startRun(int num, int threads)  //starts the implementation for the program
{
	if(threads < 1)
	{
		fprintf(stderr, "Number of threads less than one\n");
		return(-1);
	}
	val * values = createVal(threads);
	creatingThreads(num, threads, values);

	pthread_exit(NULL); 
}

int isEven(int num)			//asks the question is this number even? returns 1 if true O if false
{
	int ans = 0;
	if((num%2) == 0)
		ans = 1;
	return ans;
}

	
int collatz(int num)	//returns the number of numbers that are generated with the begining number
{
	int ans = 1, i = num;
	while(i > 1)
	{
		if(isEven(num))
		{
			i = evenNumFunction(i);
			ans++;
		}
		if(!(isEven(i)))
		{
		 	i = oddNumFunction(i);
		 	ans++;
		}
	}
	return ans;
}

int evenNumFunction(num)
{
	return (num/2);
}

int oddNumFunction(num)
{
	return ((3*num) +1);
}

val * creatingVal(int numb)
{
	val * temp = (val*)malloc(sizeof(val) +1);
	temp->szHist = numb;
	temp->histogram = (int *)malloc((sizeof(int))*numb +1);
	int i;
	for(i = 0; i < numb; i++)
	{
		temp->histogram[i] = 0;
	}
}

void * destroyVal(val * values)
{
	free(values->histogram);
	free(values);
}