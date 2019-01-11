#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
/* //function wrong
	int wep_64(){	//WEP 64bit operation function

		if(key_f == 1){


		}else{

		}
		return 0;
	}

	int wep_128(){	//WEP 128bit operation function
		return 0;
	}
*/
int wpa_wep(){

	int key_l;
	int key_f;
	int i;

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 wep_key0 '\"%s\"'";//WEP got four types, when password length equal 5 or 13 should provide '" "' for it
	char system_pwd[256];
	char PWD[256] = {0};

	do{
		printf("Select key length:\n 1. 64bit\n 2. 128bit\n");
		scanf("%d", &key_l);
	}while(key_l <= 0 || key_l >= 3);/*{
		printf("Error return to last step!!\n");
	}*/
	do{
		printf("Select key format:\n 1. Hexadecimal\n 2. ASCII\n");
		scanf("%d", &key_f);
	}while(key_f <= 0 || key_f >= 3);

	if(key_l == 1){
		//wep_64();
		if(key_f == 1){

			do{
				printf("Write down 10 words as Password:\n");
				scanf("%s", PWD);
			}while(strlen(PWD) != 10);
			
		}else{

			do{
				printf("Write down 5 words as Password:\n");
				scanf("%s", PWD);
			}while(strlen(PWD) != 5);
			
		}

	}else{
		//wep_128();
		if(key_f == 1){
			
			do{
				printf("Write down 26 words as Password:\n");
				scanf("%s", PWD);
			}while(strlen(PWD) != 26);
			
		}else{

			do{
				printf("Write down 13 words as Password:\n");
				scanf("%s", PWD);
			}while(strlen(PWD) != 13);
			
		}
	}

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
