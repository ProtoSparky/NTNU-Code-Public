#ifndef _sykkelSubclass_h
#define _sykkelSubclass_h
#include "gjenstandClass.h"

class Sykkel : public Gjenstand{
private:
	bool harTilhenger; 
public:
  void visGjenstand() override;
	void settBoolAttributt(bool data) override;
	void settIntAttributt(int data) override;
	bool hentBoolAtributt() override;
	int hentIntAtrubutt() override;
	int beregnPris() override;

};

#endif