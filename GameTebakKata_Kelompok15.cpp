//KELOMPOK 15
//1. Indah Kusuma Ningrum (2217051139)
//2. Ivan Aditya (2217051147)
//3. M.Ferdiansyah (2217051126)

#include<iostream>
#include<conio.h>
#include<vector>
#include <windows.h>
#include <ncurses/ncurses.h>
using namespace std;

int gagal;
string soalkata, jawaban;
bool tebakan;
char jawaban_user, main_lagi ;
vector<char> jawabanSalah;
string kategori[5] = {"Binatang", "Buah", "Negara", "Kota", "Benua"}, kategorikata;


void loading(){
	
	initscr();
	mvprintw(2, 39, "=================================");
	mvprintw(3, 39, "|--------GAME TEBAK KATA--------|");
	mvprintw(4, 39, "=================================");
	mvprintw(11, 40, "LOADING");
	
	//looping loading
	for(int baris=48; baris<=70; baris++){
		mvprintw(11, baris, "*");
		refresh();
		Sleep(100);
	}
		mvprintw(13, 42, "Press");
		refresh();
		Sleep(300);
		
		mvprintw(13, 48, "Any");
		refresh();
		Sleep(300);
		
		mvprintw(13, 52, "Key");
		refresh();
		Sleep(300);	
		
		mvprintw(13, 56, "To ");
		refresh();
		Sleep(300);
		
		mvprintw(13, 59, "Continue.. ");
		refresh();
		Sleep(300);
	getch();
	endwin();
}
void header(){
	
	cout << "\t\t\t\t-------SELAMAT DATANG DI GAME TEBAK KATA!-------\n";
	cout << "\n\n==============================\n";
	cout << "Tebak Kata : Bahasa Indonesia\n";
	cout << "==============================\n\n";
	
	cout << "Instruksi \t: Selamatkan temanmu sebelum dia digantung\n\n";
	cout << "Note \t\t: Kesempatanmu hanya 4 kali salah\n\n";
}

int jika_gagal(int gagal){
	if(gagal==0){
		
		cout << "	+____ __ ____+	\n";
		cout << "	|    \\  /    |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	==============	\n";
	}
	else if(gagal==1){
		cout << "	+____ __ ____+	\n";
		cout << "	|    \\  /    |	\n";
		cout << "	|      O     |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	==============	\n";
		cout << "Jumlah gagal = " << gagal;
	}
	else if(gagal==2){
		cout << "	+____ __ ____+	\n";
		cout << "	|    \\  /    |	\n";
		cout << "	|      O     |	\n";
		cout << "	|      |     |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	==============	\n";
		cout << "Jumlah gagal = " << gagal;
	}
	else if(gagal==3){
		cout << "	+____ __ ____+	\n";
		cout << "	|    \\  /    |	\n";
		cout << "	|      O     |	\n";
		cout << "	|      |     |	\n";
		cout << "	|     /      |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "	==============	\n";
		cout << "Jumlah gagal = " << gagal << endl;
		cout << "AWAS TEMANMU HAMPIR TERGANTUNG!!!\n";
	}
	
}

void status_jawaban(vector<char> jawabanSalah, string jawaban)
{

  cout<<"\nJawaban Terakhir Kamu Yang Salah : \n";

  for(int i = 0; i<jawabanSalah.size(); i++)
  {
    cout<<jawabanSalah[i]<<" ";
  }

  cout<<"\n\nTebak Kata:\n";

  for(int i = 0; i<jawaban.length(); i++)
  {
    cout<<jawaban[i]<<" ";
  }
}

