#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <math.h> 

int size_array(char *str)
{
	int i;
	for (i = 0; *(str + i) != '\0'; i++);

	return i;
}


int test_atoi(char *str)
{
	int sum = 0, i;
	int len = size_array(str);
	for (i = 0; *(str + i) != '\0'; i++){
		if (*(str + i) >= '0' && *(str + i) <= '9'){
			sum += (*(str + i) - '0') * pow(10, len - i - 1);
		} else {
			printf("2 arg no is atoi\n");
			exit(1);
		}
	}
	return sum;
}

int equal_string(char *one, char *two)
{

	int i;
	
	for (i = 0; i < size_array(one); i++) {
		if (!(one[i] == two[i]))
			return 0;
	}

	return 1;
}

void shellsort(int n, int a[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
}

void mergesort(int n, int a[])
{
    int rght, rend;
    int i, j, m;
 	int b[n];
    for(int k = 1; k < n; k *= 2)
    {
        for (int left = 0; left + k < n; left += k * 2)
        {
            rght = left + k;
            rend = rght + k;
            if (rend > n) rend = n;
            m = left; i = left; j = rght;
            while (i < rght && j < rend)
            {
                if (a[i] <= a[j])
                {
                    b[m] = a[i]; i++;
                }
                else
                {
                    b[m] = a[j]; j++;
                }
                m++;
            }
            while (i < rght)
            {
                b[m] = a[i];
                i++; m++;
            }
            while (j < rend)
            {
                b[m] = a[j];
                j++; m++;
            }
            for (m = left; m < rend; m++)
            {
                a[m] = b[m];
            }
        }
    }
}
