#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Typings.h"

class TypeChart {
private:							//        n   g   f   w   e   g   b   f   r   p   f   p   g   i   d   d   s   f
	//[attacking type] [defending type]       o   r   i   a   l   r   u   l   o   o   i   s   h   c   r   a   t   a
	//n = x1, s = x2, h = x0.5, x = x0        r   a   r   t   e   o   g   y   c   i   g   y   o   e   a   r   e   i
	const char chart[18][18] = {	/*nor*/	{'n','n','n','n','n','n','n','n','h','n','n','n','x','n','n','n','h','n'},
									/*gra*/	{'n','h','h','s','n','s','h','h','s','h','n','n','n','n','h','n','h','n'},
									/*fir*/	{'n','s','h','h','n','n','s','n','h','n','n','n','n','s','h','n','s','n'},
									/*wat*/	{'n','h','s','h','n','s','n','n','s','n','n','n','n','h','h','n','n','n'},
									/*ele*/ {'n','h','n','s','h','x','n','s','h','n','n','n','n','n','h','n','n','n'},
									/*gro*/	{'n','h','s','n','s','n','h','x','s','s','n','n','n','n','n','n','s','n'},
									/*bug*/	{'n','s','h','n','n','n','n','h','n','h','h','s','n','n','n','s','h','s'},
									/*fly*/	{'n','s','n','n','h','n','s','n','h','n','s','n','n','n','n','n','h','n'},
									/*roc*/	{'n','n','s','n','n','h','s','s','n','n','h','n','n','s','n','n','h','n'},
									/*poi*/	{'n','s','n','s','n','h','h','n','h','h','n','n','h','n','n','h','x','s'},
									/*fig*/ {'s','n','n','n','n','n','h','h','s','h','n','h','x','s','n','s','s','h'},
									/*psy*/	{'n','n','n','n','n','n','h','n','n','s','s','h','h','h','n','x','n','n'},
									/*gho*/	{'x','n','n','n','n','h','n','n','n','n','n','s','s','n','n','h','n','s'},
									/*ice*/	{'n','s','n','h','n','s','n','s','n','n','n','n','n','h','s','n','h','n'},
									/*dra*/	{'n','n','n','n','n','n','n','n','n','n','n','n','n','n','s','n','h','x'},
									/*dar*/	{'n','n','n','n','n','n','n','n','n','n','h','s','s','n','n','h','n','h'},
									/*ste*/	{'n','h','h','h','h','n','n','n','s','n','n','n','n','s','n','n','h','s'},
									/*fai*/	{'n','n','h','n','n','n','n','n','n','h','s','n','n','n','s','s','h','h'} };

	//something
public:
	std::string GetDefenses(Typings type1, Typings type2 = NONE_TYPE) {
		char type1Def[18] = {};
		for (int i = 0; i < 18; i++) {
			type1Def[i] = chart[i][type1];
		}
		char type2Def[18] = {'n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n','n' };
		if (type2 != NONE_TYPE) {
			for (int i = 0; i < 18; i++) {
				type2Def[i] = chart[i][type2];
			}
		}

		std::vector<std::string> x4;
		std::vector<std::string> x2;
		std::vector<std::string> x1;
		std::vector<std::string> x05;
		std::vector<std::string> x025;
		std::vector<std::string> x0;
		for (int i = 0; i < 18; i++) {
			if (type1Def[i] == 'x' || type2Def[i] == 'x') {
				x0.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 'n' && type2Def[i] == 'n') {
				x1.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 's' && type2Def[i] == 's') {
				x4.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 'h' && type2Def[i] == 'h') {
				x025.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 'h' && type2Def[i] == 's') {
				x1.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 's' && type2Def[i] == 'h') {
				x1.push_back(TypeToString((Typings)i));
				continue;
			}
			//N and another
			if (type1Def[i] == 's' || type2Def[i] == 's') {
				x2.push_back(TypeToString((Typings)i));
			}
			if (type1Def[i] == 'h' || type2Def[i] == 'h') {
				x05.push_back(TypeToString((Typings)i));
			}
		}

		std::string output = "Defensive\n";
		output += TypeToString(type1) + "/" + TypeToString(type2);
		output += "\n\n";

		output += "x4 effective: ";
		for (int i = 0; i < x4.size(); i++) {
			output += x4[i] + ", ";
		}
		output += "\n\n";

		output += "x2 effective: ";
		for (int i = 0; i < x2.size(); i++) {
			output += x2[i] + ", ";
		}
		output += "\n\n";

		output += "x1 effective: ";
		for (int i = 0; i < x1.size(); i++) {
			output += x1[i] + ", ";
		}
		output += "\n\n";

		output += "x1/2 effective: ";
		for (int i = 0; i < x05.size(); i++) {
			output += x05[i] + ", ";
		}
		output += "\n\n";

		output += "x1/4 effective: ";
		for (int i = 0; i < x025.size(); i++) {
			output += x025[i] + ", ";
		}
		output += "\n\n";

		output += "x0 effective: ";
		for (int i = 0; i < x0.size(); i++) {
			output += x0[i] + ", ";
		}
		output += "\n\n";

		return output;
	}

