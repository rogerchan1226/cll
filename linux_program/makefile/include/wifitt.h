#ifndef WIFI_CONNECTING
#define WIFI_CONNECTING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define CLEAR_BUF \
    {\
    int ch;\
	while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ;\
        }\
    }


/* WPA CONNECT FUNCTION */
/* hw_01_wifiset.c */
int wpa_f();
int wpa_none();
int wpa_wep();
int wpa_wpa2();
int wpa_mix();
int wpa_wpa2_aes();
int wpa_wpa2_tkip();
int hex_scan();

/* WIFI CONNECTION STATE */
/* hw_02_getstate.c */
int wifi_state();

/* PSK CONNECT FUNCTION */
/* hw_03_wpstate.c */
int get_state();
int delay();
int timer();
int wps_pbc();
int wps_pin();
int psk_f();


#endif 