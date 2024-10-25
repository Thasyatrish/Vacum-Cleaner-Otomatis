#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* Nama  : Anasthasya Ivani trishardiono
   Nim   : 2602092421
   Kelas : LB20
   Tema  : Vaccum Cleaner
*/

#include <string.h>
#include <windows.h>

void garbage(){
	while(1){
	SYSTEM_POWER_STATUS status;
	if (GetSystemPowerStatus(&status)){
		printf("\nStorage Available : %d%%\n", status.BatteryLifePercent);
		}
		else{
			printf("Failed to Detect Storage\n"); //Jika wadah tidak terdeteksi
		}
			if(status.BatteryLifePercent >= 50)
		printf("\nPlease Clean First\n");
			else if(status.BatteryLifePercent <= 50)
			printf("\nReady\n");
		Sleep(10000);
	}
	
}
// System battery menampilkan baterai laptop dan printf(output) untuk menampilkan suruhan
void battery(){

	while(1){
	SYSTEM_POWER_STATUS status;
	if (GetSystemPowerStatus(&status)){
		printf("\nBattery level : %d%%\n", status.BatteryLifePercent);
		}
		else{
			printf("Failed to get battery status\n");
		}
			if(status.BatteryLifePercent >= 50)
		printf("\nReady\n");
			else if(status.BatteryLifePercent <= 50)
			printf("\nPlease Charge\n");
		Sleep(10000);
	}
}

void timer(){		 
	unsigned int x_hours=0;
	unsigned int x_minutes=0;
	unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;

	printf("Please Input Timer (Second) : ");
	scanf("%d", &count_down_time_in_secs);
	clock_t x_startTime,x_countTime;
//	count_down_time_in_secs=60;  // 1 minute is 60, 1 hour is 3600

 
    x_startTime=clock();  // start clock
    time_left=count_down_time_in_secs-x_seconds;   // update timer

	while (time_left>0) 
	{
		x_countTime=clock(); // update timer difference
		x_milliseconds=x_countTime-x_startTime;
		x_seconds=(x_milliseconds/(CLOCKS_PER_SEC))-(x_minutes*60);
		x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
		x_hours=x_minutes/60;

time_left=count_down_time_in_secs-x_seconds; // subtract to get difference 


		printf( "\nYou have %d seconds left ( %d ) count down",time_left,count_down_time_in_secs);
	}


	printf( "\n\n\nTime's Out, Turning OFF'\n\n\n");

}

int main(){
	int pilihan;
	int check = 0;
do{
    printf("Click 2 times to turn ON");
    getc(stdin);
    getc(stdin);
    printf("ON");
    printf("\t\n\n=========Choose Menu=========\n");
    printf("<1> Set Timer\n");
    printf("<2> Check battery\n");
    printf("<3> Check Garbage\n");
    printf("<0> Turn off\n");
//    printf("click 3 more time to Turn OFF\n\n");
    printf("PILIH MENU : ");
	scanf("%d", &pilihan); 
    switch(pilihan){
	
    case 1:
    	timer();
 		break; 
    case 2:
    	battery();
    	break;
    case 3:
    	garbage();
    	break;
	}
	
	}while(pilihan != 0);
} 


