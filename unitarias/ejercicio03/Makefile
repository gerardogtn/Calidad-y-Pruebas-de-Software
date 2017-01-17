gtest_include = ../../googletest/include
gmock_include = ../../googlemock/include
test_objects = FunctionsValueParametrizedTest.cpp

all : parametrizedtest

parametrizedtest :
			 g++ -std=c++0x -isystem  $(gtest_include) -isystem $(gmock_include) \
			 -lpthread $(test_objects) \
			 ../../googletest/make/gtest_main.a ../../googlemock/make/gmock_main.a \
			 -o parametrizedtests.out
