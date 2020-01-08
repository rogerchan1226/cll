/*
 *
 *  Leetcode:
 *      Runtime: 8 ms
 *      Memory Usage: 7 MB
 * 
 */ 


#include <stdio.h>
#include <string.h>





int romanToInt(char * s){
    int i = 0,
        result = 0;

    for(i = strlen(s)-1; i >= 0; i--){
        if (s[i] == 0x49){
            result = result + 1;
            continue;
        }
        
        if (s[i] == 0x56){
            if(i > 0){
                i--;
                if (s[i] == 0x49){
                    result = result + 4;
                    continue;
                }else if (s[i] == 0x56 && i != 0){
                    result = result + 5;
                    i++;
                    continue;
                }else if (s[i] == 0x56 && i != 0){
                    result = result + 10;
                    break;
                }
            }
            result = result + 5; 
        }
        
        if (s[i] == 0x58){
            if(i > 0){
                i--;
                if (s[i] == 0x49){
                    result = result + 9;
                    continue;        
                }else if (s[i] == 0x58 && i != 0){
                    result = result + 10;
                    i++;
                    continue;
                }else if (s[i] == 0x58 && i == 0){
                    result = result + 20;
                    break;
                }
            }
            result = result + 10;
        }
        
        if (s[i] == 0x4C){
            if(i > 0){
                i--;
                if (s[i] == 0x58){
                    result = result + 40;
                    continue;
                }else if (s[i] == 0x4C && i != 0){
                    result = result + 50;
                    i++;
                    continue;
                }else if (s[i] == 0x4C && i == 0){
                    result = result + 100;
                    break;
                }
            }
            result = result + 50;
        }
        
        if (s[i] == 0x43){
            if(i > 0){
                i--;
                if (s[i] == 0x58){
                    result = result + 90;
                    continue;
                }else if (s[i] == 0x43 && i != 0){
                    result = result + 100;
                    i++;
                    continue;
                }else if (s[i] == 0x43 && i == 0){
                    result = result + 200;
                    break;
                }
            }
            result = result + 100;
            
        }
        
        if (s[i] == 0x44){
            if(i > 0){
                i--;
                if (s[i] == 0x43){
                    result = result + 400;
                    continue;
                }else if (s[i] == 0x44 && i != 0){ 
                    result = result + 500;
                    i++;
                    continue;
                }else if (s[i] == 0x44 && i == 0){
                    result = result + 1000;
                    break;
                }
            } 
            result = result + 500;
            
        }
        
        if (s[i] == 0x4D){
            if(i > 0){
                i--;
                if (s[i] == 0x43){
                    result = result + 900;
                    continue;
                }else if(s[i] == 0x4D && i != 0){ 
                    result = result + 1000;
                    i++;
                    continue;
                }else if(i == 0 && s[i] == 0x4D){
                    result = result + 2000;
                    break;
                }
            }
            result = result + 1000;
        }
        
    }
    return result;
} 

 /**
  * Question's Input & Output. 
  *     You may setup any question detail by 
  *     modify "input" value.
  **/
int main () {
    char *input = {"LVIII"};
    int output = 0;

    output = romanToInt(input);
    printf("input: %s\n", input);
    printf("output: %d\n", output);
}