/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <p2matrix.h>
#include <iostream>

p2Mat22::p2Mat22()
{
}

p2Mat22::p2Mat22(p2Vec2 r1, p2Vec2 r2)
{
	this->columns[0] = r1;
	this->columns[1] = r2;
}

p2Mat22 p2Mat22::operator+(p2Mat22 m1)
{
	
	return p2Mat22
		   (p2Vec2(columns[0].x + m1.columns[0].x, columns[0].y + m1.columns[0].y), 
		    p2Vec2(columns[1].x + m1.columns[1].x, columns[1].y + m1.columns[1].y));
}

p2Mat22 p2Mat22::operator-(p2Mat22 m1)
{
	return p2Mat22
		   (p2Vec2(columns[0].x - m1.columns[0].x, columns[0].y - m1.columns[0].y),
			p2Vec2(columns[1].x - m1.columns[1].x, columns[1].y - m1.columns[1].y));
}

p2Mat22 p2Mat22::operator*(p2Mat22 m1)
{
	return p2Mat22
		   (p2Vec2(columns[0].x * m1.columns[0].x + columns[1].x * m1.columns[0].y,
		           columns[0].y * m1.columns[0].x + columns[1].y * m1.columns[0].y),
		    p2Vec2(columns[0].x * m1.columns[1].x + columns[1].x * m1.columns[1].y,
			       columns[0].y * m1.columns[1].x + columns[1].y * m1.columns[1].y));
}

p2Vec2 p2Mat22::operator*(p2Vec2 v)
{
	return p2Vec2(columns[0].x * v.x + columns[1].x * v.y,
				  columns[0].y * v.x + columns[1].y * v.y);
}

p2Mat22 p2Mat22::operator*(float f)
{
	return p2Mat22
		  (p2Vec2(columns[0].x * f , columns[0].y * f),
		   p2Vec2(columns[1].x * f , columns[1].y * f));
}

p2Mat22 p2Mat22::operator/(float f)
{
	return p2Mat22
	      (p2Vec2(columns[0].x / f, columns[0].y / f),
		   p2Vec2(columns[1].x / f, columns[1].y / f));
}

p2Mat22 p2Mat22::Invert()
{
	if (this->GetDeterminant() == 0)
	{
		std::cout << "This matrix is singular and has no inverse.\n";
	}
	else
	{
		p2Mat22 coMatrix(p2Vec2(columns[1].y, -columns[0].y),
					     p2Vec2(-columns[1].x, columns[0].x));

		return p2Mat22(coMatrix.operator*(1 / this->GetDeterminant())) ;
	}
	
}

float p2Mat22::GetDeterminant()
{
	return columns[0].x * columns[1].y - columns[0].y * columns[1].x;
}

p2Mat33::p2Mat33()
{
}

p2Mat33::p2Mat33(p2Vec3 r1, p2Vec3 r2, p2Vec3 r3)
{
	this->columns[0] = r1;
	this->columns[1] = r2;
	this->columns[2] = r3;
}

p2Mat33 p2Mat33::operator+(p2Mat33 m1)
{
	return p2Mat33
	      (p2Vec3(columns[0].x + m1.columns[0].x, columns[0].y + m1.columns[0].y, columns[0].z + m1.columns[0].z),
		   p2Vec3(columns[1].x + m1.columns[1].x, columns[1].y + m1.columns[1].y, columns[1].z + m1.columns[1].z),
		   p2Vec3(columns[2].x + m1.columns[2].x, columns[2].y + m1.columns[2].y, columns[2].z + m1.columns[2].z));
}

p2Mat33 p2Mat33::operator-(p2Mat33 m1)
{
	return p2Mat33
		  (p2Vec3(columns[0].x - m1.columns[0].x, columns[0].y - m1.columns[0].y, columns[0].z - m1.columns[0].z),
		   p2Vec3(columns[1].x - m1.columns[1].x, columns[1].y - m1.columns[1].y, columns[1].z - m1.columns[1].z),
		   p2Vec3(columns[2].x - m1.columns[2].x, columns[2].y - m1.columns[2].y, columns[2].z - m1.columns[2].z));
}

p2Mat33 p2Mat33::operator*(p2Mat33 m1)
{
	return p2Mat33
	      (p2Vec3(columns[0].x * m1.columns[0].x + columns[1].x * m1.columns[0].y + columns[2].x * m1.columns[0].z,
		          columns[0].y * m1.columns[0].x + columns[1].y * m1.columns[0].y + columns[2].y * m1.columns[0].z,
				  columns[0].z * m1.columns[0].x + columns[1].z * m1.columns[0].y + columns[2].z * m1.columns[0].z),
		   p2Vec3(columns[0].x * m1.columns[1].x + columns[1].x * m1.columns[1].y + columns[2].x * m1.columns[1].z,
			      columns[0].y * m1.columns[1].x + columns[1].y * m1.columns[1].y + columns[2].y * m1.columns[1].z,
				  columns[0].z * m1.columns[1].x + columns[1].z * m1.columns[1].y + columns[2].z * m1.columns[1].z),
		   p2Vec3(columns[0].x * m1.columns[2].x + columns[1].x * m1.columns[2].y + columns[2].x * m1.columns[2].z,
			      columns[0].y * m1.columns[2].x + columns[1].y * m1.columns[2].y + columns[2].y * m1.columns[2].z,
			      columns[0].z * m1.columns[2].x + columns[1].z * m1.columns[2].y + columns[2].z * m1.columns[2].z));
}

