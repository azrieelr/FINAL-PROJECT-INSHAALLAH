#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // library, karena kita mau memanggil fungsi baru makanya kita hrs nulis ini //
#include <conio.h>

void gotoxy (int x, int y) // di dalam program ada go to x dan y //
{
    COORD coord={0,0}; // untuk menentukan letak tanggal //
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    int TH,i,BL,hari;
    int nBL[13];
    int j=3;
    long int JumlahHari; // pake long karena banyak datanya, sedangkan ini datanya banyak // file jadi besar //
    printf("Masukkan Tahun : ");
    scanf("%d",&TH);
    printf("Masukkan Bulan : ");
    scanf("%d",&BL);
    nBL[1]=31;
    nBL[2]=28;
    nBL[3]=31;
    nBL[4]=30;
    nBL[5]=31;
    nBL[6]=30;
    nBL[7]=31;
    nBL[8]=31;
    nBL[9]=30;
    nBL[10]=31;
    nBL[11]=30;
    nBL[12]=31;

    printf("Minggu  Senin  Selasa   Rabu   Kamis  Jumat  Sabtu\n ");
    JumlahHari=(TH-1)*365+(TH-1)/4-(TH-1)/100+(TH-1)/400; // syarat kabisat //

    if(TH% 4 == 0 && TH%100 != 0 || TH%400 == 0)
	{
		nBL[2] = 29;
	}
	else
	{
		nBL[2] = 28;
	}

    for (i=1;i<BL;i++)
    {
        JumlahHari=JumlahHari+nBL[i]; // menghitung jumlah hari sebelum bulan yang mau dicari //
    }

    for(i=1;i<=nBL[BL];i++)
    {
        hari = JumlahHari%7;
        JumlahHari++;

        gotoxy(hari*7,j);
        printf("%d",i);

        if (hari==6)
        {
            j++;
        }
    }

    return 0;
}
