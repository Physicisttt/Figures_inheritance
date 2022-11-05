#include <iostream>
#include <vector>

using namespace std;

enum figure_list
{
	Empty = 0,
	First = 1,
	Circ = First,
	Rect,
	Hex,
	Last
};

class BoundingRectangle
{
public:
	double x1 = 0;//x_topleft
	double y2 = 0;//y_topleft
	double x2 = 0;//x_downright
	double y1 = 0;//y_downright

	BoundingRectangle()
	{}

	BoundingRectangle(double new_x1, double new_x2, double new_y1, double new_y2)
	{
		x1 = new_x1;
		x2 = new_x2;
		y1 = new_y1;
		y2 = new_y2;
	}

	void printBoundingRectangle()
	{
		cout << "bounding rectangle: " << endl
			<< "x1 = " << x1 << " y1 = " << y1 << endl
			<< "x2 = " << x2 << " y2 = " << y2 << endl;
	}
};

class Figure
{
public:
	int type_id = 0;

	virtual void print() = 0;

	/*virtual void print()
	{
		cout << "print Figure!" << endl;
	}*/

	virtual double getSquare()
	{
		cout << "print Figure!" << endl;
		return 0;
	}

	virtual BoundingRectangle getBoundingRect()
	{
		cout << "not implemented!" << endl;

		return BoundingRectangle(0, 0, 0, 0);
	}
};

class Rectangle : public Figure
{
public:
	double x1 = 0;//x_topleft
	double y2 = 0;//y_topleft
	double x2 = 0;//x_downright
	double y1 = 0;//y_downright

	double getX1()
	{
		return x1;//x_topleft
	}

	double getY2()
	{
		return y2;//y_topleft
	}

	double getX2()
	{
		return x2;//x_downright
	}

	double getY1()
	{
		return y1;//y_downright
	}

	double getLength()
	{
		return x2 - x1;
	}

	double getWidth()
	{
		return y1 - y2;
	}

	double getSquare()
	{
		return getLength() * getWidth();
	}

	BoundingRectangle getBoundingRect()
	{
		return BoundingRectangle(x1, x2, y1, y2);
	}

	void setCoordinates(double x_topleft, double y_topleft, double x_downright, double y_downright)//setX & setY
	{
		x1 = x_topleft;
		y2 = y_topleft;
		x2 = x_downright;
		y1 = y_downright;
	}

	void print_rec()
	{
		cout << "bounding rectangle: " << endl
			<< "x1 = " << x1 << " y1 = " << y1 << endl
			<< "x2 = " << x2 << " y2 = " << y2 << endl;
	}

	void print()
	{
		cout << "bounding rectangle: " << endl
			<< "x1 = " << x1 << " y1 = " << y1 << endl
			<< "x2 = " << x2 << " y2 = " << y2 << endl;
	}
};

class Circle : public Figure
{
public:
	double x_centre = 0;
	double y_centre = 0;
	double radius = 0;

	BoundingRectangle getBoundingRect()
	{
		//x1 ---> x_topleft
		//x2 ---> x_downright
		//y1 ---> y_downright
		//y2 ---> y_topleft
		
		return BoundingRectangle(
					x_centre - radius,
					x_centre + radius,
					y_centre - radius,
					y_centre + radius);
	}

	double getX_Centre()
	{
		return x_centre;
	}

	double getY_Centre()
	{
		return y_centre;
	}

	double getRadius()
	{
		return radius;
	}

	double getSquare()
	{
		return (3.1415 * pow(radius, 2));
	}

	void setCoordinates(double x_in, double y_in)//setX & setY
	{
		x_centre = x_in;
		y_centre = y_in;
	}

	void setRadius(double rad)
	{
		radius = rad;
	}

	void printCircle()
	{
		cout << "CIRCLE" << endl;
		cout << "Radius: " << radius << endl;
		cout << "x: " << x_centre << " y: " << y_centre << endl;
	}

	void print()
	{
		cout << "CIRCLE" << endl;
		cout << "Radius: " << radius << endl;
		cout << "x: " << x_centre << " y: " << y_centre << endl;
	}
};

class Hexagon : public Figure
{
public:
	double x_centre = 0;//HOW ?????
	double y_centre = 0;//HOW ?????
	double sRadius = 0;
	double bRadius = 0;
	double length = 0;
	//bRadius == length

	double getX_Centre()
	{
		return x_centre;
	}

	double getY_Centre()
	{
		return y_centre;
	}

	double getSRadius()
	{
		return sRadius;
	}

	double getBRadius()
	{
		return bRadius;
	}

	double getLength()
	{
		return length;
	}

	double getSquare()
	{
		return ((3 * sqrt(3) * pow(length, 2)) / (2));
	}

	BoundingRectangle getBoundingRect()
	{
		return BoundingRectangle(
			x_centre - sRadius,
			x_centre + sRadius,
			y_centre + bRadius,
			y_centre - bRadius);
	}

	void setCoordinates(double x_in, double y_in)
	{
		x_centre = x_in;
		y_centre = y_in;
	}

	void setSRadius(double sRad)
	{
		this->sRadius = sRad;
	}

	void setBRadius(double bRad)
	{
		this->bRadius = bRad;
	}

	void setLength(double len)
	{
		this->length = len;
	}

	void printHexagon()
	{
		cout << "HEXAGON" << endl;
	}

	void print()
	{
		cout << "HEXAGON" << endl;
	}
};

int main(void)
{
	vector<Figure*> Scene;

	Scene.resize(5);

	Circle Cir1;
	Cir1.radius = 3;
	Cir1.setCoordinates(1, 5);

	Figure* F1;
	F1 = &Cir1;
	Scene[0] = F1;

	cout << "virtual print test" << endl;
	F1->print();
	Scene[0]->print();

	
	

	return 1;
}