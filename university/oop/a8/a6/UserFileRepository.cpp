#include "UserFileRepository.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
UserFileRepository::UserFileRepository(const char* file)
{
	file_name = new char[strlen(file)];
	strcpy(file_name, file);
	//read_from_file();
}

void UserFileRepository::add_element(Trench element)
{
	int element_index = check_if_element_exists(element);
	if (element_index == -1) {
		element.set_quantity(1);
		data.push_back(element);
	}
	else {
		data[element_index].set_quantity(data[element_index].get_quantity() + 1);
	}
	write_to_file();
}

void UserFileRepository::write_to_file()
{
	std::string output = std::string(file_name) + "." + output_extension;
	cout << output << "\n";
	std::ofstream f(output);
	if (output_extension == "csv")
	{
		std::remove(output.c_str());
		for (auto& element : data)
		{
			std::stringstream ss;
			ss << element;
			std::string sentence = ss.str();
			std::replace(sentence.begin(), sentence.end(), ' ', ',');
			f << sentence << "\n";
		}
	}
	else if (output_extension == "html") {
		string text;
		std::string html_start = "<!DOCTYPE html> \n    \
			<html> \n \
			<head>  \n\
			<title>Trench shop</title>\n  \
			</head> \n \
			<body>  \n\
			<table border = 1>\n";

		std::string table_first_row = "<tr>\n \
			<td>Size</td> \n \
			<td>Color</td> \n\
			<td>Price</td> \n\
			<td>Quantity</td> \n\
			<td>Photograph</td> \n\
			</tr> \n";

		std::string html_end = "</table> \n\
								</body > \n\
								</html> \n";
		text = html_start + table_first_row + "\n";
		for (auto& element : data)
		{
			std::stringstream ss;
			ss << element;
			//std::string sentence = ss.str();
			string word;
			string new_table_row = "<tr>\n";
			std::vector<std::string>words;
			while (ss >> word)
			{
				words.push_back(word);
			}
			for (auto& wrd : words)
			{
				new_table_row += "<td> " + wrd + " \n";
			}
			new_table_row += "</tr>\n";
			text += new_table_row;
		}
		text += html_end;
		f << text;
	}
	f.close();
}

void UserFileRepository::read_from_file()
{
	std::ifstream f(file_name);
	Trench element;
	//check if file is empty
	if (f.peek() == std::ifstream::traits_type::eof())
	{
		return;
	}
	while (f >> element)
	{
		add_element(element);
	}
}

void UserFileRepository::set_output_extension(std::string extension)
{
	output_extension = extension;
}
