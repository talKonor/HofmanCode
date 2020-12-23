#include "Node.h"

Node::Node()
{
	frequency = 0;
	ch = -1;
}

Node::Node(char ch, int frequency)
{
	setCh(ch);
	setFreq(frequency);
}

Node::~Node()
{
}

bool Node::setCh(char ch)
{
	this->ch = ch;
	return true;
}

bool Node::setFreq(int frequency)
{
	this->frequency = frequency;
	return true;
}

void Node::addFreq(int num)
{
	this->frequency += num;
}

char Node::getChar()
{
	return ch;
}

int Node::getFreq()
{
	return frequency;
}
