#pragma once


class Beibao
{
public:
	Beibao();
	~Beibao();



	

	int maxWight;
	int num;
	int *weight;
	int *value;
	int *select;
	int **nvalue;
	int getMaxValue();
	int getMaxValue(int maxWeight, int num, int *weight, int *value);

	

	void ioIn();


};

