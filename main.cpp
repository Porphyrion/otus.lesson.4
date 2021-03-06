#include <iostream>
#include <vector>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <list>
#include <tuple>
#include "print_ip.h"

/*!
\mainpage
Программа печати ip-адресов.
Адрес может быть представлен в виде произвольного целочисленного типа. Представление не зависит от знака типа. Выводит адрес побайтово начиная со старшего с символом "."" в качестве разделителя.
Адрес может быть представлен в виде строки. Выводится как есть.
Адрес может быть представлен в виде контейнеров std::list, std::vector.
Выводится содержимое контейнера поэлементно и разделяется ".".
*/

/*!
\file
\brief Основной файл программы
*/
int main(int argc, char const *argv[]){

	print_ip(char(-1));
	print_ip(short(0));
	print_ip(int(2130706433));
	print_ip(long(8875824491850138409));
	print_ip(std::string{"13.45.65.89"});
	print_ip(std::vector<int>{1,24,54,65});
	print_ip(std::list<std::string>{"243", "895", "543", "146"});
	auto x = std::make_tuple(1,22,59,666);
	print_ip(x);

	return 0;
}
