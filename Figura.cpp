#include "Figura.h"

// Aquest mètode ens permet reinicialitzar una figura existent amb un nou tipus de figura.

void Figura::inicialitza(TipusFigura tipusFigura)
{
	m_mida = 0;
	m_tipusFigura = tipusFigura;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;

	// Reinicialitzem la matriu de la figura amb colors buits.
	
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
		
			m_figura[i][j] = NO_COLOR;

	// Omplim la matriu amb els colors corresponents segons el nou tipus de figura.
	
	switch (m_tipusFigura)
	{
	    
	case FIGURA_O:
	
		m_mida = 2;
		m_color = COLOR_GROC;
		m_figura[0][0] = COLOR_GROC;
		m_figura[0][1] = COLOR_GROC;
		m_figura[1][0] = COLOR_GROC;
		m_figura[1][1] = COLOR_GROC;
		break;
		
	case FIGURA_I:
	
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		m_figura[1][0] = COLOR_BLAUCEL;
		m_figura[1][1] = COLOR_BLAUCEL;
		m_figura[1][2] = COLOR_BLAUCEL;
		m_figura[1][3] = COLOR_BLAUCEL;
		break;
		
	case FIGURA_T:
	
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		m_figura[0][1] = COLOR_MAGENTA;
		m_figura[1][0] = COLOR_MAGENTA;
		m_figura[1][1] = COLOR_MAGENTA;
		m_figura[1][2] = COLOR_MAGENTA;
		break;
		
	case FIGURA_L:
	
		m_mida = 3;
		m_color = COLOR_TARONJA;
		m_figura[0][2] = COLOR_TARONJA;
		m_figura[1][0] = COLOR_TARONJA;
		m_figura[1][1] = COLOR_TARONJA;
		m_figura[1][2] = COLOR_TARONJA;
		break;
		
	case FIGURA_J:
	
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		m_figura[0][0] = COLOR_BLAUFOSC;
		m_figura[1][0] = COLOR_BLAUFOSC;
		m_figura[1][1] = COLOR_BLAUFOSC;
		m_figura[1][2] = COLOR_BLAUFOSC;
		break;
		
	case FIGURA_Z:
	
		m_mida = 3;
		m_color = COLOR_VERMELL;
		m_figura[0][0] = COLOR_VERMELL;
		m_figura[0][1] = COLOR_VERMELL;
		m_figura[1][1] = COLOR_VERMELL;
		m_figura[1][2] = COLOR_VERMELL;
		break;
		
	case FIGURA_S:
	
		m_mida = 3;
		m_color = COLOR_VERD;
		m_figura[0][1] = COLOR_VERD;
		m_figura[0][2] = COLOR_VERD;
		m_figura[1][0] = COLOR_VERD;
		m_figura[1][1] = COLOR_VERD;
		break;
	}
}

// Aquí definim el constructor predeterminat de la classe Figura. Quan creem una nova figura, tot es posa a zero o buit.
Figura::Figura()
{
	m_mida = 0;
	m_color = NO_COLOR;
	m_tipusFigura = NO_FIGURA;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
		
			m_figura[i][j] = NO_COLOR;
}

// Aquí definim un constructor que ens permet crear una figura amb un tipus concret, com ara O, I, T, etc.
Figura::Figura(TipusFigura tipusFigura)
{
	m_mida = 0;
	m_tipusFigura = tipusFigura;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;
	
	// Inicialitzem la matriu de la figura amb colors buits.
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
		
			m_figura[i][j] = NO_COLOR;

	// Depenent del tipus de figura, omplim la matriu amb els colors corresponents.
	switch (m_tipusFigura)
	{
	case FIGURA_O:
	
		m_mida = 2;
		m_color = COLOR_GROC;
		m_figura[0][0] = COLOR_GROC;
		m_figura[0][1] = COLOR_GROC;
		m_figura[1][0] = COLOR_GROC;
		m_figura[1][1] = COLOR_GROC;
		break;
		
	case FIGURA_I:
	
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		m_figura[1][0] = COLOR_BLAUCEL;
		m_figura[1][1] = COLOR_BLAUCEL;
		m_figura[1][2] = COLOR_BLAUCEL;
		m_figura[1][3] = COLOR_BLAUCEL;
		break;
		
	case FIGURA_T:
	
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		m_figura[0][1] = COLOR_MAGENTA;
		m_figura[1][0] = COLOR_MAGENTA;
		m_figura[1][1] = COLOR_MAGENTA;
		m_figura[1][2] = COLOR_MAGENTA;
		break;
		
	case FIGURA_L:
	
		m_mida = 3;
		m_color = COLOR_TARONJA;
		m_figura[0][1] = COLOR_TARONJA;
		m_figura[1][1] = COLOR_TARONJA;
		m_figura[2][1] = COLOR_TARONJA;
		m_figura[2][2] = COLOR_TARONJA;
		break;
		
	case FIGURA_J:
	
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		m_figura[0][1] = COLOR_BLAUFOSC;
		m_figura[1][1] = COLOR_BLAUFOSC;
		m_figura[2][0] = COLOR_BLAUFOSC;
		m_figura[2][1] = COLOR_BLAUFOSC;
		break;
		
	case FIGURA_Z:
	
		m_mida = 3;
		m_color = COLOR_VERMELL;
		m_figura[0][0] = COLOR_VERMELL;
		m_figura[0][1] = COLOR_VERMELL;
		m_figura[1][1] = COLOR_VERMELL;
		m_figura[1][2] = COLOR_VERMELL;
		break;
		
	case FIGURA_S:
	
		m_mida = 3;
		m_color = COLOR_VERD;
		m_figura[0][1] = COLOR_VERD;
		m_figura[0][2] = COLOR_VERD;
		m_figura[1][0] = COLOR_VERD;
		m_figura[1][1] = COLOR_VERD;
		break;
	}
}

// Aquest mètode gira la figura en la direcció indicada (horària o antihorària).

void Figura::girar(const DireccioGir& gir)
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];
	ColorFigura invertir[MAX_ALCADA][MAX_AMPLADA];

	// Transposa la matriu de la figura.
	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
		
			transposada[j][i] = m_figura[i][j];

	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
		
			m_figura[i][j] = transposada[i][j];

	// Inverteix la matriu segons la direcció de gir.
	
	if (gir == GIR_HORARI)
	{
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
			
				invertir[i][j] = m_figura[i][m_mida - 1 - j];
	}
	else
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
			
				invertir[i][j] = m_figura[m_mida - 1 - i][j];

	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
		
			m_figura[i][j] = invertir[i][j];
}

// Aquest mètode mou la figura cap avall o cap amunt segons la direcció indicada.
void Figura::baixar(const int& dirY)
{
	if (dirY == -1)
	
		m_posicio.vertical--;
		
	else
	
		m_posicio.vertical++;
}

// Aquest mètode mou la figura cap a la dreta o cap a l'esquerra segons la direcció indicada.
void Figura::desplacar(const int& dirX)
{
	if (dirX == -1)
	
		m_posicio.horitzontal--;
	else
	
		m_posicio.horitzontal++;
}
