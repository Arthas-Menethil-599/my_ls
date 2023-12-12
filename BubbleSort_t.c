#include "a.h"

/* 
part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

this functions sorts out the list of files for the -t option, i.e time-based sorting

*/

__time_t compare_t (my_files one, my_files two) {

    __time_t diff = one.time-two.time;
    __time_t diff_n = one.time_n-two.time_n;

    if (diff==0) {
        
        if (one.time_n==two.time_n) {
            return my_strcmp_t(two, one);
        }
        return diff_n;
    }
    return diff;
}

void my_swap_t(my_files *ptrOne, my_files *ptrTwo)
{
    my_files tmp;

    tmp = *ptrOne;
    *ptrOne = *ptrTwo;
    *ptrTwo = tmp;
}

int	my_strcmp_t (my_files one, my_files two)
{
  int	i;

  char* s1= one.file_name;
  char* s2= two.file_name;

  i = 0;
  while (s1[i] != 0 || s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return ((s1[i] - s2[i] < 0) ? -1 : 1);
      i += 1;
    }
  return (0);
}


void BubbleSort_t(my_files *a, int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size-1; j++)
		{
			if( compare_t(a[j], a[j+1])>0)
			{
                my_swap_t(&a[j],&a[j+1]);
			}
		}
	}
}