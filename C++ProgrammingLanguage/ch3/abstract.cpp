#include<vector>

class Shape{
public:
	virtual Point center() const =0;
	virtual void move(Point to) =0;

	virtual void draw() const =0;
	virtual void rotate(int angle) =0;

	virtual ~Shape(){}
};

class Circle : public Shape{
public:
	Circle(Point p, int rr):x{p},r{rr} {}

	Point center() const
	void move(Point to){ x = to;}

	void draw() const;
	void rotate(int i) {}

private:
	Point x;
	int r;
};



