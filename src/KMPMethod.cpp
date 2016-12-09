#include "KMPMethod.h"
#include "string.h"
#include "stdio.h"

int KMPMethod::match(const char *text, const char *pattern) {
	if (*text == '\0' || *pattern == '\0') {
		return -1;
	}

	int tLen = strlen(text);
	int pLen = strlen(pattern);
	if (tLen < pLen) {
		return -1;
	}

	const char *p = pattern;
	const char *b = text;
	const char *t = b;


	int map[pLen];

	map[0]=0;
	int j =0;
	for(int i = 1; i< pLen;i++){
		while(j>0 && p[j]!=p[i]){
			j = map[j];
		}
		if(p[j]==p[i]){
			j++;
		}
		map[i]=j;
	}

	for(int i = 0; i< pLen;i++){
		printf(">>>>>map[%d]=%d<<<<<\n",i,map[i]);
	}

	int i = 0;
	int k = 0;
	while (t[i] != '\0') {
		if (p[k] == t[i]) {
			i++;
			k++;
		} else {
			p = pattern + map[k];
			i++;
		}
		if (p[k] == '\0') {
			return i-j;
		}
	}
	return -1;
}
