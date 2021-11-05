#include "../headers/polynomial.h"

using namespace std;

ostream& operator << (ostream& os, const polynomial& poly)
{
	try
	{

		for (size_t i = 0; i <= poly.size(); i++)
		{
			if (poly[i] != 0)
			{
				if (poly[i] < 0)
					os << " " << poly[i] << "x^" << i << "";
				else if (i != 0 && poly[i] > 0)
					os << " +" << poly[i] << "x^" << i << "";
				else
					os << poly[i] << "x^" << i << "";
			}
		}
	}
	catch (const char*)
	{
		//if (err == "List is empty")
		os << "";
	}
	return os;
}


int main()
{
	return 0;
}