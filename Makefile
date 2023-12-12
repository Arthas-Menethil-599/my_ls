CC=gcc
CC_OPT= -g3 -fsanitize=address -Wall -Wextra -Werror
OUT=my_ls

all: ${OUT}
${OUT}:  get_opt.o main.o simple_ls.o a_ls.o t_ls.o ta_ls.o BubbleSort_t.o BubbleSort.o 
	${CC} ${CC_OPT} main.o get_opt.o simple_ls.o a_ls.o t_ls.o ta_ls.o BubbleSort_t.o BubbleSort.o -o ${OUT}

main.o: main.c
	${CC} ${CC_OPT} main.c -c

get_opt.o: get_opt.c
	${CC} ${CC_OPT} get_opt.c -c

simple_ls.o: simple_ls.c
	${CC} ${CC_OPT} simple_ls.c -c

a_ls.o: a_ls.c
	${CC} ${CC_OPT} a_ls.c -c

t_ls.o: t_ls.c
	${CC} ${CC_OPT} t_ls.c -c

ta_ls.o: ta_ls.c
	${CC} ${CC_OPT} ta_ls.c -c	

BubbleSort_t.o: BubbleSort_t.c
	${CC} ${CC_OPT} BubbleSort_t.c -c

BubbleSort.o: BubbleSort.c
	${CC} ${CC_OPT} BubbleSort.c -c

clean:
	rm *.o ${OUT}