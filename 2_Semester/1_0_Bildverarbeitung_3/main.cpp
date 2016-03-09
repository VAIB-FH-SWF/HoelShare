/**
 *
 * File:   main.cpp
 * Author: hoelshare
 *
 * Created on 1. Maerz 2016, 15:21
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "pgm_bild.h"

using namespace std;

// #####  LOCAL PROTOTYPES #################################
void bild_lesen(pgm_bild *bild, string ifs_file_name);
void bild_schreiben(pgm_bild *bild, string ofs_file_name);
void delete_pixel_matrix(Pixel **m);
Pixel** new_pixel_matrix(size_t rows, size_t columns);
void glaetten(pgm_bild *bild1, pgm_bild *bild2);
void invertieren(pgm_bild *bild1, pgm_bild *bild2);
void kantenbildung(pgm_bild *bild1, pgm_bild *bild2);
void kopiere_bildkopf(pgm_bild *bild1, pgm_bild *bild2);
void schaerfen(pgm_bild *bild1, pgm_bild *bild2);

/**
 * Haupteinstiegspunkt
 * @return Programm mit Fehlern beendet?
 */
int main()
{
	pgm_bild *bild = new pgm_bild();
	pgm_bild *bild2 = new pgm_bild();
	// Bild einlesen und in bild speichern
	bild_lesen(bild, "dreifach.pgm");

	// Bild invertieren und in bild2 speichern
	invertieren(bild, bild2);
	bild_schreiben(bild2, "invertiert.pgm");

	//Bild schaerfen und in Bild2 speichern
	schaerfen(bild, bild2);
	// Bild2 in Datei schreiben
	bild_schreiben(bild2, "schaerfen.pgm");

	// Bild glaetten und in bild2 speichern
	glaetten(bild, bild2);
	bild_schreiben(bild2, "glaetten.pgm");

	// Bei dem Bild die kantenbilden und in bild2 abspeichern
	kantenbildung(bild, bild2);
	bild_schreiben(bild2, "kanten.pgm");

	// speicher des Bildes wieder freigeben
	delete_pixel_matrix(bild->bild);
	delete_pixel_matrix(bild2->bild);
	delete bild;
	delete bild2;

	return 0;
}

/**
 * Liesst ein Bild ein
 * @param bild Pointer auf das zu erzeugende Bild
 * @param ifs_file_name Pfad mit Dateinamen zu dem Bild
 */
void bild_lesen(pgm_bild *bild, string ifs_file_name)
{
	ifstream dateiStream;
	dateiStream.open(ifs_file_name.c_str());
	// Wenn der Stream nicht geoeffnet werden kann,
	// wird das Programm mit dem Code 1 beendet
	if (!dateiStream)
	{
		exit(1);
	}

	// Temporaere Variablen, die beim einlesen beoetigt werden
	string strTemp;
	int iTemp;

	// Neues Bild Objekt erstellen
	// Speicher beschaffen
	dateiStream >> strTemp;

	// Wenn der Dateityp nicht P2 ist, wird das Programm mit einem Fehler beendet
	if (strTemp != "P2")
	{
		exit(2);
	}
	// sehr unschoen!!!!
	// Die Werte in magic setzen
	bild->magic[0] = 'P';
	bild->magic[1] = '2';

	dateiStream >> bild->nx;
	dateiStream >> bild->ny;
	dateiStream >> bild->graumax;

	// Wenn der Grauwert nicht zwischen 0 - 255 liegt,
	// wird das Programm mit dem Fehler Code 3 beendet
	if (bild->graumax > 255 || bild->graumax < 0)
	{
		exit(3);
	}

	// Speicher des Bildes allokieren
	bild->bild = new_pixel_matrix(bild->ny, bild->nx);

	// Bild einlesen
	for (int row = 0; row < bild->ny; row++)
	{
		for (int col = 0; col < bild->nx; col++)
		{
			dateiStream >> iTemp;
			// Wenn der eingelesene Wert kleiner als 0 oder groesser als der Maximale Grauwert ist
			// wird das Programm mit dem Fehlercode 4 beendet
			if (iTemp < 0 || iTemp > bild->graumax)
			{
				exit(4);
			}
			bild->bild[row][col] = iTemp;
		}
	}
	// Stream schliessen
	dateiStream.close();
}

/**
 * Schreibt das Bild in eine Datei
 * @param bild Bild das gespeichert werden soll
 * @param ofs_file_name Name der Datei
 */
