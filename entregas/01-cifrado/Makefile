gtest_include = ../../googletest/include
gmock_include = ../../googlemock/include
test_objects = CifradoTypedTest.cpp

all : test

test :
			 g++ -std=c++0x -ggdb -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(test_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o test.out
