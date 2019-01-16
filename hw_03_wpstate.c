#include <stdio.h>
#include <stdlib.h>



int timer(){
	int countdown = 30;

	while(countdown != 0){
		printf("%d\n", countdown);
		countdown --;

	}
	return 0;
}

int wps_pbc(){
	int v;

	system("/home/rtl/wpa_cli -iwlan0 wps_pbc");
	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");

	v= timer();
	return 0;
}

int wps_pin(){
	return 0;
}

int main(){
	int wps_t;

	while(1){
		printf("Select wps type:\n 1.pbc\n 2.pin\n");
		scanf("%d", &wps_t);
		if(wps_t ==1){
			wps_pbc();
			break;

		}else if(wps_t ==2){
			wps_pin();
			break;

		}else if(wps_t <=0 || wps_t >=3){
			printf("Error!!\n");
			continue;

		}
	}
	return 0;
}