#include "BMMethod.h"
#include "string.h"
#include "stdio.h"
#include <algorithm>

using namespace std;

int BMMethod::match(const char *text, const char *pattern) {
	if (*text == '\0' || *pattern == '\0') {
		return -1;
	}

	int tLen = strlen(text);
	int pLen = strlen(pattern);
	if (tLen < pLen) {
		return -1;
	}

	int badMap[256];
	for(int i = 0; i <256; i++){
		badMap[i] = pLen;
	}
	for(int i = 0; i< pLen; i++){
		badMap[pattern[i]] = pLen-1-i;
	}

	printf(">>>>>badMap[A]=%d<<<<\n<", badMap['A']);
	printf(">>>>>badMap[B]j=%d<<<<\n<", badMap['B']);
	printf(">>>>>badMap[C]j=%d<<<<\n<", badMap['C']);
	printf(">>>>>badMap[D]j=%d<<<<\n<", badMap['D']);


	int suffix[pLen];
	suffix[pLen-1] = pLen;
	for(int i = pLen -2; i >=0; i--){
		int j = i;
		while(j >=0 && pattern[j] == pattern[pLen-1-i+j]) j--;
		suffix[i] = i -j;
	}

	for(int i =0; i<pLen;i++){
		printf(">>>>>suffix[%d]=%d<<<<\n<", i, suffix[i]);
	}

	int gsMap[pLen];
	for(int i = 0; i < pLen; i++){
		gsMap[i] = pLen;
	}
	for (int i = 0; i < pLen; i++) {
		printf(">>>>>gsMap[%d]=%d<<<<\n<", i, gsMap[i]);
	}
	for(int i = pLen -1; i >=0;i--){
		if(suffix[i] ==i+1 ){
			for(int j = 0; j < pLen - 1 - i; j++)
			if(gsMap[j] == pLen){
				gsMap[j] = pLen-1-i;
			}
		}
	}
	for (int i = 0; i < pLen; i++) {
		printf(">>>>>gsMap[%d]=%d<<<<\n<", i, gsMap[i]);
	}
	for(int i =0; i<=pLen-2;i++){
		gsMap[pLen-1-suffix[i]]= pLen-1-i;
	}
	for (int i = 0; i < pLen; i++) {
		printf(">>>>>gsMap[%d]=%d<<<<\n<", i, gsMap[i]);
	}



	int j=0;
	int i;
	while(j <=tLen-pLen){
		for(i=pLen -1;i>= 0 && pattern[i] == text[i+j];i--);

		printf(">>>>>curr:i=%d<<<<\n<", i);
		printf(">>>>>curr:j=%d<<<<\n<", j);
		printf(">>>>badMap=%d<<<<\n<", badMap[text[i+j]]);
		printf(">>>>gsMap=%d<<<<\n<", gsMap[text[i]]);
		if(i < 0){
			return j;
		}
		else j += max(badMap[text[i+j]] - pLen + 1 + i, gsMap[i]);
		printf(">>>>>next:j=%d<<<<\n<", j);
	}

	return -1;
}
