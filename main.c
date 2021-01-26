#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//DEKLARASI GLOBAL PROGRAM
int n,i,rak,piladm,pil;
FILE *fn;
FILE *rk;
char nama[100],buku[100][100];
char password[100];
char usr[100];
char pws[100];
char temp[100];
char pinjam;
int logincntr=0;

struct daftarbook{
    char milik[100],judul[100],penulis[100],penerbit[100],kategori[100],user[100];
    int jumlah,t,b,th;
}book[100],simpan;

/*
Bisa melihat ada apa aja buku yang ready tetapi jika ingin meminjam wajib login terlebih dahulu dan jika mengembalikan tidak perlu login
karena sistem akan otomatis akan mendatanya dan untuk denda dikalkulasikan pada sistem perpustakaan yang dibuat, denda yang diterapkan di
perpustakaan KAMI yaitu sehari Rp.2.000,-/hari dan jika buku hilang maka denda Rp.100.000,-/buku
*/

//Main Menu
void menuaw(){
    system("color 3f");
    rewind(fn);system("cls");
    dingdong();
    printf("\n\n");
    printf("\t\t\t\t\t\t\tInput Menu: ");scanf("%d",&n);
    switch(n){
        case 1:system("cls");crte();break;
        case 2:system("cls");login();break;
        default:system("cls");menuaw();break;
    }
}
void menu(){

    system("color 3f");
    rewind(fn);system("cls");
    printf("\n\t\t\t\t\t+===============================================+\n\n");
    printf("\n\t\t\t\t\t+-----------------------------------------------+\n");
    printf("\t\t\t\t\t|\t   WELCOME TO ANTILA'S LIBRARY \t\t|");
    printf("\n\t\t\t\t\t+-----------------------------------------------+\n\n");
    printf("\n\t\t\t\t\t+===============================================+\n\n");
    printf("\t\t\t\t\t\t\t ----------\\----------\n");
    printf("\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t |~~~~~~~~~|~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t ----------/----------\n");

    printf("\n\t\t\t\t\t=================================================\n\n");
    printf("\t\t\t\t\t**********\t     1).New User\t*********\n");
    printf("\t\t\t\t\t**********\t     2).Login   \t*********\n");
    printf("\n\t\t\t\t\t=================================================\n");
    printf("\n\n");

    printf("\t\t\t\t\t\t\tInput Menu: ");
    scanf("%d",&n);

    switch(n){
        case 1:system("cls");crte();break;
        case 2:system("cls");login();break;
        default:system("cls");menu();break;
    }
}
//Create Username
void crte(){
    ding1();
    system("cls");system("color 3f");
    printf("\t|\t\tRegister Menu\t\t|\n");
    printf("\t-----------------------------------------");
    fn=fopen("file.txt","a+");
    printf("\n\tCreate Username: ");scanf("%13s",&nama);
    printf("\tCreate Password: ");readPass(password);
    printf("\n\nCreate Succses");Sleep(500);system("cls");
    ding();
    fprintf(fn,"%13s%13s \n",nama,password);system("cls");
    menu();
    strcpy(nama,NULL);
    strcpy(password,NULL);
    fclose(fn);
}

