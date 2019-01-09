#include <stdio.h>
#include <stdlib.h>


int wpa_none(){
	char SSID [256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";

	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt NONE");
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

int main(){

	int Stype;
	int SSID;

	printf("Select your Wifi Security Type: \n 1.None Mode\n 2.WEP\n 3.WPA\n 4.MIX\n");
	scanf("%d", &Stype);

	if(Stype == 1){

		printf("Write down SSID:\n");
		scanf("%s", &SSID);
		wpa_none();

	}else if{

		wpa_wep();

	}else if{

		wpa_wpa();

	}else if{
	
		wpa_mix();
	
	}

	return 0;

}
