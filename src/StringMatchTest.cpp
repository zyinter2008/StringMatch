#include "gtest/gtest.h"
#include "BruteForce.h"

TEST(StringMatchTest, should_return_right_position_when_match_pattern_str_by_brute_force_method){
	BruteForce bf;
	char text[] = "HERE IS A SIMPLE EXAMPLE", pattern[] = "EXAMPLE";

	ASSERT_EQ(17, bf.match(text, pattern));
}

TEST(StringMatchTest, should_return_error_when_pattern_str_empty_in_brute_force_method){
	BruteForce bf;
	char text[] = "HERE IS A SIMPLE EXAMPLE", pattern[] = "";

	ASSERT_EQ(-1, bf.match(text, pattern));
}

