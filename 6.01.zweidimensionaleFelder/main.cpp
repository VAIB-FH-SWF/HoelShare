//==========================================================
//
//	  Filename:	main.cpp
//
// Description: TODO	
//
//	   Version:	1.0
// 	   Created:	26.10.2015 20:12:39
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Typ Definition
 */
typedef unsigned int uint;
/**
 * Arraygroesse festlegen
 */
const uint nmat = 10;

/**
 * Funktionsprototypen
 */
void matrix_diag    (int mat[nmat][nmat], uint n, uint diag,  int value);
void matrix_dreieck (int mat[nmat][nmat], uint n, uint k,     int value);
void matrix_frame   (int mat[nmat][nmat], uint n, uint frame, int value);
void matrix_null    (int mat[nmat][nmat], uint n);
void matrix_print   (int mat[nmat][nmat], uint n);

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main()
{
   int mat[nmat][nmat];
   matrix_null(mat, nmat);
   cout << "10x10-Matrix; Nullmatrix:" << endl;
   matrix_print(mat, nmat);

   matrix_frame(mat, nmat, 2, 1);
   cout << endl << "10x10-Matrix; Rahmenstaerke 2:" << endl;
   matrix_print(mat, nmat);

   matrix_diag(mat, nmat, 1, 1);
   cout << endl << "10x10-Matrix; 3 Diagonalen:" << endl;
   matrix_print(mat, nmat);

   matrix_dreieck(mat, nmat, 5, 1);
   cout << endl << "10x10-Matrix; 5 Diagonalreihen links oben:" << endl;
   matrix_print(mat, nmat);
   return (0);
}

/**
 * Gibt die Matrix auf der Console aus
 */
void matrix_print   (int mat[nmat][nmat], uint n)
{
   for(uint zeile = 0; zeile < n; zeile++)
   {
      for(uint spalte = 0; spalte < n; spalte++)
      {
         cout << setw(4) << mat[zeile][spalte];
      }
      cout << endl;
   }
}

/**
 * Setzt alle Werte der Matrix auf 0
 */
void matrix_null    (int mat[nmat][nmat], uint n)
{
   for (uint zeile = 0; zeile < n; zeile++)
   {
      for (uint spalte = 0; spalte < n; spalte++)
      {
         mat[zeile][spalte] = 0;
      }
   }
}

/**
 * Setzt die Matrix auf 0 und setzt einen Rahmen
 * @param frame Breite des Rahmens
 * @param value Wert des Rahmens
 */
void matrix_frame   (int mat[nmat][nmat], uint n, uint frame, int value)
{
   if(frame > n/2+1)
   {
      frame = n/2+1;
   }
   matrix_null(mat, n);
   for (uint zeile = 0; zeile < n; zeile++)
   {
      for (uint spalte = 0; spalte < n; spalte++)
      {
         if (zeile < frame || n - zeile <= frame || spalte < frame
               || n - spalte <= frame)
         {
            mat[zeile][spalte] = value;
         }
      }
   }
}

/**
 * Setzt die Matrix auf 0 und zeichnet eine Diagonale von links Oben nach Rechts unten
 * Die Breite der Diagonale wird in ungeraden Schritten gewertet, da bei geraden Werten
 * nicht entschieden werden kann, an welcher Seite von der Mitte aus das einzelne Feld
 * gesetzt wird
 * @param diag Breite der Diagonale
 * @param value Wert der Diagonale
 */
void matrix_diag    (int mat[nmat][nmat], uint n, uint diag, int value)
{
   // Setzt zu hohe (unsinnige) Werte auf das Maximum von Anzahl Zeilen / 2 -1
   if(diag > n/2-1)
   {
      diag = n/2-1;
   }
   // Matrix auf 0 setzen
   matrix_null(mat, n);
   // Nur wenn der Wert groesser als 0 ist, wird die Diagonale gezeichnet
   // Es muss geprueft werden, da bei graden Werten der Breite der naechst
   // hoehere gewaehlt wird
   if (diag > 0)
   {
      for (uint zeile = 0; zeile < n; zeile++)
      {
         for (uint diagZaehler = 0; diagZaehler < (diag + 2) / 2; diagZaehler++)
         {
            if (zeile + diagZaehler < n)
            {
               mat[zeile + diagZaehler][zeile] = value;
               mat[zeile][zeile + diagZaehler] = value;
            }
         }
      }
   }
}

/**
 * Setzt die Werte der Matrix auf 0 und anschliessend in der oberen
 * Linken Ecke ein Dreieck
 */
void matrix_dreieck (int mat[nmat][nmat], uint n, uint k, int value)
{
   if(k > n/2-1)
   {
      k = n/2-1;
   }

   matrix_null(mat, n);
   for (uint zeile = 0; zeile < n; zeile++)
   {
      for (uint spalte = 0; spalte < n; spalte++)
      {
         if (zeile + spalte <= k)
         {
            mat[zeile][spalte] = value;
         }
      }
   }
}


