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

	int map[pLen];

	map[0] = 0;
	int j = 0;
	for (int i = 1; i < pLen; i++) {
		while (j > 0 && pattern[j] != pattern[i]) {
			j = map[j - 1];
		}
		if (pattern[j] == pattern[i]) {
			j++;
		}
		map[i] = j;
	}

	for (int i = 0; i < pLen; i++) {
		printf(">>>>>map[%d]=%d<<<<<\n", i, map[i]);
	}

	int k = 0;
	for (int i = 0; i < tLen; i++) {
		printf(">>>>>i=%d<<<<<\n", i);
		while (k > 0 && pattern[k] != text[i]) {
			k = map[k - 1];
		}

		if (pattern[k] == text[i]) {
			k++;
		}
		printf(">>>>>k=%d<<<<<\n", k);
		if (pattern[k] == '\0') {
			printf(">>>>>i=%d<<<<<\n", i);
			printf(">>>>>k=%d<<<<<\n", k);
			return i - k + 1;
		}
	}

	return -1;
}
