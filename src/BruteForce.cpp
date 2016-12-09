#include "BruteForce.h"
#include "string.h"

int BruteForce::match(const char *text, const char *pattern) {
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
	while (*t != '\0') {
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
