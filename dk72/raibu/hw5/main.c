#include "dk_tool.h" 
#include "right_triangle.h"

int main(int argc, char const *argv[])
{
	rtriangle_array* x = new_rtriangle_array(3);
	for (int i = 0; i < x->len; ++i)
	{
		prtriangle2d tri = enter_params();
		addto_rtriangle_array(x, tri); 
			 
	}
	//freopen(argv[1], "w", stdout);
	char* json = tarray_to_json(x);
	printf("%s\n", json);
	free(json);
	
	

	quick_sort(x->array, 0, x->cur-1);

	printf("\n\n\n__SORTED__\n\n\n");

	json = tarray_to_json(x);
	printf("%s\n", json);
	free(json);
	free_rtriangle_array(x);
	//freopen("/dev/stdout", "w", stdout);
	return 0;
}
















