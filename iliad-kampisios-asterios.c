#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int y=0,ml=0,xl,i,counter,z,N;
	char c;
	double time1;
	time_t t1,t2;
	//the main characters of Iliad
	char *hero[15]={"Achilles","Agamemnon","Apollo","Jupiter","Hector","Venus","Mars","Minerva","Ajax","Hellen","Juno","Pluto","Ceres","Paris","Neptune"};
	char oa[100],lexi[50];
	FILE *f;
	printf("\nKAMPISIOS ASTERIOS CS4417062 TECHNOLOGICAL EDUCATIONAL INSTITUTE OF THESSALLY\n\n");
	printf("\ngive me the file: ");
	gets(oa);
	f=fopen(oa,"r");
	if(!f){
		printf("\nthis file does not exist \n");
		return -1;
	}
	//word-counter (just extra)
	while(!feof(f)){
		c=fgetc(f);
		if((c>='0' && c<='9') || (c>='A' && c<='z'))
			if(ml==0){
				y++;
				ml=1;
			}
			else{
				ml=1;
			}
		else
			ml=0;
	}
		fclose(f);
	t1=time(NULL);
	for(z=0;z<15;z++){
		f=fopen(oa,"r");
		strcpy(lexi,hero[z]);
		counter=0;
		xl=strlen(lexi);
		//search for the character
		while(!feof(f)){
			c=fgetc(f);
			if((c>='0' && c<='9') || (c>='A' && c<='z'))
				if(ml==0 && lexi[0]==c){
					ml=1;
					i=1;
					while(lexi[i]==(c=fgetc(f)) && i<xl){
						i++;
						if(i==xl-1){
						counter++;
						}
					}
				}
				else{
					ml=0;
				}		
		}
		printf("\nthe character named '%s' is mentioned in the text %d times\n",hero[z],counter);
	}
	t2=time(NULL);
	time1=((double)(t2 -t1));
	printf("\nthe words in the text is: %d ",y);
	printf("\n the search competed in: %f sec \n",time1);//will work on an much more big search
	fclose(f);
	return 0;
}
