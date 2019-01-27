### cll means "C Language Learning". So this `repo` only build for record my C traning.

# Table of Contents

- [test01](#test01)
- [Homework](#homework)
  - [hw_01_wifiset](#hw_01_wifiset)
  - [hw_02_getstate](#hw_02_getstate)
  - [hw_03_wpstate](#hw_03_wpstate)
- [Function Tool & Library Practice](#function-tool-&-library-practice)
  - [delay_tool](#delay_tool)

## test01

__Only for testing__

# Homework
### Practice by project

## hw_01_wifiset

__Demo board wifi function setting.__

This is first C language homework from my tutor Daniel. 
"It is the fastest way for you to familiar our job!" he said. 
So.... let's do this!!

According to WPA Security types. 
This program gonna divides in four-parts to control/set Wifi Connection of the Demo Board.
```
  1. None Mode
  2. WEP Mode
  3. WPA2 Mode
  4. MIX Mode
```

## hw_02_getstate

__Show wifi status.__

After done the [`hw_01_wifiset`](#hw_01_wifiset). It can possible set the wifi connect detail. 
So next, I build `hw_02_getstate.c` to show the wifi connection status let user know.
  * Step 1. Let system build the `.txt` file to record wifi status by commend line.
```
  system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
```

  * Step 2. Try to get the string from TXT file I build. 
  I used function `fopen`, `fgets` and ` fclose`.

Function `fopen` should write as `fopen(" file locate ", " r(read) or w(write) ");` to open the file.
```
  FILE *fpr;    //
  fpr=fopen("/tmp/status.txt", "r");
```

And then let function `fgets` get the string. 
it should write as `fgets(buffer, buffer length, from where);`
```
  fgets(wifi_status, 256, fpr);
```

But `fgets` only can get string from first line. 
So I build a while loop to collect all information.
```
  while(fgets(wifi_status, 256, fpr) != NULL){
  }
```

End here, It can get whole wifi status information string. 
But the output only needs wifi wpa state, which is COMPLETE, SCANNING...etc. 
So 

## hw_03_wpstate

# Function Tool & Library Practice

### Record the C library practice and some useful function I was design

## delay_tool

__Library include `time.h`.__

When I was practice to design the wifi WPS security function, 
it need a countdown timer to let user to know how much secound it left and it Compelete connect or not. 
So I figered out by making a delay function as below.
```
int delay(unsigned int secs){      	        //Set the function name as "delay". and get the input seconds from other function
	int time_count = time(0) + secs;        //time(0) equal time(NULL), it means start counting time as seconds from 1/1/1970 0:00
	while (time(0) < time_count);           //time(0) will start counting by second until it equal time_count
	return 0;                               //Return back
}
```
End now every function can set the delay by this delay function. for example:
```
int main(){
  delay(11);
  printf("hello word\n");
  return 0;
}
```
It will print `hello world` after eleven seconds from the beginning of program.<br>
In file `delay_tool.c` I create two types timer by using this delay function.
