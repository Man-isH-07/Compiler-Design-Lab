#include<iostream>
#include<string.h>
#define MAX 20
#include<ctype.h>
#include<stdlib.h>
using namespace std;
int i;
char s[MAX];
int E();
int getint()
{
	int j=0;
	char w[MAX];
	if(!isdigit(s[i]))
	return(-1);
	while(isdigit(s[i]))
		w[j++]=s[i++];
	w[j]='\0';
	return(atoi(w));
}

int F()
{
	int v;
	while(s[i]=='(')
	{
		i++;
		if(i<strlen(s))
		v=E();
		if(s[i]!=')')
		return(-1);
		else
		{
			i++;
			return(v);
		}
	}
	v=getint();
	return(v);
}

int T()
{
	int v;
	v=F();
	while(s[i]=='*')
	{
		i++;
		if(i==strlen(s))
		return(-1);
		v=v*F();
	}
	while(s[i]=='/')
	{
		i++;
		if(i==strlen(s))
		return(-1);
		v=v/F();
	}
	return(v);
}

int E()
{
	int v;
	v=T();
	while(s[i]=='+')
	{
		i++;
		if(i==strlen(s))
		return(-1);
		v=v+T();
	}
	while(s[i]=='-')
	{
		i++;
		if(i==strlen(s))
		return(-1);
		v=v-T();
	}
	return(v);
}

int main()
{
	int ans;
	cout<<"Grammar:\nE->E+T|E-T|T\nT->T*F|T/F|F\nF->(E)|0|1|.....|9\n";
	cout<<"Enter The Expression:";
	cin>>s;

	ans=E();
	if(ans==-1)
	cout<<"\nError in parsing the Expression.";
	else
	cout<<"Result is:"<<ans;
	return 0;
}





Output:

Case 1:

Grammar:
E->E+T|E-T|T
T->T*F|T/F|F
F->(E)|0|1|.....|9
Enter The Expression:2+4
Result is:6

Case2:

Grammar:
E->E+T|E-T|T
T->T*F|T/F|F
F->(E)|0|1|.....|9
Enter The Expression:(2+3)*4
Result is:20

Case 3:

Grammar:
E->E+T|E-T|T
T->T*F|T/F|F
F->(E)|0|1|.....|9
Enter The Expression:(3-1)*5
Result is:10

Case 4:
Grammar:
E->E+T|E-T|T
T->T*F|T/F|F
F->(E)|0|1|.....|9
Enter The Expression:(1-3)*2
Result is:-4
