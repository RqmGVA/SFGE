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

int main()
{
	p2Mat33 mat1(p2Vec3(-1,2,3), p2Vec3(-2,1,4), p2Vec3(2,1,5));
	p2Mat33 mat2 = mat1.Invert();
		//std::cout << v1.x << v1.y << v1.z;
	std::cout << mat2.columns[0].x << "\n" << mat2.columns[0].y << "\n" << mat2.columns[0].z << "\n" << mat2.columns[1].x << "\n" << mat2.columns[1].y << "\n" << mat2.columns[1].z << "\n" << mat2.columns[2].x << "\n" << mat2.columns[2].y << "\n" << mat2.columns[2].z << "\n";
	
	
	system("PAUSE");

	
}