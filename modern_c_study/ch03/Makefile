GTEST_LIB 			= /home/pcw1029/googletest/myGoogleTestLib/lib
GTEST_INCLUDE 	= /home/pcw1029/googletest/googletest/include

SRC_INCLUDE		= ./src

#컴파일 옵션
G++ 		= g++
G++_FLAGS 	= -c -Wall -I$(GTEST_INCLUDE) -I$(SRC_INCLUDE) -std=c++11
LD_FLAGS 	= -L$(GTEST_LIB) -lgtest -lpthread

#Chapter3 
GTEST_OBJS	= ./gtest/stack_gtest.o
OBJS 		= ./src/stack.o
GTEST_APP 	= stack_gtest

all: $(GTEST_APP)

$(GTEST_APP): $(OBJS) $(GTEST_OBJS)
	$(G++) -o $(GTEST_APP) $(OBJS) $(GTEST_OBJS) $(LD_FLAGS) 
	
%.o : %.cc
	$(G++) $(G++_FLAGS) -o $@ $^

clean:
	rm -f $(GTEST_APP) $(OBJS) $(GTEST_OBJS)
                    
.PHONY: all clean