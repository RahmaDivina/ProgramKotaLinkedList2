	/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "spnrsll.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define NAMA 50 
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "spnrsll.h"
#include "bodynrsl.cpp"

void Menu();

int main(){
	/* Kamus Lokal */
		NodeKota kota;
		int i;
		int pilihMenu;
		int pilihanList;
		infotype X;
		addressK cari;

	/* Program */
	
	
	CreateList (&kota);
	do{
		system("cls");
		Menu();
		scanf("%d",&pilihMenu);

		switch(pilihMenu){
			case 1 :{ 
				X = AlokasiInfotype();
				printf("Inputkan Nama Kota : ");
				scanf("%s",X);	
					if(Searchkota(kota, X) == Nil){
						InsVLast(&kota,X);		
						printf("\nKota %s Berhasil Dibuat\n", X);
					}
					else{		
						printf("Sudah Terdapat Kota Pada Nomor Tersebut !");		
					}
				break;
				InsVLast(&kota, X);
        		printf("\nKota %s Berhasil Dibuat\n", X);
				getch();
				system("cls");			
				break;
		}
			case 2 : {
				
				printf("Inputkan Nama Kota Yang Akan Ditambah Warga : ");
				infotype namaKota = AlokasiInfotype();
				scanf("%s", namaKota);
				
				cari = Searchkota(kota,namaKota);
				if (cari == Nil) {
        			printf("Kota Tidak Ditemukan !");            
    			}
    			else{
    				printf("Masukan Nama Warga : ");
					X = AlokasiInfotype();
					scanf("%s",X);
					InsVFirst(cari,X);
					printf("Warga Berhasil Ditambahkan Ke %s.\n", namaKota);
				}
				getch();	
				system("cls");	
				break;
		}
			case 3 :{ 
				printf("Inputkan Nama Kota Yang Akan Di Hapus : "); 
				X = AlokasiInfotype();
				scanf("%s",X);
				
					if(kota.First != Nil){
						printf("Kota %s Berhasil Dihapus !",X);
						DelKota(&kota, X);
					}
					else{
						printf("Kota Tidak Ada, Tidak Perlu Dihapus !");
					}
				getch();		
				break;
		}
			case 4 : {
				printf("Masukkan Nama Kota Dari Warga Yang Akan Di Hapus : ");
				X = AlokasiInfotype();
				scanf("%s",X);
				
				
					cari = Searchkota(kota, X);
					if(cari == Nil){
						printf("Kota Tidak Ada, Tidak Perlu Dihapus !");
					}
					else{
						X = AlokasiInfotype();
						printf("Masukan Nama Warga Yang Akan Dihapus : ");
						scanf("%s",X);
						DelP(cari, X);
                		printf("Warga Dengan Nama %s Berhasil Dihapus Dari Kota %s\n", X, cari->namaKota);
					}
				getch();		
				break;
			}
			case 5 : {
					PrintKota(kota);
				getch();
				break;
			}	
			case 6 :{
				printf("Anda Telah Keluar Dari Program !");
				break;
			}
				
			default : printf("Masukan Insert Yang Valid!");
			break;
		}

		}while(pilihMenu != 6);
}


void Menu(){
	printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	printf("\n               Program Kota                ");
	printf("\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
	printf("1. Tambah Kota\n");
	printf("2. Tambah Warga Baru\n");
	printf("3. Hapus Kota\n");
	printf("4. Hapus Warga\n");
	printf("5. Tampilkan Seluruh Informasi Kota\n");
	printf("6. Keluar Program");

	printf("\n\nMasukkan pilihanmu : ");
}

