#include "BruteForce.h"
#include "string.h"
#include "stdio.h"

int BruteForce::match(const char *text, const char *pattern) {
	printf(">>>text:%s<<<<\n", text);
	printf(">>>pattern:%s<<<<\n", pattern);
	if (*text == '\0' || *pattern == '\0') {
		return -1;
	}
	int tLen = strlen(text);
	int pLen = strlen(pattern);
	printf(">>>text:%d<<<<\n", tLen);
	printf(">>>pattern:%d<<<<\n", pLen);
	if (tLen < pLen) {
		return -1;
	}

	const char *p = pattern;
	const char *b = text;
	const char *t = b;

	while (*p != '\0') {
		printf(">>>p:%s<<<<\n", p);
		printf(">>>t:%s<<<<\n", t);
		printf(">>>pattern:%s<<<<\n", pattern);
		printf(">>>text:%s<<<<\n", text);

		if (*p == *t) {
			p++;
			t++;
		} else {
			p = pattern;
			b++;
			t = b;
		}
		if (*p == '\0') {
			return (t - text) - (p - pattern);
		}
	}
	return -1;
}
