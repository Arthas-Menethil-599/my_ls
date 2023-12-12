/* 
this header file is part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

*/



#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include<string.h>

typedef struct t_opt {
    char a;
    char t;

} t_opt ; 

typedef struct my_files {

    char* file_name;
    int file_type;
    __time_t time;
    __time_t time_n;

} my_files;

void which_opt(t_opt* variant, char* argv);
int option_flag (char* argv);
t_opt* get_opt (t_opt* variant, int argc, char *argv[]);
void simple_ls (my_files a[100], int sum);
void a_ls (my_files a[100], int sum);
void t_ls (my_files a[100], int sum);
void ta_ls (my_files a[100], int sum);
void BubbleSort(char ** A, int size);
void BubbleSort_t(my_files *a, int size);
void my_swap_t(my_files *ptrOne, my_files *ptrTwo);
__time_t compare_t (my_files one, my_files two);
void my_swap(char **ptrOne, char **ptrTwo);
int	my_strcmp(char *s1, char *s2);
int	my_strcmp_t (my_files one, my_files two);