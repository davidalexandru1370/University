#pragma once
#include "Repository.h"
class TrenchRepository : public Repository
{
public:
	TrenchRepository(int);
	~TrenchRepository();
	int check_if_element_exists(Trench &element) override;
	void add_element(Trench element) override;
private:
};

