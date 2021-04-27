#include "List.h"
#include "Vector.h"
#include "Specialty.h"
#include "Student.h"
int main()
{
	String p1 = "Dstr", t1 = "Zaduljitelna", s1 = "IS";
	Discipline test1, test2(p1, t1, 1), test3(p1, t1, 1);
	Vector<int> t;
	t.add(3);
	t.add(3);
	t.add(3);
	t.print();
	
	return 0;
}