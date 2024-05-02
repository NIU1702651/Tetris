#include "figura.h"
void Figura::crearFigura(const TipusFigura& tipus, int
	matriu[MAX_ALCADA][MAX_AMPLADA])
{
	if (tipus == NO_FIGURA)
	{
		for (int f = 0; f < 4; f++)
		{
			for (int c = 0; c < 4; c++)
			{
				if (matriu == nullptr)
					m_figura[f][c] = COLOR_NEGRE;
				else
					matriu[f][c] = COLOR_NEGRE;
			}
		}
	}
	else if (tipus != m_tipus)
	{
		m_tipus = tipus;
		switch (m_tipus)
		{
		case FIGURA_O:
			m_color = COLOR_GROC;
			break;
		case FIGURA_I:
			m_color = COLOR_BLAUCEL;
			break;
		case FIGURA_T:
			m_color = COLOR_MAGENTA;
			break;
		case FIGURA_L:
			m_color = COLOR_TARONJA;
			break;
		case FIGURA_J:
			m_color = COLOR_BLAUFOSC;
			break;
		case FIGURA_Z:
			m_color = COLOR_VERMELL;
			break;
		case FIGURA_S:
			m_color = COLOR_VERD;
			break;
		case NO_FIGURA:
			m_color = NO_COLOR;
			break;
		}
		if (tipus >= FIGURA_I && tipus < FIGURA_Z)
		{
			for (int i = 0; i < 3; i++)
			{
				m_figura[1][i] = m_color;
			}
			switch (tipus) {
			case FIGURA_I:
				m_maxCol = MAX_AMPLADA; m_maxFil = MAX_ALCADA; m_columnaCentre =
					2;
				m_figura[1][3] = m_color;
				break;
			case FIGURA_T:
				m_figura[0][1] = m_color;
				break;
			case FIGURA_L:
				m_figura[0][2] = m_color;
				break;
			case FIGURA_J:
				m_figura[0][0] = m_color;
				break;
			default:
				break;
			}
		}
		else
		{
			m_figura[0][1] = m_color;
			m_figura[1][1] = m_color;
			switch (tipus) {
			case FIGURA_O:
				m_maxCol = 2; m_maxFil = 2; m_potRotar = false;
				m_figura[0][0] = m_color;
				m_figura[1][0] = m_color;
				break;
			case FIGURA_Z:
				m_figura[0][0] = m_color;
				m_figura[1][2] = m_color;
				break;
			case FIGURA_S:
				m_figura[0][2] = m_color;
				m_figura[1][0] = m_color;
				break;
			default:
				break;
			}
		}
	}
}
void Figura::copiaMatriu(const int matriu[MAX_ALCADA][MAX_AMPLADA])
{
	for (int f = 0; f < m_maxFil; f++)
	{
		for (int c = 0; c < m_maxCol; c++)
		{
			m_figura[c][f] = matriu[c][f];
		}
	}
}
void Figura::girFigura(const DireccioGir& direccioGir)
{
	if (m_potRotar)
	{
		int matriuTrans[MAX_ALCADA][MAX_AMPLADA];
		crearFigura(NO_FIGURA, matriuTrans);
		for (int f = 0; f < m_maxFil; f++)
		{
			for (int c = 0; c < m_maxCol; c++)
			{
				if (m_figura[f][c] != NO_COLOR)
				{
					matriuTrans[c][f] = m_figura[f][c];
				}
			}
		}
		copiaMatriu(matriuTrans);
		int matriuTemp[MAX_ALCADA][MAX_AMPLADA];
		crearFigura(NO_FIGURA, matriuTemp);
		for (int f = 0; f < m_maxFil; f++)
		{
			for (int c = 0; c < m_maxCol; c++)
			{
				matriuTemp[f][c] = m_figura[direccioGir != GIR_HORARI ? m_maxFil - 1 - f :
					f][direccioGir == GIR_HORARI ? m_maxCol - 1 - c : c];
			}
		}
		copiaMatriu(matriuTemp);
		if (direccioGir == GIR_HORARI)
		{
			m_gir++;
			if (m_gir > 3)
			{
				m_gir = 0;
			}
		}
		else
		{
			m_gir--;
			if (m_gir < 0)
			{
				m_gir = 3;
			}
		}
	}
}
