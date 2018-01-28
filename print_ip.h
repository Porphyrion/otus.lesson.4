/*!
\file
\brief Заголовочный файл с определением метафункции печати ip-адреса

Шаблонная метафункция печати ip-адресс
*/
#include <iostream>
#include <vector>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <list>
#include "mytypetraits.h"

/*!
Шаблонная функция печати адреса в зависимости от переданного в нее параметра 
\param[T тип передаваемого параметра
\param[t передаваемый параметр
*/


/*!
Специализация для целочисленных типов
*/
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


/*!
Специализация для std::string
*/
template<class T>
typename std::enable_if<std::is_same<std::string, T>::value, void>::type print_ip(T t)
{	
	std::cout<<t<<std::endl;
}


/*!
Специализация для std::vector и std::list
*/
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