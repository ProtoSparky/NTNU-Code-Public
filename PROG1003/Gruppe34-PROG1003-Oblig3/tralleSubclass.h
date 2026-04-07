#ifndef _tralleSubclass_h
#define _tralleSubclass_h
#include "gjenstandClass.h"


class Tralle : public Gjenstand{
private:
	bool drasele; //true om trallen har en sele
public:
  void visGjenstand() override;
	void settBoolAttributt(bool data) override;
	void settIntAttributt(int data) override;
	bool hentBoolAtributt() override; 
	int hentIntAtrubutt() override; 
	int beregnPris() override; 
};

#endif