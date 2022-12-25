#ifndef MANACOST_H
#define MANACOST_H

class ManaCost {

	private:
		int W;
		int U;
		int B;
		int R;
		int G;
		int generic;

	public:
		ManaCost(){}

		ManaCost(
			int W
			, int U
			, int B
			, int R
			, int G
			, int generic
		);
};

#endif