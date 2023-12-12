/* 
part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

this functions prints out the lexicographically-sorted order of files, including those, which are hidden

*/
#include "a.h"

void a_ls (my_files a[100], int sum) {

    int dirs_index=0;
    int files_index=0;
    char **files=(char**)malloc(500*sizeof(char**));
    char **dirs=(char**)malloc(500*sizeof(char**));

    for (int i = 0; i<sum; i++) {

        if (a[i].file_type==4 || a[i].file_type!=4) {
            dirs[dirs_index]=a[i].file_name;
            dirs_index+=1;
        }
        // if (a[i].file_type!=4) {
        //     files[files_index]=a[i].file_name;
        //     files_index+=1;
        // }
    }

    BubbleSort(files, files_index);
    BubbleSort(dirs, dirs_index);


    for (int i=0; i<dirs_index; i++) {
        printf("%s  ", dirs[i]);
    }

    for (int i=0; i<files_index; i++) {
        printf("%s ", files[i]);
    }


    free(files);
    free(dirs);
}