void bild_schreiben(pgm_bild *bild, string ofs_file_name)
{
	ofstream dateiStream;
	dateiStream.open(ofs_file_name.c_str());
	// Wenn der Stream nicht geoeffnet werden kann
	if (!dateiStream)
	{
		exit(1);
	}

	// Kopfdaten ausgeben
	dateiStream << bild->magic << endl;
	dateiStream << bild->nx << " ";
	dateiStream << bild->ny << endl;
	dateiStream << bild->graumax << endl;
	dateiStream << right;
	// Bilddaten speichern
	int ausgaben = 0;
	for (int row = 0; row < bild->ny; row++)
	{
		for (int col = 0; col < bild->nx; col++)
		{
			// Bild Wert in int Konvertieren und ausgeben
			dateiStream << " " << setw(3) << int(bild->bild[row][col]);

			// Eine Zeile darf Maximal 75 Zeichen enthalten, dies entspricht ca jeder 18 ausgabe
			ausgaben++;
			if (ausgaben % 18 == 0)
			{
				// Zeile beenden
				dateiStream << endl;
			}
		}
	}
	// Dateistream Flushen und schliessen
	dateiStream.flush();
	dateiStream.close();
}

/**
 * Speicher der Matrix freigeben
 * @param m Pixel-Matrix
 */
void delete_pixel_matrix(Pixel **m)
{
	delete[] *m;
	delete[] m;
}

/**
 * Speicher fuer die Matrix allokieren
 * @param rows Anzahl der Zeilen
 * @param columns Anzahl der Spalten
 * @return die neu erstellte Pixel Matrix
 */
Pixel** new_pixel_matrix(size_t rows, size_t columns)
{
	size_t i;
	Pixel **m;
	m = new Pixel*[rows];
	// Speicher fuer die komplette Matrix reservieren
	*m = new Pixel[rows * columns];
	// den Pointer auf die korrekte Position zeigen lassen
	for (i = 1; i < rows; i++)
	{
		m[i] = m[i - 1] + columns;
	}
	return m;
}

/**
 * Erstellt eine geglaettete Kopie des Bildes
 * Zum glaetten wird der Mittelwert aus den umliegenden Pixeln berechnet
 * Die Randpixel werden dabei in das Original Bild kopiert
 * @param bild1 Bild von dem kopiert wird
 * @param bild2 Bild in der die Kopie gespeichert wird
 */
void glaetten(pgm_bild *bild1, pgm_bild *bild2)
{
	// Den Bildkopf kopieren
	kopiere_bildkopf(bild1, bild2);
	int sum;
	for (int row = 0; row < bild1->ny; row++)
	{
		for (int col = 0; col < bild1->nx; col++)
		{
			sum = 0;
			// handelt es sich um einen Randpixel
			if (row == 0 || col == 0 || row == bild1->ny - 1 || col == bild1->nx)
			{
				bild2->bild[row][col] = bild1->bild[row][col];
			}
			else // es handelt sich um einen Pixel im innenbereich
			{
				// Von Zeile - 1 bis Zeile + 1
				// falls diese im Bereich des Bildes sind
				for (int tRow = row - 1; tRow < row + 1; tRow++)
				{
					// Von Spalte - 1 bis Spalte + 1
					// falls diese im Bereich des Bildes sind
					for (int tCol = col - 1; tCol < col + 1; tCol++)
					{
						// Summe erhoehen
						sum += bild1->bild[tRow][tCol];
					}
				}
				// Den mittelwert berechnen und das Ergebnis runden
				bild2->bild[row][col] = round(double(sum) / double(9));
			}
		}
	}
}

/**
 * Erstellt eine Kopie des Bildes, in der Pixel fuer Pixel invertiert wird
 * Invertiert = Maximales Grau - aktuelles Grau
 * @param bild1 Bild von dem kopiert wird
 * @param bild2 Bild in der die Kopie gespeichert wird
 */
void invertieren(pgm_bild *bild1, pgm_bild *bild2)
{
	// Den Bildkopf kopieren
	kopiere_bildkopf(bild1, bild2);

	for (int row = 0; row < bild1->ny; row++)
	{
		for (int col = 0; col < bild1->nx; col++)
		{
			// Dem Bild zwei den neuen Wert zuweisen
			bild2->bild[row][col] = bild1->graumax - bild1->bild[row][col];
		}
	}

}

/**
 * Erstellt eine Kopie des Objektes, bei denen die Kanten hervorgehoben sind
 * Dazu wird ueber die umliegenden Pixel eine Gewichtungsmatrix gelegt und durch 9 geteilt
 *  0 -1  0
 * -1 +4 -1
 *  0 -1  0
 *
 * @param bild1 Bild von dem kopiert wird
 * @param bild2 Bild in der die Kopie gespeichert wird
 */
