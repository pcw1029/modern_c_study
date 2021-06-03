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
	STACK stStack = NEW_STACK(iStackMem);
	int iData;
	EXPECT_EQ(false, stackPop(&stStack, &iData));
}

TEST(StackTest, pushReturnFalse)
{
	int iStackMem[16];
	STACK stStack = NEW_STACK(iStackMem);
	int i;
	for(i=0; i<16; i++){
		stackPush(&stStack, i);
	}
	EXPECT_EQ(false, stackPush(&stStack, i));
}

TEST(StackTest, pushNpopReturnTrue)
{
	int iStackMem[16];
	STACK stStack = NEW_STACK(iStackMem);
	int i;
	int iData;
	for(i=0; i<16; i++){
		stackPush(&stStack, i);
	}
	for(i=15; i>=0; i--){
		stackPop(&stStack, &iData);
		EXPECT_EQ(true, i==iData);
	}
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
