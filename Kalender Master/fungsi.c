#include "header.h"

void displaycalendar(struct date t) //Mencetak kalender sesuai data yang diberikan
{
    int daycode;
	daycode = determinedaycode(t.year); //mencari kode bulan
    determineleapyear(t.year); //menentukan tahun kabisat
    calendar(t, daycode); //mencetak kalender
}

int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; //Tanggal max di setiap bulan
char *months[]=
{
	" ",
	"Januari",
	"Februari",
	"Maret",
	"April",
	"Mei",
	"Juni",
	"Juli",
	"Agustus",
	"September",
	"Oktober",
	"November",
	"Desember"
}; //Daftar nama bulan


int dayofweek(struct date t) //Mencari nomor hari dalam satu minggu dari data "tanggal/bulan/tahun" yang di berikan
{
    static int d[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    t.year -= t.month < 3;
    return (t.year + t.year / 4 - t.year / 100 + t.year / 400 + d[t.month - 1] + t.day) % 7;
}


void nameofday(struct date t) //Mengganti nomor hari yang di berikan fungsi "dayofweek" dengan nama hari
{
    int day = dayofweek(t);
    switch(day) { //Mencetak nama hari sesuai data angka yang didapat
    case 1:
        printf("Senin");
        break;
    case 2:
        printf("Selasa");
        break;
    case 3:
        printf("Rabu");
        break;
    case 4:
        printf("Kamis");
        break;
    case 5:
        printf("Jumat");
        break;
    case 6:
        printf("Sabtu");
        break;
    case 7:
        printf("Minggu");
        break;
    }
}


void calendar(struct date t, int daycode)  //Mencetak kalender
{
	int month, day;
	for ( month = 1; month <= 12; month++ ) //Menjalan kan perhitungan bulan dari bulan Januari sampai Desember
    {
	    if(month == t.month)
        { //Hanya mencetak kalender berdasarkan data bulan
	        printf("\n  ");
            nameofday(t); //Mencetak nama hari
            printf(" , %d / %s / %d", t.day, months[month], t.year); //Mencetak "tanggal/bulan/tahun"
            printf("\n\n Min  Sen  Sel  Rab  Kam  Jum  Sab\n" );

            // Correct the position for the first date
                for ( day = 1; day <= 1 + daycode * 5; day++ ) //Mencetak spasi sesuai kode bulan untuk menentukan posisi tanggal awal di mulai nya bulan
            {
                printf(" ");
            }

            // Print all the dates for one month
            for ( day = 1; day <= days_in_month[month]; day++ ) //Mencetak semua tanggal
            {
                if(day == t.day) //Menambahkan sysbol asterisk "*" sesuai data tanggal yang di berikan
                {
                    printf("*%2d",day);
                }
                else
                {
                    printf("%3d", day );
                }
                // Is day before Sat? Else start next line Sun.
                if ( ( day + daycode ) % 7 > 0 ) { //Apabila sudah sampai sabtu, maka akan menggeser kebawah posisi tanggal setelah nya
                    printf("  " );
                } else {
                    printf("\n " );
                }
            }
	    }
        // Set position for next month
        daycode = ( daycode + days_in_month[month] ) % 7; //Menentukan posisi di mulai nya tanggal di bulan setelah nya
	}
}

int determinedaycode(int year) { //Mencari kode bulan untuk menentukan mulai nya tanggal di bulan baru
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}

int determineleapyear(int year) { //Menentukan apakah tahun kabisat atau bukan
	if((year% 4 == 0 && year%100 != 0) || year%400 == 0) {
		days_in_month[2] = 29;
		return 1;
	} else {
		days_in_month[2] = 28;
		return 0;
	}
}

//INPUTAN KEGIATAN


void tambah(kegiatan keg[], int *n ){
    printf(" Inputkan Tanggal \n");
    printf(" -----------------\n");
    printf("\t Tanggal : "); scanf("%d", &keg[*n].tgl);
    printf("\t Bulan   : "); scanf("%d", &keg[*n].bln);
    printf("\t Tahun   : "); scanf("%d", &keg[*n].thn);


    printf(" Inputkan Waktu \n");
    printf(" ---------------\n");
    printf("\t Jam Exmp (07)      : "); fflush(stdin); gets(keg[*n].jam);
    printf("\t Menit Exmp (00)    : "); fflush(stdin); gets(keg[*n].menit);
    printf("\t Nama Kegiatan      : "); fflush(stdin); gets(keg[*n].nama_keg);
    printf("\t Tempat Pelaksanaan : "); fflush(stdin); gets(keg[*n].tempat);
}

void lihat(kegiatan keg[], int n){
    int i;
    for(i=0;i<n;i++){

            printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");

    }
}
void searchtgl(kegiatan keg[], int n, int golek){
    int i;
    for(i=0;i<n;i++){

            if(keg[i].tgl==golek){
                printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
            }
        }

}

void specifix(kegiatan keg[], int n, int golek){
    int i;
    for(i=0;i<n;i++){

            if(keg[i].tgl&&keg[i].bln&&keg[i].thn==golek){
                printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
            }
        }

}
void searchbln(kegiatan keg[], int n, int golek){
    int i;
    for(i=0;i<n;i++){

            if(keg[i].bln==golek){
               printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
            }

    }
}
void searchthn(kegiatan keg[], int n, int golek){
    int i;
    for(i=0;i<n;i++){

            if(keg[i].thn==golek){
                printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
            }

    }
}

void searchnamakeg(kegiatan keg[], int n, char gol[]){    ///SING IKI
    int i;
    for(i=0;i<n;i++){

            if(strcmp(keg[i].nama_keg,gol)==0){
                printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
            }
    }

}

void searchtempat(kegiatan keg[], int n, char gol[]){
    int i;
    for(i=0;i<n;i++){

            if(strcmp(keg[i].tempat,gol)==0){
               printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
            }
    }

}

void uruttahun (kegiatan keg[], int n)
{
        int i,j,temp;
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            if(keg[j].thn<keg[i].thn)
            {
                temp=keg[j].thn;
                keg[j].thn=keg[i].thn;
                keg[i].thn=temp;
            }
        }
    }

    for(i=0;i<n;i++)
            {
                    printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
                    printf("----------------------------------\n");
                    printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
                    printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
                    printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
                    printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
                    printf("----------------------------------\n\n");
            }
}




