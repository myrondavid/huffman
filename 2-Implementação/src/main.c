#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/compress.h"
#include "../header/decompress.h"

void help() {
  printf("Huffman Help\n\n");

  printf("Usage: huffman [options] [source_filename_path] [destination_filename_path]\n");
  printf("Uso: huffman [options] [arquivo_de_origem] [arquivo_de_destino]\n\n");

  printf("Options:\n");
  printf("%s\n", "-c: Compress the source file to the destination file");
  printf("%s\n", "-d: Decompress the source file to the destination file");

  exit(0);
}

int main(int argc, char const *argv[]) {
  FILE *file, *dest_file;

  char *src_filename, *dest_filename, option[3];
  unsigned char *file_content;
  long int file_size;

  if(argc == 1) {
    help();
  } else {
    if(argc == 2 && strcmp(argv[1], "-help") == 0) {
      help();
      exit(0);
    } else if(argc != 4) {
      printf("Invalid arguments! See 'huffman -help' for more information. \n");
      exit(1);
    }

    src_filename = (char*)malloc(strlen(argv[2]) * sizeof(char));
    dest_filename = (char*)malloc(strlen(argv[3]) * sizeof(char));

    strcpy(option, argv[1]);
    strcpy(src_filename, argv[2]);
    strcpy(dest_filename, argv[3]);

    if(strcmp(option, "-c") != 0 && strcmp(option, "-d") != 0) {
      printf("Invalid option! See 'huffman -help' for more information.\n");
      exit(1);
    }

    file = fopen(src_filename, "rb");
    dest_file = fopen(dest_filename, "wb+");

    if(file == NULL) {
      printf("The source file does not exist!\n");
      exit(1);
    }

    fseek(file, 0, SEEK_END);                             /* Set the pointer to the end of the file */
    file_size = ftell(file);                              /* Return the position of the pointer on the file */
    rewind(file);                                         /* Rollback the pointer to the beginning of thee file */
    file_content = (unsigned char*)malloc((file_size + 1) * (sizeof(unsigned char)));
    //fread(file_content, sizeof(unsigned char), file_size, file);   /* Read the content of the file */
    fclose(file);
    file_content[file_size] = 0;
  }

  if(strcmp(option, "-c") == 0){
    compress(file, file_size, dest_file);
  } else {
    //decompress(file_content, file_size, dest_filename);
  }

  return 0;
}
