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

typedef unsigned int uint;

const uint nmat = 10;

void matrix_diag    (int mat[nmat][nmat], uint n, uint diag,  int value);
void matrix_dreieck (int mat[nmat][nmat], uint n, uint k,     int value);
void matrix_frame   (int mat[nmat][nmat], uint n, uint frame, int value);
void matrix_null    (int mat[nmat][nmat], uint n);
void matrix_print   (int mat[nmat][nmat], uint n);

int main()
{
   int mat[nmat][nmat];
   matrix_null(mat, nmat);
   cout << "10x10-Matrix; Nullmatrix:" << endl;
   matrix_print(mat, nmat);

   matrix_frame(mat, nmat, 2, 1);
   cout << endl << "10x10-Matrix; Rahmenstaerke 2:" << endl;
   matrix_print(mat, nmat);

   matrix_diag(mat, nmat, 7, 1);
   cout << endl << "10x10-Matrix; 3 Diagonalen:" << endl;
   matrix_print(mat, nmat);

   matrix_dreieck(mat, nmat, 5, 1);
   cout << endl << "10x10-Matrix; 5 Diagonalreihen links oben:" << endl;
//   matrix_print(mat, nmat);
   return (0);
}

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

void matrix_diag    (int mat[nmat][nmat], uint n, uint diag, int value)
{
   if(diag > n/2-1)
   {
      diag = n/2-1;
   }

   matrix_null(mat, n);
   if (diag > 0)
   {
      for (uint zeile = 0; zeile < nmat; zeile++)
      {
         for (uint spalte = max((int) 0, (int) (zeile - (diag / 2)));
               spalte <= min(nmat - 1, zeile + (diag / 2)); spalte++)
         {
            mat[zeile][spalte] = value;
         }
      }
   }
}

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


