#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#define MAX_CHARACHTERS 70

using namespace std;

namespace sdds {

	const char defSymbol[9] = "+-+|+-+|";

	class Label {

		char symbol[9];
		char* frameLine;

	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();

		std::ostream& printLabel() const;
	};
}
#endif // !SDDS_LABEL_H
