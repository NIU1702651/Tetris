#ifndef JOC_H
#define JOC_H
#include "tauler.h"
#include "figura.h"
#include <string>
using namespace std;
class Joc
{
public:
	Joc() {}
	~Joc() {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
private:
	Tauler m_taulerJoc;
	Figura* m_figuraActual = nullptr;
	int punts, nivell;
};
ifstream& operator>>(ifstream& input, Figura& figura);
ifstream& operator>>(ifstream& input, Tauler& tauler);
ofstream& operator<<(ofstream& output, Tauler& tauler);
#endif // JOC_H
