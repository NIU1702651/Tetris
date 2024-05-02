#include "joc.h"
void Joc::inicialitza(const string& nomFitxer)
{
	if (m_figuraActual == nullptr)
		m_figuraActual = new Figura();
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (!fitxer.is_open())
	{
		cout << "Error obrint el fitxer " << nomFitxer << endl;
	}
	else
	{
		fitxer >> *m_figuraActual;
		fitxer >> m_taulerJoc;
		fitxer.close();
	}
}
bool Joc::giraFigura(DireccioGir direccio)
{
	bool girValid = true;
	if (m_figuraActual->getGir())
	{
		girValid = m_taulerJoc.girValid(m_figuraActual, direccio);
		if (girValid)
		{
			m_figuraActual->girFigura(direccio);
		}
	}
	return girValid;
}
bool Joc::mouFigura(int dirX)
{
	bool movimentValid = m_taulerJoc.movientValid_H(m_figuraActual, dirX > 0);
	if (movimentValid)
	{
		m_figuraActual->moureF_H(dirX > 0);
	}
	return movimentValid;
}
int Joc::baixaFigura()
{
	bool movimentValid = m_taulerJoc.movientValid_V(m_figuraActual);
	int filesCompletes = 0;
	if (movimentValid)
	{
		m_figuraActual->moureF_V();
	}
	else
	{
		filesCompletes = m_taulerJoc.setTauler(m_figuraActual);
	}
	return filesCompletes;
}
void Joc::escriuTauler(const string& nomFitxer)
{
	if (!m_figuraActual->getAlTauler())
	{
		m_figuraActual->mostrarFigura();
		m_taulerJoc.setTauler(m_figuraActual);
	}
	cout << "abans de guardar";
	m_taulerJoc.mostraTauler();
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (!fitxer.is_open())
	{
		cout << "Error obrint el fitxer " << nomFitxer << endl;
	}
	else
	{
		fitxer << m_taulerJoc;
		fitxer.close();
	}
}
ifstream& operator>>(ifstream& input, Figura& figura)
{
	int tipus, fila, columna, gir;
	input >> tipus >> fila >> columna >> gir;
	figura = Figura(TipusFigura(tipus), fila, columna, gir);
	return input;
}
ifstream& operator>>(ifstream& input, Tauler& tauler)
{
	int nLinia = 0;
	for (int f = 0; f < MAX_FILA; f++)
	{
		for (int c = 0; c < MAX_COL; c++)
		{
			int color;
			input >> color;
			tauler.setCelaTauler(f, c, color);
		}
	}
	return input;
}
ofstream& operator<<(ofstream& output, Tauler& tauler)
{
	int nLinia = 0;
	for (int f = 0; f < MAX_FILA; f++)
	{
		for (int c = 0; c < MAX_COL; c++)
		{
			if (c != 0)
				output << " ";
			output << tauler.getCelaTauler(f, c);
		}
		output << endl;
	}
	return output;
}
