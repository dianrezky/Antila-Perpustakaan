#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int n,i,rak,piladm,pil;
FILE *fn;
FILE *rk;
FILE *pp;

char pinjam,pilih;
char usr[100];
int tglawal,tglbalik,bnykbk;
struct daftarbook{
    char milik[100],judul[100],penulis[100],penerbit[100],kategori[100],user[100];
    int jumlah,t,b,th,total,bnykbk;
}book[100],simpan;

struct tm *Sys_T;
time_t Tval;

//MENU PERPUSTAKAAN UNTUK PENGUNJUNG!

void menuperpus(){

    system("cls");system("color 3f");

    printf("\t\t\t\t\t\t===========================\n");
    printf("\t\t\t\t\t\t=     ANTILA'S LIBRARY    =\n");
    printf("\t\t\t\t\t\t===========================\n");
    printf("\t\t\t\t\t\t     Welcome %s \n",usr);

    printf("1. Lihat Daftar Buku\n");
    printf("2. Buku Yang Dipinjam\n");
    printf("3. Denda Anda\n");
    printf("4. Logout\n");

    printf("Pilih Menu yang diinginkan : ");scanf("%d",&pil);fflush(stdin);
    switch(pil){
        case 1:daftarbuku();break;
        case 2:bukupinjam();break;
        case 3:dendabuku();break;
        case 4:menu();break;
    }
}

void urutbuku(){

    int x,imax,y;
    i=0;

    rk=fopen("databasebook.txt","r+");
     while(!feof(rk)){
        i++;
        fscanf(rk,"%[^#]#%[^#]#%[^#]#%[^#]#%d#\n",&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].jumlah);
    }
    fclose(rk);

    for(x=1;x<=i;x++){
        imax=x;
        for(y=x+1;y<=i;y++)
            if(strcmp(book[imax].judul,book[y].judul)>0)
                imax=y;
          simpan=book[imax];
          book[imax]=book[x];
          book[x]=simpan;
        }

        rk=fopen("databasebook.txt","w+");
        for(x=1;x<=i;x++){
            fprintf(rk,"%s#%s#%s#%s#%d#\n",book[x].judul,book[x].penulis,book[x].penerbit,book[x].kategori,book[x].jumlah);
        }
        fclose(rk);
}


void daftarbuku(){

    i=0;
    int o=0;


    urutbuku();

    system("cls");
    rk=fopen("databasebook.txt","r+");

    printf("\n\t\t\t\t\t\t\t\t\t LIST OF THE BOOK\n\n");
    printf("__________________________________________________________________________________________________________________________________________\n");
    printf("NO|              JUDUL                |           PENULIS             |              PENERBIT               |           KATEGORI         |\n",i);
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    while(!feof(rk)){
        i++;
        o++;
        fscanf(rk,"%[^#]#%[^#]#%[^#]#%[^#]#%d#\n",&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].jumlah);

        printf("%-2d|      %-25s    |         %-15s       |         %-20s        |         %-12s       |\n",o,book[i].judul,book[i].penulis,book[i].penerbit,book[i].kategori);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(rk);

    printf("Apakah Ingin Meminjam Buku (y/t) : ");scanf("%c",&pilih);fflush(stdin);

    if(pilih=='y'){
        peminjaman();
    }
    else{
        system("pause");
        system("cls");
        menuperpus();}


    /*
    Note: batas maksimal pengembalian mau berapa hari? kalo misalkan hanya 3 hari gimana? jika lebih maka akan dikenakan denda
    */

}

