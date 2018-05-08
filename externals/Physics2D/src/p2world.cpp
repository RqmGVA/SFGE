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
#include <p2world.h>
#include <p2body.h>
#include <p2contact.h>


p2World::p2World(p2Vec2 gravity): m_Gravity(gravity)
{

}

void p2World::Step(float dt)
{

	//I wanted to do a test here : show "Contact" on the console if the both AABB of test_contact collide, but too late
	for (std::list<p2Body>::iterator it = bodies.begin(); it != bodies.end(); it++)
	{
		it->SetPosition(it->GetLinearVelocity() * dt);
	}
}

p2Body * p2World::CreateBody(p2BodyDef* bodyDef)
{
	p2Body newBody = p2Body(bodyDef, this);
	bodies.push_front(newBody);
	return&(*bodies.begin());
}

void p2World::SetContactListener(p2ContactListener * contactListener)
{
	listener = contactListener;
}
