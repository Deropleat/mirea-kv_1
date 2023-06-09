#include "cl_base.h"

cl_base::cl_base(cl_base* p_head_object, std::string s_object_name)
{
	this->p_head_object = p_head_object;
	this->s_object_name = s_object_name;
	if (p_head_object) p_head_object->subordinate_objects.push_back(this);
}

cl_base* cl_base::get_head_object()
{
	return p_head_object;
}

cl_base* cl_base::get_sub_object_by_name(std::string s_object_name)
{
	if (!s_object_name.empty()) for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->get_object_name() == s_object_name) return subordinate_object;
	
	return nullptr;
}

std::string cl_base::get_object_name()
{
	return s_object_name;
}

bool cl_base::change_object_name(std::string s_object_name)
{
	if (s_object_name.empty()) return false;
	for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->get_object_name() == s_object_name) return false;
	
	this->s_object_name = s_object_name;
	return true;
}

void cl_base::show_object_tree()
{
	if (subordinate_objects.size() > 0)
	{
		std::cout << std::endl << get_object_name();
		for (cl_base* subordinate_object : subordinate_objects) std::cout << " " << subordinate_object->get_object_name();
		for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->subordinate_objects.size() > 0) subordinate_object->show_object_tree();
	}
}