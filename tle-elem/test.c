#include <stdio.h>

int main(){
	printf("Are you a student of ICT dept? [y/n]\n");
	char ans1;
	scanf(" %c", &ans1);

	if(ans1 == 'y'){
		printf("Do you come to the IOT Lab regularly? [y/n]\n");
		char ans2;
		scanf(" %c", &ans2);

		if(ans2 == 'y') {
			
			printf("have you solved 100 questions in Codeforces? [y/n]");	
			char ans3;
			scanf(" %c", &ans3);

			if(ans3 == 'y'){
				printf("Aceess is given!");
			} else {
				printf("Access Denied!\n");
			}

		} else {
			printf("Access Denied!\n");
		}

	} else {
		printf("Access Denied!\n");
	}
}
// numpy, pandaz, matplotlib