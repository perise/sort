objects = quick_sort.o sort_helper.o main.o
cflags = -c -I./inc
all: $(objects)
	gcc -o sort $(objects)
$(objects): %.o: %.c
	gcc $(cflags) $< -o $@
clean:
	rm -rf *.o *.BAK
	rm -rf sort
