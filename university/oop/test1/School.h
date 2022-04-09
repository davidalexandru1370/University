#pragma once
class School
{
private:
	char* name;
	float longitude;
	float latitude;
	char* date_of_visit;
	bool visited;
public:
	School(const char* _name, double _longitude, double _latitude, const char* _date_of_visit,bool _visited);
	~School();
	School(const School& school);
	char* get_name();
	float get_longitude();
	float get_latitude();
	char* get_date_of_visit();
	bool get_visited();
	void set_name(char* new_name);
	void set_longitude(float new_longitude);
	void set_latitude(float new_latitude);
	void set_date_of_visit(char* new_date_of_visit);
	void set_visited(bool new_value);
};

