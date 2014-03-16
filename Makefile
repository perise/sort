objects = quick_sort.o sort_helper.o main.o
all: $(objects)
	gcc -o sort $(objects)
$(objects): %.o: %.c
	gcc -c $< -o $@
clean:
	rm -rf *.o *.BAK
	rm -rf sort
