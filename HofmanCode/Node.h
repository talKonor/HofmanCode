#pragma once
class Node
{
private:
	int frequency;
	char ch;

public:
	Node();
	Node(char ch, int frequency = 1);
	~Node();

	bool setCh(char ch);
	bool setFreq(int frequency);

	void addFreq(int num = 1);

	char getChar();
	int getFreq();
};

