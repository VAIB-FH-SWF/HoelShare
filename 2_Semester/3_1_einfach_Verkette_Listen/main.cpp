/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Aufgabe 3.1 Einfach verkettete Liste 			 */
/* 				 aus statischen Elementen						 */
/*																 */
/*      Version: 1.0											 */
/*     Erstellt: 21.03.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Definition der Struktur Element
struct Element
{
		/**  Schluessel des Listenelements */
		long key;
		/** die im Listenelement zu verwaltende Information */
		long info;
		/** Zeiger auf das naechste Element */
		struct Element *next;
};
// ---------- end of struct element ----------


/**
 * Haupteinstiegspunkt
 * @return Immer 0
 */
int main()
{
	// Zwei Listenzeiger (Datentyp Element*) anlegen
	Element* l;
	Element* cursor;

	// Vier Listenelemente x1, x2, x3, x4 anlegen
	Element x1, x2, x3, x4;
	// Als Schlüsselwerte (key) werden fortlaufend die Werte 1 bis 4 zugewiesen.
	// Als Informationen (info) werden fortlaufend die Werte 11 bis 44 zugewiesen.
	x1.key = 1;
	x1.info = 11;

	x2.key = 2;
	x2.info = 22;

	x3.key = 3;
	x3.info = 33;

	x4.key = 4;
	x4.info = 44;

	// Elemente verketten
	x1.next = &x2;
	x2.next = &x3;
	x3.next = &x4;
	x4.next = NULL;

	// L zeigt als Anker auf das 1. Listenelement
	l = &x1;
	cursor = l;
	// Das Element mit dem Schlüsselwert 3 suchen
	//Element mit dem Schlüsselwert 3
	do
	{
		if(cursor->key == 3)
			break;
	} while ((cursor = cursor->next)); // cursor wird als Zeiger beim Durchlaufen der Liste verwendet

	//Das Programm muss auch dann einwandfrei arbeiten,
	//wenn die Liste leer ist und wenn der gesuchte Schlüsselwert nicht in der
	//Liste vorhanden ist.
	if (cursor)
	{
		// Zahlen- und Adresswerte können mit dem Ausgabemanipulator setw(14) mit einer
		// Breite von 14 Zeichen ausgegeben werden
		cout << "Listenelement gefunden :" << setw(12) << cursor << endl << endl;
		cout << "key\t=" << setw(14) << cursor->key << endl;
		cout << "info\t=" << setw(14) << cursor->info << endl;
		cout << "next\t=" << setw(14) << cursor->next << endl;
	}
	else
	{
		cout << "Der Wert konnte nicht gefunden werden!" << endl;
	}

	return 0;
}
