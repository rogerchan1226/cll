#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
	char wifi_status[25]={0};
	char strbuff [25];
	char *p;
	char *q;

	FILE *fpr;

	system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
	fpr=fopen("/tmp/status.txt", "w");

	fscanf(fpr, "%s", wifi_status);
	

	//p = strstr(strbuff, "wpa_state=");
	//int i=0;

	//p += strlen("wpa_state=");
	
	//q=strstr(p,"\n");

	//strncpy(wifi_status, p, q-p);

	printf("%s\n", wifi_status);
	fclose(fpr);
	

	
	
	return 0;

}