#include <stdio.h>
#include <stdlib.h>


char ssid_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";
char SSID[256] = {0};
char system_cmd[256];
/*char SSID [256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";
  The mistake I made*/

int wpa_none(){

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	/*system("/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '"SSID"'");
	  The mistake I made*/
	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt NONE");
	system(system_cmd);
	system("/home/rtl/wpa_cli -iwlan0 enable_network 0");
	system("/home/rtl/wpa_cli -iwlan0 save_config");
	
	return 0;
}

	int wep_64(){	//WEP 64bit operation function

	}

int wpa_wep(){

	//int key_l;

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 wep_key0 '\"%s\"'";//WEP got four types, when password length equal 5 or 13 should provide '" "' for it
	char PWD[256] = {0};
	char system_pwd[256];

	/*printf("Select key length:\n 1. 64bit\n 2. 128bit\n");
	scanf("%d", &key_l);
		if(key_l == 1){
			//wep_64();
			return 0;
		}else if(key_l == 2){
			//wep_128();
			return 0;
		}else if(key_l >= 3 || key_l <= 0){
			printf("Error return back to last step\n");

			return wpa_wep();
		}
	*/

	printf("Write down Password:\n");
	scanf("%s", PWD);
	sprintf(system_pwd, pwd_set, PWD);

	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt NONE");
	system(system_cmd);
	system(system_pwd);
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 wep_tx_keyidx 0");
	system("/home/rtl/wpa_cli -iwlan0 enable_network 0");
	system("/home/rtl/wpa_cli -iwlan0 save_config");
	
	return 0;
}

int wpa_wpa2(){

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 psk '\"%s\"'";
	char PWD[256] = {0};
	char system_pwd[256];

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	printf("Write down Password:\n");
	scanf("%s", PWD);
	sprintf(system_pwd, pwd_set, PWD);

	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt WPA-PSK");
	system(system_cmd);
	system(system_pwd);
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 pairwise CCMP");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 group CCMP");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 proto RSN");
	system("/home/rtl/wpa_cli -iwlan0 enable_network 0");
	system("/home/rtl/wpa_cli -iwlan0 save_config");

	return 0;
}

int wpa_mix(){

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 psk '\"%s\"'";
	char PWD[256] = {0};
	char system_pwd[256];

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	printf("Write down Password:\n");
	scanf("%s", PWD);
	sprintf(system_pwd, pwd_set, PWD);

	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt WPA-PSK");
	system(system_cmd);
	system(system_pwd);
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 pairwise CCMP TKIP");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 group CCMP TKIP");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 proto WPA RSN");
	system("/home/rtl/wpa_cli -iwlan0 enable_network 0");
	system("/home/rtl/wpa_cli -iwlan0 save_config");

	return 0;
}

int main(void){

	int Stype;
	int keyl;

	printf("Select your Wifi Security Type: \n 1.None Mode\n 2.WEP Mode\n 3.WPA2 Mode\n 4.MIX Mode\n");
	scanf("%d", &Stype);

	if(Stype == 1){

		wpa_none();

	}else if(Stype == 2){

		wpa_wep();

	}else if(Stype == 3){

		wpa_wpa2();

	}else if(Stype == 4){
	
		wpa_mix();
	
	}else if(Stype >= 5 || Stype <= 0){
	
		printf("Error!!\n");
	
	}


	return 0;

}
