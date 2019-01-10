#include <stdio.h>
#include <stdlib.h>


int wpa_none(){

	char ssid_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";
	char SSID[256] = {0};
	char system_cmd[256];
	//char SSID [256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	
	//system("/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '"SSID"'");
	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt NONE");
	system(system_cmd);
	system("/home/rtl/wpa_cli -iwlan0 enable_network 0");
	system("/home/rtl/wpa_cli -iwlan0 save_config");
	
	return 0;
}

int wpa_wep(){
	return 0;
}

int wpa_wpa(){
	return 0;
}

int wpa_mix(){
	return 0;
}

int main(void){

	int Stype;

	printf("Select your Wifi Security Type: \n 1.None Mode\n 2.WEP Mode\n 3.WPA Mode\n 4.MIX Mode\n");
	scanf("%d", &Stype);

	if(Stype == 1){

		wpa_none();

	}else if(Stype == 2){

		wpa_wep();

	}else if(Stype == 3){

		wpa_wpa();

	}else if(Stype == 4){
	
		wpa_mix();
	
	}else if(Stype >= 5 || Stype <= 0){
	
		printf("Error!!\n");
	
	}


	return 0;

}
