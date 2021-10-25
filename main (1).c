#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 1

int main(int argc, char* argv[]){
   char buf[MAX];
   char buf2[MAX];
   int desc;
   int lbajt;
   int rbajt;
 
   if (argc<2){
      fprintf(stderr, "Za malo argumentow. Uzyj:\n");
      exit(1);
   }
   desc = open(argv[1], O_RDWR);
   if (desc == -1){
      perror("Blad otwarcia pliku zrodlowego");
      exit(1);
   }
   //=======================================================================
   int rozm; //odczytanie rozmiaru pliku
    rozm = lseek(desc, 0, SEEK_END);
   if (rozm == -1){
      perror("Blad w pozycjonowaniu");
      exit(1);
   }
   printf("rozmiar: %d \n", rozm);
   lseek(desc, 0, SEEK_SET);
   int max_iter = rozm / 2;
   printf("ile iteracji: %d", ile_iter);
    
    int counter = 1;
   while((lbajt = read(desc, buf, MAX)) > 0){
        //printf("%c", buf[0]);
        lseek(desc, -1 * counter, SEEK_END);//przesuniecie na koniec
        rbajt = read(desc, buf2, MAX);//odczytanie od konca
        lseek(desc, -1 * counter, SEEK_END);//przesuniecie na koniec znowu
        write(desc, buf, lbajt);//zapisanie od konca
        lseek(desc, counter-1, SEEK_SET);//przesuniecie na start pozycjonowaniu
        write(desc, buf2, MAX);
        
        counter++;
        if(counter > max_iter){
            break;
        }
   }
   
   
   
   
   
   
   
   if (lbajt == -1){
      perror("Blad odczytu pliku zrodlowego");
      exit(1);
   }
    //==============================================
   if (close(desc) == -1 ){
      perror("Blad zamkniecia pliku");
      exit(1);
   }

   exit(0);
}
