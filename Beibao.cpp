#include "stdafx.h"
#include "Beibao.h"


Beibao::Beibao()
{
	ioIn();
	
}




Beibao::~Beibao()
{
}
int Beibao::getMaxValue(){
	return getMaxValue(maxWight, num, weight, value);
}

int Beibao::getMaxValue(int maxWeight, int num, int *weight, int *value){
	int temp = 0;
	nvalue = new int*[num+1];
	for (int i = 0; i <= num; i++){
		nvalue[i] = new int[maxWight + 1];
		nvalue[i][0] = 0;
	}
	for (int i = 0; i <= maxWeight; i++){
		nvalue[0][i] = 0;
	}
	for (int i = 1; i <= num; i++){
		for (int j = 1; j <= maxWeight; j++){
			if (weight[i-1] > j){
				nvalue[i][j] = nvalue[i - 1][j];
			}
			else{
				
				nvalue[i][j] = max(nvalue[i - 1][j], nvalue[i - 1][j - weight[i-1]] + value[i-1]);
			}
		}
	}

	int max = maxWeight;
	for (int i = num; i>0; i--){
		if (max <= 0){
			break;
		}
		if (nvalue[i][max] > nvalue[i - 1][max]){
			select[i-1] = 1;
			max -= weight[i - 1];
		}
	}

	for (int i = 0; i < num; i++){
		cout << select[i];
	}
	cout << endl;
	cout << nvalue[num][maxWeight] << endl;
	return nvalue[num][maxWeight];
}

void Beibao::ioIn(){
	cin >> maxWight >> num;
	weight = new int[num];
	value = new int[num];
	select = new int[num];
	
	for (int i = 0; i < num; i++){
		cin >> weight[i] >> value[i];
		select[i] = 0;
	}
}


