/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Das Spiel des Lebens (engl. Game of Life) ist   */
/* ein vom Mathematiker John Horton Conway 1970 entworfenes      */
/* Spiel, das eine sehr einfache Art von Evolution simuliert. 	 */
/* In einem zweidimen- sionalen Feld gibt es lebende und tote 	 */
/* Zellen (Abbildung 2.1; die lebenden Zellen sind mit einer 	 */
/* Nummernzeichen # markiert). Nach vier einfachen Regeln 	 	 */
/* (siehe unten) wird aus der gerade vorhandenen Generation 	 */
/* eine neue Generation berechnet.								 */
/*																 */
/*      Version: 1.0											 */
/*     Erstellt: 09.03.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

typedef unsigned int uint;
void zufallsbelegung(int** feld, uint hoehe, uint breite);
uint next_generation(int** feld1, int** feld2, uint hoehe, uint breite);
void print_feld(int** feld, uint hoehe, uint breite);
int** new_int_matrix(int rows, int columns);
void delete_int_matrix(int **m);
uint holeAnzahlLebendeNachbarn(int ** feld, uint zeile, uint spalte);
void tauscheFelder(int*** feld1, int*** feld2);

int main()
{
	int** ausgabeFeld;
	int** zwischenSpeicherFeld;
	uint hoehe = 10;
	uint breite = 10;
	uint generation = 0;
	uint population = 0;
	// Hoehe einlesen
	cout << "Bitte die Hoehe eingeben: ";
	cin >> hoehe;
	cout << "Bitte die Breite eingeben: ";
	cin >> breite;

	ausgabeFeld = new_int_matrix(hoehe, breite);
	zwischenSpeicherFeld = new_int_matrix(hoehe, breite);
	zufallsbelegung(ausgabeFeld, hoehe, breite);
	do
	{
		population = next_generation(ausgabeFeld, zwischenSpeicherFeld, hoehe, breite);
		tauscheFelder(&ausgabeFeld, &zwischenSpeicherFeld);
		print_feld(ausgabeFeld, hoehe, breite);
		cout << "[" << hoehe << "," << breite << "] Generation " << generation << " / Population " << population
				<< " / (quit : 'q') ... weiter ..." << endl;
		generation++;
	} while (cin.get() != 'q'); // Sobald die Eingabe 'q' Entspricht, wird das Programm beendet

	delete_int_matrix(ausgabeFeld);
	delete_int_matrix(zwischenSpeicherFeld);
	return 0;
}

/**
 * Belegt das Feld an zufaelligen Positionen mit Werten
 *
 * @param feld
 * @param hoehe
 * @param breite
 */
void zufallsbelegung(int** feld, uint hoehe, uint breite)
{
	// Zufallsgenerator inistialieren
	// Der Generator bekommt als Seed die aktuelle Zeit
	srand(time(0));
	// int Felder sind Standardmaessig mit 0 initialisiert
	// daher muessen die Randzellen nicht extra definiert werden
	for (uint row = 1; row < hoehe - 1; row++)
	{
		for (uint col = 1; col < breite - 1; col++)
		{
			// Den Zufallswert / Maximaler Zufallswert
			// ergibt eine Zahl zwischen 0 und 1
			// diese wird gerundet im Feld abgespeichert
			feld[row][col] = rand() % 2;
		}
	}
}

/**
 * Erzeugt die naechste Generation, dazu werden 4 einfache Regeln befolgt
 *
 * 1. Eine tote Zelle mit genau drei Nachbarn wird in der nächsten Generation
 *    neu geboren.
 * 2. Eine lebende Zelle mit weniger als zwei Nachbarn stirbt in der folgenden
 *    Generation an Vereinsamung.
 * 3. Eine lebende Zelle mit zwei oder drei Nachbarn bleibt in der folgenden
 *    Generation am Leben.
 * 4. Eine lebende Zelle mit mehr als drei Nachbarn stirbt in der folgenden
 *    Generation an Überbevölkerung.
 * @param feld1 Quelle
 * @param feld2 Temporaeres Feld
 * @param hoehe Hoehe des Feldes
 * @param breite Breite des Feldes
 * @return Anzahl der Lebenden Zellen
 */
