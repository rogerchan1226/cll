#include <stdio.h>
#include <errno.h>
#include "wifitt.h"


int main(){
	int wcf;
	int i;
	//int res;

	while(1){
		printf("Select WIFI Connect Function:\n  1. WPA\n  2. PSK\n");
		scanf("%d", &wcf);
		CLEAR_BUF 
		/*printf("%d\n", res);
		if(res !=1){
			printf("%d\n", errno);
			continue;
		}*/

		if(wcf == 1){
			wpa_f();
			printf("Try to Connecting.....PLEASE WAIT\n");
			delay(10);
			i = wifi_state();
			if(i==1){
				break;
			}
			printf("Connect Fail Please Retry!!\n");
			continue;

		}else if(wcf == 2){
			psk_f();
			break;

		}else{
			printf("Select Fail, Please Enter 1 or 2 Only!!\n");
			continue;
		}
	}
	return 0;
}