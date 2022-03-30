#pragma once
class Trench
{
public:
	Trench();
	Trench(int _size, int _quantity, char _color[], int _price, char _photograph[]);
	Trench(const Trench& trench);
	~Trench();
	int get_size();
	int get_quantity();
	char* get_color();
	int get_price();
	char* get_photograph();
	void set_size(int value);
	void set_quantity(int value);
	void set_color(char value[]);
	void set_price(int value);
	void set_photograph(char value[]);
	bool operator==(const Trench& trench) const;
	Trench operator=(const Trench& trench);
	Trench operator+(const Trench& trench);

private:
	int size;
	int quantity;
	int price;
	char* color;
	char* photograph;
};