uint next_generation(int** feld1, int** feld2, uint hoehe, uint breite)
{
	uint anzahlLebendeZellen = 0;

	for (uint row = 1; row < hoehe - 1; row++)
	{
		for (uint col = 1; col < breite - 1; col++)
		{
			// Regel 1
			if (feld1[row][col] == 0 && holeAnzahlLebendeNachbarn(feld1, row, col) == 3)
			{
				anzahlLebendeZellen++;
				feld2[row][col] = 1;
				//cout << "Regel 1 angewendet " << row << ", " << col << endl;
			}
			// Regel 2
			else if (feld1[row][col] == 1 && holeAnzahlLebendeNachbarn(feld1, row, col) < 2)
			{
				feld2[row][col] = 0;
				//cout << "Regel 2 angewendet " << row << ", " << col << endl;
			}
			// Regel 3
			// Es genuegt die Pruefung auf kleiner 4, da mit < 2 Lebende Zellen Regel 2 greifen wuerde
			else if (feld1[row][col] == 1 && holeAnzahlLebendeNachbarn(feld1, row, col) < 4)
			{
				feld2[row][col] = 1;
				anzahlLebendeZellen++;
				//cout << "Regel 3 angewendet " << row << ", " << col << endl;
			}
			// Regel 4
			else if (feld1[row][col] == 1 && holeAnzahlLebendeNachbarn(feld1, row, col) > 3)
			{
				feld2[row][col] = 0;
				//cout << "Regel 4 angewendet " << row << ", " << col << endl;
			}
			// Alle Zellen, auf die keine der Regeln anzuwenden ist,
			// werden unveraëndert in die naechste Generation uëbernommen.
			else
			{
				feld2[row][col] = feld1[row][col];
				if (feld1[row][col])
				{
					anzahlLebendeZellen++;
				}
				//cout << "Keine angewendet " << row << ", " << col << endl;
			}
		}
	}

	return anzahlLebendeZellen;
}

/**
 * Gibt die Anzahl der Lebenden Nachbarn zurueck
 * @param feld Matrix mit den Zellen
 * @param zeile Zeile bei der die umliegenden Nachbarn geprueft werden sollen
 * @param spalte Spalte bei der die umliegenden Nachbarn geprueft werden sollen
 * @return Anzahl der lebendigen Nachbarn
 */
uint holeAnzahlLebendeNachbarn(int ** feld, uint zeile, uint spalte)
{
	uint anzahl = 0;
	for (uint row = zeile - 1; row <= zeile + 1; row++)
	{
		for (uint col = spalte - 1; col <= spalte + 1; col++)
		{
			// Es sollen nur die Nachbarn betrachtet werden
			if (zeile == row && spalte == col)
			{
				continue;
			}
			// Wenn das Feld nicht gesetzt ist, wird die Anzahl erhoeht
			if (feld[row][col])
			{
				anzahl++;
			}
		}
	}
	return anzahl;
}

/**
 * Gibt das Feld auf der Console aus
 * @param feld Feld das ausgegeben werden soll
 * @param hoehe Hoehe des Feldes
 * @param breite Breite des Feldes
 */
void print_feld(int** feld, uint hoehe, uint breite)
{
	for (uint row = 1; row < hoehe - 1; row++)
	{
		for (uint col = 1; col < breite - 1; col++)
		{
			//Wenn der Wert nicht 0 ist, lebt die Zelle und es wird eine # ausgegeben
			// ansonsten ist die Zelle Tot und es muss ein leeres Feld ausgegeben werden
			if (!feld[row][col])
			{
				cout << " ";
			}
			else
			{
				cout << "#";
			}
		}
		cout << endl;
	}
}

/**
 * Allokiert den Speicher fuer die Matrix
 * @param rows Zeilenanzahl
 * @param columns Spaltenanzahl
 * @return die Matrix
 */
int** new_int_matrix(int rows, int columns)
{
	// Die Matrix wird mit 2 Spalten und 2 Reihen mehr gespeichert
	// dadurch besitzen alle Relevanten Zellen 8 Nachbarzellen
	rows += 2;
	columns += 2;
	int i;
	int **m;
	m = new int*[rows];
	*m = new int[rows * columns]();
	for (i = 1; i < rows; i += 1)
	{
		m[i] = m[i - 1] + columns;
	}
	return m;
}

/**
 * Gibt den Speicher der Matrix frei
 * @param m Matrix dessen Speicher freigegeben werden soll
 */
void delete_int_matrix(int** m)
{
	// Loescht das Datenarray
	delete[] *m;
	// Loescht das Pointer Array
	delete[] m;
}

/**
 * Tauscht die Pointer auf die zwei Felder
 * @param feld1 Erste Matrix
 * @param feld2 Zweite Matrix
 */
void tauscheFelder(int*** feld1, int*** feld2)
{
	int** zwischenspeicher = *feld1;
	*feld1 = *feld2;
	*feld2 = zwischenspeicher;

}
