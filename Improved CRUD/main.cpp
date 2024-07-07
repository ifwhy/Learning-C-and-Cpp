#include "CRUD/Menu.hpp"
#include "CRUD/CRUD.hpp"

int main(){
	Menu menu = Menu();
	CRUD crud = CRUD();

	system(CLEAR_CONSOLE);
	do {
		menu.showMenu();
		switch (menu.getPilihan()){

			case CREATE_DATA: // Menambahkan Data
				crud.addDataMhs();
				menu.backTo();
				break;

			case READ_DATA: // Menampilkan Data
				system(CLEAR_CONSOLE);
				crud.showDataMhs();
				menu.backTo();
				break;

			case UPDATE_DATA: // Mengupdate Data
				crud.updateDataMhs();
				menu.backTo();
				break;

			case DELETE_DATA: // Menghapus Data
				crud.deleteDataMhs();
				menu.backTo();
				break;
			
			case SEARCH_DATA: // Mencari Data
				crud.searchDataMhs();
				menu.backTo();
				break;
			
			case VISIT_FACULTY: // Mengunjungi Fakultas
				crud.visitFaculty();
				menu.backTo();
				break; 

			case EXIT: // Keluar Menu
				menu.setIsLoop(false);
				break;

			default: // Menghandle pilihan lain
				menu.showWrongChoice();
				menu.setIsLoop(false);
				break;
		}
	} while (menu.getIsLoop());
	
	menu.showThanks();
	menu.SetConsoleColor(WHITE, BLACK);
	return 0;
}