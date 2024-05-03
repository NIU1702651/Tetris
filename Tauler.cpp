#include "Tauler.h"

// Constructor bàsic, posa el tauler tot de color negre.

Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
		
			m_tauler[i][j] = COLOR_NEGRE;
			
}


// Constructor que copia un tauler donat.

Tauler::Tauler(ColorFigura tauler[MAX_COL][MAX_FILA])
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = tauler[i][j];
}


// Verifica si una posició està dins dels límits del tauler i és buida.

bool Tauler::posicioValida(const Posicio& pos) const
{
	bool esValida = true;

	if (0 > pos.horitzontal || pos.horitzontal >= MAX_FILA || pos.vertical >= MAX_COL)
	
		esValida = false;
		
	else
	{
	    
		if (m_tauler[pos.vertical][pos.horitzontal] != COLOR_NEGRE)
			esValida = false;
			
	}

	return esValida;
}


// Verifica si una figura pot moure's a una posició determinada sense sortir del tauler ni ocupar caselles ocupades.

bool Tauler::esMovimentValid(const Figura& figura, const Posicio& pos) const
{
	bool esValid = true;
	int i = 0;

	while (i < figura.getMida() && esValid)
	{
		int j = 0;
		while (j < figura.getMida() && esValid)
		{
			if (figura.getFigura(i, j) != NO_COLOR)
			{
			    
				Posicio pos_tmp;
				pos_tmp.vertical = pos.vertical + i;
				pos_tmp.horitzontal = pos.horitzontal + j;

				esValid = posicioValida(pos_tmp);
				
			}
			
			j++;
		}
		
		i++;
	}

	return esValid;
}

// Elimina files completes i desplaça les files superiors.
int Tauler::eliminarFilesCompletades()
{
	int nCompletades = 0;

	for (int i = 0; i < MAX_FILA; ++i)
	{
		bool completa = true;
		int j = 0;

		while (j < MAX_COL && completa)
		{
			if (m_tauler[i][j] == 0) {
				completa = false;
			}
			j++;
		}

		if (completa)
		{
			nCompletades++;
			for (int fila = i; fila > 0; --fila)
				for (int k = 0; k < MAX_COL; ++k)
				
					m_tauler[fila][k] = m_tauler[fila - 1][k];
					

			for (int k = 0; k < MAX_COL; ++k)
			
				m_tauler[0][k] = COLOR_NEGRE;
		}

	}
	
	return nCompletades;
}

// Elimina una figura del tauler.

void Tauler::eliminarFigura(Figura figura, const Posicio& pos)
{
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; j < figura.getMida(); j++)
		
			if (figura.getFigura(i, j) != NO_COLOR)
			{
			    
			   
				m_tauler[pos.vertical + i][pos.horitzontal + j] = COLOR_NEGRE;
				
			}
}


// Col·loca una figura en una posició sense verificar si és vàlida.

void Tauler::collocarFigura(Figura figura, const Posicio& pos)
{
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; j < figura.getMida(); j++)
		{
		    
			if (figura.getFigura(i, j) != NO_COLOR)
			{
			    
				m_tauler[pos.vertical + i][pos.horitzontal + j] = figura.getColor();
				
			}
		}
		
	figura.setPosicio(pos);
}
