#include "cl_application.h"

cl_application::cl_application(cl_application* p_head_object, std::string s_object_name) : cl_base(p_head_object)
{
}

void cl_application::bild_tree_objects()
{
	std::string name, head, sub;
	cl_base* last_head = this, *last_sub = nullptr;
	
	std::cin >> name;
	change_object_name(name);
	while (true)
	{
		std::cin >> head >> sub;
		if (head == sub) break;

		if (last_sub && head == last_sub->get_object_name()) last_head = last_sub;
		if (!last_sub->get_sub_object_by_name(sub) && head == last_head->get_object_name()) last_sub = new cl_base_2(last_head, sub);
	}
}

int cl_application::exec_app()
{
	std::cout << get_object_name();
	show_object_tree();

	return 0;
}
