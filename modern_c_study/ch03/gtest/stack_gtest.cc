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
	int iStackMem[16];
	RANGE stRange = {0, 9};
	STACK stStack = NEW_STACK_WITH_RANGE(iStackMem, &stRange);
	int iData;
	EXPECT_EQ(false, stackPop(&stStack, &iData));
}

TEST(StackTest, pushReturnFalse)
{
	int iStackMem[16];
	RANGE stRange = {0, 9};
	STACK stStack = NEW_STACK_WITH_RANGE(iStackMem, &stRange);
	int i;
	for(i=0; i<16; i++){
		stackPush(&stStack, 1);
	}
	EXPECT_EQ(false, stackPush(&stStack, 1));
}

TEST(StackTest, pushNpopReturnTrue)
{
	int iStackMem[16];
	RANGE stRange = {0, 9};
	STACK stStack = NEW_STACK_WITH_RANGE(iStackMem, &stRange);
	int i;
	int iData;
	for(i=0; i<16; i++){
		stackPush(&stStack, (i%10));
	}
	for(i=15; i>=0; i--){
		stackPop(&stStack, &iData);
		EXPECT_EQ(true, (i%10)==iData);
	}
}

TEST(StackTest, pushOutOfRangeValueReturnFalse)
{
	int iStackMem[16];
	RANGE stRange = {0, 9};
	STACK stStack = NEW_STACK_WITH_RANGE(iStackMem, &stRange);
	EXPECT_EQ(false, stackPush(&stStack, -1));
	EXPECT_EQ(false, stackPush(&stStack, 10));
}

TEST(StackTest, pushOutOfRangeValueReturnTrue)
{
	int iStackMem[16];
	RANGE stRange = {0, 9};
	STACK stStack = NEW_STACK_WITH_RANGE(iStackMem, &stRange);
	EXPECT_EQ(true, stackPush(&stStack, 0));
	EXPECT_EQ(true, stackPush(&stStack, 9));
}


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
