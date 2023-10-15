#include<stdio.h>
#include<string.h>
int state[7][3];
char f(char sk , char tk){
	return (state[sk][tk]);
}
int main(){
	char p[100]={"abababc"};
	char t[100]="aaaabbbababaaabababcabbabba";
	int n=strlen(t);
	state[0][0]=1, 	state[0][1]=0, 	state[0][2]=0;
	state[1][0]=1, 	state[1][1]=2, 	state[1][2]=0;
	state[2][0]=3, 	state[2][1]=0, 	state[2][2]=0;
	state[3][0]=1, 	state[3][1]=4, 	state[3][2]=0;
	state[4][0]=5, 	state[4][1]=0, 	state[4][2]=0;
	state[5][0]=1, 	state[5][1]=6, 	state[5][2]=0;
	state[6][0]=5, 	state[6][1]=-1, state[6][2]=-1;
	int k=0, s=0, i, index;
	while(k<n && s!=-1) {
		if(t[k]=='a'){
			i=0;
		}
		if(t[k]=='b'){
			i=1;
		}
		if(t[k]=='c'){
			i=2;
		}
		s=f(s, i);
		k=k+1;
	}
	if(s==-1){
		index=k-strlen(p);
	}
	else {
		index=-1;
	}
	printf("index of p in t is %d", index);

}
