#include <iostream>
#include <vector>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <list>
#include "print_ip.h"



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
