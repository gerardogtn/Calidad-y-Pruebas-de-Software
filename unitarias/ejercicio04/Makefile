gtest_include = ../../googletest/include
gmock_include = ../../googlemock/include
typedtest_objects = TypedTestExample.cpp
typedtestconstructor_objects = TypedTestWithSpecialConstructor.cpp

all : typedtest typedtestconstructor

typedtest :
			 g++ -std=c++0x -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(typedtest_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o typedtest.out

typedtestconstructor:
			 g++ -std=c++0x -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(typedtestconstructor_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o typedtestconstructor.out
