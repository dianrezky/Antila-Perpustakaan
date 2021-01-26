#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>


//LOADING
void load(){
   printf("\n\n\n\n\n\n\n\n\n\n\n\n");
   printf("\t\t\t\t\t     System is Loading. Please wait a few minutes...\n\t\t\t\t\t");
   hm();
}
void loadd1(){
   printf("\n\n\n\n\n\n\n\n\n\n\n\n");
   printf("\t\t\t\t\t     System is Loading. Please wait a few minutes...\n\t\t\t\t\t");
   hm1();
}
void loadd2(){
   printf("\n\n\n\n\n\n\n\n\n\n\n\n");
   printf("\t\t\t\t\t     System is Loading. Please wait a few minutes...\n\t\t\t\t\t");
   hm2();
}

void hm(){
    int x; double y;
    char sl[]="                                                        ";
    for(x=0; sl[x]!=NULL; x++){
     printf("%c",219);Sleep(100);
      for(y=0; y<=9999999; y++)
      {}
   }
}
void hm1(){
    int x; double y;
    char sl[]="                                                         ";
    for(x=0; sl[x]!=NULL; x++){
     printf("%c",219);Sleep(100);
      for(y=0; y<=90999999; y++)
      {}
   }
}

void hm2(){
    int x; double y;
    char sl[]="                                                          ";
    for(x=0; sl[x]!=NULL; x++){
     printf("%c",219);Sleep(100);
      for(y=0; y<=5999999; y++)
      {}
   }
}
void ding(){
    int i;
    system("color 02");
    for(i=0;i<5;i++){
    load();system("cls");
    }
    load();Sleep(2500);
}
void ding1(){
    int i;
    system("color 02");
    for(i=0;i<1;i++){
    load();system("cls");
    }
    load();Sleep(4500);
}
void ding2(){
    int i;
    system("color 02");
    for(i=0;i<2;i++){
    load();system("cls");
    }
    load();Sleep(2500);
}
void ding3(){
    int i;
    system("color 02");
    for(i=0;i<3;i++){
    load();system("cls");
    }
    load();Sleep(3000);
}
void test(){
    dingdong();
}

void load1(){

   int x; double y;
   char sl[]="\n\t\t\t\t\t+===============================================+\n\n \n\t\t\t\t\t+-----------------------------------------------+\n \t\t\t\t\t|\t   WELCOME TO ANTILA'S LIBRARY \t\t|";
   char sp[]="\n\t\t\t\t\t+-----------------------------------------------+\n\n \n\t\t\t\t\t+===============================================+\n\n \t\t\t\t\t\t\t ----------\\----------\n";
   char sq[]="\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n \t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n \t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n \t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n \t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n";
   char ss[]="\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n \t\t\t\t\t\t\t ----------\\----------\n \n\t\t\t\t\t=================================================\n\n";
   char sw[]="\t\t\t\t\t**********\t     1).New User\t*********\n \t\t\t\t\t**********\t     2).Login   \t*********\n \n\t\t\t\t\t=================================================\n";

   for(x=0; sl[x] !=NULL; x++)
   {
      printf("%c",sl[x]);
      for(y=0; y<6999999; y++)
      {}
   }
   for(x=0; sp[x] !=NULL; x++)
   {
      printf("%c",sp[x]);
      for(y=0; y<6999999; y++)
      {}
   }
   for(x=0; sq[x] !=NULL; x++)
   {
      printf("%c",sq[x]);
      for(y=0; y<6999999; y++)
      {}
   }
   for(x=0; ss[x] !=NULL; x++)
   {
      printf("%c",ss[x]);
      for(y=0; y<6999999; y++)
      {}
   }for(x=0; sw[x] !=NULL; x++)
   {
      printf("%c",sw[x]);
      for(y=0; y<6999999; y++)
      {}
   }
}


void dingdong(){
    int i;
    for(i=0;i<1;i++){
        load1();}


}
