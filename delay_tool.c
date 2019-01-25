#include <stdio.h>
#include <time.h>



int delay(unsigned int secs){
	int time_count = time(0) + secs;   
	while (time(0) < time_count);
	return 0;               
}

int count_d(){
	int start_t;
	long end_t = 10;

	printf("Count Down Timer Start Counting!!\n");

	for(start_t=0; start_t <= end_t; start_t++){
		if(start_t == end_t){
			printf("%ld\nEnd Count!!\n", end_t - start_t);
			break;
		}		
		printf("%ld\n", end_t - start_t);
		delay(1);
		continue;
	}
	return 0;
}

int count_s(){
	int start_t;
	long end_t = 10;

	printf("Timer Start Counting!!\n");

	for(start_t=0; start_t <= end_t; start_t++){
		if(start_t == end_t){
			printf("%d\nEnd Count!!\n", start_t);
			break;
	}
	printf("%d\n", start_t);
	delay(1);
	continue;
	}
	return 0;
}

int main(){
	int select_t;
	printf("Select Timer Type: \n  1.Count Down Timer\n  2.Timer\n");

	for(;;){
		scanf("%d", &select_t);

		switch(select_t){
			case(1):
				count_d();
				break;
			case(2):
				count_s();
				break;
			default:
			printf("Select Fail, Please Retry!!\n");
			continue;
		}
		break;
	}
	return 0;
}