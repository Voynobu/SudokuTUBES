#include "stdio.h"
#include "stdlib.h"
#include "Sudoku.h"
#include "time.h"
#include "windows.h"
#include "stdbool.h"

#define MAX_BONUS_TIME 60 // Set Max score

int DisplayMenu(){
	int input;
	int consoleWidth = 116;
	
	// Display menu
	system("cls");
	
	printCentered("O============================O", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|           SUDOKU           |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("O============================O", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|  1. New Game               |", consoleWidth);
	printCentered("|  2. Highscore              |", consoleWidth);
	printCentered("|  3. How To Play            |", consoleWidth);
	printCentered("|  4. Exit                   |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("|                            |", consoleWidth);
	printCentered("O============================O", consoleWidth);
	
	printf("\n\t\t\tPilih opsi 1,2 3 dan 4 untuk melanjutkan : ");
	scanf("%d", &input);
	
	return input;
}

int HowToPlay(){
	int consoleWidth = 116;
	int input;
	
	system("cls");
	printCentered("O===========================================================================================================O", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("|                                              HOW TO PLAY                                                  |", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("O===========================================================================================================O", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("|         1. Input sesuai opsi yang tersedia, Input angka 0 untuk kembali ke menu sebelumnya                |", consoleWidth);
	printCentered("|         2. Input angka 0 untuk kembali ke menu sebelumnya                                                 |", consoleWidth);
	printCentered("|         3. Input baris dan kolom untuk mengalokasikan baris dan kolom pada papan sudoku                   |", consoleWidth);
	printCentered("|         4. Input IsiAngka untuk mengisikan angka pada papan yang kosong                                   |", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("|                                                                                                           |", consoleWidth);
	printCentered("O===========================================================================================================O", consoleWidth);
	printCentered("(0) Kembali : ", consoleWidth);
	scanf("%d", &input);
	return input;
}

int NewGame(){
	int Difficulty;
	
	// Display tingak kesulitan
	system("cls");
	int consoleWidth = 116;
	
	printCentered("O====================================O", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|      Pilih Tingkat Kesulitan!      |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("O====================================O", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|  (1) MUDAH                         |", consoleWidth);
	printCentered("|  (2) NORMAL                        |", consoleWidth);
	printCentered("|  (3) SULIT                         |", consoleWidth);
	printCentered("|  (0) KEMBALI                       |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("|                                    |", consoleWidth);
	printCentered("O====================================O", consoleWidth);
	
	printf("\n\t\t\tPilih opsi untuk melanjutkan : ");
	scanf("%d", &Difficulty);
	
	return Difficulty;
}

int Leaderboard(){
	
	int consoleWidth = 116;
	
	typedef struct {
		char nama[3];
		int skor; 
	}Player;
	
	Player HS[100];
	
	system("cls");
	FILE* f1 = fopen("sigma.txt","r");
	int i,j,count,input;
	char Nama1[3],Nama2[3];
	count = 0;
	if(f1 == NULL){
		perror("File tidak dapat diakses\n");
		return 1;
	}
	rewind(f1);
	while(!feof(f1)){
		fscanf(f1, "%s %d", &HS[count].nama,&HS[count].skor);
		count++;
	}

	i = 0;

	system("cls");
	printCentered("O=======================================O", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|               HIGHSCORE               |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("O=======================================O", consoleWidth);
	if(f1 == NULL){ //buka file, mode update
	printCentered("O========================================O", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|       File tidak dapat dibuka !       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("O=======================================O", consoleWidth);
		return 1;
	} else { //baca data
		printCentered("O============================================O", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		while(i < 5){
			printf("				   |	  INISIAL: %s     SKOR: %d   	|\n", HS[i].nama, HS[i].skor);
			i++;
		}
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("O============================================O", consoleWidth);
		}
	printf("\n\t\t\t(0) Kembali\n");
	printf("\t\t\tPilih Opsi : ");
	scanf("%d", &input);
	if(input == 0){
		fclose(f1);
	}
	return input;
}

int Highscore(int Score){
	
	typedef struct {
		char nama[3];
		int skor; 
	}Player;
	
	Player HS[100];
	int consoleWidth = 116;
	int input;
 	
 	int i = 1;
	
 	HS[i].skor = Score; // Belum dikerjakan
	printf("\n\n Total Skor Anda = %d", Score);
	printf("\nInisial (3 karakter): ");
	scanf("%s", &HS[i].nama);
	fflush(stdin);
 	 
	FILE* fbuka = fopen("sigma.txt","a");
 	
	if(fbuka == NULL){
 		perror("File tidak dapat dibuka");
 		exit(1);
	}
	fprintf(fbuka, "%s %d", HS[i].nama,HS[i].skor);
	
	fclose(fbuka);
		FILE* f1 = fopen("sigma.txt","r");
	int j,count;
	count = 0;
	if(f1 == NULL){
		perror("File tidak dapat diakses\n");
		return 1;
	}
	rewind(f1);
	while(!feof(f1)){
		fscanf(f1, "%s %d", &HS[count].nama,&HS[count].skor);
		count++;
	}
	fclose(f1);
	
	i=0;
	while(i<=count){
		j=i+1;
		while(j<=count){
			if(HS[j].skor > HS[i].skor){
				Player temp = HS[i];
				HS[i] = HS[j];
				HS[j] = temp;
 			}
 			j++;
		}
		i++;
	}
	FILE*f2 = fopen("sigma.txt","w");
	for(i=0;i<=count;i++){
		fprintf(f2,"%s %d\n", HS[i].nama, HS[i].skor);
	}
	fclose(f2);
	
	count = 0;
	i = 0;
	FILE*f3 = fopen("sigma.txt", "r");
		while(!feof(f3)){
		fscanf(f1, "%s %d", &HS[count].nama,&HS[count].skor);
		count++;
	}
	
	system("cls");
	printCentered("O=======================================O", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|               HIGHSCORE               |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("O=======================================O", consoleWidth);
	if(f1 == NULL){ //buka file, mode update
	printCentered("O=======================================O", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|       File tidak dapat dibuka !       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("|                                       |", consoleWidth);
	printCentered("O=======================================O", consoleWidth);
		return 1;
	} else { //baca data
		printCentered("O============================================O", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		while(i < 5){
			printf("				   |	  INISIAL: %s     SKOR: %d   	|\n", HS[i].nama, HS[i].skor);
			i++;
		}
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("	   |\x1b[30m============================================\x1b[0m|", consoleWidth);
		printCentered("O============================================O", consoleWidth);
		}
		
	printf("\n\n\t\t\t Pilih (0) Untuk Kembali : ");
	scanf("%d", &input);
}

int Exit(){
	system("cls");
	printf("\n\n\n\n\n\n\t\t\tTERIMAKASIH TELAH BERMAIN\n\n\n\n\n");
	return 0;
}

void InputTidakValid(int input){
	system("cls");
		printf("\n\n\n\n\n\n\t\t\tInput tidak valid! Silahkan coba lagi. Tekan ENTER untuk melanjutkan.\n");
		getchar();
		getchar();
}

int Randomizer(int Index, int Difficulty, int SimpanSoal[10][9][9], int SimpanJawaban[10][9][9]){
	// Deklarasi dan Inisialisasi 10 Sudoku Easy dari Ke-3 Tingkat Kesulitan
	int Easy[10][9][9] = {

	{// Easy 1 :
		{8, 6, 7, 9, 1, 5, 3, 4, 2},
		{1, 9, 3, 4, 2, 7, 5, 6, 8},
		{5, 2, 4, 6, 8, 3, 1, 9, 7},
		{4, 3, 5, 8, 7, 1, 9, 2, 6},
		{2, 7, 6, 3, 4, 9, 8, 5, 1},
		{9, 8, 1, 2, 5, 6, 4, 7, 3},
		{7, 4, 9, 1, 3, 2, 6, 8, 5},
		{6, 1, 2, 5, 9, 8, 7, 3, 4},
		{3, 5, 8, 7, 6, 4, 2, 1, 9}
	},
	{// Easy 2
		{3, 2, 4, 9, 1, 5, 7, 8, 6},
		{5, 8, 6, 4, 2, 7, 3, 1, 9},
		{1, 7, 9, 6, 8, 3, 4, 5, 2},
		{6, 5, 8, 1, 3, 2, 9, 7, 4},
		{2, 9, 1, 7, 6, 4, 8, 3, 5},
		{7, 4, 3, 5, 9, 8, 2, 6, 1},
		{9, 6, 2, 8, 7, 1, 5, 4, 3},
		{8, 1, 5, 3, 4, 9, 6, 2, 7},
		{4, 3, 7, 2, 5, 6, 1, 9, 8}
	},
	{// Easy 3
		{6, 7, 2, 3, 5, 1, 9, 4, 8},
		{8, 3, 1, 4, 6, 9, 2, 7, 5},
		{5, 4, 9, 2, 8, 7, 6, 3, 1},
		{1, 5, 7, 9, 4, 6, 8, 2, 3},
		{3, 9, 6, 1, 2, 8, 7, 5, 4},
		{2, 8, 4, 5, 7, 3, 1, 6, 9},
		{4, 1, 5, 6, 9, 2, 3, 8, 7},
		{7, 6, 3, 8, 1, 5, 4, 9, 2},
		{9, 2, 8, 7, 3, 4, 5, 1, 6}
	},
	{// Easy 4
		{5, 8, 1, 2, 7, 6, 3, 9, 4},
		{2, 9, 6, 4, 3, 5, 8, 1, 7},
		{7, 4, 3, 9, 8, 1, 2, 6, 5},
		{8, 6, 5, 7, 4, 9, 1, 2, 3},
		{3, 7, 4, 6, 1, 2, 5, 8, 9},
		{1, 2, 9, 3, 5, 8, 7, 4, 6},
		{6, 5, 8, 1, 9, 3, 4, 7, 2},
		{4, 3, 2, 8, 6, 7, 9, 5, 1},
		{9, 1, 7, 5, 2, 4, 6, 3, 8}
	},
	{// Easy 5
		{3, 1, 5, 6, 7, 2, 4, 8, 9},
		{4, 9, 6, 8, 3, 1, 7, 5, 2},
		{2, 7, 8, 5, 4, 9, 3, 1, 6},
		{9, 6, 4, 1, 5, 7, 2, 3, 8},
		{1, 8, 2, 3, 9, 6, 5, 4, 7},
		{5, 3, 7, 2, 8, 4, 6, 9, 1},
		{6, 2, 9, 4, 1, 5, 8, 7, 3},
		{8, 5, 1, 7, 6, 3, 9, 2, 4},
		{7, 4, 3, 9, 2, 8, 1, 6, 5}
	},
	{// Easy 6
		{8, 7, 1, 3, 4, 5, 9, 2, 6},
		{3, 4, 9, 7, 2, 6, 8, 5, 1},
		{2, 5, 6, 8, 9, 1, 4, 7, 3},
		{1, 3, 2, 4, 7, 9, 6, 8, 5},
		{7, 6, 4, 5, 3, 8, 2, 1, 9},
		{5, 9, 8, 1, 6, 2, 7, 3, 4},
		{4, 2, 7, 9, 1, 3, 5, 6, 8},
		{9, 1, 5, 6, 8, 7, 3, 4, 2},
		{6, 8, 3, 2, 5, 4, 1, 9, 7}
	},
	{// Easy 7
		{3, 5, 1, 7, 6, 2, 8, 9, 4},
		{4, 6, 9, 3, 8, 1, 5, 2, 7},
		{2, 8, 7, 4, 5, 9, 1, 6, 3},
		{7, 3, 4, 2, 9, 8, 6, 5, 1},
		{8, 1, 5, 6, 7, 3, 2, 4, 1},
		{6, 9, 2, 1, 4, 5, 7, 3, 8},
		{1, 2, 8, 9, 3, 6, 4, 7, 5},
		{5, 7, 3, 8, 2, 4, 9, 1, 6},
		{9, 4, 6, 5, 1, 7, 3, 8, 2}
	},
	{// Easy 8
		{1, 6, 2, 5, 9, 8, 7, 4, 3},
		{4, 7, 9, 1, 3, 2, 6, 5, 8},
		{5, 3, 8, 7, 6, 4, 2, 9, 1},
		{9, 1, 3, 4, 2, 7, 5, 8, 6},
		{6, 8, 7, 9, 1, 5, 3, 2, 4},
		{2, 5, 4, 6, 8, 3, 1, 7, 9},
		{3, 4, 5, 8, 7, 1, 9, 6, 2},
		{7, 2, 6, 3, 4, 9, 8, 1, 5},
		{8, 9, 1, 2, 5, 6, 4, 3, 7}
	},
	{// Easy 9
		{9, 8, 4, 3, 1, 5, 6, 7, 2},
		{2, 5, 7, 4, 9, 6, 8, 3, 1},
		{6, 1, 3, 2, 7, 8, 5, 4, 9},
		{3, 7, 8, 6, 2, 9, 4, 1, 5},
		{4, 2, 9, 8, 5, 1, 7, 6, 3},
		{5, 6, 1, 7, 4, 3, 9, 2, 8},
		{8, 3, 2, 9, 6, 4, 1, 5, 7},
		{7, 4, 5, 1, 8, 2, 3, 9, 6},
		{1, 9, 6, 5, 3, 7, 2, 8, 4}
	},
	{// Easy 10
		{9, 1, 3, 5, 6, 8, 7, 2, 4},
		{2, 5, 4, 1, 9, 7, 3, 8, 6},
		{6, 8, 7, 3, 4, 2, 5, 1, 9},
		{3, 4, 5, 9, 2, 6, 1, 7, 8},
		{7, 2, 6, 8, 5, 1, 9, 4, 3},
		{8, 9, 1, 4, 7, 3, 6, 5, 2},
		{1, 6, 2, 7, 3, 4, 8, 9, 5},
		{4, 7, 9, 6, 8, 5, 2, 3, 1},
		{5, 3, 8, 2, 1, 9, 4, 6, 7}
	}
	};
		int SoalEasy[10][9][9] = {
			
	{// Soal Bonus Easy 1 :
		{0, 6, 7, 9, 1, 5, 3, 4, 2},
		{1, 9, 3, 4, 2, 7, 5, 6, 8},
		{5, 2, 4, 6, 8, 3, 1, 9, 7},
		{4, 3, 5, 8, 7, 1, 9, 2, 6},
		{0, 7, 6, 3, 4, 9, 8, 5, 1},
		{9, 8, 1, 2, 5, 6, 4, 7, 3},
		{7, 4, 9, 1, 3, 2, 6, 8, 5},
		{0, 1, 2, 5, 9, 8, 7, 3, 4},
		{3, 0, 8, 7, 6, 4, 2, 1, 9}
	},
	{// Soal Easy 2
		{3, 2, 0, 0, 1, 0, 7, 8, 0},
		{0, 0, 6, 4, 0, 7, 0, 1, 0},
		{0, 0, 9, 0, 0, 3, 0, 5, 2},
		{0, 0, 0, 0, 0, 0, 9, 0, 4},
		{0, 9, 0, 7, 6, 4, 8, 3, 0},
		{7, 0, 0, 5, 0, 8, 0, 6, 1},
		{9, 6, 2, 0, 7, 0, 5, 4, 0},
		{8, 0, 0, 3, 4, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 6, 0, 0, 8}
	},
	{// Soal Easy 3
		{6, 7, 2, 3, 5, 0, 9, 0, 0},
		{0, 3, 0, 0, 0, 0, 2, 0, 5},
		{0, 0, 9, 0, 0, 7, 6, 3, 1},
		{0, 0, 0, 9, 4, 6, 8, 2, 3},
		{0, 9, 6, 0, 2, 8, 0, 0, 0},
		{0, 0, 4, 0, 0, 3, 1, 0, 0},
		{0, 0, 0, 6, 9, 2, 0, 0, 7},
		{7, 0, 3, 0, 1, 5, 0, 0, 0},
		{0, 2, 0, 0, 0, 4, 0, 0, 6}
	},
	{// Soal Easy 4
		{0, 0, 0, 2, 7, 0, 0, 9, 0},
		{0, 9, 0, 4, 0, 5, 8, 1, 7},
		{0, 0, 3, 0, 0, 0, 0, 0, 5},
		{0, 0, 0, 7, 0, 9, 0, 2, 3},
		{0, 0, 4, 0, 1, 2, 0, 8, 0},
		{1, 0, 0, 3, 5, 0, 0, 4, 0},
		{6, 5, 0, 1, 0, 0, 4, 0, 0},
		{0, 3, 2, 0, 6, 7, 9, 0, 1},
		{9, 1, 0, 0, 0, 0, 0, 3, 8}
	},
	{// Easy 5
		{0, 1, 5, 0, 7, 0, 0, 0, 0},
		{4, 0, 0, 8, 0, 0, 7, 5, 0},
		{0, 0, 8, 0, 0, 9, 0, 1, 6},
		{9, 6, 4, 1, 0, 7, 0, 3, 0},
		{0, 8, 2, 3, 9, 0, 5, 0, 0},
		{5, 0, 0, 0, 0, 4, 0, 9, 0},
		{0, 2, 0, 4, 1, 0, 8, 0, 0},
		{0, 0, 1, 7, 0, 3, 9, 0, 4},
		{0, 0, 0, 9, 2, 0, 0, 6, 5}
	},
	{// Easy 6
		{0, 7, 0, 3, 0, 5, 0, 0, 6},
		{3, 4, 9, 7, 0, 0, 8, 0, 0},
		{2, 0, 6, 0, 9, 1, 0, 7, 3},
		{0, 3, 2, 0, 0, 9, 6, 0, 0},
		{0, 0, 0, 0, 3, 8, 0, 1, 9},
		{5, 0, 0, 1, 0, 2, 0, 0, 4},
		{0, 0, 7, 9, 1, 3, 0, 0, 8},
		{9, 0, 0, 0, 8, 0, 0, 4, 0},
		{0, 0, 3, 0, 0, 0, 1, 0, 7}
	},
	{// Soal Easy 7
		{0, 0, 0, 7, 6, 2, 0, 9, 0},
		{0, 0, 0, 3, 8, 0, 0, 2, 7},
		{2, 8, 0, 0, 5, 9, 1, 6, 3},
		{0, 0, 0, 0, 0, 0, 6, 0, 1},
		{0, 1, 5, 0, 0, 3, 2, 0, 0},
		{6, 0, 0, 0, 4, 5, 7, 0, 8},
		{0, 2, 0, 9, 0, 0, 4, 0, 5},
		{0, 7, 0, 8, 2, 4, 0, 0, 0},
		{9, 0, 0, 5, 0, 7, 0, 8, 0}
	},
	{// Soal Easy 8
		{1, 0, 0, 5, 0, 0, 0, 4, 3},
		{4, 7, 0, 1, 0, 2, 0, 5, 0},
		{0, 0, 0, 0, 0, 0, 2, 9, 1},
		{9, 0, 3, 4, 0, 0, 5, 8, 6},
		{6, 0, 0, 0, 0, 5, 0, 2, 0},
		{0, 5, 0, 0, 0, 0, 1, 7, 0},
		{3, 0, 5, 8, 0, 0, 9, 6, 2},
		{0, 2, 6, 3, 0, 9, 8, 0, 5},
		{8, 0, 0, 0, 5, 0, 0, 0, 0}
	},
	{// Soal Easy 9
		{9, 8, 0, 0, 1, 0, 0, 0, 2},
		{0, 0, 7, 0, 9, 6, 8, 0, 0},
		{6, 0, 3, 0, 7, 0, 0, 0, 9},
		{3, 7, 8, 6, 0, 9, 4, 1, 0},
		{4, 0, 9, 0, 0, 1, 0, 6, 3},
		{5, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 3, 0, 0, 0, 0, 0, 5, 7},
		{0, 0, 5, 1, 8, 0, 3, 9, 0},
		{0, 0, 0, 5, 3, 7, 2, 8, 4}
	},
	{// Soal Easy 10
		{0, 0, 3, 5, 6, 0, 7, 0, 0},
		{0, 0, 4, 0, 0, 7, 0, 0, 0},
		{6, 8, 7, 0, 0, 2, 5, 1, 0},
		{0, 0, 0, 9, 2, 0, 1, 7, 0},
		{7, 2, 0, 8, 0, 1, 9, 4, 3},
		{0, 9, 0, 0, 7, 3, 0, 0, 2},
		{1, 0, 2, 0, 3, 4, 8, 0, 0},
		{4, 0, 9, 6, 0, 0, 0, 0, 0},
		{0, 3, 8, 0, 0, 9, 0, 0, 0}
	}
	};
	
		int Medium[10][9][9] = {
	
	{// Medium 1 :
		{1, 9, 7, 6, 8, 3, 5, 4, 2},
		{3, 4, 2, 9, 1, 5, 8, 7, 6},
		{5, 6, 8, 4, 2, 7, 1, 3, 9},
		{6, 8, 5, 1, 3, 2, 7, 9, 4},
		{7, 3, 4, 5, 9, 8, 6, 2, 1},
		{2, 1, 9, 7, 6, 4, 3, 8, 5},
		{4, 7, 3, 2, 5, 6, 9, 1, 8},
		{8, 5, 1, 3, 4, 9, 2, 6, 7},
		{9, 2, 6, 8, 7, 1, 4, 5, 3}
	},
	{// Medium 2
		{3, 8, 7, 4, 1, 5, 9, 6, 2},
		{4, 9, 2, 7, 6, 3, 1, 8, 5},
		{5, 1, 6, 9, 2, 8, 3, 7, 4},
		{8, 2, 3, 1, 5, 7, 4, 9, 6},
		{7, 5, 4, 3, 9, 6, 2, 1, 8},
		{1, 6, 9, 2, 8, 4, 7, 5, 3},
		{9, 4, 9, 6, 7, 2, 5, 3, 1},
		{2, 7, 5, 8, 3, 1, 6, 4, 9},
		{6, 3, 1, 5, 4, 9, 8, 2, 7}
	},
	{// Medium 3
		{5, 6, 8, 9, 1, 3, 4, 2, 7},
		{3, 4, 2, 6, 8, 7, 9, 1, 5},
		{1, 9, 7, 2, 5, 4, 6, 8, 3},
		{6, 8, 5, 4, 7, 9, 1, 3, 2},
		{7, 3, 4, 1, 6, 2, 5, 9, 8},
		{2, 1, 9, 5, 3, 8, 7, 6, 4},
		{9, 2, 6, 3, 4, 5, 8, 7, 1},
		{4, 7, 3, 8, 9, 1, 2, 5, 6},
		{8, 5, 1, 7, 2, 6, 3, 4, 9}
	},
	{// Medium 4
		{9, 4, 8, 6, 2, 7, 1, 3, 5},
		{2, 1, 7, 4, 3, 5, 8, 6, 9},
		{5, 6, 3, 1, 8, 9, 4, 2, 7},
		{3, 5, 6, 8, 7, 4, 9, 1, 2},
		{4, 7, 9, 2, 5, 1, 3, 8, 6},
		{8, 2, 1, 9, 6, 3, 5, 7, 4},
		{6, 3, 2, 5, 4, 8, 7, 9, 1},
		{7, 9, 5, 3, 1, 2, 6, 4, 8},
		{1, 8, 4, 7, 9, 6, 2, 5, 3}
	},
	{// Medium 5
		{7, 4, 5, 3, 9, 6, 2, 1, 8},
		{1, 9, 6, 2, 8, 4, 7, 5, 3},
		{8, 3, 2, 1, 5, 7, 4, 9, 6},
		{3, 7, 8, 4, 1, 5, 9, 6, 2},
		{4, 2, 9, 7, 6, 3, 1, 8, 5},
		{5, 6, 1, 9, 2, 8, 3, 7, 4},
		{9, 8, 4, 6, 7, 2, 5, 3, 1},
		{2, 5, 7, 8, 3, 1, 6, 4, 9},
		{6, 1, 3, 5, 4, 9, 8, 2, 7}
	},
	{// Medium 6
		{2, 9, 3, 6, 5, 4, 7, 1, 8},
		{8, 6, 1, 7, 2, 3, 4, 5, 9},
		{4, 7, 5, 9, 8, 1, 2, 3, 6},
		{1, 5, 7, 8, 9, 6, 3, 2, 4},
		{6, 2, 4, 1, 3, 5, 9, 8, 7},
		{9, 3, 8, 2, 4, 7, 1, 6, 5},
		{3, 4, 6, 5, 1, 9, 8, 7, 2},
		{7, 1, 2, 4, 6, 8, 5, 9, 3},
		{5, 8, 9, 3, 7, 2, 6, 4, 1}
	},
	{// Medium 7
		{2, 8, 4, 9, 1, 6, 7, 5, 3},
		{3, 9, 6, 4, 7, 5, 2, 1, 8},
		{1, 5, 7, 3, 8, 2, 4, 9, 6},
		{4, 1, 5, 7, 3, 8, 9, 6, 2},
		{9, 2, 8, 6, 5, 1, 3, 7, 4},
		{7, 6, 3, 2, 4, 9, 1, 8, 5},
		{6, 7, 2, 8, 9, 4, 5, 3, 1},
		{8, 3, 1, 5, 2, 7, 6, 4, 9},
		{5, 4, 9, 1, 6, 3, 8, 2, 7}
	},
	{// Medium 8
		{3, 9, 1, 5, 6, 2, 8, 4, 7},
		{8, 7, 6, 9, 4, 3, 1, 2, 5},
		{5, 4, 2, 1, 8, 7, 3, 9, 6},
		{6, 1, 5, 2, 3, 9, 4, 7, 8},
		{9, 2, 7, 8, 5, 4, 6, 3, 1},
		{4, 8, 3, 7, 1, 6, 2, 5, 9},
		{1, 3, 4, 6, 9, 5, 7, 8, 2},
		{2, 5, 8, 3, 7, 1, 9, 6, 4},
		{7, 6, 9, 4, 2, 8, 5, 1, 3}
	},
	{// Medium 9
		{8, 3, 2, 4, 9, 6, 1, 5, 7},
		{1, 9, 6, 7, 5, 3, 2, 8, 4},
		{7, 4, 5, 2, 1, 8, 3, 9, 6},
		{4, 2, 9, 1, 8, 5, 7, 6, 3},
		{3, 7, 8, 9, 6, 2, 4, 1, 5},
		{5, 6, 1, 3, 7, 4, 9, 2, 8},
		{6, 1, 3, 8, 2, 7, 5, 4, 9},
		{2, 5, 7, 6, 4, 9, 8, 3, 1},
		{9, 8, 4, 5, 3, 1, 6, 7, 2}
	},
	{// Medium 10
		{1, 7, 9, 6, 8, 3, 5, 2, 4},
		{5, 8, 6, 4, 2, 7, 1, 9, 3},
		{3, 2, 4, 9, 1, 5, 8, 6, 7},
		{4, 3, 7, 2, 5, 6, 9, 8, 1},
		{9, 6, 2, 8, 7, 1, 4, 3, 5},
		{8, 1, 5, 3, 4, 9, 2, 7, 6},
		{6, 5, 8, 1, 3, 2, 7, 4, 9},
		{2, 9, 1, 7, 6, 4, 3, 5, 8},
		{7, 4, 3, 5, 9, 8, 6, 1, 2}
	}		
	};
		int SoalMedium[10][9][9] = {
			
	{// Soal Medium 1 :
		{1, 0, 7, 6, 8, 3, 0, 4, 0},
		{0, 4, 2, 9, 1, 0, 0, 0, 6},
		{0, 6, 8, 0, 0, 7, 0, 3, 0},
		{0, 0, 0, 1, 3, 2, 7, 9, 0},
		{0, 0, 0, 0, 0, 8, 0, 2, 1},
		{2, 0, 9, 7, 6, 0, 3, 8, 0},
		{4, 7, 3, 0, 0, 0, 0, 0, 8},
		{8, 0, 0, 0, 0, 0, 0, 6, 0},
		{9, 0, 0, 0, 7, 0, 0, 0, 3}
	},
	{// Soal Medium 2
		{3, 8, 7, 4, 0, 5, 0, 0, 2},
		{0, 0, 2, 7, 6, 0, 0, 0, 0},
		{5, 0, 0, 0, 0, 0, 3, 0, 0},
		{8, 2, 0, 0, 0, 0, 0, 9, 0},
		{0, 0, 0, 3, 9, 0, 0, 0, 0},
		{0, 6, 0, 0, 0, 0, 7, 0, 0},
		{9, 0, 9, 0, 0, 2, 5, 3, 0},
		{0, 7, 0, 0, 0, 1, 0, 4, 0},
		{0, 3, 0, 0, 4, 0, 8, 2, 0}
	},	
	{// Soal Medium 3
		{0, 6, 8, 9, 1, 0, 4, 0, 0},
		{3, 4, 2, 0, 0, 7, 0, 0, 0},
		{0, 0, 7, 0, 0, 0, 0, 8, 0},
		{0, 0, 5, 4, 7, 9, 0, 3, 0},
		{0, 0, 4, 0, 0, 2, 0, 9, 0},
		{0, 1, 0, 0, 0, 0, 7, 0, 4},
		{0, 2, 0, 3, 4, 0, 0, 7, 0},
		{4, 0, 0, 0, 9, 1, 2, 0, 6},
		{8, 0, 1, 0, 2, 6, 3, 4, 9}
	},
	{// Soal Medium 4
		{9, 0, 8, 0, 0, 7, 0, 0, 5},
		{0, 0, 0, 4, 0, 0, 0, 6, 0},
		{0, 6, 3, 0, 0, 0, 0, 2, 7},
		{0, 5, 6, 8, 7, 4, 9, 1, 0},
		{0, 0, 0, 2, 0, 0, 3, 8, 0},
		{8, 2, 1, 0, 6, 3, 5, 7, 0},
		{6, 0, 2, 5, 4, 0, 0, 0, 0},
		{0, 9, 0, 0, 0, 0, 0, 0, 8},
		{0, 0, 0, 0, 9, 6, 0, 5, 0}
	},
	{// Soal Medium 5
		{0, 0, 5, 0, 0, 0, 2, 1, 0},
		{1, 9, 6, 2, 8, 4, 7, 5, 3},
		{0, 3, 0, 1, 5, 0, 4, 0, 6},
		{3, 0, 8, 0, 0, 5, 0, 0, 0},
		{4, 0, 0, 0, 6, 3, 0, 0, 0},
		{5, 0, 1, 9, 2, 0, 3, 7, 4},
		{0, 0, 0, 0, 0, 2, 5, 0, 0},
		{0, 5, 0, 0, 3, 0, 6, 0, 0},
		{0, 1, 3, 0, 4, 0, 0, 0, 0}
	},
	{// Soal Medium 6
		{0, 9, 0, 0, 0, 0, 7, 0, 0},
		{0, 0, 0, 7, 2, 0, 4, 5, 0},
		{0, 0, 5, 0, 8, 1, 0, 3, 0},
		{1, 0, 7, 0, 0, 0, 3, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 8, 0},
		{9, 3, 0, 0, 4, 7, 0, 0, 0},
		{0, 4, 0, 0, 0, 0, 8, 0, 2},
		{7, 0, 2, 4, 6, 8, 5, 0, 3},
		{5, 8, 9, 3, 7, 0, 6, 0, 1}
	},
	{// Soal Medium 7
		{0, 8, 4, 9, 0, 0, 7, 5, 0},
		{3, 0, 6, 4, 7, 5, 2, 0, 8},
		{0, 5, 0, 3, 8, 2, 4, 0, 6},
		{0, 1, 5, 0, 0, 8, 9, 0, 2},
		{9, 0, 8, 6, 0, 0, 0, 0, 4},
		{7, 6, 3, 0, 4, 9, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 5, 2, 7, 6, 4, 9},
		{0, 0, 0, 1, 0, 0, 0, 0, 0}
	},
	{// Soal Medium 8
		{3, 9, 1, 5, 6, 0, 0, 4, 7},
		{8, 7, 0, 9, 4, 0, 1, 2, 5},
		{0, 0, 2, 1, 8, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 9, 0, 7, 8},
		{9, 0, 0, 0, 0, 4, 6, 0, 1},
		{0, 0, 3, 7, 0, 0, 0, 0, 0},
		{0, 3, 4, 0, 0, 0, 7, 0, 2},
		{0, 0, 0, 0, 0, 1, 0, 6, 0},
		{7, 6, 0, 4, 0, 0, 0, 0, 0}
	},
	{// Soal Medium 9
		{8, 0, 2, 4, 0, 0, 1, 5, 7},
		{1, 0, 6, 7, 5, 3, 0, 0, 0},
		{0, 0, 5, 0, 0, 8, 3, 9, 6},
		{0, 2, 9, 1, 8, 5, 0, 6, 0},
		{0, 0, 8, 9, 6, 2, 4, 0, 5},
		{0, 0, 1, 3, 7, 4, 0, 0, 0},
		{0, 1, 0, 8, 0, 7, 5, 0, 0},
		{0, 0, 7, 0, 4, 0, 0, 0, 0},
		{9, 0, 4, 5, 0, 0, 0, 7, 2}
	},
	{// Soal Medium 10
		{1, 7, 9, 6, 0, 3, 5, 0, 4},
		{5, 8, 6, 4, 0, 0, 1, 9, 0},
		{0, 2, 4, 9, 0, 5, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 9, 0, 0},
		{0, 0, 0, 0, 7, 0, 0, 3, 0},
		{8, 0, 0, 3, 0, 0, 0, 0, 6},
		{0, 0, 0, 1, 3, 2, 0, 4, 0},
		{0, 0, 1, 7, 6, 0, 0, 0, 8},
		{7, 0, 0, 5, 9, 8, 0, 1, 2}
	}
	};
	
		int Hard[10][9][9] = {
		
	{// Hard 1 :
		{4, 5, 2, 6, 8, 3, 7, 9, 1},
		{7, 8, 6, 9, 1, 5, 2, 4, 3},
		{3, 1, 9, 4, 2, 7, 8, 6, 5},
		{9, 7, 4, 1, 3, 2, 5, 8, 6},
		{2, 6, 1, 5, 9, 8, 4, 3, 7},
		{8, 3, 5, 7, 6, 4, 9, 1, 2},
		{5, 4, 3, 8, 7, 1, 6, 2, 9},
		{6, 2, 7, 3, 4, 9, 1, 5, 8},
		{1, 9, 8, 2, 5, 6, 3, 7, 4}
	},
	{// Hard 2
		{3, 1, 4, 7, 5, 9, 2, 8, 6},
		{2, 5, 6, 8, 4, 1, 7, 9, 3},
		{8, 7, 9, 6, 2, 3, 4, 5, 1},
		{1, 8, 7, 9, 6, 2, 5, 3, 4},
		{6, 4, 5, 3, 1, 8, 9, 2, 7},
		{9, 3, 2, 4, 7, 5, 6, 1, 8},
		{4, 9, 1, 2, 3, 6, 8, 7, 5},
		{5, 6, 8, 1, 9, 7, 3, 4, 2},
		{7, 2, 3, 5, 8, 4, 1, 6, 9}
	},
	{// Hard 3
		{6, 2, 7, 5, 3, 1, 9, 8, 4},
		{5, 9, 4, 8, 2, 7, 6, 1, 3},
		{8, 1, 3, 6, 4, 9, 2, 5, 7},
		{1, 7, 5, 4, 9, 6, 8, 3, 2},
		{3, 6, 9, 2, 1, 8, 7, 4, 5},
		{2, 4, 8, 7, 5, 3, 1, 9, 6},
		{4, 5, 1, 9, 6, 2, 3, 7, 8},
		{7, 3, 6, 1, 8, 5, 4, 2, 9},
		{9, 8, 2, 3, 7, 4, 5, 6, 1}
	},
	{// Hard 4
		{1, 6, 5, 7, 9, 8, 3, 2, 4},
		{4, 2, 9, 3, 1, 6, 5, 8, 7},
		{8, 3, 7, 2, 4, 5, 1, 9, 6},
		{7, 8, 1, 5, 2, 3, 6, 4, 9},
		{9, 4, 3, 1, 6, 7, 2, 5, 8},
		{6, 5, 2, 9, 8, 4, 7, 3, 1},
		{5, 9, 8, 6, 3, 1, 4, 7, 2},
		{2, 7, 6, 4, 5, 9, 8, 1, 3},
		{3, 1, 4, 8, 7, 2, 9, 6, 5}
	},
	{// Hard 5
		{4, 3, 7, 8, 9, 5, 1, 6, 2},
		{9, 1, 2, 4, 6, 7, 5, 3, 8},
		{5, 8, 6, 2, 3, 1, 4, 7, 9},
		{7, 9, 1, 3, 8, 6, 2, 5, 4},
		{2, 4, 3, 5, 1, 9, 6, 8, 7},
		{8, 6, 5, 7, 2, 4, 9, 1, 3},
		{6, 2, 9, 1, 7, 8, 3, 4, 5},
		{1, 5, 8, 9, 4, 3, 7, 2, 6},
		{3, 7, 4, 6, 5, 2, 8, 9, 1}
	},
	{// Hard 6
		{3, 7, 8, 9, 2, 6, 4, 1, 5},
		{4, 2, 9, 1, 5, 8, 7, 6, 3},
		{5, 6, 1, 3, 4, 7, 9, 2, 8},
		{6, 1, 3, 8, 7, 2, 5, 4, 9},
		{9, 8, 4, 5, 1, 3, 6, 7, 2},
		{2, 5, 7, 6, 9, 4, 8, 3, 1},
		{8, 3, 2, 4, 6, 9, 1, 5, 7},
		{7, 4, 5, 2, 8, 1, 3, 9, 6},
		{1, 9, 6, 7, 3, 5, 2, 8, 4}
	},
	{// Hard 7
		{6, 2, 9, 3, 5, 4, 8, 1, 7},
		{1, 5, 8, 7, 6, 2, 3, 9, 4},
		{3, 7, 4, 8, 1, 9, 2, 6, 5},
		{8, 6, 5, 9, 3, 1, 4 ,7, 2},
		{2, 4, 3, 6, 7, 8, 9, 5, 1},
		{7, 9, 1, 2, 4, 5, 6, 3, 8},
		{5, 8, 6, 4, 9, 7, 1, 2, 3},
		{4, 3, 7, 1, 2, 6, 5, 8, 9},
		{9, 1, 2, 5, 8, 3, 7, 4, 6}
	},
	{// Hard 8
		{3, 9, 6, 1, 2, 8, 7, 4, 5},
		{1, 5, 7, 9, 4, 6, 8, 3, 2},
		{2, 8, 4, 5, 7, 3, 1, 9, 6},
		{4, 1, 5, 6, 9, 2, 3, 7, 8},
		{7, 6, 3, 8, 1, 5, 4, 2, 9},
		{9, 2, 8, 7, 3, 4, 5, 6, 1},
		{6, 7, 2, 3, 5, 1, 9, 8, 4},
		{8, 3, 1, 4, 6, 9, 2, 5, 7},
		{5, 4, 9, 2, 8, 7, 6, 1, 3}
	},
	{// Hard 9
		{5, 3, 1, 6, 2, 7, 4, 8, 9},
		{6, 4, 9, 8, 1, 3, 7, 5, 2},
		{8, 2, 7, 5, 9, 4, 3, 1, 6},
		{1, 8, 5, 7, 3, 6, 9, 2, 4},
		{9, 6, 2, 4, 5, 1, 8, 7, 3},
		{3, 7, 4, 9, 8, 2, 1, 6, 5},
		{7, 5, 3, 2, 4, 8, 6, 9, 1},
		{2, 1, 8, 3, 6, 9, 5, 4, 7},
		{4, 9, 6, 1, 7, 5, 2, 3, 8}
	},
	{// Hard 10
		{4, 2, 1, 3, 7, 5, 8, 9, 6},
		{5, 7, 9, 6, 8, 2, 3, 4, 1},
		{3, 8, 6, 1, 4, 9, 2, 7, 5},
		{9, 3, 2, 7, 5, 8, 1, 6, 4},
		{8, 4, 5, 2, 1, 6, 9, 3, 7},
		{1, 6, 7, 4, 9, 3, 5, 2, 6},
		{2, 5, 4, 9, 6, 1, 7, 8, 3},
		{6, 1, 3, 8, 2, 7, 4, 5, 9},
		{7, 9, 8, 5, 3, 4, 6, 1, 2}
	}
	};
		int SoalHard[10][9][9] = {
		
	{// Soal Hard 1 :
		{0, 0, 0, 0, 0, 3, 7, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 4, 0},
		{3, 1, 0, 0, 0, 0, 0, 6, 0},
		{9, 0, 4, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 5, 9, 0, 0, 0, 0},
		{8, 3, 0, 7, 6, 0, 9, 0, 0},
		{0, 4, 3, 8, 0, 0, 6, 2, 9},
		{6, 0, 0, 3, 0, 0, 0, 5, 8},
		{0, 0, 0, 2, 0, 0, 3, 7, 0}
	},
	{// Soal Hard 2
		{3, 1, 0, 7, 5, 9, 2, 0, 6},
		{2, 5, 0, 0, 0, 0, 0, 9, 0},
		{8, 7, 0, 6, 0, 3, 4, 5, 1},
		{0, 0, 0, 9, 6, 0, 0, 3, 4},
		{0, 0, 5, 0, 0, 8, 0, 0, 0},
		{0, 3, 0, 0, 0, 0, 6, 0, 8},
		{0, 9, 1, 2, 0, 6, 0, 0, 0},
		{0, 6, 0, 0, 0, 0, 0, 4, 0},
		{0, 0, 3, 5, 8, 0, 1, 0, 0}
	},
	{// Soal Hard 3
		{0, 0, 0, 0, 3, 0, 0, 8, 4},
		{5, 0, 0, 0, 2, 0, 0, 1, 0},
		{0, 1, 3, 0, 0, 9, 0, 5, 0},
		{1, 0, 0, 0, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{2, 0, 8, 7, 0, 0, 0, 9, 6},
		{0, 0, 1, 9, 0, 0, 3, 7, 0},
		{0, 3, 6, 0, 8, 5, 4, 0, 9},
		{9, 8, 0, 0, 0, 0, 0, 0, 0}
	},
	{// Soal Hard 4
		{1, 6, 0, 7, 9, 8, 3, 2, 0},
		{4, 2, 9, 3, 0, 6, 5, 8, 0},
		{0, 0, 7, 0, 0, 0, 1, 9, 0},
		{0, 0, 0, 5, 0, 0, 0, 0, 9},
		{0, 4, 3, 0, 6, 7, 0, 0, 0},
		{6, 5, 0, 0, 0, 0, 0, 3, 0},
		{0, 0, 0, 6, 0, 1, 0, 7, 2},
		{2, 0, 0, 0, 5, 9, 0, 0, 3},
		{0, 0, 4, 0, 0, 0, 0, 6, 0}
	},
	{// Soal Hard 5
		{4, 3, 7, 8, 0, 5, 0, 0, 2},
		{9, 1, 0, 4, 0, 0, 0, 3, 0},
		{0, 8, 0, 0, 0, 1, 4, 7, 9},
		{0, 9, 1, 3, 0, 0, 0, 0, 0},
		{0, 0, 0, 5, 1, 0, 0, 8, 7},
		{0, 0, 5, 0, 0, 0, 9, 0, 3},
		{0, 2, 9, 0, 7, 8, 0, 0, 5},
		{1, 0, 0, 9, 4, 3, 0, 2, 0},
		{0, 0, 0, 0, 5, 0, 8, 0, 1}
	},
	{// Soal Hard 6
		{3, 0, 8, 0, 2, 0, 0, 0, 5},
		{0, 2, 0, 1, 5, 0, 7, 6, 3},
		{0, 0, 0, 0, 0, 7, 0, 0, 0},
		{0, 1, 0, 8, 7, 2, 0, 4, 0},
		{9, 0, 0, 5, 1, 3, 6, 7, 0},
		{2, 0, 0, 6, 9, 4, 0, 0, 0},
		{8, 0, 0, 0, 6, 9, 0, 0, 7},
		{0, 4, 5, 2, 8, 0, 0, 9, 0},
		{1, 9, 6, 7, 0, 0, 0, 8, 4}
	},
	{// Soal Hard 7
		{0, 2, 0, 0, 0, 0, 8, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 9, 4},
		{0, 0, 0, 8, 1, 9, 2, 0, 0},
		{0, 0, 5, 0, 0, 1, 4 ,0, 0},
		{0, 0, 3, 0, 7, 0, 0, 5, 0},
		{0, 0, 0, 2, 4, 5, 6, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 2, 0},
		{0, 3, 0, 0, 0, 6, 5, 8, 9},
		{9, 0, 0, 0, 8, 3, 0, 0, 0}
	},
	{// Soal Hard 8
		{3, 0, 0, 0, 2, 0, 0, 0, 0},
		{0, 5, 7, 0, 0, 0, 0, 3, 0},
		{2, 0, 0, 5, 0, 0, 0, 0, 0},
		{0, 1, 5, 6, 0, 0, 3, 7, 8},
		{0, 6, 0, 0, 1, 0, 4, 0, 9},
		{9, 2, 0, 0, 0, 0, 5, 0, 0},
		{6, 7, 0, 3, 0, 0, 0, 0, 0},
		{0, 3, 1, 0, 6, 0, 0, 0, 7},
		{0, 0, 9, 0, 8, 0, 6, 0, 0}
	},
	{// Soal Hard 9
		{0, 3, 0, 0, 2, 0, 4, 8, 0},
		{6, 0, 9, 0, 1, 0, 0, 5, 2},
		{0, 0, 0, 0, 0, 4, 0, 0, 0},
		{0, 8, 5, 7, 0, 6, 9, 2, 0},
		{0, 6, 0, 0, 0, 0, 0, 0, 3},
		{0, 7, 0, 0, 0, 2, 0, 6, 5},
		{0, 0, 3, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 6, 0, 0, 4, 0},
		{4, 9, 6, 1, 0, 0, 0, 0, 0}
	},
	{// Soal Hard 10
		{4, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 2, 0, 0},
		{0, 0, 2, 0, 0, 0, 0, 0, 4},
		{0, 4, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 3, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 3},
		{0, 0, 3, 0, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 2}
	}
	};
	
	int Angka, BASE_SCORE;
	
	// menyimpan array sesuai difficulty untuk dipakai di function InputAngka
	switch (Difficulty){
		case 1:
			for(int row = 0; row < 9; row++){
				for(int col = 0; col < 9; col++){
					SimpanSoal[Index][row][col] = SoalEasy[Index][row][col]; // Digunakan untuk menyamakan dengan array SimpanJawaban di InputAngka
					SimpanJawaban[Index][row][col] = Easy[Index][row][col];
				}
			}
			BASE_SCORE = 20;
			return BASE_SCORE;
			break;
		
		case 2:
			for(int row = 0; row < 9; row++){
				for(int col = 0; col < 9; col++){
					SimpanSoal[Index][row][col] = SoalMedium[Index][row][col];
					SimpanJawaban[Index][row][col] = Medium[Index][row][col];
				}
			}
			BASE_SCORE = 30;
			return BASE_SCORE;
			break;
		
		case 3:
			for(int row = 0; row < 9; row++){
				for(int col = 0; col < 9; col++){
					SimpanJawaban[Index][row][col] = Hard[Index][row][col];
					SimpanSoal[Index][row][col] = SoalHard[Index][row][col];
				}
			}
			BASE_SCORE = 40;
			return BASE_SCORE;
			break;
			
		default:
			break;
	}
}

bool CekBlok(int SimpanSoal[10][9][9], int Index, int row, int col) {
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (SimpanSoal[Index][i][j] == 0) {
                return false; // Ada angka 0, blok belum penuh
            }
        }
    }
    return true; // Tidak ada angka 0, blok penuh
}

bool CekVertikal(int SimpanSoal[10][9][9], int Index, int row, int col){
	for(int j = 0; j < 9; j++){ // kolom
		if(SimpanSoal[Index][row][j] == 0){
			return false;
		}
	}
	return true;
}

bool CekHorizontal(int SimpanSoal[10][9][9], int Index, int row, int col){
	for(int i = 0; i < 9; i++){
		if(SimpanSoal[Index][i][col] == 0){
			return false;
		}
	}
	return true;
}

bool CekFinal(int SimpanSoal[10][9][9], int Index, int row, int col){
	for (row = 0; row < 9; row++){
		for(col = 0; col < 9; col++){
			if(SimpanSoal[Index][row][col] == 0){
				return false;
			}
		}
	}
	return true;
}

int Permainan (int Score, int BASE_SCORE, int Index, int SimpanSoal[10][9][9], int SimpanJawaban[10][9][9]){
	
	int IsiAngka, brs, klm, Angka, JumlahSalah, Difficulty;
	Score = 0;
	int Score1;
	bool Benar = false, Cek = true;
	
	while(Benar == false){
		// Pengecekan jika Array sudah terisi semua
		menu:
		if(CekFinal(SimpanSoal, Index, brs, klm)){
			Benar = true;
		}
		// Display Papan yang sudah terisi oleh array sesuai difficulty
		system("cls");
		time_t time_start = time(NULL);
		printf("\n\nPetunjuk :");
		printf("  kolom -->\t\t\t\t\tJumlah Salah: %d/3\n", JumlahSalah);
		printf("\x1b[30mPetunjuk :\x1b[0m  baris  |\t\t\t\t\tScore : %d", Score);
		printf("\n\x1b[30mPetunjuk :  baris\x1b[0m  |\n\x1b[30mPetunjuk :  baris\x1b[0m  V\n\n");
		printf("\t\tBoard Choosen : %d\n\n", Index - 1 + 2);
		printf("\t\t  \x1b[37m1 2 3   4 5 6   7 8 9\x1b[0m\n");
		for(int row = 0; row < 9; row++){
			for(int col = 0; col < 9; col++){
				if((row %3 == 0) && (col == 0)){
					printf("\t\t\x1b[35m- - - - - - - - - - - - -\x1b[0m\n");
				}
				if(col == 0){
					printf("\t\t\x1b[35m| \x1b[0m");
				} else if(col %3 == 0){
					printf("\x1b[35m| \x1b[0m");
				}
				Angka = SimpanSoal[Index][row][col];
				if(Angka == 0){
					printf("\x1b[30m%d \x1b[0m", SimpanSoal[Index][row][col]);
				} else {
					printf("%d ", SimpanSoal[Index][row][col]);
				}
				if((col == 8) && (row != 4)){
					printf("\x1b[35m| \x1b[0m");
				} 
				if(col == 8 && row == 0){
					printf(" 1");
				} else if (col == 8 && row == 1){
					printf(" 2");
				} else if (col == 8 && row == 2){
					printf(" 3");
				} else if (col == 8 && row == 3){
					printf(" 4");
				} else if (col == 8 && row == 4){
					printf("\x1b[35m| \x1b[0m 5\t\t Masukkan (0) untuk kembali");
				} else if (col == 8 && row == 5){
					printf(" 6");
				} else if (col == 8 && row == 6){
					printf(" 7");
				} else if (col == 8 && row == 7){
					printf(" 8");
				} else if (col == 8 && row == 8){
					printf(" 9");
				}
				
				
			}
			printf("\n");
		}
		printf("\t\t\x1b[35m- - - - - - - - - - - - -\x1b[0m\n\n\n");
	
		printf("\t\tMasukkan baris : ");
		scanf(" %d", &brs);
		if(brs == 0){
			return brs;
		}
		brs--;
		menu_klm:
		printf("\t\tMasukkan kolom : ");
		scanf(" %d", &klm);
		if(klm == 0){
			goto menu;
		}
		klm--;
		printf("\t\tMasukkan Angka : ");
		scanf(" %d", &IsiAngka);
		if(IsiAngka == 0){
			goto menu;
		}
		
		// Jika input jawaban benar akan diisi oleh jawaban tersebut
		if(IsiAngka == SimpanJawaban[Index][brs][klm]){
			if(SimpanSoal[Index][brs][klm] == 0){
				SimpanSoal[Index][brs][klm] = IsiAngka;
				Score += Scoring(time_start, BASE_SCORE);		
				for(int row = 0; row < 9; row += 3){
					for(int col = 0; col < 9; col += 3){
						if(CekBlok(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 5;
						}
						if(CekVertikal(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 5;
						}
						if(CekHorizontal(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 5;
						}
						if(CekVertikal(SimpanSoal, Index, row, col) && CekHorizontal(SimpanSoal, Index, row, col) && CekBlok(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 15;
						}
						if(CekVertikal(SimpanSoal, Index, row, col) && CekHorizontal(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 10;
						} else if (CekVertikal(SimpanSoal, Index, row, col) && CekBlok(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 10;
						} else if (CekHorizontal(SimpanSoal, Index, row, col) && CekBlok(SimpanSoal, Index, row, col)){
							Score = Score + BASE_SCORE * 10;
						}
					}
				}
			}
		} else if (SimpanSoal[Index][brs][klm] == 0){
			printf("Salah\n");
			JumlahSalah++;
			if(JumlahSalah == 3){
				Benar = true;
				return JumlahSalah;
				break;
			}
		}
		if(CekFinal(SimpanSoal, Index, brs, klm)){
			Benar = true;
			DisplayWin();
			system("cls");
			Highscore(Score);
		}
	}
}

int Scoring(int time_start, int BASE_SCORE){
	
	int total_score;
	time_t end_time = time(NULL);
	int time_used = (int)difftime(end_time, time_start);
	
	if(time_used > MAX_BONUS_TIME) {
		time_used = MAX_BONUS_TIME;
	}
	int bonus_score = MAX_BONUS_TIME - time_used;
    int turn_score = BASE_SCORE + bonus_score;
    total_score += turn_score;
    
	return total_score;
}

void DisplayLose(){
	
	int ConsoleWidth = 116;
	system("cls");
	printf("\n\n\n\n");
    printCentered(" #####     ###    ##     ## ########       ###   ##      ##  ######## #######      ", ConsoleWidth);
    printCentered("##   ##   ## ##   ###   ### ##            ## ##   ##    ##   ##       ##    ##     ", ConsoleWidth);
    printCentered("##       ##   ##  #### #### ##           ##   ##  ##    ##   ##       ##    ##     ", ConsoleWidth);
    printCentered("##  ### ##     ## ## ### ## ######       ##   ##   ##  ##    ######   #######      ", ConsoleWidth);
    printCentered("##   ## ######### ##  #  ## ##           ##   ##   ##  ##    ##       ##   ##      ", ConsoleWidth);
    printCentered("##   ## ##     ## ##     ## ##            ## ##     ####     ##       ##    ##     ", ConsoleWidth);
    printCentered(" #####  ##     ## ##     ## ########       ###       ##      ######## ##     ##    ", ConsoleWidth);
    printf("\n");
}

void DisplayWin(){
	
	int ConsoleWidth = 116;
	system("cls");
    printf("\n\n\n\n");
    printCentered("##     ##  ######   ##    ##      ##      ## ## ##    ## ", ConsoleWidth);
    printCentered("###   ### ##    ##  ##    ##      ##  ##  ## ## ###   ## ", ConsoleWidth);
    printCentered(" ### ###  ##    ##  ##    ##      ##  ##  ## ## ##### ## ", ConsoleWidth);
    printCentered("   ###    ##    ##  ##    ##      ##  ##  ## ## ## ##### ", ConsoleWidth);
    printCentered("   ###    ##    ##  ##    ##      ##  ##  ## ## ##  #### ", ConsoleWidth);
    printCentered("   ###    ##    ##  ##    ##       ########  ## ##   ### ", ConsoleWidth);
    printCentered("   ###     ######    ######         ##  ##   ## ##    ## ", ConsoleWidth);
    printf("\n");
    getchar();
    getchar();
}
void printCentered(const char* text, int consoleWidth) {
    int padding = (consoleWidth - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" "); // Print leading spaces
    }
    printf("%s\n", text); // Print the text
}
