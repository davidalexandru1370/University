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
}

std::vector<Trench> Repository::get_all()
{
	/// <summary>
	/// Retrieve all the data in the repository
	/// </summary>
	/// <returns>Vector with all data</returns>

	return data;
	
}

RepositoryException::RepositoryException(std::string error)
{
	message = error;
}

const char* RepositoryException::what() const noexcept
{
	return message.c_str();
}
