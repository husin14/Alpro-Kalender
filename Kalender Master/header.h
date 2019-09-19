#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <dos.h>
#include <string.h>

typedef struct{
    int tgl;
    int bln;
    int thn;
    char jam [50];
    char menit [50];
    char nama_keg [50];
    char tempat [50];
}kegiatan;

struct date {
    int day;
    int month;
    int year;
};
//calender
int determinedaycode(int year);
int determineleapyear(int year);
int dayofweek(struct date t);
void nameofday(struct date t);
void calendar(struct date t, int daycode);
void displaycalendar(struct date t);

#endif // HEADER_H_INCLUDED
