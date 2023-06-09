#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_base_2.h"

class cl_application : public cl_base
{
public:
	cl_application(cl_application* = nullptr, std::string = "Base_object");

	void bild_tree_objects();
	int exec_app();
};

#endif
