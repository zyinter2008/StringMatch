#include "BadCharMethod.h"
#include "string.h"
#include "stdio.h"

int BadCharMethod::match(const char *text, const char *pattern) {
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

	int j=0;
	int i;
	while(j <=tLen-pLen){
		for(i=pLen -1;i>= 0 && pattern[i] == text[i+j];i--);
		if(i < 0){
			return j;
		}
		else j += badMap[text[i+j]];
		printf(">>>>>next:j=%d<<<<\n<", j);
	}

	return -1;
}
