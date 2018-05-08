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
#include <p2body.h>
#include <p2collider.h>

p2Body::p2Body(p2BodyDef* p2BodyDef, p2World* world)
{

	this->world = world;
	position = p2BodyDef->position;

	/*switch (p2BodyType)
	{
	case p2BodyType::STATIC:
		p2BodyDef->type = p2BodyType::STATIC;
		break;
	case p2BodyType::KINEMATIC:
		p2BodyDef->type = p2BodyType::KINEMATIC;
		break;
	case p2BodyType::DYNAMIC:
		p2BodyDef->type = p2BodyType::DYNAMIC;
		break;
	}*/
	mass = p2BodyDef->mass;
	type = p2BodyDef->type;
	linearVelocity = p2BodyDef->linearVelocity;
}

p2Vec2 p2Body::GetLinearVelocity()
{
	return linearVelocity;
}

void p2Body::addforce(p2Vec2 f)
{
	this->force = f;
}

void p2Body::SetLinearVelocity(p2Vec2 velocity)
{
	linearVelocity = velocity;
}
float p2Body::GetAngularVelocity()
{
	return angularVelocity;
}

bool p2Body::CheckContact(p2Body *)
{
		p2Vec2 body1 = this->aabb.GetCenter() - p2Vec2(this->aabb.GetHalfExtends().x, this->aabb.GetHalfExtends().y);
		p2Vec2 body2 = body->aabb.GetCenter() - p2Vec2(body->aabb.GetHalfExtends().x, body->aabb.GetHalfExtends().y);


		if ((body2.x >= body1.x + this->aabb.GetHalfExtends().x * 2) || (body2.x + body->aabb.GetHalfExtends().x * 2 <= body1.x)
			|| (body2.y >= body1.y + this->aabb.GetHalfExtends().y * 2) || (body2.y + body->aabb.GetHalfExtends().y * 2 <= body1.y))
		{
			return false;
		}
		else
		{
			return true;
		}
	}


p2Vec2 p2Body::GetPosition()
{
	return position;
}

float p2Body::GetMass()
{
	return mass;
}

void p2Body::SetMass(float mass)
{
	this->mass = mass;
}

void p2Body::addBody(p2Body * body)
{
	bodies.push_front(*body);
}

void p2Body::SetPosition(p2Vec2 p)
{
	this->position = position + p;
}



p2Collider * p2Body::CreateCollider(p2ColliderDef * colliderDef)
{
	p2Shape* shape = colliderDef->shape;

	if (shape->GetType() == Type::CIRCLE)
	{
		p2CircleShape* shapeCircle = dynamic_cast<p2CircleShape>(shape);
		aabb = p2AABB(position, p2Vec2(shapeCircle->GetRadius(), shapeCircle->GetRadius()));
	}
	if (shape->GetType() == Type::RECTANGLE)
	{
		p2RectShape shapeRectangle = dynamic_cast<p2RectShape*>(shape);
		aabb = p2AABB(position, p2Vec2(shapeRectangle->GetSize().x, shapeRectangle->GetSize().y));
	}

	collider = new p2Collider(colliderDef, this);
	return collider;
}