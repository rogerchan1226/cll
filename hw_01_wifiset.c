#include <stdio.h>
#include <stdlib.h>


int wpa_none()
{
	return 0;
}

int main(){

	int Stype;

	printf("Select your Wifi Security Type: \n 1.None Mode\n 2.WEP\n 3.WPA\n 4.MIX\n");
	scanf("%d", &Stype);

	if(Stype == 1)
		wpa_none();
	
	else if ()


	exit (0);

}
