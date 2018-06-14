/*!
\file
\brief Заголовочный файл с определением метакласса

Данный файл содержит в себе определение шаблонного
метакласса, используемого для проверки типа
*/

#include <vector>
#include <list>
/*
Проверяет, является ли тип std::vector или std::list
*/
template<typename T>
struct is_vector_or_list{
	static const bool value = false;
};
/*
Специализация is_vector_or_list для std::vector
*/
template<typename T>
struct is_vector_or_list<std::vector<T>>
{
	static const bool value = true;
};
/*
Специализация is_vector_or_list для std::list
*/
template<typename T>
struct is_vector_or_list<std::list<T>>
{
	static const bool value = true;
};
