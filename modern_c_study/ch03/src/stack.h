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

/**
* @brief 스택 메모리에 데이터를 저장한다.
* @param i_iValue 스택에 저장할 데이터
* @return 저장 성공시 True, 아니면 False
*/
bool stackPush(int i_iValue);

/**
* @brief 스택 메모리에서 데이터를 가져온다.
* @param o_iValue 스택 메모리에서 가져온 데이터를 저장할 변수
* @return 스택 메모리에서 데이터 가져오기 성공시 True, 아니면 False
*/
bool stackPop(int *o_iValue);

#ifdef __cplusplus
}
#endif

#endif /* CH03_SRC_STACK_H_ */
