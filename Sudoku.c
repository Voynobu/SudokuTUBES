#include "stdio.h"
#include "stdlib.h"
#include "Sudoku.h"

int DisplayMenu(){
	int input;
	
	menu:
	system("cls");
	printf("\x1b[30m//////////////\n");
	printf("////\x1b[0mSUDOKU\x1b[30m////\n");
	printf("//////////////\x1b[0m\n");
	
	printf("\n///MENU///\n");
	printf("(1) New Game \n");
	printf("(2) Load Game\n");
	printf("(3) LEADERBOARD \n");
	printf("(4) KELUAR\n");
	
	printf("\nPilih opsi 1,2, 3 dan 4 untuk melanjutkan : ");
	scanf("%d", &input);
	
	return input;
}

int NewGame(){
	int input;
	
	system("cls");
	printf("\n\n\\\\\\PILIH KESULITAN\\\\\\");
	printf("\n\n(1) MUDAH");
	printf("\n(2) NORMAL");
	printf("\n(3) SULIT\n");
	printf("(0) KEMBALI\n");
	
	printf("\nPilih opsi untuk melanjutkan : ");
	scanf("%d", &input);
	
	return input;
}

int LoadGame(){
	int input;
	
	system("cls");
	printf("\n\n\\\\\\PILIH KESULITAN\\\\\\");
	printf("\n\n(1) Save Game 1");
	printf("\n(2) Save Game 2");
	printf("\n(3) Save Game 3");
	printf("\n(0) Kembali\n");
	
	printf("\nPilih opsi untuk melanjutkan : ");
	scanf("%d", &input);
	
	return input;
}

int Leaderboard(){
	int input;
	
	FILE *frec; //nama file atau pointer ke file, defined in <stdio.h>
	char jwb;
	
	struct skor { //data terstruktur/record bernama mhs
	char inisial[3];	
	int Skor;
	} skr;
	
	system("cls");
	printf("HIGH SCORE\n");
	if((frec=fopen("skr1.dat","rb"))==NULL) //buka file, mode update
	printf("File tidak dapat dibuka !");
	else { //baca data
		while (fread(&skr, sizeof(skr), 1, frec)) { //cek apakah end of file ?
			printf("\nINISIAL: %s\nSKOR: %d\n", skr.inisial, skr.Skor);
		}
		fclose(frec); //tutup file
	}
	printf("\n(0) KEMBALI\n");

	printf("\nPilih opsi untuk melanjutkan: ");
	scanf("%d", &input);
	
	return input;
}

int Exit(){
	system("cls");
	printf("\nTERIMAKASIH TELAH BERMAIN\n");
	return 0;
}

void ArrSudoku(){
	
	int Sudoku[2];
	
	Sudoku[0] = 1;
	Sudoku[1] = 2;
	Sudoku[2] = 3;
}

int SeleksiSudoku(){
	
}

int InputTidakValid(){
	system("cls");
	printf("Input tidak valid! Silahkan coba lagi. Tekan Apa saja untuk melanjutkan.\n");
	getchar();
	getchar();
}



