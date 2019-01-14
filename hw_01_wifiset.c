#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char ssid_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";
char SSID[256] = {0};
char system_cmd[256];
/*char SSID [256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 ssid '\"%s\"'";
  The mistake I made*/

int hex_scan(char *PWD){

	int i;
	for (i=0; PWD[i]; i++){
		if(isxdigit(PWD[i])){
			continue;
		}else{
			return 0;
		}	
	}
		return 1;
}

int wpa_wpa2_aes(){

	int key_f;
	int v;

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 psk '\"%s\"'";
	char PWD[256] = {0};
	char system_pwd[256];

	do{
		printf("Select key format:\n 1. Hexadecimal\n 2. ASCII\n");
		scanf("%d", &key_f);
	}while(key_f <= 0 || key_f >= 3);

	if(key_f == 1){		
		while(1){
			memset (PWD, '0', 256);	//clean the buffer
			printf("Write down 64 words as Password:\n");
			scanf("%s", PWD);

			if(strlen(PWD) != 64){
				printf("Password ERROR.\nPlease enter exactly 64 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
				continue;
			}else{
				v= hex_scan(PWD);	//64 <=> length()
				if(v==0){
					printf("Password ERROR.\nPlease enter exactly 64 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
					continue;
				}
				break;
			}				
		}
	}else{
		while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 8 ~ 63 words as Password:\n");
				scanf("%s", PWD);
				if(strlen(PWD) <= 7 && strlen(PWD) >= 64){
					printf("Password ERROR.\nPlease enter exactly 8 ~ 63 words.\n");
					continue;
				}else{
					if(isascii(PWD[0])){	//ascii verification
						break;
					}else{
						printf("Password ERROR.\nPlease enter exactly 8 ~ 63 words.\n");
						continue;
					}
				}
		}
	}

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

int wpa_wpa2_tkip(){

	int key_f;
	int v;

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 psk '\"%s\"'";
	char PWD[256] = {0};
	char system_pwd[256];

	do{
		printf("Select key format:\n 1. Hexadecimal\n 2. ASCII\n");
		scanf("%d", &key_f);
	}while(key_f <= 0 || key_f >= 3);

	if(key_f == 1){		
		while(1){
			memset (PWD, '0', 256);	//clean the buffer
			printf("Write down 64 words as Password:\n");
			scanf("%s", PWD);

			if(strlen(PWD) != 64){
				printf("Password ERROR.\nPlease enter exactly 64 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
				continue;
			}else{
				v= hex_scan(PWD);	//64 <=> length()
				if(v==0){
					printf("Password ERROR.\nPlease enter exactly 64 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
					continue;
				}
				break;
			}				
		}
	}else{
		while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 8 ~ 63 words as Password:\n");
				scanf("%s", PWD);
				if(strlen(PWD) <= 7 && strlen(PWD) >= 64){
					printf("Password ERROR.\nPlease enter exactly 8 ~ 63 words.\n");
					continue;
				}else{
					if(isascii(PWD[0])){	//ascii verification
						break;
					}else{
						printf("Password ERROR.\nPlease enter exactly 8 ~ 63 words.\n");
						continue;
					}
				}
		}
	}

	sprintf(system_pwd, pwd_set, PWD);

	system("/home/rtl/wpa_cli -iwlan0 remove_network 0");
	system("/home/rtl/wpa_cli -iwlan0 add_network 0");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 key_mgmt WPA-PSK");
	system(system_cmd);
	system(system_pwd);
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 pairwise TKIP");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 group TKIP");
	system("/home/rtl/wpa_cli -iwlan0 set_network 0 proto RSN");
	system("/home/rtl/wpa_cli -iwlan0 enable_network 0");
	system("/home/rtl/wpa_cli -iwlan0 save_config");

	return 0;

}

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
	int v;

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
			while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 10 words as Password:\n");
				scanf("%s", PWD);

				if(strlen(PWD) != 10){
					printf("Password ERROR.\nPlease enter exactly 10 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
					continue;
				}else{
					v= hex_scan(PWD);	//64 <=> length()
					if(v==0){
						printf("Password ERROR.\nPlease enter exactly 10 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
						continue;
					}
					break;
				}				
			}		
		}else{
			while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 5 words as Password:\n");
				scanf("%s", PWD);
				if(strlen(PWD) != 5){
					printf("Password ERROR.\nPlease enter exactly 5 words.\n");
					continue;
				}else{
					if(isascii(PWD[0])){	//ascii verification
						break;
					}else{
						printf("Password ERROR.\nPlease enter exactly 5 words.\n");
						continue;
					}
				}
			}			
		}

	}else{
		//wep_128();
		if(key_f == 1){			
			while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 26 words as Password:\n");
				scanf("%s", PWD);

				if(strlen(PWD) != 26){
					printf("Password ERROR.\nPlease enter exactly 26 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
					continue;
				}else{
					v= hex_scan(PWD);	//64 <=> length()
					if(v==0){
						printf("Password ERROR.\nPlease enter exactly 26 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
						continue;
					}
					break;
				}			
			}	
		}else{
			while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 13 words as Password:\n");
				scanf("%s", PWD);

				if(strlen(PWD) != 13){
					printf("Password ERROR.\nPlease enter exactly 13 words.\n");
					continue;
				}else{
					if(isascii(PWD[0])){	//ascii verification
						break;
					}else{
						printf("Password ERROR.\nPlease enter exactly 13 words.\n");
						continue;
					}
				}
			}			
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

	int s_mode;

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	do{
		printf("Select Security Mode:\n 1. AES\n 2. TKIP\n");
		scanf("%d", &s_mode);
	}while(s_mode <= 0 || s_mode >= 3);

	if(s_mode == 1){
		wpa_wpa2_aes();
	}else{
		wpa_wpa2_tkip();
	}

}

int wpa_mix(){

	int key_f;
	int v;

	char pwd_set[256] = "/home/rtl/wpa_cli -iwlan0 set_network 0 psk '\"%s\"'";
	char PWD[256] = {0};
	char system_pwd[256];

	printf("Write down SSID:\n");
	scanf("%s", SSID);
	sprintf(system_cmd, ssid_set, SSID);

	do{
		printf("Select key format:\n 1. Hexadecimal\n 2. ASCII\n");
		scanf("%d", &key_f);
	}while(key_f <= 0 || key_f >= 3);

	if(key_f == 1){		
		while(1){
			memset (PWD, '0', 256);	//clean the buffer
			printf("Write down 64 words as Password:\n");
			scanf("%s", PWD);

			if(strlen(PWD) != 64){
				printf("Password ERROR.\nPlease enter exactly 64 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
				continue;
			}else{
				v= hex_scan(PWD);	//64 <=> length()
				if(v==0){
					printf("Password ERROR.\nPlease enter exactly 64 words.\nAnd 'a-f', 'A-F', '0-9' only.\n");
					continue;
				}
				break;
			}				
		}
	}else{
		while(1){
				memset (PWD, '0', 256);	//clean the buffer
				printf("Write down 8 ~ 63 words as Password:\n");
				scanf("%s", PWD);
				if(strlen(PWD) <= 7 && strlen(PWD) >= 64){
					printf("Password ERROR.\nPlease enter exactly 8 ~ 63 words.\n");
					continue;
				}else{
					if(isascii(PWD[0])){	//ascii verification
						break;
					}else{
						printf("Password ERROR.\nPlease enter exactly 8 ~ 63 words.\n");
						continue;
					}
				}
		}
	}		

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
