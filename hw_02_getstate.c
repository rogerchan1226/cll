#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
	
	//char *p;
	//char *q;
	FILE *fpr;
	//int i;
	char wifi_status[256]={0};
	//char strbuff[25]={0};
	
	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
	fpr=fopen("/tmp/status.txt", "r");
	while(fgets(wifi_status, 256, fpr) != NULL){
	//p = strstr(strbuff, "wpa_state=");
	//p += strlen("wpa_state=");	
	//q=strstr(p,"\n");
	//strncpy(wifi_status, p, q-p);
		printf("%s", wifi_status);
	}
	fclose(fpr);

	return 0;

}