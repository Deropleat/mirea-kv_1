#ifndef CL_BASE_H
#define CL_BASE_H

#include "main.h"

class cl_base
{
public:
	cl_base(cl_base* = nullptr, std::string = "Base_object");
	
	cl_base* get_head_object();
	cl_base* get_sub_object_by_name(std::string);

	std::string get_object_name();
	bool change_object_name(std::string);
	void show_object_tree();
private:
	std::string s_object_name;
	cl_base* p_head_object = nullptr;
	std::vector<cl_base*> subordinate_objects;
};

#endif