void animasi_menang(){
	initscr();
	
	mvprintw(2, 39, "                                  ");
	mvprintw(3, 39, "                                  ");
	mvprintw(4, 39, "                                  ");
	mvprintw(11, 40, "                                 ");
	mvprintw(13, 42, "                                 ");
	mvprintw(13, 48, "                                 ");
	mvprintw(13, 52, "                                 ");
	mvprintw(13, 56, "                                 ");
	mvprintw(13, 59, "                                 ");
	
	mvprintw(20, 18, "Hore! Kamu telah menyelamatkan temanmu");
	refresh();
	Sleep(500);
	
	mvprintw(11, 18, "+____ __ ____+\n");
	mvprintw(12, 18, "|            |\n");
	
		mvprintw(13, 25, "O");
		refresh();
		Sleep(500);
		
		mvprintw(14, 25, "|");
		refresh();
		Sleep(500);	
		
		mvprintw(15, 24, "/");
		refresh();
		Sleep(500);
		
		mvprintw(15, 26, "\\");
		refresh();
		Sleep(500);	
		
			
for(int i=1; i <=3; i++){
		mvprintw(13, 24, "\\");
		refresh();
		Sleep(400);
		
		mvprintw(13, 26, "/");
		refresh();
		Sleep(400);	
		
		
		mvprintw(13, 24, " ");
		refresh();
		Sleep(50);
		
		mvprintw(13, 26, " ");
		refresh();
		Sleep(50);
		
		mvprintw(14, 24, "/");
		refresh();
		Sleep(400);	
		
		
		mvprintw(14, 26, "\\");
		refresh();
		Sleep(400);	
		
		mvprintw(14, 24, " ");
		refresh();
		Sleep(50);
		
		mvprintw(14, 26, " ");
		refresh();
		Sleep(50);
	
	}
	getch();
	endwin();
}
void ending(string jawaban, string soalkata){
	
	if(jawaban==soalkata){
		animasi_menang();

	}
	else{
		cout << "Yah, temanmu sudah digantung:( \n\n";
		
		cout << "	+____ __ ____+	\n";
		cout << "	|    \\  /    |	\n";
		cout << "	|      O     |	\n";
		cout << "	|      |     |	\n";
		cout << "	|     / \\    |	\n";
		cout << "	|            |	\n";
		cout << "	|            |	\n";
		cout << "Jumlah gagalmu sudah mencapai 4!" << endl; 
		cout << "TEMANMU SUDAH TERGANTUNG!!! KAMU SUDAH TIDAK PUNYA TEMAN LAGI\n\n";
		_getch();
		
	}
}

void menukategori(){
	
	kategori:
	
	cout << "Silakan Pilih kategori kata yang akan ditebak \n";
	cout << "[1] Binatang \n";
	cout << "[2] Buah \n";
	cout << "[3] Negara \n";
	cout << "[4] Kota \n";
	cout << "[5] Benua \n\n";
	
	char jwb_kategori;
	
	cout << "Kategori : ";cin >> jwb_kategori;
	system("cls");
	 
	
	if(jwb_kategori == '1'){
		soalkata = "komodo";
		kategorikata = kategori[0];
	}
	else if(jwb_kategori == '2'){
		soalkata = "pepaya";
		kategorikata = kategori[1];
	}
	else if(jwb_kategori == '3'){
		soalkata = "kanada";
		kategorikata = kategori[2];
	}
	else if(jwb_kategori == '4'){
		
		soalkata = "bekasi";
		kategorikata = kategori[3];
	}
	else if(jwb_kategori == '5'){
		
		soalkata = "afrika";
		kategorikata = kategori[4];
	}
	else{
		cout << "INPUTAN ANDA SALAH!!!"<< endl;
		cout << "TEKAN ENTER UNTUK KEMBALI KE MENU KATEGORI" << endl;
		_getch();
		system("cls");
		goto kategori;
	}
}

void ulang (){
	
	int process();
	char main_ulang;
	
	cout << "Apakah anda ingin bermain lagi? (y/n)" << endl;
	cin >> main_ulang;
	
	switch(main_ulang){
	
	case 'y':
		system("cls");
		menukategori();
		jawabanSalah.clear();
		process();
		break;
	case 'Y':
		system("cls");
		menukategori();
		jawabanSalah.clear();
		process();
		break;
	case 'n':
		system("cls");
		cout << "Terima Kasih Telah Memainkan Game ini";
		break;
	case 'N':
		system("cls");
		cout << "Terima Kasih Telah Memainkan Game ini";
		break;
	default:
		cout << "INPUTAN ANDA SALAH!\n";
		ulang();
}
	
}

int process(){
string jawaban = "______";
	int gagal = 0;
	bool tebakan = false;
	
	do {
		cout << "\nKATEGORI : " <<  kategorikata << endl << endl;
    jika_gagal(gagal);
    status_jawaban(jawabanSalah, jawaban);
	
    cout << "\n\nSilakan masukkan tebakan anda (per huruf) : ";
    cin >> jawaban_user;

    for(int i = 0; i<soalkata.length(); i++)
    {
      if(jawaban_user==soalkata[i])
      {
        jawaban[i] = jawaban_user;
        tebakan = true;
      }
    }
    if(tebakan)
    {
      system("cls");
      cout<<"\nBenar!\n";
    }
    else
    {
      system("cls");
      cout<<"\nJawaban Kamu Salah!\n";
      jawabanSalah.push_back(jawaban_user);
      gagal++;
    }
    tebakan = false;
}
while(jawaban!=soalkata && gagal < 4);

	ending(jawaban,soalkata);	
	ulang();
	
	return 0;
}


int main(){
	system("cls");
	loading();
	header();
	
	string jawaban = "______";
	int gagal = 0;
	bool tebakan = false;
	
	menukategori();
	
	process();
	return 0;
}
