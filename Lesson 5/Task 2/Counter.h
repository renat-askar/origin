#pragma once

class Counter
{
	int count{};

	public:
		Counter();
		Counter(int initial);

		const int get() const;
		void decrease();
		void increase();
};
