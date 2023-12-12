
/* 
part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

this function sorts the files&dirs in lexicographical order

*/



#include "a.h"

void my_swap(char **ptrOne, char **ptrTwo)
{
    char *tmp;

    tmp = *ptrOne;
    *ptrOne = *ptrTwo;
    *ptrTwo = tmp;
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 || s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return ((s1[i] - s2[i] < 0) ? -1 : 1);
      i += 1;
    }
  return (0);
}



void BubbleSort(char ** A, int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size-1; j++)
		{
			if( my_strcmp(A[j], A[j+1])>0 )
			{
                my_swap(&A[j], &A[j+1]);
			}
		}
	}
}