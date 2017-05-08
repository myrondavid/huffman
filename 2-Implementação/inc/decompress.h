#ifndef DECOMPRESS_H
#define DECOMPRESS_H

  /*
  Função que descomprime o arquivo.
  Recebe:
  - Array unsigned char contendo os bytes do arquivo
  - long int: numero de bytes que o arquivo possui
  - String: nome do arquivo de destino
  Retorna: void
  */
  void decompress(unsigned char *file_content, long int file_size, char *dest_filename);

#endif