void kantenbildung(pgm_bild *bild1, pgm_bild *bild2)
{
	// Den Bildkopf kopieren
	kopiere_bildkopf(bild1, bild2);
	int sum = 0;

	for (int row = 0; row < bild1->ny; row++)
	{
		for (int col = 0; col < bild1->nx; col++)
		{
			sum = 0;
			// handelt es sich um einen Randpixel
			if (row == 0 || col == 0 || row == bild1->ny - 1 || col == bild1->nx)
			{
				// Dann wird der Wert in das neue Bild kopiert
				bild2->bild[row][col] = bild1->bild[row][col];
			}
			else // es handelt sich um einen Pixel im innenbereich
			{
				// Von Zeile - 1 bis Zeile + 1
				// falls diese im Bereich des Bildes sind
				for (int tRow = row - 1; tRow < row + 1; tRow++)
				{
					// Von Spalte - 1 bis Spalte + 1
					// falls diese im Bereich des Bildes sind
					for (int tCol = col - 1; tCol < col + 1; tCol++)
					{
						// Summe und Anzahl erhoehen
						// Wenn der Pixel in der gleichen Spalte oder Reihe ist,
						// und nicht gleich der Pixel in der Mitte ist
						if ((tRow == row || tCol == col) && !(tRow == row && tCol == col))
						{
							sum -= bild1->bild[tRow][tCol];
						}
					}
				}
				// Der mittlere Pixel wird mit 4 Multipliziert
				sum += (4 * bild1->bild[row][col]);

				bild2->bild[row][col] = abs(round(((double) sum) / 9.0));
			}
		}
	}

}

/**
 * Kopiert die Kopfdaten des Bildes
 * @param bild1 Bild von dem kopiert wird
 * @param bild2 Bild in der die Kopie gespeichert wird
 */
void kopiere_bildkopf(pgm_bild *bild1, pgm_bild *bild2)
{
	bild2->graumax = bild1->graumax;
	strcpy(bild2->magic, bild1->magic);
	bild2->nx = bild1->nx;
	bild2->ny = bild1->ny;
	// Die Bildmatrix soll nicht kopiert werden
	// Nur den Speicher fuer die Matrix beschaffen
	if (bild2->bild != nullptr)
	{
		// Speicher wieder freigeben, bevor neuer Reserviert wird
		delete_pixel_matrix(bild2->bild);
	}
	// neuen Speicher fuer die Bildmatrix besorgen
	bild2->bild = new_pixel_matrix(bild2->ny, bild2->nx);
}

/**
 * Erstellt eine geschaerfte Kopie des Bildes
 * Dazu wird ueber die umliegenden Pixel eine Gewichtungsmatrix gelegt
 * -1 -1 -1
 * -1 +9 -1
 * -1 -1 -1
 *
 * @param bild1 Bild von dem kopiert wird
 * @param bild2 Bild in der die Kopie gespeichert wird
 */
void schaerfen(pgm_bild *bild1, pgm_bild *bild2)
{
	// Den Bildkopf kopieren
	kopiere_bildkopf(bild1, bild2);
	int sum = 0;
	for (int row = 0; row < bild1->ny; row++)
	{
		for (int col = 0; col < bild1->nx; col++)
		{
			sum = 0;
			// handelt es sich um einen Randpixel
			if (row == 0 || col == 0 || row == bild1->ny - 1 || col == bild1->nx)
			{
				// Dann wird der Wert in das neue Bild kopiert
				bild2->bild[row][col] = bild1->bild[row][col];
			}
			else // es handelt sich um einen Pixel im innenbereich
			{
				// Von Zeile - 1 bis Zeile + 1
				// falls diese im Bereich des Bildes sind
				for (int tRow = row - 1; tRow < row + 1; tRow++)
				{
					// Von Spalte - 1 bis Spalte + 1
					// falls diese im Bereich des Bildes sind
					for (int tCol = col - 1; tCol < col + 1; tCol++)
					{
						// Wenn die aktuelle Zeile/Spalte <> der eigentlichen Zeile/Spalte ist,
						// wird der Wert mit -1 Multipliziert und dann addiert
						if (row != tRow || col != tCol)
						{
							sum -= bild1->bild[tRow][tCol];
						}
					}
				}
				// der Wert des mittleren Pixels wird mit 9 multipliziert
				sum += bild1->bild[row][col] * 9;
				// Wenn der Wert kleiner als 0 ist wird dieser zu 0
				// Wenn der Wert groeser als der Max. Grauwird wird dieser zu diesem
				// Ansonsten wird der Wert uebernommen
				sum = (sum < 0 ? 0 : sum > bild2->graumax ? bild2->graumax : sum);
				bild2->bild[row][col] = sum;
			}
		}
	}
}
