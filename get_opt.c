
/* 
part of "my_ls" fuction implementation

submitted on Jun, 27, 2020
author: tustykbayeva_a, alzionvontrichar@gmail.com

this functions handles the -t -a and -at flags and switches the correstonding flags on in the t_opt struct

*/


#include "a.h"

void which_opt(t_opt* variant, char* argv) {
    int index = 0;

    while (argv[index]!='\0') {

        if (argv[index]=='a') {
            variant->a=1;
        } 

        if (argv[index]=='t') {
            variant->t=1;
        }

        index+=1;
    }
}


int option_flag (char* argv) {

    if (argv[0]=='-') {
        return 1;
    }

    return 0;
}

t_opt* get_opt (t_opt* variant, int argc, char *argv[]){

    variant->a=0;
    variant->t=0;

    int index = 0;

    while (index<argc) {

        if (option_flag(argv[index])==1) {
            which_opt(variant, argv[index]+1);
        }
        index+=1;
    }


    return variant;
}