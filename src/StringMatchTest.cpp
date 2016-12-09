#include "gtest/gtest.h"
#include "BruteForce.h"
#include "KMPMethod.h"

TEST(StringMatchTest, should_return_right_position_when_match_pattern_str_by_brute_force_method) {
	BruteForce bf;
	char text[] = "HERE IS A SIMPLE EXAMPLE", pattern[] = "EXAMPLE";

	ASSERT_EQ(17, bf.match(text, pattern));
}

TEST(StringMatchTest, should_return_error_when_pattern_str_empty_in_brute_force_method) {
	BruteForce bf;
	char text[] = "HERE IS A SIMPLE EXAMPLE", pattern[] = "";

	ASSERT_EQ(-1, bf.match(text, pattern));
}

TEST(StringMatchTest, should_return_error_when_text_str_empty_in_brute_force_method) {
	BruteForce bf;
	char text[] = "", pattern[] = "EXAMPLE";

	ASSERT_EQ(-1, bf.match(text, pattern));
}

TEST(StringMatchTest, should_return_error_when_text_str_length_less_than_pattern_str_length_in_brute_force_method) {
	BruteForce bf;
	char text[] = "EXAMP", pattern[] = "EXAMPLE";

	ASSERT_EQ(-1, bf.match(text, pattern));
}

TEST(StringMatchTest, should_return_error_when_pattern_str_not_match_text_str_by_brute_force_method) {
	BruteForce bf;
	char text[] = "HERE IS A SIMPLE", pattern[] = "EXAMPLE";

	ASSERT_EQ(-1, bf.match(text, pattern));
}

TEST(StringMatchTest, should_return_right_position_when_match_pattern_str_by_kmp_method) {
	KMPMethod kmp;
	char text[] = "BBC ABCDAB ABCDABCDABDE", pattern[] = "ABCDABD";

	ASSERT_EQ(15, kmp.match(text, pattern));
}
