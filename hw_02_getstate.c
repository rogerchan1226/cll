#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	
	//char *p;
	//char *q;
	FILE *fpr;
	//int i;
	char wifi_status[256]={0};
	//char state_string[256]="wpa_state=";
	//char strbuff[25]={0};
	
	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
	fpr=fopen("/tmp/status.txt", "r");
	while(fgets(wifi_status, 256, fpr) != NULL){
		int state_buffer = strncmp(wifi_status, "wpa_state=", 10);
	//p = strstr(strbuff, "wpa_state=");
	//p += strlen("wpa_state=");	
	//q=strstr(p,"\n");
	//strncpy(wifi_status, p, q-p);
		if(state_buffer == 0){
			printf("%s", wifi_status);
			break;
			
		}else {
			continue;
		}
	}
	fclose(fpr);

	return 0;

}