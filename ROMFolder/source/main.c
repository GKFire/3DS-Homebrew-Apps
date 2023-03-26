/*
Made by GKFireDev
Last updated Mar. 25th 2023


*/
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "menus.h"


//3DS top screen: 30 rows by 50 columns
//3DS bottom screen: 30 rows by 40 columns

short MenuSelected = 0;
bool finished_g = 1;
bool status_g = 0;

void update3DS(PrintConsole top, PrintConsole bottom){
	consoleSelect(&top);
	consoleClear();
	consoleSelect(&bottom);
	consoleClear();
}


int main()
{
	gfxInitDefault();
	PrintConsole top, bottom;
	consoleInit(GFX_TOP, &top);
	consoleInit(GFX_BOTTOM, &bottom);

	while (aptMainLoop())
	{
		hidScanInput();

		if(MenuSelected == 0){
			MainMenu(top, bottom);
		} else if(MenuSelected == 1){
			LoaderMenu(top, bottom);
		}

		u32 kDown = hidKeysDown();
		if(MenuSelected == 0){
			if((kDown & KEY_A) || (kDown & KEY_START)){
				MenuSelected = 1;
				update3DS(top, bottom);
			}
			if(kDown & KEY_B){
				break;
			}
		} else if(MenuSelected == 1){
			if(kDown & KEY_B){
				if(finished_g){
					MenuSelected = 0;
					update3DS(top, bottom);
				}
			} else if(kDown & KEY_A){
				if(status_g) break;
				finished_g = 0;
				struct stat st = {0};
				printf("Looking For ROM folder..\n");
				if (stat("sdmc:/rom", &st) == -1) {
					printf("Making ROM folder..\n");
					mkdir("sdmc:/rom", 0700);
				}
				printf("Looking For NDS folder..\n");
				if (stat("sdmc:/rom/nds", &st) == -1) {
					printf("Making NDS folder..\n");
					mkdir("sdmc:/rom/nds", 0700);

				}
				printf("Looking For NES folder..\n");
				if (stat("sdmc:/rom/nes", &st) == -1) {
					printf("Making NES folder..\n");
					mkdir("sdmc:/rom/nes", 0700);

				}
				printf("Looking For SNES folder..\n");
				if (stat("sdmc:/rom/snes", &st) == -1) {
					printf("Making SNES folder..\n");
					mkdir("sdmc:/rom/snes", 0700);

				}
				printf("Looking For GENESIS folder..\n");
				if (stat("sdmc:/rom/genesis", &st) == -1) {
					printf("Making GENESIS folder..\n");
					mkdir("sdmc:/rom/genesis", 0700);

				}
				printf("Looking For GBA folder..\n");
				if (stat("sdmc:/rom/gba", &st) == -1) {
					printf("Making GBA folder..\n");
					mkdir("sdmc:/rom/gba", 0700);

				}
				finished_g = 1;
				status_g = 1;
				printf("Press B or A To Exit");
			}
		}



		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();

	return 0;
}