void readPass(char *temp) //Menyamarkan Password
{
    int key=0,index=0;
    do{
        key=getch();
        switch (key){
            case 0:
            case 224:
                getch();
                break;
            case '\b':
                if(index>0){
                    index=index-1;
                    temp[index] = 0;
                    printf("\b \b");
                }
                break;
            default:
                if(key>31&&key<127){
                    temp[index]=key;
                    index = index + 1;
                    printf("*");
                }
        }
    } while(key!=13);
    temp[index]='\0';
}
//Login
void login(){

    printf("\t\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t|\t\tMENU LOGIN    \t\t|\n");
    printf("\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t-----------------------------------------\n");

    if(logincntr>0){
        system("cls");
        printf("\t\t\t\t\t   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\t\t\t\t\t    USERNAME OR PASSWORD WAS INCORRECT \n");
        printf("\t\t\t\t\t   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    fn=fopen("file.txt","r+");

    bool loginz;
    loginz=false;
    printf("\n\n\t\t\t\t\t PLEASE INSERT YOUR USERNAMSE AND PASSWORD\n\n");
    printf("\n\t\t\t\t\t\t   Username: ");scanf("%13s",&usr);
    printf("\t\t\t\t\t\t   Password: ");readPass(pws);

    /*disini akan ditambahkan jika if atau login menggunakan admin dan pass admin maka sistem akan memberlakukan menu khusus untuk admin
    yang nantinya admin bisa mengghapus penguna yang bermasalah dan bisa mengirim beberapa peringatan.*/
    while(!feof(fn)){
        fscanf(fn,"%13s%13s",nama,password);        //Untuk Mengambil data dari file
        if((strcmp(nama,usr)==0)&&(strcmp(pws,password)==0)){
            loginz=true;printf("\n\n\t\t\t\t\t     Login Successful Welcome %s !\n\n",usr);break;
        }
    }
    if(!loginz){
        logincntr=1;
        login();
    }
    if(loginz){
        system("cls");
        ding1();system("cls");

        if((strcmp("admin",usr)==0)&&(strcmp(pws,"admin")==0)){
            system("color 3f");
            printf("\tPilihan Admin : \n");
            printf("\t1. Edit User\n");
            //mau ditambahin menu edit denda atau keterlambatan ga ? jadinya yang masukkin admin
            printf("\t2. Edit Rak Perpus\n");

            printf("\tPilihan : ");scanf("%d",&piladm);
            switch(piladm){
                case 1:rmv();break;
                case 2:menperadm();break;
            }
        }
        else menuperpus();
        /*Nantinya ini diisi oleh menu dari Perpustakaan bagi yang ingin meminjam dan mengembalikan buku*/
    }
    exit(0);
}

//Remove
void rmv(){

    char phandler[100][100];
    char uhandler[100][100];
    fn=fopen("file.txt","r+");
    int cntr=0;
    while (!feof(fn)){
        fscanf(fn,"%13s%13s",nama,password);
        strcpy(uhandler[cntr],nama);
        strcpy(phandler[cntr],password);
        cntr++;
    }
    fclose(fn);printf("\n");
    for(i=0;i<cntr-1;i++)
        printf("\tUsername: %s \n",uhandler[i]);
    printf("\n\tInput Username to remove: ");scanf("%s",&nama);
    system("cls");
    printf("\tYou must input password for remove username: ");readPass(password);
    if(strcmp(password,"admin")==0){
        for(i=0;i<cntr-1;i++){
            if(strcmp(uhandler[i],nama)==0){
                int cntr2=i;
                save(cntr-1,cntr2,uhandler,phandler);break;
            }
        }
    }
    fclose(fn);

}
//Save file
void save(int a,int b,char u[100][100],char p[100][100]){
    fopen("file.txt","w+");
    for(i=0;i<a;i++){
        if(i==b){
            fprintf(fn,"");
            continue;
        }
        else
            fprintf(fn,"%13s%13s\n",u[i],p[i]);
    }
    fclose(fn);
    menu();
}

void daftarbukuadm(){

    i=0;
    char pinjam;

    system("cls");
    rk=fopen("databasebook.txt","r+");
    printf("\n\t\t\t\t\t\t\t\t\t LIST OF THE BOOK\n\n");
    printf("__________________________________________________________________________________________________________________________________________\n");
    printf("NO|              JUDUL                |           PENULIS             |              PENERBIT               |           KATEGORI         |\n",i);
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    while(!feof(rk)){
        i++;
        fscanf(rk,"%[^#]#%[^#]#%[^#]#%[^#]#%d#\n",&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].jumlah);
        printf("%-2d|      %-25s    |         %-15s       |         %-20s        |         %-12s       |\n",i,book[i].judul,book[i].penulis,book[i].penerbit,book[i].kategori);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(rk);

    printf("Press the enter to back of menu <-");
    getch();system("cls");
    menperadm();

}


void removebook(){

    char phandler[100][100];
    char uhandler[100][100];
    char qhandler[100][100];
    char khandler[100][100];
    int jhandler[100],gnt;
    rk=fopen("databasebook.txt","r+");
    int cntr=0;
    while (!feof(rk)){
        fscanf(rk,"%[^#]#%[^#]#%[^#]#%[^#]#%d#\n",&book[i].judul,&book[i].penulis,&book[i].penerbit,&book[i].kategori,&book[i].jumlah);
        strcpy(uhandler[cntr],book[i].judul);
        strcpy(phandler[cntr],book[i].penulis);
        strcpy(qhandler[cntr],book[i].penerbit);
        strcpy(khandler[cntr],book[i].kategori);
        jhandler[cntr]=book[i].jumlah;
        cntr++;
    }
    fclose(rk);printf("\n");
    for(i=0;i<cntr;i++){
        printf("\t%d. Judul: %s \n",i+1,uhandler[i]);
    }
    printf("\n\tMasukkan No. Buku yg ingin di remove: ");scanf("%d",&gnt);
    gnt=gnt-1;
    system("cls");


    rk=fopen("databasebook.txt","w+");
    for(i=0;i<cntr;i++){
        if(gnt!=i){
            fprintf(rk,"%s#%s#%s#%s#%d#\n",uhandler[i],phandler[i],qhandler[i],khandler[i],jhandler[i]);
        }
    }
    fclose(rk);
    printf("\n\nThe Data Was Successfully Deleted\n");
    system("pause");
    system("cls");
    menperadm();

}

//MENU UNTUK ADMIN!

void menperadm(){

    system("cls");system("color 3f");

    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t|\t\tMENU ADMIN \t\t|\n");
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("1. Lihat Buku\n");
    printf("2. Tambah Buku\n");
    printf("3. Hapus Buku\n");
    printf("5. Logout\n");

    printf("Kategori Yang Diinginkan : ");scanf("%d",&rak);fflush(stdin);

    switch(rak){
        case 1:daftarbukuadm();break;
        case 2:tambahbuku();break;
        case 3:removebook();break;
        case 5:system("cls");ding();menu();break;
    }
}

void tambahbuku(){

    i=0;
    char pilbuku;
    system("cls");
    rk=fopen("databasebook.txt","a+");

    do{
        i++;
        printf("Masukkan Judul Buku : ");
        gets(book[i].judul);
        printf("Penulis : ");
        gets(book[i].penulis);
        printf("Penerbit : ");
        gets(book[i].penerbit);
        printf("Kategori : ");
        gets(book[i].kategori);
        fflush(stdin);
        printf("Jumlah : ");
        scanf("%d",&book[i].jumlah);
        fflush(stdin);
        fprintf(rk,"%s#%s#%s#%s#%d#\n",book[i].judul,book[i].penulis,book[i].penerbit,book[i].kategori,book[i].jumlah);
        printf("Apakah Anda Ingin Menambahkan Buku Lagi (y/t) : ");
        scanf("%c",&pilbuku);
        fflush(stdin);

    }

    while(pilbuku=='y');

    fclose(rk);
    menperadm();
}

//PROGRAM UTAMA!

int main()
{
    system("color 02");
    system("pause");
    //ding();Sleep(2500);
    fn=fopen("file.txt","a+");
    if(fn==NULL)
        printf("file not to be open");
    else{
        fclose(fn);
        menuaw();
    }
    return 0;
}

