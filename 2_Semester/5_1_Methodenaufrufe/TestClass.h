/*****************************************************************/
/*    Dateiname: TestClass.h										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 24.04.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#ifndef TESTCLASS_H_
#define TESTCLASS_H_
#include <string>

using namespace std;

class TestClass
{
	public:
		// ====================  LIFECYCLE     =======================================
		TestClass(int _value = 0, string _name = "");
		TestClass(const TestClass &other);
		~TestClass();
// ==================== ACCESSORS
		void print();
// ==================== MUTATORS
		TestClass& set_name(string _name);
		TestClass& set_value(int _value);
// ==================== OPERATORS
		TestClass& operator =(const TestClass &other);
		TestClass operator +(const TestClass &other);
	private:
// ==================== DATA MEMBERS =======================================
		int value;
		string name;
};
// ----- end of class Class -----

#endif /* TESTCLASS_H_ */
