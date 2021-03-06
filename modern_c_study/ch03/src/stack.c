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

/**
* @brief 스택 메모리가  가득 차 있는지 확인 한다.
* @return 스택메모리가 FULL이면 True, 아니면 False
*/
static bool isStackFull(STACK* pstStack)
{
	return pstStack->iStackCount == pstStack->iStackSize;
}

/**
* @brief 스택 메모리가  비어 있는지 확인 한다.
* @return 스택메모리가 비어있으면 True, 아니면 False
*/
static bool isStackEmpty(STACK* pstStack)
{
	return pstStack->iStackCount == 0;
}

bool checkOutOfRange(VALIDATOR* pstValidator, int i_iValue)
{
	RANGE *pstRange = (RANGE *)pstValidator->pvData;
	if(pstRange->iMax < i_iValue || pstRange->iMin > i_iValue)
		return false;
	return true;
}

bool checkPrevValue(VALIDATOR* pstValidator, int i_iValue)
{
	PREV_VALUE *pstPrevValue = (PREV_VALUE *)pstValidator->pvData;
	if(pstPrevValue->iPrevValue >= i_iValue)
		return false;
	pstPrevValue->iPrevValue = i_iValue;
	return true;
}

static bool validate(VALIDATOR* pstValidator, int i_iValue)
{
	if(! pstValidator)
		return true;
	return pstValidator->validate(pstValidator, i_iValue);
}

bool stackPush(STACK* pstStack, int i_iValue)
{
	if(isStackFull(pstStack) || !validate(pstStack->pstValidator, i_iValue))
			return false;
	pstStack->piStackBuff[pstStack->iStackCount++] = i_iValue;
	return true;
}

bool stackPop(STACK* pstStack, int *o_iValue)
{
	if(isStackEmpty(pstStack))
		return false;
	*o_iValue = pstStack->piStackBuff[--pstStack->iStackCount];
	return true;
}

