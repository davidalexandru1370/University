#include "TrenchRepository.h"
#include "Trench.h"
#include <string>
TrenchRepository::TrenchRepository() {
}

TrenchRepository::~TrenchRepository() = default;

int TrenchRepository::check_if_element_exists(Trench & element)
{
	auto index = std::find_if(data.begin(), data.end(), [element](Trench& trench)  {return trench == element; });
	if (data.end() != index)
	{
		throw RepositoryException("Element already exists\n");
	}
	return 1;
}

void TrenchRepository::add_element(Trench element)
{
	check_if_element_exists(element);
	data.push_back(element);
}