	std::string GetOffenses(Typings type1, Typings type2 = NONE_TYPE) {
		char type1Def[18] = {};
		for (int i = 0; i < 18; i++) {
			type1Def[i] = chart[type1][i];
		}
		char type2Def[18] = { 'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x' };
		if (type2 != NONE_TYPE) {
			for (int i = 0; i < 18; i++) {
				type2Def[i] = chart[type2][i];
			}
		}

		std::vector<std::string> x2;
		std::vector<std::string> x1;
		std::vector<std::string> x05;
		std::vector<std::string> x0;
		for (int i = 0; i < 18; i++) {
			if (type1Def[i] == 's' || type2Def[i] == 's') {
				x2.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 'n' || type2Def[i] == 'n') {
				x1.push_back(TypeToString((Typings)i));
				continue;
			}
			if (type1Def[i] == 'h' || type2Def[i] == 'h') {
				x05.push_back(TypeToString((Typings)i));
				continue;
			}
			x0.push_back(TypeToString((Typings)i));
		}

		std::string output = "Offensive\n";
		output += TypeToString(type1) + "/" + TypeToString(type2);
		output += "\n\n";

		output += "x2 effective: ";
		for (int i = 0; i < x2.size(); i++) {
			output += x2[i] + ", ";
		}
		output += "\n\n";

		output += "x1 effective: ";
		for (int i = 0; i < x1.size(); i++) {
			output += x1[i] + ", ";
		}
		output += "\n\n";

		output += "x1/2 effective: ";
		for (int i = 0; i < x05.size(); i++) {
			output += x05[i] + ", ";
		}
		output += "\n\n";

		output += "x0 effective: ";
		for (int i = 0; i < x0.size(); i++) {
			output += x0[i] + ", ";
		}
		output += "\n\n";

		return output;
	}

	float GetEffectiveness(Typings attackType, Typings defendingType1, Typings defendingType2 = NONE_TYPE) {
		char type1eff = chart[attackType][defendingType1];
		char type2eff;
		if (defendingType2 != NONE_TYPE) {
			type2eff = chart[attackType][defendingType2];
		}
		else {
			type2eff = 'n';
		}

		if (type1eff == 'x' || type2eff == 'x') {
			return 0.0f;
		}
		if (type1eff == 's' && type2eff == 's') {
			return 4.0f;
		}
		if (type1eff == 'n' && type2eff == 'n') {
			return 1.0f;
		}
		if (type1eff == 'h' && type2eff == 'h') {
			return 0.25f;
		}
		if (type1eff == 's' && type2eff == 'h') {
			return 1.0f;
		}
		if (type1eff == 'h' && type2eff == 's') {
			return 1.0f;
		}
		if (type1eff == 's' || type2eff == 's') {
			return 2.0f;
		}
		if (type1eff == 'h' || type2eff == 'h') {
			return 0.5f;
		}

		return 1.0f;
	}
};

static TypeChart chart;