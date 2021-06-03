/*
 * stack.c
 *
 *  Created on: 2021. 6. 3.
 *      Author: pcw1029
 */
/**
* @file stack.c
* @brief 스택 알고리즘
* @details PUSH와  POP을 이용하여 데이터를 메모리에 저장하고 저장된 데이터를 가져올수 있다.
* @date 2021/06/03
*/

#include "stack.h"
static int g_iStackBuff[16]; 	/**< 스택 메모리 */
static int g_iStackCount;		/**< 스택 메모리의 저장된 데이터 수 */

/**
* @brief 스택 메모리가  가득 차 있는지 확인 한다.
* @return 스택메모리가 FULL이면 True, 아니면 False
*/
static bool isStackFull()
{
	return g_iStackCount == sizeof(g_iStackBuff)/sizeof(int);
}

/**
* @brief 스택 메모리가  비어 있는지 확인 한다.
* @return 스택메모리가 비어있으면 True, 아니면 False
*/
static bool isStackEmpty()
{
	return g_iStackCount == 0;
}


bool stackPush(int i_iValue)
{
	if(isStackFull())
			return false;
	g_iStackBuff[g_iStackCount++] = i_iValue;
	return true;
}

bool stackPop(int *o_iValue)
{
	if(isStackEmpty())
		return false;
	*o_iValue = g_iStackBuff[--g_iStackCount];
	return true;
}

