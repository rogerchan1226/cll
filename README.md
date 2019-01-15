# cll
cll means "C Language Learning". So this `repo` only build for record C traning.

### 1. test01.c 

Only for testing

### 2. hw_01_wifiset.c

__Demo board wifi function setting.__

This is first C language homework from my tutor Daniel. "It is the fastest way for you to fimiler our job!" he said. 
So.... let's do this!!

According to WPA Security types. This program ganna divides in four-parts to control/set Wifi Connection of the Demo Board.
```
  1. None Mode
  2. WEP Mode
  3. WPA2 Mode
  4. MIX Mode
```

### 3. hw_02_getstate.c

* Show wifi status.

After done the `hw_01_wifiset`. It can possible set the wifi connect detail. So next, I build `hw_02_getstate.c` to get the wifi connection status let user know.

  * Step 1. Let system build the `.txt` to record wifi status by commend line.
```
  system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
```

  * Step 2. Try to get the string from TXT file we builded. I used function `fopen`, `fget` and ` fclose`.

Function `fopen` should write as `fopen(" file locate ", " r(read) or w(write) ");`
```
FILE *fpr;    //
fpr=fopen("/tmp/status.txt", "r");
```
