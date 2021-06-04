/*
 * stack.h
 *
 *  Created on: 2021. 6. 3.
 *      Author: pcw1029
 */

#ifndef CH03_SRC_STACK_H_
#define CH03_SRC_STACK_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NEW_STACK(iStackMem) { 0, sizeof(iStackMem)/sizeof(int), (iStackMem) }

typedef struct {
	int iStackCount;	/**< 스택 메모리의 저장된 데이터 수 */
	const int iStackSize;	/**< 스택 메모리의 크기 */
	int* const piStackBuff;	/**< 스택 메모리 */
}STACK;

/**
* @brief 스택 메모리에 데이터를 저장한다.
* @param pstStack 스택 메모리 정보
* @param i_iValue 스택에 저장할 데이터
* @return 저장 성공시 True, 아니면 False
*/
bool stackPush(STACK* pstStack, int i_iValue);

/**
* @brief 스택 메모리에서 데이터를 가져온다.
* @param pstStack 스택 메모리 정보
* @param o_iValue 스택 메모리에서 가져온 데이터를 저장할 변수
* @return 스택 메모리에서 데이터 가져오기 성공시 True, 아니면 False
*/
bool stackPop(STACK* pstStack, int *o_iValue);

#ifdef __cplusplus
}
#endif

#endif /* CH03_SRC_STACK_H_ */
