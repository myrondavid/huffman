OBJS = source/main.c source/huff_tree.c source/priority_queue.c source/table.c source/compress.c
DEPS = header/huff_tree.h header/priority_queue.h header/table.h header/compress.h 


compile:
	gcc $(OBJS) $(DEPS) -o main -lm

test:
	gcc src/teste.c src/priority_queue.c inc/priority_queue.h src/huff_tree.c inc/huff_tree.h -o teste

clean:
	rm -f main
