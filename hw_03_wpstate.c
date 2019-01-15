#include <stdio.h>




int wps_pbc(){
	system("/home/rtl/wpa_cli -iwlan0 wps_pbc");
	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
	
}

int wps_pin(){

}

int main(){
	int wps_t;

	for{
		printf("Select wps type:\n 1.pbc\n 2.pin");
		scanf("%d", wps_t);
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