void uruttahunasc (kegiatan keg[], int n)
{
        int i,j,temp;
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            if(keg[j].thn>keg[i].thn)
            {
                temp=keg[j].thn;
                keg[j].thn=keg[i].thn;
                keg[i].thn=temp;
            }
        }
    }

    for(i=0;i<n;i++)
            {
                    printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
                    printf("----------------------------------\n");
                    printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
                    printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
                    printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
                    printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
                    printf("----------------------------------\n\n");
            }
}



void urutbulan (kegiatan keg[], int n)
{
     int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
                if(keg[j].bln<keg[i].bln)
            {
                temp=keg[j].bln;
                keg[j].bln=keg[i].bln;
                keg[i].bln=temp;
            }
        }

    }
    for(i=0;i<n;i++){

            printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
        }
}



void urutbulanasc (kegiatan keg[], int n)
{
     int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
                if(keg[j].bln>keg[i].bln)
            {
                temp=keg[j].bln;
                keg[j].bln=keg[i].bln;
                keg[i].bln=temp;
            }
        }

    }
    for(i=0;i<n;i++){

            printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
        }
}


void uruttgl(kegiatan keg[], int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++)
        {
            if(keg[j].tgl<keg[i].tgl){
                temp=keg[j].tgl;
                keg[j].tgl=keg[i].tgl;
                keg[i].tgl=temp;
            }
        }
    }
    for(i=0;i<n;i++){

           printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
        }

}




void uruttglasc(kegiatan keg[], int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++)
        {
            if(keg[j].tgl>keg[i].tgl){
                temp=keg[j].tgl;
                keg[j].tgl=keg[i].tgl;
                keg[i].tgl=temp;
            }
        }
    }
    for(i=0;i<n;i++){

           printf(" Daftar Kegiatan Ke #%d\n\n", i+1);
            printf("----------------------------------\n");
            printf("\t Tanggal              : %d-%d-%d\n", keg[i].tgl, keg[i].bln, keg[i].thn);
            printf("\t Waktu                : %s.%s\n", keg[i].jam, keg[i].menit);
            printf("\t Nama Kegiatan        : %s\n", keg[i].nama_keg);
            printf("\t Tempat Pelaksanaan   : %s\n", keg[i].tempat);
            printf("----------------------------------\n\n");
        }

}



void hapus(kegiatan keg[], int *n, int pilihdel)
{
    int i;
    kegiatan temp = keg[pilihdel];
    for(i = pilihdel; i < *n; i++) {
        keg[i] = keg[i + 1];
    }
    *n = *n - 1;
    printf("\n Data dengan nama Kegiatan : %s Telah terhapus..!\n", temp.nama_keg);
}

