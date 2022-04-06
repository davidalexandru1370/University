#include "Repository.h"
#include <exception>
#include <fstream>
bool Repository::check_if_index_belongs(int index)
{
	/// <summary>
	/// Check if index belongs to repository vector dimensions
	/// </summary>
	/// <param name="index">integer strictly positive representing the position</param>
	/// <returns>true if index belongs, otherwise false</returns>
	return index < 0 || index >= data.size() ? false : true;
}

Repository::Repository()
{
	read_from_file();
	input_file_name = new char[15];
	output_file_name = new char[15];
	strcpy(output_file_name, "output.txt");
	strcpy(input_file_name, "input.txt");
	//data = Vector<Trench>{ size };
	/// <summary>
	/// Constructor for repository class
	/// </summary>
	/// <param name="size">initial size of vector dimension</param>
	/// <returns></returns>
}

void Repository::remove_at(int index)
{
	/// <summary>
	/// Remove element at given index
	/// </summary>
	/// <param name="index">integer strictly positive</param>
	if (check_if_index_belongs(index) == false)
	{
		throw std::exception("Index is outside the bounds of the array\n");
	}
	//data->remove_at(index);
	//data.remove_at(index);
	data.erase(data.begin() + index);
	write_to_file();
}

void Repository::update_at(int index, Trench new_element)
{
	/// <summary>
	/// Update element at given position with new element
	/// </summary>
	/// <param name="index">position to be updated</param>
	/// <param name="new_element">new element</param>
	if (check_if_index_belongs(index) == false)
	{
		throw std::exception();
	}
	//data->set_element(index, new_element);
	data[index] = new_element;
	write_to_file();
}

std::vector<Trench> Repository::get_all()
{
	/// <summary>
	/// Retrieve all the data in the repository
	/// </summary>
	/// <returns>Vector with all data</returns>
	//Vector* all = new Vector(*data);
	//Vector<Trench> copy_data = data;
	return data;
	//return data;
}

void Repository::write_to_file()
{
	char file_name[] = "input.txt";
	std::ofstream f(file_name);
	for (auto& element : data)
	{
		f << element<<"\n";
	}
}

void Repository::read_from_file()
{
	char file_name[] = "output.txt";
	std::ifstream f(file_