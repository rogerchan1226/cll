#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int wifi_state(){
	
	char *front;
	FILE *fpr;
	char wifi_status[256]={0};
	
	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
	fpr=fopen("/tmp/status.txt", "r");	//r = read!!!
	while(fgets(wifi_status, 256, fpr) != NULL){
		int state_buffer = strncmp(wifi_status, "wpa_state=", 10);	//***

		if(state_buffer == 0){
			front = strstr(wifi_status, "wpa_state=");		//strstr = search string
			front += strlen("wpa_state=");
			printf("%s", front);
			int front_buffer = strncmp(front, "COMPLETED", 9);
			if(front_buffer == 0){
				return 1;
			}
			break;

		}else{
			continue;
		}
	}
	fclose(fpr);

	return 0;

}