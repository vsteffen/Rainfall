#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class N {
	public:
		char buff[0x64];
		int var1;

		N() {};
		N(int n) {
			var1 = n;
		}

		void setAnnotation(char *str) {
			memcpy(buff, str, strlen(str));
		}

		virtual int operator+(N &n) {
			return (var1 + n.var1);
		}

		virtual int operator-(N &n) {
			return (var1 - n.var1);
		}
};

int main(int ac, char **av) {
	if (ac <= 0x1)
		exit(1);
	N *n1 = new N(5);
	N *n2 = new N(6);

	N *n_ptr1;
	N *n_ptr2;

	n_ptr1 = n1;
	n_ptr2 = n2;

	n_ptr1->setAnnotation(av[1]);
	return (*n_ptr2 + *n_ptr1);
}
