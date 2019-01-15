#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	
	char *front;
	//char *end;
	FILE *fpr;
	char wifi_status[256]={0};
	
	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
	fpr=fopen("/tmp/status.txt", "r");	//r = read!!!
	while(fgets(wifi_status, 256, fpr) != NULL){
		int state_buffer = strncmp(wifi_status, "wpa_state=", 10);	//***

		if(state_buffer == 0){
			front = strstr(wifi_status, "wpa_state=");
			front += strlen("wpa_state=");		//***
			//end = strstr(front, "\n");
			//memset(wifi_status, '\0', 256);
			//strncpy(wifi_status, front, end-front);
			printf("%s", front);
			break;			
		}else{
			continue;
		}
	}
	fclose(fpr);

	return 0;

}