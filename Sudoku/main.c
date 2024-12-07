#include <stdio.h>
#include <stdlib.h>
#include "Sudoku.h"
#include <time.h>
#include <stdbool.h>
#include "windows.h"

int main(){
	// menggunakan
	enum Menu {
		Menu_New_Game = 1,
		Menu_Leaderboard,
		Menu_CaraBermain,
		Menu_Exit
	};

	int BASE_SCORE, Score, Index, input, brs, klm, IsiAngka, Difficulty, WaktuDetik, SimpanSoal[10][9][9], SimpanJawaban[10][9][9];
	bool IsiSudoku, Benar;
	
	while (2) { // Loop terus berjalan sampai pengguna memilih keluar
        menu_Display:
		Difficulty = 0;
		Score = 0;
        input = DisplayMenu(); // Panggil fungsi untuk menampilkan menu utama
        switch (input) {
			case Menu_New_Game:
				//Generate Random Angka
				srand(time(NULL));	//Seed random
				menu_NG:
				Index = rand()% 9 + 1;	// Angka Random (1 - 9)
				Difficulty = NewGame();
				switch (Difficulty){
					case 1:
						BASE_SCORE = Randomizer(Index, Difficulty, SimpanSoal, SimpanJawaban);
						input = Permainan(Score, BASE_SCORE, Index, SimpanSoal, SimpanJawaban);
						if(input == 3){
							system("cls");
							DisplayLose();
							getchar();
							getchar();
							goto menu_Display;
						}
						if(input == 0){
							goto menu_NG;
						}
						if(input == 4){
							goto menu_Display;
						}
					case 2:
						BASE_SCORE = Randomizer(Index, Difficulty, SimpanSoal, SimpanJawaban);
						input = Permainan(Score, BASE_SCORE, Index, SimpanSoal, SimpanJawaban);
						if(input == 3){
							system("cls");
							DisplayLose();
							getchar();
							getchar();
							goto menu_Display;
						}
						if(input == 0){
							goto menu_NG;
						}
						if(input == 4){
							goto menu_Display;
						}
					case 3:
						BASE_SCORE = Randomizer(Index, Difficulty, SimpanSoal, SimpanJawaban);
						input = Permainan(Score, BASE_SCORE, Index, SimpanSoal, SimpanJawaban);
						if(input == 3){
							input--;
							system("cls");
							DisplayLose();
							getchar();
							getchar();
							goto menu_Display;
						}
						if(input == 0){
							goto menu_NG;
						}
						if(input == 4){
							goto menu_Display;
						}
					case 0:
						break;
					default:
						InputTidakValid();
						goto menu_NG;
				}
				break;
				
        	// Menampilkan 5 score teratas
        	case Menu_Leaderboard:
        		menu_L:
            	input = Leaderboard(); // Panggil fungsi leaderboard
            	switch(input){
            		case 0:
            			break;
            		default:
            			InputTidakValid();
            			goto menu_L;
				}
            	break; // Kembali ke menu utama
        	
        	case Menu_CaraBermain:
        		menu_HW:
				input = HowToPlay();
        		switch(input){
        			case 0:
        				break;
        			default:
        				InputTidakValid();
            			goto menu_HW;
				}
				break;
        		
        	case Menu_Exit:
            	Exit(); // Untuk keluar
            	return 0;
            
            default:
            	InputTidakValid();
            	break;
        } 
    }
}
