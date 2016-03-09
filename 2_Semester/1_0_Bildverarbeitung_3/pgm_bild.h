/* 
 * Struktur in der ein Bild gespeichert wird
 * File:   pgm_bild.h
 * Author: hoelshare
 *
 * Created on 1. März 2016, 15:52
 */

#ifndef PGM_BILD_H
#define PGM_BILD_H

typedef unsigned char Pixel;

/**
 * Struktur in der ein Bild gespeichert wird
 */
struct pgm_bild
{
		/** Bildtyp */
		char magic[2];
		/** Zeilenzahl */
		int nx;
		/** Spaltenzahl */
		int ny;
		/** max. Grauwert */
		int graumax;
		/** Bildmatrix */
		Pixel **bild;
};

#endif /* PGM_BILD_H */

