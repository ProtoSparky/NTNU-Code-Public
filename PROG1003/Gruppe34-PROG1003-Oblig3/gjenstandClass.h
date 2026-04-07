#ifndef _gjenstandClass_h
#define _gjenstandClass_h
#include "enum.h";

class Gjenstand{
private:
	int gjenstandNr; 
	enum gjenstandType gjenstandEnum;
public:
	void settGjenstandNr(int nr);
	int hentGjenstadNr();
	void settEnum(int enumTall);
	int hentGjenstandEnum();
	virtual void visGjenstand();
	virtual void settBoolAttributt(bool data);
	virtual void settIntAttributt(int data);
	virtual bool hentBoolAtributt();
	virtual int hentIntAtrubutt();
	void visGjenstandTabell(Gjenstand* gjenstand);
	virtual int beregnPris(); 
	void endreAttrubutt();
};

#endif