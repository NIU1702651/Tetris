#ifndef FIGURA_H
#define FIGURA_H
#include <fstream>
#include <iostream>
using namespace std;
typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;
typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;
typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;
const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;
class Figura
{
public:
	Figura() { crearFigura(); }
	Figura(const TipusFigura& tipus, const int& fila, const int& columna, const int
		& gir) :m_fila(fila), m_columna(columna) {
		crearFigura(); crearFigura(tipus); while (m_gir != gir)
			girFigura(GIR_HORARI);
	}
	//Figura(const Figura &f2);
	~Figura() { cout << "figura borrada" << endl; }
	//Figura &operator =(const Figura &f2);
	void girFigura(const DireccioGir& direccioGir);
	void moureF_H(bool dreta = true) { m_columna += dreta; m_columna -= !dreta; }
	void moureF_V() { m_fila++; }
	// void setTipus(const TipusFigura &tipus) {m_tipus = tipus;} //No necessitem
	// void setColor(const ColorFigura &color) {m_color = color;} //No necessitem
	void setFila(const int& fila) { m_fila = fila; }
	void setColumna(const int& columna) { m_columna = columna; }
	void setGir(const int& gir) { m_gir = gir; }
	void setAlTauler(const bool& setAlTauler) { m_alTauler = setAlTauler; }
	TipusFigura getTipus() const { return m_tipus; }
	// ColorFigura getColor() const {return m_color;} //No necessitem
	int getMaxFila() const { return m_maxFil; }
	int getMaxColumna() const { return m_maxCol; }
	int getFila() const { return m_fila; }
	int getColumna() const { return m_columna; }
	int getFilaCentre() const { return m_filaCentre; }
	int getColumnaCentre() const { return m_columnaCentre; }
	int getGir() const { return m_gir; }
	bool getAlTauler() const { return m_alTauler; }
	int getCelaFigura(const int& fila, const int& columna) const {
		return
			m_figura[fila][columna];
	}
	void mostrarFigura() const {
		for (int f = 0; f < m_maxFil; f++) {
			for (int c = 0; c < m_maxCol;
				c++) {
				cout << m_figura[f][c];
			} cout << endl;
		}
	}
private:
	void crearFigura(const TipusFigura& tipus = NO_FIGURA, int
		matriu[MAX_ALCADA][MAX_AMPLADA] = nullptr);
	void copiaMatriu(const int matriu[MAX_ALCADA][MAX_AMPLADA]);
	TipusFigura m_tipus = NO_FIGURA;
	ColorFigura m_color = COLOR_NEGRE;
	int m_figura[MAX_ALCADA][MAX_AMPLADA];
	int m_maxCol = 3, m_maxFil = 3;
	int m_fila = -1, m_columna = -1;
	int m_filaCentre = 1, m_columnaCentre = 1;
	int m_gir = 0; //{0..3}
	bool m_potRotar = true;
	bool m_alTauler = false;
};
#endif // FIGURA_H