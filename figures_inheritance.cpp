#include <iostream>
#include <vector>

using namespace std;

int random_int(int left_border, int right_border)
{
	return left_border + rand() % (right_border - left_border + 1);
}

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
		: x1(new_x1), x2(new_x2), y1(new_y1), y2(new_y2){}

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

	virtual double getSquare()
	{
		cout << "not implemented!" << endl;
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
		cout << "RECTANGLE: " << endl
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

Figure* createRectangle()
{
	// random number in [left, right]
	int left = 1;
	int right = 20;

	Rectangle* newRectangle = new Rectangle;

	newRectangle->x1 = random_int(left, right);
	newRectangle->y1 = random_int(left, right);
	int len = random_int(left, right);
	int wid = random_int(left, right);
	newRectangle->x2 = newRectangle->x1 + len;
	newRectangle->y2 = newRectangle->y1 + wid;

	Figure* newFigure;
	newFigure = newRectangle;
	newFigure->type_id = figure_list::Rect;

	return newFigure;
}

Figure* createCircle()
{
	// random number in [left, right]
	int left = 3;
	int right = 20;

	//min and max value of radius
	int rad_min = 2;
	int rad_max = 7;

	Circle* newCircle = new Circle;
	newCircle->radius = random_int(rad_min, rad_max);
	newCircle->setCoordinates(random_int(left, right), random_int(left, right));

	Figure* newFigure;
	newFigure = newCircle;
	newFigure->type_id = figure_list::Circ;

	return newFigure;
}

Figure* createHexagon()
{
	// random number in [left, right]
	int left = 1;
	int right = 20;

	//how should I describe hexagon?

	Hexagon* newHexagon = new Hexagon;
	//filling hexagon


	Figure* newFigure;
	newFigure = newHexagon;
	newFigure->type_id = figure_list::Hex;

	return newFigure;
}

Figure* createFigure()
{
	int type = random_int(figure_list::Circ, figure_list::Rect);

	switch (type)
	{
	case figure_list::Circ:
	{
		return createCircle();
		break;
	}

	case figure_list::Rect:
	{
		return createRectangle();
		break;
	}

	case figure_list::Hex:
	{
		return createHexagon();
		break;
	}

	default:
		//cout << "createFigure error!" << endl;
		break;
	}

	return nullptr;
}

bool intersection(const BoundingRectangle a, const BoundingRectangle b)
{
	double ax1 = a.x1;
	double ay1 = a.y1;
	double ax2 = a.x2;
	double ay2 = a.y2;

	double bx1 = b.x1;
	double by1 = b.y1;
	double bx2 = b.x2;
	double by2 = b.y2;


	// ax2 < bx1 ---> no intersection on X
	// bx2 < ax1 ---> no intersection on X
	// ay2 < by1 ---> no intersection on Y
	// by2 < ay1 ---> no intersection on Y

	// (ax2 < bx1) || (bx2 < ax1) ---> no intersection on X
	// (ay2 < by1) || (by2 < ay1) ---> no intersection on Y

	//(no X) || (no Y) ---> no intersection
	//( (ax2 < bx1) || (bx2 < ax1) ) || ( (ay2 < by1) || (by2 < ay1) ) ---> no intersection

	if (((ax2 < bx1) || (bx2 < ax1)) || ((ay2 < by1) || (by2 < ay1)))
	{
		return false;// no intersection
	}
	else
	{
		return true;// intersection
	}
}

bool Scene_Intersection(Figure* f, vector<Figure*>& scene)
{
	for (int i = 0; i < scene.size(); i++)
	{
		if (scene[i] != nullptr)//not empty figure
		{
			Figure* oldFigure = scene[i];
			if (intersection(f->getBoundingRect(), oldFigure->getBoundingRect()))
			{
				return true;
			}
		}
		else//empty figure ---> no intersection
		{

		}
	}

	return false;
	//return true; //intersection
	//return false; // no intersection
}

void printFigure(Figure* f)
{
	f->print();
}

void fillScene(vector<Figure*>& scene)
{
	int i = -1;
	int attempts = 0;
	while (attempts <= 100)
	{
		attempts++;

		Figure* newFigure = createFigure();
		if (!Scene_Intersection(newFigure, scene))
		{
			i++;
			cout << "succesfully created figure " << i << " on " << attempts << " attempt" << endl;
			scene.resize(i + 1);
			scene[i] = newFigure;

			attempts = 0;
		}
	}
}

void printScene(vector<Figure*>& scene)
{
	for (int i = 0; i < scene.size(); i++)
	{
		cout << "Figure " << i << " is ";
		printFigure(scene[i]);
		cout << endl;
	}
}

int main(void)
{
	vector<Figure*> Scene;

/*
	//Scene.resize(5);

	Circle Cir1;
	Cir1.radius = 3;
	Cir1.setCoordinates(1, 5);

	Figure* F1;
	F1 = &Cir1;
	Scene[0] = F1;

	Circle Cir2;
	Cir2.radius = 4;
	Cir2.setCoordinates(10,15);

	Figure* F2;
	F2 = &Cir2;
	Scene[1] = F2;
*/
//////////////////////////////////////////////////////////////////////////////////////////

	cout << "\nthis is fillScene test\n" << endl;

	//fillScene1(Scene);
	fillScene(Scene);

//////////////////////////////////////////////////////////////////////////////////////////

	cout << "\nthis is printScene test\n" << endl;
	
	printScene(Scene);


//////////////////////////////////////////////////////////////////////////////////////////
	return 1;
}