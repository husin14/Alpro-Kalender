#include "header.h";

int main()
{

    SYSTEMTIME str_t; //str_t di gunakan sebagai variable untuk menyimpan tanggal sekarang
	GetLocalTime(&str_t); //memberikan data tanggal sekarang ke variable str_t
	struct date t = {str_t.wDay,str_t.wMonth,str_t.wYear}; //memberikan data tangal di str_t ke struct tanggal

    displaycalendar(t); //mencetak kalender


    kegiatan *keg;
    keg=malloc(sizeof(kegiatan)*1000); //memesan memori sebesar struct kegiatan untuk variabel kegiatan
    int pilihan, n=0;
    int pilihdel;
    char wrong;
utama:
        puts("");
    printf(" ------------------- \n");
    printf("| KALENDER KEGIATAN |\n");
    printf(" ------------------- \n\n");
    printf(" Pilihan Menu!!! \n");
    printf(" --------------- \n");
    printf(" 1. Tambah Kegiatan \n");
    printf(" 2. Lihat Data Kegiatan \n");
    printf(" 3. Cari Kegiatan \n");
    printf(" 4. Urutan Kegiatan \n");
    printf(" 5. Hapus Kegiatan \n");
    printf(" --------------------------------------- \n");
    printf(" Pilih salah satu menu : "); scanf("%d", &pilihan);
    system("cls");
    if(pilihan>5){
        printf(" ------------------- \n");
        printf("| PILIHAN SALAH !!! |\n");
        printf(" ------------------- \n\n");
        printf(" Pilih antara angka 1-5...!\n");
        printf(" Ketik Y untuk kembali : "); scanf("%s", &wrong);
        if(wrong=='Y'||wrong=='y'){
            system("cls");
            goto utama;
        }
    }
    else{
        switch(pilihan){
            case 1:
                back:
                printf(" ----------------- \n");
                printf("| TAMBAH KEGIATAN |\n");
                printf(" ----------------- \n\n");
                awalan:
                tambah(keg, &n);
                if (keg->tgl<1)
                {
                    puts("");
                    printf("maaf anda tidak bisa melanjutkan program karena tanggal kurang dari 1");
                    puts("");
                    goto awalan;
                }
                else if (keg->bln<1)
                {
                     puts("");
                    printf("maaf anda tidak bisa melanjutkan program karena bulan kurang dari 1");
                    puts("");
                    goto awalan;
                }
                else if (keg->thn<1)
                {
                     puts("");
                    printf("maaf anda tidak bisa melanjutkan program karena bulan kurang dari 1");
                    puts("");
                    goto awalan;
                }
                n++;
                printf(" \nKetik Y untuk tambah lagi dan N untuk kembali : "); scanf("%s", &wrong);
                if(wrong=='N'||wrong=='n'){
                    system("cls");
                    goto utama;
                }
                else{
                system("cls");
                goto back;
                }
                break;
            case 2:
                printf(" --------------------- \n");
                printf("| LIHAT DATA KEGIATAN |\n");
                printf(" --------------------- \n\n");

                lihat(keg,n);
                printf(" \nKetik Y untuk kembali : "); scanf("%s", &wrong);
                if(wrong=='Y'||wrong=='y'){
                    system("cls");
                    goto utama;
                }
                break;
            case 3:
                backcar:
                printf(" --------------- \n");
                printf("| CARI KEGIATAN |\n");
                printf(" --------------- \n\n");

                int cari, unfind;
                printf(" 1. Cari berdasarkan tanggal \n");
                printf(" 2. Cari berdasarkan bulan \n");
                printf(" 3. Cari berdasarkan tahun \n");
                printf(" 4. Cari berdasarkan nama kegiatan \n");
                printf(" 5. Cari berdasarkan tempat kegiatan \n");
                printf(" 6. Cari berdasarkan SPECIFIC DATE \n");
                printf("------------------------------\n");
                printf(" Pilih salah satu : "); scanf("%d", &cari);
                if(cari>6){
                    printf("Maaf, Data yang anda masukkan tidak tersedia...!\n");
                    printf(" Ketik 1 untuk kembali : "); scanf("%d", &unfind);
                    if(unfind==1){
                        system("cls");
                        goto backcar;
                    }
                }
                else{
                    system("cls");
                    int golek;
                    char golek1[100];
                    switch(cari){
                        case 1:
                            printf(" -------------------------- \n");
                            printf("| CARI BERDASARKAN TANGGAL |\n");
                            printf(" -------------------------- \n\n");

                            printf(" Masukkan Tanggal yang dicari : "); scanf("%d", &golek);
                            searchtgl(keg, n, golek);
                            break;
                        case 2:
                            printf(" -------------------------- \n");
                            printf("| CARI BERDASARKAN BULAN |\n");
                            printf(" -------------------------- \n\n");

                            printf(" Masukkan Bulan yang dicari : "); scanf("%d", &golek);
                            searchbln(keg, n, golek);
                            break;
                        case 3:
                            printf(" -------------------------- \n");
                            printf("| CARI BERDASARKAN TAHUN |\n");
                            printf(" -------------------------- \n\n");

                            printf(" Masukkan Tahun yang dicari : "); scanf("%d", &golek);
                            searchthn(keg, n, golek);
                            break;
                        case 4:
                            printf(" -------------------------- \n");
                            printf("| CARI BERDASARKAN NAMA KEGIATAN |\n");
                            printf(" -------------------------- \n\n");

                            printf(" Masukkan Nama Kegiatan yang dicari : "); scanf(" %s",&golek1);
                            searchnamakeg(keg, n, golek1);
                            break;
                        case 5:
                            printf(" -------------------------- \n");
                            printf("| CARI BERDASARKAN TEMPAT KEGIATAN |\n");
                            printf(" -------------------------- \n\n");

                            printf(" Masukkan Nama Kegiatan yang dicari : "); scanf(" %s",&golek1);
                            searchtempat(keg,n,golek1);
                            break;

                        case 6:
                            printf(" -------------------------- \n");
                            printf("| CARI BERDASARKAN SPECIFIX DATE |\n");
                            printf(" -------------------------- \n\n");

                            printf(" Masukkan specific yang dicari : "); scanf("%d", &golek); scanf("%d", &golek); scanf("%d", &golek);
                            searchbln(keg, n, golek);
                            break;

                    }
                }

                printf("\n Ketik Y untuk kembali : "); scanf("%s", &wrong);
                if(wrong=='Y'||wrong=='y')
                {
                    system("cls");
                    goto utama;
                }
                break;
            case 4:
             muleh:
                printf(" --------------- \n");
                printf("| URUTKAN KEGIATAN |\n");
                printf(" --------------- \n\n");
             int cari1, raktemu;
             printf(" 1. Cari berdasarkan tahun \n");
             printf(" 2. Cari berdasarkan bulan \n");
             printf(" 3. Cari berdasarkan tanggal \n");
             printf("pilih salah satu = "); scanf("%d",&cari1);
             if(cari1>3)
                {
                    printf("Maaf, Data yang anda masukkan tidak tersedia...!\n");
                    printf(" Ketik 1 untuk kembali : "); scanf("%d", &raktemu);
                    if(raktemu==1)
                    {
                        system("cls");
                        goto muleh;
                    }
                }
             else
                {
                    system("cls");
                    switch(cari1)
                    {
                        case 1:

                        printf(" ------------------------------------- \n");
                        printf("| URUTAN KEGIATAN BERDASARKAN TAHUN |\n");
                        printf(" ------------------------------------- \n\n");

                        printf("=====SECARA ASCENDING====");
                        puts("");
                        uruttahun(keg,n);
                        puts("");
                        printf("=====SECARA DESCENDING====");
                        puts("");
                        uruttahunasc(keg,n);


                        break;

                        case 2:

                        printf(" ------------------------------------- \n");
                        printf("| URUTAN KEGIATAN BERDASARKAN BULAN |\n");
                        printf(" ------------------------------------- \n\n");

                        printf("=====SECARA ASCENDING====");
                        puts("");
                        urutbulan(keg,n);
                        puts("");
                        printf("=====SECARA DESCENDING====");
                        puts("");
                        urutbulanasc(keg,n);


                        break;

                        case 3:

                        printf(" ------------------------------------- \n");
                        printf("| URUTAN KEGIATAN BERDASARKAN TANGGAL |\n");
                        printf(" ------------------------------------- \n\n");

                        printf("=====SECARA ASCENDING====");
                        puts("");
                        uruttgl(keg,n);
                        puts("");
                        printf("=====SECARA DESCENDING====");
                        puts("");
                        uruttglasc(keg,n);
                        break;
                    }

                printf("\n Ketik Y untuk kembali : "); scanf("%s", &wrong);
                if(wrong=='Y'||wrong=='y')
                {
                    system("cls");
                    goto utama;
                }
                }
                break;
            case 5:
                printf(" ---------------- \n");
                printf("| HAPUS KEGIATAN |\n");
                printf(" ---------------- \n\n");

                lihat(keg, n);
                printf("\n Pilih kegiatan yang ingin dihapus : "); scanf("%d", &pilihdel);
                hapus(keg, &n, pilihdel-1);

                printf("\n Ketik Y untuk kembali : "); scanf("%s", &wrong);
                if(wrong=='Y'||wrong=='y'){
                    system("cls");
                    goto utama;
                }
                break;


        }
    }
    return 0;

}
