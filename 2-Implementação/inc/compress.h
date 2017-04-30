#ifndef COMPRESS_H
#define COMPRESS_H

  /*
  Função que comprime o arquivo.
  Recebe:
  - Array unsigned char contendo os bytes do arquivo
  - long int: numero de bytes que o arquivo possui
  - String: nome do arquivo de destino
  Retorna: void
  */
  void compress(unsigned char *file_content, long int file_size, char *dest_filename);

#endif