void bukupinjam(){

    i=0;
    int o=0;
    system("cls");
    rk=fopen("pinjambuku.txt","r+");
    printf("\n\t\t\t\t\t\t\t\t\t BOOK BORROWING LIST n\n");
    printf("_______________________________________________________________________________________________________________________________________\n");
    printf("NO|              JUDUL                |           PENULIS             |              PENERBIT               |      TANGGAL PINJAM     |\n",i);
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
    while(!feof(rk)){
        i++;
        fscanf(rk,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#\n",&book[i].milik,&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].bnykbk,&book[i].t,&book[i].b,&book[i].th);
        if(strcmp(usr,book[i].milik)==0){
            o++;
            printf("%-2d|      %-25s    |         %-15s       |         %-20s        |         %d/%d/%d       |\n",o,book[i].judul,book[i].penulis,book[i].penerbit,book[i].t,book[i].b,book[i].th);
        }
    }
   printf("---------------------------------------------------------------------------------------------------------------------------------------\n");

   fclose(rk);

    printf("Apakah Anda Ingin Mengembalikan Buku (y/t) ? ");
    scanf("%c",&pilih);

    if(pilih=='y'){
        pengembalian();
    }
    else{
        system("pause");
        system("cls");
        menuperpus();
    }

}


void peminjaman(){

        printf("No Berapa Yang Ingin Dipinjam : ");scanf("%d",&pil);fflush(stdin);
        printf("Apakah anda yakin ingin meminjam buku %s (y/t) : ",book[pil].judul);scanf("%c",&pinjam);
        printf("Berapa Banyak Buku Yang Ingin Dipinjam : ");
        scanf("%d",&book[i].bnykbk);fflush(stdin);

        if(pinjam=='y'){

            Tval = time(NULL);
            Sys_T = localtime(&Tval);

           rk=fopen("pinjambuku.txt","a+");

           book[i].total=book[i].jumlah-book[i].bnykbk;

            fprintf(rk,"%s#%s#%s#%s#%s#%d#%d#%d#%d#\n",usr,book[pil].judul,book[pil].penulis,book[pil].penerbit,book[pil].kategori,book[i].bnykbk,Sys_T->tm_mday,Sys_T->tm_mon+1,1900+Sys_T->tm_year);
            fclose(rk);

            printf("\n\n!! Congratulations The Book Has Been Borrowed On %d/%d/%d !!\n",Sys_T->tm_mday,Sys_T->tm_mon+1,1900+Sys_T->tm_year);

            printf("Do You Want To Back To Menu ( y/t ) ? ");
            scanf("%c",&pilih);

            if(pilih=='y'){
                system("pause");
                system("cls");
                menuperpus();
            }
        }
        else{
            system("pause");
            system("cls");
            menuperpus();
        }

}

void pengembalian(){

    char phandler[100][100];
    char uhandler[100][100];
    char qhandler[100][100];
    char khandler[100][100];
    char zhandler[100][100];
    int jhandler[100],bhandler[100],thandler[100],thhandler[100],gnt;
    rk=fopen("pinjambuku.txt","r+");
    int cntr=0;
    while (!feof(rk)){
        fscanf(rk,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#\n",&book[i].milik,&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].jumlah,&book[i].t,&book[i].b,&book[i].th);
        strcpy(zhandler[cntr],book[i].milik);
        strcpy(uhandler[cntr],book[i].judul);
        strcpy(phandler[cntr],book[i].penulis);
        strcpy(qhandler[cntr],book[i].penerbit);
        strcpy(khandler[cntr],book[i].kategori);
        jhandler[cntr]=book[i].bnykbk;
        thandler[cntr]=book[i].t;
        bhandler[cntr]=book[i].b;
        thhandler[cntr]=book[i].th;

        cntr++;
    }
    fclose(rk);printf("\n");
    for(i=0;i<cntr;i++){
        if(strcmp(zhandler[i],usr)==0){
        printf("\t%d. Judul: %s \n",i+1,uhandler[i]);
    }}

    printf("\n\tMasukkan No. Buku Yang Ingin Dikembalikan : ");scanf("%d",&gnt);
    gnt=gnt-1;

    pp=fopen("denda.txt","a+");
    rk=fopen("pinjambuku.txt","w+");
    for(i=0;i<cntr;i++){
        if(gnt!=i){
            fprintf(rk,"%s#%s#%s#%s#%s#%d#%d#%d#%d#\n",zhandler[i],uhandler[i],phandler[i],qhandler[i],khandler[i],jhandler[i],thandler[i],bhandler[i],thhandler[i]);
        }
        if(gnt==i){
            fprintf(pp,"%s#%s#%s#%s#%s#%d#%d#%d#%d#\n",zhandler[i],uhandler[i],phandler[i],qhandler[i],khandler[i],jhandler[i],thandler[i],bhandler[i],thhandler[i]);
        }

    }
    fclose(rk);
    fclose(pp);

    Tval = time(NULL);
    Sys_T = localtime(&Tval);

    printf("\n\nBuku Telah Berhasil Dikembalikan Pada %d / %d / %d \n",Sys_T->tm_mday,Sys_T->tm_mon+1,1900+Sys_T->tm_year);
    printf("\n\nPlease Click Enter To Back To Menu\n");
    system("pause");
    system("cls");
    menuperpus();

}



void dendabuku(){

    system("cls");

    int pinjam,balik;
    int lamapinjam,denda,total;


    total=0;
    denda=0;
    i=0;
    pp=fopen("denda.txt","r+");
    int b=0;

    if(!pp){
        printf("YOU HAVE TO RETURN BOOK FIRST\n");
    }
    else {
    while(!feof(pp)){
        i++;
        fscanf(pp,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#\n",&book[i].milik,&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].bnykbk,&book[i].t,&book[i].b,&book[i].th);
        b++;
    }

    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    for(i=1;i<=b;i++){
        if(strcmp(book[i].milik,usr)==0){

            Tval = time(NULL);
            Sys_T = localtime(&Tval);

            pinjam=book[i].t;
            balik=Sys_T->tm_mday;
            lamapinjam=(balik-pinjam);

            if(lamapinjam>3){
                denda=lamapinjam*2000;
            }
            else{
                denda=0;
            }

            total=total+denda;

            printf("lama pinjam Buku %s %d hari dan denda = Rp %d \n",book[i].judul,lamapinjam,denda);

        }
    }
    printf("Total Denda Anda Rp. %d\n",total);

    fclose(pp);
    }
    printf("Press any key to back...");getch();
    menuperpus();
}




