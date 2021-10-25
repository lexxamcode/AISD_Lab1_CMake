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

int getKey()
{
	int key = _getch();

	if (key == 0 || key == 224)
		key = _getch();
	return key;
}

int startMenu(polynomial& poly1, polynomial& poly2, unsigned& arrow)
{
	if (arrow == 1)
	{
		cout << poly1 << "\t<--" << endl;
		cout << poly2 << endl;
		cout << "Sum polynomials" << endl;
		cout << "First minus Second" << endl;
	}
	else if (arrow == 2)
	{
		cout << poly1 << endl;
		cout << poly2 << "\t<--" << endl;
		cout << "Sum polynomials" << endl;
		cout << "First minus Second" << endl;
	}
	else if (arrow == 3)
	{
		cout << poly1 << endl;
		cout << poly2 << endl;
		cout << "Sum polynomials" << "\t<--" << endl;
		cout << "First minus Second" << endl;

	}
	else if (arrow == 4)
	{
		cout << poly1 << endl;
		cout << poly2 << endl;
		cout << "Sum polynomials" << endl;
		cout << "First minus Second" << "\t<--" << endl;
	}
	
	return getKey();
}

void mult(polynomial& poly)
{
	char mstr[256];
	double multiply;
	do
	{
		system("cls");
		cout << poly << " * ";
		gets_s(mstr, 256);
		multiply = strtod(mstr, NULL);
	} while (errno != ERROR);

	poly = poly * multiply;
}

void calc(polynomial& poly)
{
	char mstr[256];
	double x;
	do
	{
		system("cls");
		cout << poly << "; x = ";
		gets_s(mstr, 256);
		x = strtod(mstr, NULL);
	} while (errno != ERROR);

	cout << poly << " with x = " << x << ": " << poly.calculate(x) << endl;
	system("pause");
}

void addDegree(polynomial& poly)
{
	char mstr[256];
	int degree;
	double factor;
	do
	{
		system("cls");
		cout <<"Enter factor: ";
		gets_s(mstr, 256);
		factor = strtod(mstr, NULL);
	} while (errno != ERROR);

	do
	{
		system("cls");
		cout << "Enter degree: ";
		gets_s(mstr, 256);
		degree = atoi(mstr);
	} while (degree < 0);

	poly.set(factor, degree);
}

void deleteDegree(polynomial& poly)
{
	char mstr[256];
	int degree;
	do
	{
		system("cls");
		cout <<"Enter degree: ";
		gets_s(mstr, 256);
		degree = atoi(mstr);
	} while (degree < 0);

	try
	{
		poly[degree] = 0;
	}
	catch (int err)
	{
		if (err == -1)
			return;
	}
	catch (const char*)
	{
		return;
	}
}

int polynomialSettings(polynomial& poly, unsigned& arrow)
{
	cout << poly << endl;

	if (arrow == 1)
	{
		cout << "Multiply by double\t<--" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 2)
	{
		cout << "Multiply by double" << endl;
		cout << "Delete polynomial's degree\t<--" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 3)
	{
		cout << "Multiply by double" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree\t<--" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 4)
	{
		cout << "Multiply by double" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial\t<--" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 5)
	{
		cout << "Multiply by double" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate\t<--" << endl;
	}
	return getKey();
}

int main()
{
	polynomial poly1(2);
	polynomial poly2(2);
	unsigned arrow = 1;
	while (true)
	{
		system("cls");
		int stm = startMenu(poly1, poly2, arrow);
		if (stm == 27)
			break;
		else if (stm == 80 && arrow < 4)
			arrow++;
		else if (stm == 72 && arrow > 1)
			arrow--;
		else if (stm == 13 )
		{
			if (arrow == 1)
			{
				arrow = 1;
				while (true)
				{
					system("cls");
					int chng = polynomialSettings(poly1, arrow);
					if (chng == 27)
					{
						arrow = 1;
						break;
					}
					else if (chng == 80 && arrow < 5)
						arrow++;
					else if (chng == 72 && arrow > 1)
						arrow--;
					else if (chng == 13 && arrow == 1)
						mult(poly1);
					else if (chng == 13 && arrow == 2)
						deleteDegree(poly1);
					else if (chng == 13 && arrow == 3)
						addDegree(poly1);
					else if (chng == 13 && arrow == 4)
						poly1 = poly1.randomize();
					else if (chng == 13 && arrow == 5)
						calc(poly1);
				}
			}
			else if (arrow == 2)
			{
				arrow = 1;
				while (true)
				{
					system("cls");
					int chng = polynomialSettings(poly2, arrow);
					if (chng == 27)
					{
						arrow = 1;
						break;
					}
					else if (chng == 80 && arrow < 5)
						arrow++;
					else if (chng == 72 && arrow > 1)
						arrow--;
					else if (chng == 13 && arrow == 1)
						mult(poly2);
					else if (chng == 13 && arrow == 2)
						deleteDegree(poly2);
					else if (chng == 13 && arrow == 3)
						addDegree(poly2);
					else if (chng == 13 && arrow == 4)
						poly2 = poly2.randomize();
					else if (chng == 13 && arrow == 5)
						calc(poly2);
				}
			}
			else if (arrow == 3)
			{
				cout << "Result: " << endl;
				cout << poly1 + poly2 << endl;
				system("pause");
			}
			else if (arrow == 4)
			{
				cout << "Result: " << endl;
				cout << poly1 - poly2 << endl;
				system("pause");
			}
		}
	}

	return 0;
}