/*
 * stack_gtest.cc
 *
 *  Created on: 2021. 6. 3.
 *      Author: pcw1029
 */
#include "gtest/gtest.h"
#include "stack.h"

TEST(StackTest, popReturnFalse)
{
	int iData;
	EXPECT_EQ(false, stackPop(&iData));
}

TEST(StackTest, pushReturnFalse)
{
	int i;
	for(i=0; i<16; i++){
		stackPush(i);
	}
	EXPECT_EQ(false, stackPush(i));
}

TEST(StackTest, pushNpopReturnTrue)
{
	int iData;
	int i;
	for(i=0; i<16; i++){
		stackPush(i);
	}
	for(i=15; i>=0; i--){
		stackPop(&iData);
		EXPECT_EQ(true, i==iData);
	}
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