p2Vec3 p2Mat33::operator*(p2Vec3 v)
{
	return p2Vec3
	            (columns[0].x * v.x + columns[1].x * v.y + columns[2].x * v.z,
			     columns[0].y * v.x + columns[1].y * v.y + columns[2].y * v.z,
				 columns[0].z * v.x + columns[1].z * v.y + columns[2].z * v.z);
}

p2Mat33 p2Mat33::operator*(float f)
{
	return p2Mat33
				 (p2Vec3(columns[0].x * f, columns[0].y * f, columns[0].z * f),
				  p2Vec3(columns[1].x * f, columns[1].y * f, columns[1].z * f),
				  p2Vec3(columns[2].x * f, columns[2].y * f, columns[2].z * f));
}

p2Mat33 p2Mat33::operator/(float f)
{
	return p2Mat33
				 (p2Vec3(columns[0].x / f, columns[0].y / f, columns[0].z / f),
				  p2Vec3(columns[1].x / f, columns[1].y / f, columns[1].z / f),
				  p2Vec3(columns[2].x / f, columns[2].y / f, columns[2].z / f));
}

p2Mat33 p2Mat33::Invert()
{
	p2Mat22	subMatrix1
					 (p2Vec2(columns[1].y, columns[1].z),
					  p2Vec2(columns[2].y, columns[2].z));
	p2Mat22 subMatrix2
					 (p2Vec2(columns[0].y, columns[0].z),
					  p2Vec2(columns[2].y, columns[2].z));
	p2Mat22 subMatrix3
					 (p2Vec2(columns[0].y, columns[0].z),
					  p2Vec2(columns[1].y, columns[1].z));
	p2Mat22	subMatrix4
					 (p2Vec2(columns[1].x, columns[1].z),
		              p2Vec2(columns[2].x, columns[2].z));
	p2Mat22	subMatrix5
					 (p2Vec2(columns[0].x, columns[0].z),
					  p2Vec2(columns[2].x, columns[2].z));
	p2Mat22	subMatrix6
					 (p2Vec2(columns[0].x, columns[0].z),
					  p2Vec2(columns[1].x, columns[1].z));
	p2Mat22	subMatrix7
					 (p2Vec2(columns[1].x, columns[1].y),
				   	  p2Vec2(columns[2].x, columns[2].y));
	p2Mat22	subMatrix8
					 (p2Vec2(columns[0].x, columns[0].y),
					  p2Vec2(columns[2].x, columns[2].y));
	p2Mat22	subMatrix9
					 (p2Vec2(columns[0].x, columns[0].y),
					  p2Vec2(columns[1].x, columns[1].y));

	p2Mat33 coMatrix
					 (p2Vec3(subMatrix1.GetDeterminant(), -subMatrix4.GetDeterminant(), subMatrix7.GetDeterminant()),
					  p2Vec3(-subMatrix2.GetDeterminant(), subMatrix5.GetDeterminant(), -subMatrix8.GetDeterminant()),
					  p2Vec3(subMatrix3.GetDeterminant(), -subMatrix6.GetDeterminant(), subMatrix9.GetDeterminant()));
	p2Mat33 transposedMatrix
					 (p2Vec3(coMatrix.columns[0].x, coMatrix.columns[1].x, coMatrix.columns[2].x),
					  p2Vec3(coMatrix.columns[0].y, coMatrix.columns[1].y, coMatrix.columns[2].y),
					  p2Vec3(coMatrix.columns[0].z, coMatrix.columns[1].z, coMatrix.columns[2].z));
	return p2Mat33 (transposedMatrix.operator*(1/this->GetDeterminant()));
}

float p2Mat33::GetDeterminant()
{
	p2Mat22 subMatrix1
					 (p2Vec2(columns[1].y, columns[1].z),
					  p2Vec2(columns[2].y, columns[2].z));
	p2Mat22 subMatrix2
					 (p2Vec2(columns[0].y, columns[0].z),
					  p2Vec2(columns[2].y, columns[2].z));
	p2Mat22 subMatrix3
					 (p2Vec2(columns[0].y, columns[0].z),
					  p2Vec2(columns[1].y, columns[1].z));
	return columns[0].x * subMatrix1.GetDeterminant() 
		 - columns[1].x * subMatrix2.GetDeterminant() 
		 + columns[2].x * subMatrix3.GetDeterminant();
}
