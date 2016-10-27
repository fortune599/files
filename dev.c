#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int randGen(){
  int fd = open("/dev/random", O_RDONLY);
  if (!(fd + 1)){ printf("error opening:\n%s", strerror(errno)); return; }
  int* buff = malloc(4);
  read(fd, buff, 4);
  close(fd);
  return *buff;
}

int main(){
  int rands[10];
  int i = 0;
  //printf("%d\n", randGen());
  while (i < 10){
    rands[i] = randGen();
    printf("random %d: %d\n", i, rands[i]);
    i++;
  }

  int xd = open("rand.txt", O_CREAT | O_WRONLY, 0644);
  printf("\nwriting to rand.txt...\n");
  write(xd, rands, 40);
  close(xd);

  int rands2[10];
  xd = open("rand.txt", O_RDONLY);
  printf("\nreading from rand.txt...\n");
  read(xd, rands2, 40);
  close(xd);
  
  printf("\nverifying values:\n");
  i = 0;
  while (i < 10){
    printf("random %d: %d\n", i, rands2[i]);
    i++;
  }

  return 0;
}
