#include <iostream>
#include <vector>
#include <type_traits>
#include <typeinfo>
#include <sstream>
#include <string>
#include <list>
#include "mytypetraits.h"



template<class T>
typename std::enable_if<std::is_integral<T>::value, void>::type print_ip(T t)
{	
	std::vector<unsigned short> ip{};
	for(auto i = 0; i < sizeof(t); i++){
		ip.push_back((((unsigned short)t)&0x00FF));
		t = t>>8;
	}
	for(auto i = ip.rbegin(); i != ip.rend(); i++){
		if(i != ip.rbegin()){
			std::cout<<"."<<*i;
		}
		else{
			std::cout<<*i;
		}
	}
	std::cout<<std::endl;
}

template<class T>
typename std::enable_if<std::is_same<std::string, T>::value, void>::type print_ip(T t)
{	
	std::cout<<t<<std::endl;
}

template<class T>
typename std::enable_if<is_vector_or_list<T>::value, void>::type print_ip(T t)
{	
	for(auto i = t.begin(); i != t.end(); i++){
		if(i!= t.begin()){
			std::cout<<"."<<*i;
		}
		else{
			std::cout<<*i;
		}
	}
	std::cout<<std::endl;
}

int main(int argc, char const *argv[]){
	
	print_ip(char(-1));///< Печать адреса как char(-1)
	print_ip(short(0));///< Печать адреса как short(0)
	print_ip(int(2130706433));///<Печать адреса как int(2130706433)
	print_ip(long(8875824491850138409));///<Печать адреса как long(8875824491850138409)
	print_ip(std::string{"13.45.65.89"});///<Печать адреса как std::string
	print_ip(std::vector<int>{1,24,54,65});///<Печать адреса как std::vector
	print_ip(std::list<std::string>{"243", "895", "543", "146"});///<Печать адреса как std::list

	return 0;
}
