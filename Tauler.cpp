#include "Tauler.h"
void Tauler::crearTauler(const int& fila, const string& linia)
{
	for (int f = 0; f < MAX_FILA; f++)
	{
		for (int c = 0; c < MAX_COL; c++)
		{
			m_tauler[f][c] = COLOR_NEGRE;
		}
	}
}
bool Tauler::movientValid_H(const Figura* figura, bool dreta)
{
	int Y = figura->getFila();
	int X = figura->getColumna();
	bool valid = false;
	int limit = dreta ? X + figura->getMaxColumna() - figura->getColumnaCentre() : X -
		figura->getMaxColumna() + figura->getColumnaCentre();
	if (dreta ? limit <= MAX_COL : limit >= 0)
	{
		TipusFigura tFig = figura->getTipus();
		int gir = figura->getGir();
		if (tFig == FIGURA_I)
			if (gir == 0 || gir == 2)
				valid = m_tauler[Y][dreta ? X + 3 : X - 2] == 0;
			else
			{
				int xT = dreta ? X + 1 : X - 1;
				valid = m_tauler[Y - 1][xT] == 0 &&
					m_tauler[Y][xT] == 0 && m_tauler[Y + 1][xT] == 0 &&
					m_tauler[Y + 2][xT] == 0;
			}
		else if (tFig == FIGURA_O)
		{
			int xT = dreta ? X + 1 : X - 1;
			valid = m_tauler[Y][xT] == 0 && m_tauler[Y + 1][xT] == 0;
		}
		else if (tFig == FIGURA_T || tFig == FIGURA_L || tFig == FIGURA_J)
		{
			if (gir == 0 || gir == 2)
			{
				int xT = dreta ? X + 2 : X - 2;
				valid = m_tauler[Y][dreta ? X + 2 : X - 2] == 0 &&
					m_tauler[dreta ? Y + 1 : Y - 1][dreta ? tFig == FIGURA_L ? X : tFig ==
					FIGURA_T ? X + 1 : X + 2 : tFig == FIGURA_L ? X : tFig == FIGURA_T ? X - 1 : X - 2] == 0;
			}
			else
			{
				int xT = dreta ? X + 1 : X - 1;
				valid = m_tauler[Y - 1][gir == 1 ? tFig == FIGURA_L ? X - 2 : xT : tFig == FIGURA_J
					? X - 2 : xT] == 0 &&
					m_tauler[Y][tFig == FIGURA_T ? X - 2 : xT] == 0 &&
					m_tauler[Y + 1][gir == 1 ? tFig == FIGURA_J ? X - 2 : xT : tFig == FIGURA_L ?
					X - 2 : xT] == 0;
			}
		}
		else if (tFig == FIGURA_S || tFig == FIGURA_Z)
		{
			if (gir == 0 || gir == 2)
			{
				int xT = dreta ? tFig == FIGURA_S ? X + 2 : X + 1 : tFig == FIGURA_S ? X - 1 : X - 2;
				int xT2 = dreta ? tFig == FIGURA_S ? X + 1 : X + 2 : tFig == FIGURA_S ? X - 2 : X - 1;
				valid = m_tauler[Y][xT] == 0 &&
					m_tauler[Y + 1][xT2] == 0;
			}
			else
			{
				int xT = dreta ? X + 1 : X - 2;
				valid = m_tauler[Y - 1][dreta ? tFig == FIGURA_S ? X : xT : tFig == FIGURA_S ? xT
					: X - 1] == 0 &&
					m_tauler[Y][xT] == 0 &&
					m_tauler[Y + 1][dreta ? tFig == FIGURA_S ? xT : X : tFig == FIGURA_S ? X - 1
					: xT] == 0;
			}
		}
	}
	return valid;
}
bool Tauler::movientValid_V(const Figura* figura)
{
	int X = figura->getColumna();
	int Y = figura->getFila();
	bool valid = false;
	TipusFigura tFig = figura->getTipus();
	int gir = figura->getGir();
	if (tFig == FIGURA_O)
		valid = m_tauler[Y + 2][X - 1] == 0 && m_tauler[Y + 2][X] == 0;
	else if (tFig == FIGURA_I)
	{
		if (gir == 0 || gir == 2)
		{
			valid = m_tauler[Y + 1][X - 1] == 0 &&
				m_tauler[Y + 1][X] == 0 &&
				m_tauler[Y + 1][X + 1] == 0 &&
				m_tauler[Y + 1][X + 2] == 0;
		}
		else
			valid = m_tauler[Y + 3][X] == 0;
	}
	else if (tFig == FIGURA_S || tFig == FIGURA_Z)
	{
		if (gir == 0 || gir == 2)
		{
			valid = m_tauler[tFig == FIGURA_Z ? Y + 1 : Y + 2][X - 1] == 0 &&
				m_tauler[Y + 2][X] == 0 &&
				m_tauler[tFig == FIGURA_S ? Y + 1 : Y + 2][X + 1] == 0;
		}
		else
		{
			valid = m_tauler[tFig == FIGURA_Z ? Y + 2 : Y + 1][X - 1] == 0 &&
				m_tauler[tFig == FIGURA_S ? Y + 1 : Y + 2][X] == 0;
		}
	}
	else {
		if (gir == 0 || gir == 2)
		{
			valid = m_tauler[gir == 0 && tFig == FIGURA_L ? Y + 2 : Y + 1][X - 1] == 0 &&
				m_tauler[gir == 0 && tFig == FIGURA_T ? Y + 2 : Y + 1][X] == 0 &&
				m_tauler[gir == 0 && tFig == FIGURA_J ? Y + 2 : Y + 1][X + 1] == 0;
		}
		else
		{
			int yT = gir == 1 ? tFig == FIGURA_L ? Y : tFig == FIGURA_T ? Y + 1 : Y + 2 : tFig ==
				FIGURA_L ? Y + 2 : tFig == FIGURA_T ? Y + 1 : Y;
			valid = m_tauler[yT][X - 1] == 0 &&
				m_tauler[Y + 2][X] == 0;
		}
	}
	return valid;
}
bool Tauler::girValid(const Figura* figura, DireccioGir& direccio)
{
	int X = figura->getColumna();
	int Y = figura->getFila();
	bool valid = false;
	TipusFigura tFig = figura->getTipus();
	int gir = figura->getGir();
	if (tFig == FIGURA_I)
	{
		if (gir % 2 == 0)
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y + 1][X] == 0 &&
			m_tauler[Y + 2][X] == 0;
		else
			valid = m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0 &&
			m_tauler[Y][X + 2] == 0;
	}
	else if (tFig == FIGURA_S || tFig == FIGURA_Z)
	{
		if (gir % 2 == 0)
		{
			if (tFig == FIGURA_S)
				valid = m_tauler[Y][X - 1] == 0 &&
				m_tauler[Y - 1][X - 1] == 0;
			else
				valid = m_tauler[Y + 1][X] == 0 && m_tauler[Y - 1][X - 1] == 0;
		}
		else
		{
			if (tFig == FIGURA_S)
				valid = m_tauler[Y][X + 1] == 0 &&
				m_tauler[Y - 1][X - 1] == 0;
			else
				valid = m_tauler[Y - 1][X] == 0 &&
				m_tauler[Y - 1][X + 1] == 0;
		}
	}
	else if (tFig == FIGURA_L)
	{
		if ((gir == 0 && direccio == GIR_HORARI) || (gir == 2 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 1
			valid = m_tauler[Y - 1][X - 1] == 0 &&
			m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y + 1][X] == 0;
		else if ((gir == 1 && direccio == GIR_HORARI) || (gir == 3 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 2
			valid = m_tauler[Y - 1][X + 1] == 0 &&
			m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0;
		else if ((gir == 2 && direccio == GIR_HORARI) || (gir == 0 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 3
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y + 1][X] == 0 &&
			m_tauler[Y + 1][X + 1] == 0;
		else if ((gir == 3 && direccio == GIR_HORARI) || (gir == 1 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 0
			valid = m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0 &&
			m_tauler[Y + 1][X - 1] == 0;
	}
	else if (tFig == FIGURA_T)
	{
		if ((gir == 0 && direccio == GIR_HORARI) || (gir == 2 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 1
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y + 1][X] == 0;
		else if ((gir == 1 && direccio == GIR_HORARI) || (gir == 3 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 2
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0; else if ((gir == 2 && direccio == GIR_HORARI) || (gir == 0 && direccio ==
				GIR_ANTI_HORARI)) //Mierm Estat 3
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y][X + 1] == 0 &&
			m_tauler[Y + 1][X] == 0;
			else if ((gir == 3 && direccio == GIR_HORARI) || (gir == 1 && direccio ==
				GIR_ANTI_HORARI)) //Mierm Estat 0
			valid = m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0 &&
			m_tauler[Y + 1][X] == 0;
	}
	else // if (tFig == FIGURA_J)
	{
		if ((gir == 0 && direccio == GIR_HORARI) || (gir == 2 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 1
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y + 1][X - 1] == 0 &&
			m_tauler[Y + 1][X] == 0;
		else if ((gir == 1 && direccio == GIR_HORARI) || (gir == 3 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 2
			valid = m_tauler[Y - 1][X - 1] == 0 &&
			m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0;
		else if ((gir == 2 && direccio == GIR_HORARI) || (gir == 0 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 3
			valid = m_tauler[Y - 1][X] == 0 &&
			m_tauler[Y - 1][X + 1] == 0 &&
			m_tauler[Y + 1][X] == 0;
		else if ((gir == 3 && direccio == GIR_HORARI) || (gir == 1 && direccio ==
			GIR_ANTI_HORARI)) //Mierm Estat 0
			valid = m_tauler[Y][X - 1] == 0 &&
			m_tauler[Y][X + 1] == 0 &&
			m_tauler[Y + 1][X + 1] == 0;
	}
	return valid;
}
int Tauler::setTauler(Figura* figura)
{
	int f_fila = -1, f_columna;
	for (int f = figura->getFila() - figura->getFilaCentre(); f < (figura->getFila() -
		figura->getFilaCentre() + figura->getMaxFila()); f++)
	{
		f_fila++; f_columna = -1;
		for (int c = figura->getColumna() - figura->getColumnaCentre(); c <
			(figura->getColumna() - figura->getColumnaCentre() + figura->getMaxColumna()); c++)
		{
			f_columna++;
			m_tauler[f][c] = ColorFigura(m_tauler[f][c] + figura->getCelaFigura(f_fila, f_columna));
		}
	}
	figura->setAlTauler(true);
	return borrarFilesCompletes();
}
void Tauler::mostraTauler()
{
	for (int f = 0; f < MAX_FILA; f++)
	{
		for (int c = 0; c < MAX_COL; c++)
		{
			if (c != 0)
				cout << " ";
			cout << m_tauler[f][c];
		}
		cout << endl;
	}
}
vector<int> Tauler::filesCompletes()
{
	vector<int> d;
	for (int f = 0; f < MAX_FILA; f++)
	{
		bool borrar = false;
		for (int c = 0; c < MAX_COL && !borrar; c++)
		{
			borrar = !(m_tauler[f][c] == 0);
		}
	}
	return d;
}
int Tauler::borrarFilesCompletes()
{
	vector<int> d = filesCompletes();
	for (int i = d.size() - 1; i >= 0; i++)
	{
		for (int c = 0; c < MAX_COL; c++)
		{
			m_tauler[d[i]][c] = m_tauler[d[i] - 1][c];
		}
	}
	return d.size();
}
