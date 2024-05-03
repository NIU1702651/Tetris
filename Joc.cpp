#include "Joc.h"

// Aquí comencem definint el mètode que inicialitza el joc amb les dades llegides d'un fitxer.
void Joc::inicialitza(const string& nomFitxer)
{
	Posicio posicio;
	int tipus, gir;
	ifstream fitxer;
	m_figuraCollocada = false;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		// Llegim el tipus de figura, la posició (x,y), la rotació de la figura i el tauler amb els seus colors.
		fitxer >> tipus;
		
		m_figura.inicialitza(TipusFigura(tipus));

		fitxer >> posicio.vertical >> posicio.horitzontal;

		posicio.vertical--;
		posicio.horitzontal--;

		m_figura.setPosicio(posicio);
		m_posicio = posicio;
		
		fitxer >> gir;
		
		
		for (int i = 0; i < gir; i++)
			m_figura.girar(GIR_HORARI);


		for (int i = 0; i < MAX_COL; i++)
		{
			for (int j = 0; j < MAX_FILA; j++)
			{
			    
				int color;
				fitxer >> color;

				m_tauler.setTauler(ColorFigura(color), i, j);
			}
		}

		fitxer.close();
	}
}

// Aquest mètode gira la figura en la direcció especificada i verifica si el moviment és vàlid.
// Si no ho és, ajusta la rotació de la figura.

bool Joc::giraFigura(DireccioGir direccio)
{
	bool gira = true;
	m_figura.girar(direccio);

	if (!m_tauler.esMovimentValid(m_figura, m_posicio))
	{
		if (direccio == GIR_HORARI)
		
			m_figura.girar(GIR_ANTI_HORARI);
			
		else
		
			m_figura.girar(GIR_HORARI);
			
		gira = false;
	}

	return gira;
}


// Aquest mètode mou la figura en la direcció especificada i verifica si la posició és vàlida.
// Si no ho és, ajusta la posició de la figura.

bool Joc::mouFigura(int dirX)
{
	bool mou = true;
	m_figura.desplacar(dirX);

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	
	{
		if (dirX == -1)
		
			m_figura.desplacar(1);
		else
		
			m_figura.desplacar(-1);
		mou = false;
	}
	
	else
	
		m_posicio = m_figura.getPosicio();

	return mou;
}

// Aquest mètode fa baixar la figura actual una fila.

int Joc::baixaFigura()
{
	int nFiles = 0;
	m_figura.baixar(1);

	// Si el moviment no és vàlid, col·loca la figura en la posició actual, elimina les files completades i retorna el nombre de files eliminades.
	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	
	{
		m_figura.baixar(-1);
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
		m_figuraCollocada = true;
		nFiles = m_tauler.eliminarFilesCompletades();
	}
	
	else
	
		m_posicio = m_figura.getPosicio();

	return nFiles;
}

// Aquest mètode escriu l'estat actual del tauler en un fitxer passat com a paràmetre.

void Joc::escriuTauler(const string& nomFitxer)
{
	int i, j;
	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		// Si la figura encara no està col·locada, la col·loca temporalment per escriure el tauler.
		if (!m_figuraCollocada)
			m_tauler.collocarFigura(m_figura, m_posicio);

		// S'escriu el tauler en el document.
		for (int i = 0; i < MAX_COL; i++)
		{
		    
			for (int j = 0; j < MAX_FILA; j++)
			
				fitxer << int(m_tauler.getTauler(i, j)) << " ";
			fitxer << endl;
		}

		// S'elimina la figura que s'ha col·locat temporalment.
		
		if(!m_figuraCollocada)
		
			m_tauler.eliminarFigura(m_figura, m_posicio);
			
		fitxer.close();
	}
}
