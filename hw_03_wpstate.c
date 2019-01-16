#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int delay(unsigned int secs) {
	int retTime = time(0) + secs;   
	while (time(0) < retTime);               
}

int timer(wps_t){
	unsigned char *front;
	unsigned char *pin;
	FILE *fpr=NULL;
	unsigned int start_t;
	unsigned long tm_sec = 180;
	unsigned char wifi_status[256]={0};
	unsigned char wifi_pin[15]={0};
	//clock_t start = clock();
	//printf("%s:%d\n",__func__,__LINE__);

	for(start_t=0; start_t < tm_sec; start_t++){
		system("clear");
		if(wps_t==2){
			fpr=fopen("/tmp/pin.txt", "r");
			fgets(wifi_pin, 256, fpr);
			printf("%s\n", wifi_pin);
			fclose(fpr);
		}
		//printf("%s:%d\n",__func__,__LINE__);
		system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
		//printf("%s:%d\n",__func__,__LINE__);
		//printf("%ld", end_t-start_t);
		//clock_t end = (clock()-start) / CLOCKS_PER_SEC;
		//msec = end * 1000 / CLOCKS_PER_SEC;
		printf("%ld\n", tm_sec-start_t);

		//printf("%s:%d\n",__func__,__LINE__);
		fpr=fopen("/tmp/status.txt", "r");
		while(fgets(wifi_status, 256, fpr) != NULL){

			//printf("%s:%d\n",__func__,__LINE__);
			unsigned int state_buffer = strncmp(wifi_status, "wpa_state=", 10);	//***

			if(state_buffer == 0){
				//printf("%s:%d\n",__func__,__LINE__);
				front = strstr(wifi_status, "wpa_state=");		//strstr = search string
				front += strlen("wpa_state=");
				fclose(fpr);
				break;
						
			}
			//printf("%s:%d\n",__func__,__LINE__);
			continue;
			
		}
		if(strncmp(front, "COMPLETED\n", 8)==0){
			printf("%s", front);
			//printf("%s:%d\n",__func__,__LINE__);
			return 1;

		}else if(/*strncmp(front, "DISCONNECTED\n", 10)==0 ||*/ strncmp(front, "INACTIVE\n", 8)==0){
			printf("%s", front);
			return 0;
					
		}else{
			printf("%s", front);
			delay(1);
			continue;
						
		}
		//printf("%s:%d\n",__func__,__LINE__);
		//tm_sec --;
	}
	return 0;
}

int wps_pbc(){
	int v;

	system("/home/rtl/wpa_cli -iwlan0 wps_pbc");
	delay(3);
	v= timer();
	if(v==0){
		printf("Connnect Fail!!\n");
	}else{
		printf("Device Connecting!!\n");
		system("/home/rtl/wpa_cli -iwlan0 save_config");
	}
	return 0;
}

int wps_pin(){
	int v;

	system("/home/rtl/wpa_cli -iwlan0 wps_pin any > /tmp/pin.txt");
	//delay(3);
	v= timer();
	if(v==0){
		printf("Connnect Fail!!\n");
		system("rm /tmp/pin.txt");
	}else{
		printf("Device Connecting!!\n");
		system("rm /tmp/pin.txt");
		system("/home/rtl/wpa_cli -iwlan0 save_config");
	}
	return 0;
}

int main(int argc, char *argv[]){
	int wps_t;

	system("/home/rtl/wpa_cli -iwlan0 disconnect");
	system("/home/rtl/wpa_cli -iwlan0 remove_network all");
	while(1){
		printf("Select wps type:\n 1.pbc\n 2.pin\n");
		scanf("%d", &wps_t);
		if(wps_t ==1){
			wps_pbc(wps_t);
			break;

		}else if(wps_t ==2){
			wps_pin(wps_t);
			break;

		}else if(wps_t <=0 || wps_t >=3){
			printf("Error!!\n");
			continue;

		}
	}
	return 0;
}