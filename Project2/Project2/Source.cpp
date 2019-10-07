#include"CRaquetas.h"
#include"CMapa.h"
#include"CPelota.h"
void main() {
	Console::CursorVisible = false;
	CMapa *m = new CMapa();
	CRaquetas *a = new CRaquetas(1, 1, true, m, 900000);
	CRaquetas *b = new CRaquetas(18, 118, true, m, 900000);
	CPelota *p = new CPelota(15, 60, m, false, true, false, true, a, b, 855000);
	while (true)
	{
		a->desplazar();
		b->desplazar();
		p->desplazar();
		p->avisarIA(b);
		p->avisarIA(a);
	}
}