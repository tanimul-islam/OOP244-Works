//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 10/7/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;

namespace sdds {

	Line::operator const char* () const {
		return (const char*)m_value;
	}

	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}

	Line::~Line() {
		delete[] m_value;
	}

	void TextFile::setFilename(const char* fname, bool isCopy) {
		if (!isCopy) {
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else {
			m_filename = new char[strLen(fname) + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines() {
		ifstream file(m_filename);
		if (file.is_open()) {
			char temp;
			while (file.get(temp)) {
				if (temp == '\n') {
					m_noOfLines++;
				}
			}

			if (file.eof() && m_noOfLines > 0) {
				m_noOfLines++;
			}

			if (m_noOfLines == 0) {
				delete[] m_filename;
				m_filename = nullptr;
			}

			file.close();
		}
		else {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}

	void TextFile::loadText() {
		unsigned i = 0;
		if (m_filename != nullptr) {
			m_textLines = new Line[m_noOfLines];
			ifstream file(m_filename);
			string line;
			if (file.is_open()) {
				for (i = 0; getline(file, line); i++) {
					m_textLines[i].m_value = new char[strLen(line.c_str()) + 1];
					strCpy(m_textLines[i].m_value, line.c_str());
				}
			}
			m_noOfLines = i;
		}
	}

	void TextFile::saveAs(const char* fileName)const {
		unsigned i = 0;
		ofstream out(fileName);
		for (i = 0; i < m_noOfLines; i++)
			out << m_textLines[i] << endl;
	}

	void TextFile::setEmpty() {
		if (m_textLines != nullptr) {
			delete[] m_textLines;
			m_textLines = nullptr;
		}
		if (m_filename != nullptr) {

			delete[] m_filename;
			m_filename = nullptr;
		}

		m_noOfLines = 0;
	}

	TextFile::TextFile(unsigned pageSize) {
		m_filename = nullptr;
		m_noOfLines = 0;
		m_textLines = nullptr;
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) {
		m_pageSize = pageSize;
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		if (filename != nullptr) {
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const TextFile& textFile) {
		m_pageSize = textFile.m_pageSize;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_textLines = nullptr;
		if (this != &textFile) {
			if (textFile.m_filename != nullptr && textFile.m_noOfLines > 0) {
				m_noOfLines = textFile.m_noOfLines;
				setFilename(textFile.m_filename, true);
				loadText();
			}
			saveAs(m_filename);
		}

	}

	TextFile& TextFile::operator=(const TextFile& textFile) {
		if (m_filename != nullptr && m_noOfLines != 0 && textFile.m_filename != nullptr && textFile.m_noOfLines != 0) {
			delete[] m_textLines;
			m_textLines = nullptr;
			m_noOfLines = textFile.m_noOfLines;
			m_textLines = new Line[m_noOfLines];
			for (unsigned i = 0; i < m_noOfLines; i++) {
				m_textLines[i].m_value = new char[strLen(textFile.m_textLines[i].m_value) + 1];
				strCpy(m_textLines[i].m_value, textFile.m_textLines[i].m_value);
			}
			saveAs(m_filename);
		}
		return *this;
	}

	TextFile:: ~TextFile() {
		if (m_filename != nullptr) {
			delete[] m_filename;
			m_filename = nullptr;
		}
		if (m_textLines != nullptr) {
			delete[] m_textLines;
			m_textLines = nullptr;
		}
	}

	std::ostream& TextFile::view(std::ostream& ostr)const {
		if (m_filename != nullptr && m_textLines != nullptr) {
			unsigned i = 0;
			ostr << m_filename << endl;
			ostr.fill('=');
			ostr.width(strLen(m_filename));
			ostr << '=' << endl;
			for (i = 0; i < m_noOfLines && i < m_pageSize; i++) {
				ostr << m_textLines[i] << endl;
			}
			//checking the pageSize
			if (i < m_noOfLines) { //means more line remains. Giving prompt
				do {
					unsigned j = 0;
					char enter;
					ostr << "Hit ENTER to continue...";
					cin.get(enter);
					for (j = 0; i < m_noOfLines && j < m_pageSize; j++) {
						ostr << m_textLines[i] << endl;
						i++;
					}
				} while (i < m_noOfLines);
			}

		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr) {
		string temp;
		istr >> temp;
		m_filename = new char[strLen(temp.c_str()) + 1];
		strCpy(m_filename, temp.c_str());

		//ignoring \n charachter 
		istr.ignore(32767, '\n');
		setNoOfLines();
		loadText();
		return istr;
	}

	TextFile::operator bool()const {
		bool ok = true;
		if (m_filename == nullptr) {
			ok = false;
		}
		return ok;
	}

	unsigned TextFile::lines()const {
		return m_noOfLines;
	}

	const char* TextFile::name()const {
		return m_filename;
	}

	const char* TextFile::operator[](unsigned index)const {
		if (m_filename == nullptr) {
			return NULL;
		}
		if (index >= m_noOfLines) {
			index = index - m_noOfLines;
		}
		return m_textLines[index].m_value;
	}

	std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
		text.view(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, TextFile& text) {
		text.getFile(istr);
		return istr;
	}
}