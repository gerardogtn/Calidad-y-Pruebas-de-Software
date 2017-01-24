gtest_include = ../../googletest/include
gmock_include = ../../googlemock/include
typedtest_objects = SorterTypeParametrized.cpp
typedtestconstructor_objects = TypedTestWithSpecialConstructor.cpp
valueparametrizedtest_objects = ValueParametrizedTest.cpp

all : typedtest

typedtest :
			 g++ -std=c++0x -ggdb -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(typedtest_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o typedtest.out

typedtestconstructor:
			 g++ -std=c++0x -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(typedtestconstructor_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o typedtestconstructor.out

valueparametrizedtest:
			 g++ -std=c++0x -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(valueparametrizedtest_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o valueparametrizedtest.out
