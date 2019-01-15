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

__Show wifi status.__

After done the `hw_01_wifiset`. It can possible set the wifi connect detail. So next, I build `hw_02_getstate.c` to get the wifi connection status let user know.

  * Step 1. Let system build the `.txt` file to record wifi status by commend line.
```
  system("/home/rtl/wpa_cli -iwlan0 status > /tmp/status.txt");
```

  * Step 2. Try to get the string from TXT file I builded. I used function `fopen`, `fget` and ` fclose`.

Function `fopen` should write as `fopen(" file locate ", " r(read) or w(write) ");` to open the file.
```
  FILE *fpr;    //
  fpr=fopen("/tmp/status.txt", "r");
```

And then let function `fget` get the string. it should write as `fget(buffer, buffer length, from where)`
```
  fgets(wifi_status, 256, fpr);
```

But `fget` only can get string from first line. So I build a while loop to collect all informations.
```
  while(fgets(wifi_status, 256, fpr) != NULL){
  }
```

End here, I can get whole wifi status informations string. But the output only needs wifi wpa state, which is CONPLETE, SCANNING...etc. So 
