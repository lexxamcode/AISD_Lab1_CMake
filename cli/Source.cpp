#include "../headers/polynomial.h"

using namespace std;

template <typename TYPE>
ostream& operator << (ostream& os, const polynomial<TYPE>& poly)
{
	try
	{

		for (size_t i = 0; i <= poly.size(); i++)
		{
			if (poly[i] != static_cast<TYPE>(0))
			{
				if (i == 0)
					os << "" << poly[i] << "x^" << i << "";
				else
					os << " " << poly[i] << "x^" << i << "";
			}
		}
	}
	catch (const char*)
	{
		//if (err == "List is empty")
		os << "0";
	}
	return os;
}

void addIntDegree(polynomial<int>& poly)
{
	int degree;
	int factor;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Enter the degree: ";
		try
		{
			gets_s(mstr, 256);
			degree = stoi(mstr);
			if (degree < 0) throw "Power is less than 0";
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
		catch (const char*)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the factor: ";
		try
		{
			gets_s(mstr, 256);
			factor = stoi(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	poly.set(factor, degree);
}
void addFloatDegree(polynomial<float>& poly)
{
	int degree;
	float factor;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Enter the degree: ";
		try
		{
			gets_s(mstr, 256);
			degree = stoi(mstr);
			if (degree < 0) throw "Power is less than 0";
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
		catch (const char*)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the factor: ";
		try
		{
			gets_s(mstr, 256);
			factor = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	poly.set(factor, degree);
}
void addDoubleDegree(polynomial<double>& poly)
{
	int degree;
	double factor;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Enter the degree: ";
		try
		{
			gets_s(mstr, 256);
			degree = stoi(mstr);
			if (degree < 0) throw "Power is less than 0";
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
		catch (const char*)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the factor: ";
		try
		{
			gets_s(mstr, 256);
			factor = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	poly.set(factor, degree);
}
void addComplexFloatDegree(polynomial<complex<float>>& poly)
{
	int degree;
	float r_factor;
	float i_factor;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Enter the degree: ";
		try
		{
			gets_s(mstr, 256);
			degree = stoi(mstr);
			if (degree < 0) throw "Power is less than 0";
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
		catch (const char*)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the Real part of the factor: ";
		try
		{
			gets_s(mstr, 256);
			r_factor = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the Imag part of the factor: ";
		try
		{
			gets_s(mstr, 256);
			i_factor = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	complex<float> factor(r_factor, i_factor);
	poly.set(factor, degree);
}
void addComplexDoubleDegree(polynomial<complex<double>>& poly)
{
	int degree;
	double r_factor;
	double i_factor;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Enter the degree: ";
		try
		{
			gets_s(mstr, 256);
			degree = stoi(mstr);
			if (degree < 0) throw "Power is less than 0";
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
		catch (const char*)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the Real part of the factor: ";
		try
		{
			gets_s(mstr, 256);
			r_factor = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	while (true)
	{
		system("cls");
		cout << "Enter the Imag part of the factor: ";
		try
		{
			gets_s(mstr, 256);
			i_factor = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}

	complex<double> factor(r_factor, i_factor);
	poly.set(factor, degree);
}
void intMult(polynomial<int>& poly)
{
	int multiply;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << poly << " * ";
		try
		{
			gets_s(mstr, 256);
			multiply = stoi(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	poly = poly * multiply;
}
void floatMult(polynomial<float>& poly)
{
	float multiply;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << poly << " * ";
		try
		{
			gets_s(mstr, 256);
			multiply = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	poly = poly * multiply;
}
void doubleMult(polynomial<double>& poly)
{
	double multiply;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << poly << " * ";
		try
		{
			gets_s(mstr, 256);
			multiply = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	poly = poly * multiply;
}
void complexFloatMult(polynomial<complex<float>>& poly)
{
	float real, imag;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Input Real part: ";
		try
		{
			gets_s(mstr, 256);
			real = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	while (true)
	{
		system("cls");
		cout << "Input Imag part: ";
		try
		{
			gets_s(mstr, 256);
			imag = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	complex<float> multiply(real, imag);

	poly = poly * multiply;
}
void complexDoubleMult(polynomial < complex<double>>& poly)
{
	double real, imag;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Input Real part: ";
		try
		{
			gets_s(mstr, 256);
			real = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	while (true)
	{
		system("cls");
		cout << "Input Imag part: ";
		try
		{
			gets_s(mstr, 256);
			imag = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	complex<double> multiply(real, imag);

	poly = poly * multiply;
}
void intCalc(const polynomial<int>& poly)
{
	int x;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << poly << " with x: ";
		try
		{
			gets_s(mstr, 256);
			x = stoi(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	cout << poly << " with x = " << x << ": " << poly.calculate(x) << endl;
	system("pause");
}
void floatCalc(const polynomial<float>& poly)
{
	float x;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << poly << " with x: ";
		try
		{
			gets_s(mstr, 256);
			x = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	cout << poly << " with x = " << x << ": " << poly.calculate(x) << endl;
	system("pause");
}
void doubleCalc(const polynomial<double>& poly)
{
	double x;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << poly << " with x: ";
		try
		{
			gets_s(mstr, 256);
			x = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	cout << poly << " with x = " << x << ": " << poly.calculate(x) << endl;
	system("pause");
}
void complexFloatCalc(const polynomial<complex<float>>& poly)
{
	float real, imag;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Input Real part: ";
		try
		{
			gets_s(mstr, 256);
			real = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	while (true)
	{
		system("cls");
		cout << "Input Imag part: ";
		try
		{
			gets_s(mstr, 256);
			imag = stof(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	complex<float> x(real, imag);

	cout << poly << " with x = " << x <<": " << poly.calculate(x) << endl;
	system("pause");
}
void complexDoubleCalc(const polynomial<complex<double>>& poly)
{
	double real, imag;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Input Real part: ";
		try
		{
			gets_s(mstr, 256);
			real = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}

	while (true)
	{
		system("cls");
		cout << "Input Imag part: ";
		try
		{
			gets_s(mstr, 256);
			imag = stod(mstr);
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}

	}
	complex<double> x(real, imag);

	cout << poly << " with x = " << x << ": " << poly.calculate(x) << endl;
	system("pause");
}
template <typename TYPE>
void deleteDegree(polynomial<TYPE>& poly)
{
	int degree;
	char mstr[256];
	while (true)
	{
		system("cls");
		cout << "Input the degree you want to delete: ";
		try
		{
			gets_s(mstr, 256);
			degree = stoi(mstr);
			if (degree < 0) throw "Power is less than 0";
			break;
		}
		catch (std::invalid_argument)
		{
			cout << "Invalid argument.";
			system("pause");
		}
		catch (const char*)
		{
			cout << "Invalid argument.";
			system("pause");
		}
	}
	try 
	{
		poly.remove(degree);
	}
	catch (int)
	{
		return;
	}
}
int typeChoiseMenu(int& arrow)
{
	switch (arrow)
	{
	case 1:
	{
		cout << "Int" << "\t<--" << endl;
		cout << "Float" << endl;
		cout << "Double" << endl;
		cout << "Complex Float" << endl;
		cout << "Complex Double" << endl;
		break;
	}
	case 2:
	{
		cout << "Int" << endl;
		cout << "Float" << "\t<--" << endl;
		cout << "Double" << endl;
		cout << "Complex Float" << endl;
		cout << "Complex Double" << endl;
		break;
	}
	case 3:
	{
		cout << "Int" << endl;
		cout << "Float" << endl;
		cout << "Double" << "\t<--" << endl;
		cout << "Complex Float" << endl;
		cout << "Complex Double" << endl;
		break;
	}
	case 4:
	{
		cout << "Int" << endl;
		cout << "Float" << endl;
		cout << "Double" << endl;
		cout << "Complex Float" << "\t<--" << endl;
		cout << "Complex Double" << endl;
		break;
	}
	case 5:
	{
		cout << "Int" << endl;
		cout << "Float" << endl;
		cout << "Double" << endl;
		cout << "Complex Float" << endl;
		cout << "Complex Double" << "\t<--" << endl;
		break;
	}
	}

	int key = _getch();
	return key;
}
template <typename TYPE>
int startMenu(polynomial<TYPE>& poly1, polynomial<TYPE>& poly2, int& arrow)
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

	return _getch();
}
template <typename TYPE>
int polynomialMenu(polynomial<TYPE>& poly, int& arrow)
{
	cout << poly << endl;

	if (arrow == 1)
	{
		cout << "Multiply\t<--" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 2)
	{
		cout << "Multiply" << endl;
		cout << "Delete polynomial's degree\t<--" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 3)
	{
		cout << "Multiply" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree\t<--" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 4)
	{
		cout << "Multiply" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial\t<--" << endl;
		cout << "Calculate" << endl;
	}
	else if (arrow == 5)
	{
		cout << "Multiply" << endl;
		cout << "Delete polynomial's degree" << endl;
		cout << "Add a degree" << endl;
		cout << "Generate polynomial" << endl;
		cout << "Calculate\t<--" << endl;
	}

	return _getch();
}

int main()
{
	int arrow = 1;
	while (true)
	{
		system("cls");
		int type_choise = typeChoiseMenu(arrow);
		if (type_choise == VK_ESCAPE)
			break;
		else if (type_choise == 72 && arrow > 1)
			arrow--;
		else if (type_choise == 80 && arrow < 5)
			arrow++;
		else if (type_choise == VK_RETURN)
		{
			if (arrow == 1)
			{
				polynomial<int> poly1(5);
				polynomial<int> poly2(5);

				arrow = 1;
				while (true)
				{
					system("cls");
					int start_menu = startMenu(poly1, poly2, arrow);
					if (start_menu == VK_ESCAPE)
					{
						arrow = 1;
						break;
					}
					else if (start_menu == 72 && arrow > 1)
						arrow--;
					else if (start_menu == 80 && arrow < 4)
						arrow++;
					else if (start_menu == VK_RETURN)
					{
						if (arrow == 1)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly1, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										intMult(poly1);
									}
									if (arrow == 2)
									{
										deleteDegree(poly1);
									}
									if (arrow == 3)
									{
										addIntDegree(poly1);
									}
									if (arrow == 4)
									{
										poly1 = poly1.randomize();
									}
									if (arrow == 5)
									{
										intCalc(poly1);
									}
								}
							}
						}
						else if (arrow == 2)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly2, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										intMult(poly2);
									}
									if (arrow == 2)
									{
										deleteDegree(poly2);
									}
									if (arrow == 3)
									{
										addIntDegree(poly2);
									}
									if (arrow == 4)
									{
										poly2 = poly2.randomize();
									}
									if (arrow == 5)
									{
										intCalc(poly2);
									}
								}
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
			}
			else if (arrow == 2)
			{
				polynomial<float> poly1(5);
				polynomial<float> poly2(5);
				arrow = 1;
				while (true)
				{
					system("cls");
					int start_menu = startMenu(poly1, poly2, arrow);
					if (start_menu == VK_ESCAPE)
					{
						arrow = 1;
						break;
					}
					else if (start_menu == 72 && arrow > 1)
						arrow--;
					else if (start_menu == 80 && arrow < 4)
						arrow++;
					else if (start_menu == VK_RETURN)
					{
						if (arrow == 1)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly1, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										floatMult(poly1);
									}
									if (arrow == 2)
									{
										deleteDegree(poly1);
									}
									if (arrow == 3)
									{
										addFloatDegree(poly1);
									}
									if (arrow == 4)
									{
										poly1 = poly1.randomize();
									}
									if (arrow == 5)
									{
										floatCalc(poly1);
									}
								}
							}
						}
						if (arrow == 2)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly2, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										floatMult(poly2);
									}
									if (arrow == 2)
									{
										deleteDegree(poly2);
									}
									if (arrow == 3)
									{
										addFloatDegree(poly2);
									}
									if (arrow == 4)
									{
										poly2 = poly2.randomize();
									}
									if (arrow == 5)
									{
										floatCalc(poly2);
									}
								}
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
			}
			else if (arrow == 3)
			{
				polynomial<double> poly1(5);
				polynomial<double> poly2(5);

				arrow = 1;
				while (true)
				{
					system("cls");
					int start_menu = startMenu(poly1, poly2, arrow);
					if (start_menu == VK_ESCAPE)
					{
						arrow = 1;
						break;
					}
					else if (start_menu == 72 && arrow > 1)
						arrow--;
					else if (start_menu == 80 && arrow < 4)
						arrow++;
					else if (start_menu == VK_RETURN)
					{
						if (arrow == 1)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly1, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										doubleMult(poly1);
									}
									if (arrow == 2)
									{
										deleteDegree(poly1);
									}
									if (arrow == 3)
									{
										addDoubleDegree(poly1);
									}
									if (arrow == 4)
									{
										poly1 = poly1.randomize();
									}
									if (arrow == 5)
									{
										doubleCalc(poly1);
									}
								}
							}
						}
						else if (arrow == 2)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly2, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										doubleMult(poly2);
									}
									if (arrow == 2)
									{
										deleteDegree(poly2);
									}
									if (arrow == 3)
									{
										addDoubleDegree(poly2);
									}
									if (arrow == 4)
									{
										poly2 = poly2.randomize();
									}
									if (arrow == 5)
									{
										doubleCalc(poly2);
									}
								}
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
			}
			else if (arrow == 4)
			{
				polynomial<complex<float>> poly1(5);
				polynomial<complex<float>> poly2(5);

				arrow = 1;
				while (true)
				{
					system("cls");
					int start_menu = startMenu(poly1, poly2, arrow);
					if (start_menu == VK_ESCAPE)
					{
						arrow = 1;
						break;
					}
					else if (start_menu == 72 && arrow > 1)
						arrow--;
					else if (start_menu == 80 && arrow < 4)
						arrow++;
					else if (start_menu == VK_RETURN)
					{
						if (arrow == 1)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly1, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										complexFloatMult(poly1);
									}
									if (arrow == 2)
									{
										deleteDegree(poly1);
									}
									if (arrow == 3)
									{
										addComplexFloatDegree(poly1);
									}
									if (arrow == 4)
									{
										poly1 = poly1.randomize();
									}
									if (arrow == 5)
									{
										complexFloatCalc(poly1);
									}
								}
							}
						}
						else if (arrow == 2)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly2, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										complexFloatMult(poly2);
									}
									if (arrow == 2)
									{
										deleteDegree(poly2);
									}
									if (arrow == 3)
									{
										addComplexFloatDegree(poly2);
									}
									if (arrow == 4)
									{
										poly2 = poly2.randomize();
									}
									if (arrow == 5)
									{
										complexFloatCalc(poly2);
									}
								}
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
			}
			else if (arrow == 5)
			{
				polynomial<complex<double>> poly1(5);
				polynomial<complex<double>> poly2(5);

				arrow = 1;
				while (true)
				{
					system("cls");
					int start_menu = startMenu(poly1, poly2, arrow);
					if (start_menu == VK_ESCAPE)
					{
						arrow = 1;
						break;
					}
					else if (start_menu == 72 && arrow > 1)
						arrow--;
					else if (start_menu == 80 && arrow < 4)
						arrow++;
					else if (start_menu == VK_RETURN)
					{
						if (arrow == 1)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly1, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										complexDoubleMult(poly1);
									}
									if (arrow == 2)
									{
										deleteDegree(poly1);
									}
									if (arrow == 3)
									{
										addComplexDoubleDegree(poly1);
									}
									if (arrow == 4)
									{
										poly1 = poly1.randomize();
									}
									if (arrow == 5)
									{
										complexDoubleCalc(poly1);
									}
								}
							}
						}
						else if (arrow == 2)
						{
							arrow = 1;
							while (true)
							{
								system("cls");
								int poly_menu = polynomialMenu(poly2, arrow);
								if (poly_menu == VK_ESCAPE)
								{
									arrow = 1;
									break;
								}
								else if (poly_menu == 72 && arrow > 1)
									arrow--;
								else if (poly_menu == 80 && arrow < 5)
									arrow++;
								else if (poly_menu == VK_RETURN)
								{
									if (arrow == 1)
									{
										complexDoubleMult(poly2);
									}
									if (arrow == 2)
									{
										deleteDegree(poly2);
									}
									if (arrow == 3)
									{
										addComplexDoubleDegree(poly2);
									}
									if (arrow == 4)
									{
										poly2 = poly2.randomize();
									}
									if (arrow == 5)
									{
										complexDoubleCalc(poly2);
									}
								}
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

			}
		}
	}
	return 0;
}