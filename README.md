__cll means "C Language Learning". So this `repo` only build for record C traning.__

# Table of Contents

- [test01](#test01)
- [Homework](#homework)
  - [hw_01_wifiset](#hw_01_wifiset)
  - [hw_02_getstate](#hw_02_getstate)
  - [hw_03_wpstate](#hw_03_wpstate)
- [Function Tool & Library Practice](#function-tool-&-library-practice)
  - [delay_tool](#delay_tool)

## test01

Only for testing

# Homework

## hw_01_wifiset

__Demo board wifi function setting.__

This is first C language homework from my tutor Daniel. "It is the fastest way for you to familiar our job!" he said. 
So.... let's do this!!

According to WPA Security types. This program gonna divides in four-parts to control/set Wifi Connection of the Demo Board.
```
  1. None Mode
  2. WEP Mode
  3. WPA2 Mode
  4. MIX Mode
```

## hw_02_getstate

__Show wifi status.__

After done the [`hw_01_wifiset`](#hw_01_wifiset). It can possible set the wifi connect detail. So next, I build `hw_02_getstate.c` to show the wifi connection status let user know.
  * Step 1. Let system build the `.txt` file to record wifi status by commend line.
```
  system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
```

  * Step 2. Try to get the string from TXT file I build. I used function `fopen`, `fgets` and ` fclose`.

Function `fopen` should write as `fopen(" file locate ", " r(read) or w(write) ");` to open the file.
```
  FILE *fpr;    //
  fpr=fopen("/tmp/status.txt", "r");
```

And then let function `fgets` get the string. it should write as `fgets(buffer, buffer length, from where);`
```
  fgets(wifi_status, 256, fpr);
```

But `fgets` only can get string from first line. So I build a while loop to collect all information.
```
  while(fgets(wifi_status, 256, fpr) != NULL){
  }
```

End here, It can get whole wifi status information string. But the output only needs wifi wpa state, which is COMPLETE, SCANNING...etc. So 

## hw_03_wpstate

# Function Tool & Library Practice

__Record the C library practice and some useful function I was design__

## delay_tool

Library include `time.h`.

When I was practice to design the
