#include "menus.h"

void MainMenu(PrintConsole topScreen, PrintConsole bottomScreen) {

	consoleSelect(&topScreen);
	printf("\x1b[3;15HROM Folder Maker v0.2 BETA");
	printf("\x1b[5;15HBy FlareRXW");

	consoleSelect(&bottomScreen);
	printf("Press A To Make ROM Folder\n");
	printf("Press B To Exit\n");

	consoleSelect(&topScreen);
	printf("\x1b[27;14HPress A To Make ROM Folder.\n");
	printf("\x1b[29;14HPress B To Exit\n");


}
void LoaderMenu(PrintConsole topScreen, PrintConsole bottomScreen){

	consoleSelect(&bottomScreen);
	printf("Press A To Begin...\n");
	printf("Press B to Exit\n");
}
