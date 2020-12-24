#pragma once
class Node
{
private:
	int frequency;
	char ch;
public:
	Node();
	Node(char ch, int frequency = 0);
	~Node();
	
	bool setCh(char ch);
	bool setFreq(int frequency);
	
	void addFreq(int num);
	
	char getChar();
	int getFreq();
};

