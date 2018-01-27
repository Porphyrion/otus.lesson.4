/// \brief type_traites
/// \details Проверяет является ли тип вектором или списком

#include <vector>
#include <list>

template<typename T>
struct is_vector_or_list{
	static const bool value = false;
};

template<typename T>
struct is_vector_or_list<std::vector<T>>
{
	static const bool value = true;	
};

template<typename T>
struct is_vector_or_list<std::list<T>>
{
	static const bool value = true;	
};
