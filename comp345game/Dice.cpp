#include "dice.h"


int Dice::roll(string input) {
	size_t indexD = input.find('d');
	size_t indexSize = input.find('[');
	size_t indexAdd = input.find('+');
	
	int nbOfDice, diceSize, addNum, total = 0;
	if (indexD != string::npos && indexD > 0) {
		nbOfDice = stoi(input.substr(0,indexD));
		if (indexSize != string::npos) {
			diceSize = stoi(input.substr(indexD+1,indexSize));
			if (indexAdd != string::npos) {
				addNum = stoi(input.substr(indexAdd, input.size()-1));
				for (int i = 0; i < nbOfDice; i++) {
					total += rand() % diceSize + 1;
				}
				total += addNum;
				return total;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

//int main() {
//	Dice d;
//	while (true) {
//		cout << "Input dice format xdy[+z]: " << endl;
//		string val;
//		cin >> val;
//		cout << "Dice rolled: " << d.roll(val) << endl;
//		system("pause");
//	}
//	return 0;
//}