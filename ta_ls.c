#include "a.h"

/* 
part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

this functions prints out the time-sorted order of files, including those, which are hidden

*/


void ta_ls (my_files a[100], int sum) {


    BubbleSort_t(a, sum);

    for (int i=sum-1; i>=0; i--) {
        printf("%s  ", a[i].file_name);
    }

}