OBJS = src/huffman.c src/huffman_tree.c src/heap.c src/table.c src/compress.c src/decompress.c src/util.c
DEPS = inc/huffman_tree.h inc/heap.h inc/table.h inc/compress.h inc/decompress.h inc/util.h 


compile:
	gcc $(OBJS) $(DEPS) -lssl -lcrypto -o huffman -lm

test:
	gcc source/teste.c source/priority_queue.c header/priority_queue.h -o teste

clean:
	rm -f huffman
