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

#include <p2shape.h>

p2CircleShape::p2CircleShape()
{
	p2CircleShape::SetType(Type::CIRCLE);
}

void p2CircleShape::SetType(Type type)
{
	p2Shape::type = type;
}

p2CircleShape::p2CircleShape(float m_Radius, Type type)
{
	type = Type::CIRCLE;
	this->m_Radius = m_Radius;
	this->type = type;
}

void p2CircleShape::SetRadius(float radius)
{
	m_Radius = radius;
}

float p2CircleShape::GetRadius()
{
	return m_Radius;
}

p2RectShape::p2RectShape()
{
	p2RectShape::SetType(Type::RECTANGLE);
}

void p2RectShape::SetType(Type type)
{
	p2RectShape::type = type;
}

p2RectShape::p2RectShape(p2Vec2 m_Size, Type type)
{
	type = Type::RECTANGLE;
	this->m_Size = m_Size;
	this->type = type;
}

void p2RectShape::SetSize(p2Vec2 size)
{
	m_Size = size;
}

Type p2Shape::GetType()
{
	return type;
}
