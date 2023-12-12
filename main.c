/* 
part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

this is the main function. it is quite large, but i did all the operations with command line arguments 
and directories in here so I would only have them all neatly in one place 

*/




#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include<string.h>
#include "a.h"


int main(int argc, char *argv[]) {

    struct my_files new_file[100]; 

    struct t_opt *variant = (t_opt*)malloc(sizeof(t_opt));


    variant = get_opt(variant, argc, argv);         //this function handles the cmnd line args

    DIR *dir;
    struct dirent *sd;
    struct stat st;
    char* path = 0;


    for (int i = 1; i<argc; i++) {
        
        if(argv[i][0] == '-')
        {
            continue;
        }
        else {
            path = argv[i]; 
        }
    }

    if (path==0) {
        path=".";
    }
    
    dir = opendir(path);

    if (dir == NULL) {
        printf("Path invalid\n");
        free(variant);
        closedir(dir);
        return 1;
    }


    int index_of_arr = 0;

    while ((sd=readdir(dir)) != NULL) {      //this function fills out the array of structs with info abt 
        stat(sd->d_name, &st);                 // files and directories in the current folder
        new_file[index_of_arr].file_name=sd->d_name;
        new_file[index_of_arr].file_type=sd->d_type;
        new_file[index_of_arr].time=st.st_mtim.tv_sec;
        new_file[index_of_arr].time_n=st.st_mtim.tv_nsec;
        index_of_arr +=1;
    }

    if (variant->a==1&&variant->t==0) {     // these if-statments call the functions that print out the files&dirs
        a_ls(new_file, index_of_arr);       //in the correct order
    } 

    if (variant->t==1&&variant->a==0) {
        t_ls(new_file, index_of_arr);
    }

    if (variant->t==1&&variant->a==1) {
        ta_ls(new_file, index_of_arr);
    }

    if (variant->a==0&&variant->t==0) {
        simple_ls(new_file, index_of_arr);
    }
    
    closedir(dir);

    free(variant);

    return 0;

}