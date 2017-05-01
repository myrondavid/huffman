OBJS = src/main.c src/huff_tree.c src/priority_queue.c src/table.c src/compress.c src/decompress.c
DEPS = inc/huff_tree.h inc/priority_queue.h inc/table.h inc/compress.h inc/decompress.h 


compile:
	gcc $(OBJS) $(DEPS) -o main -lm

test:
	gcc src/teste.c src/priority_queue.c inc/priority_queue.h src/huff_tree.c inc/huff_tree.h -o teste

clean:
	rm -f main
