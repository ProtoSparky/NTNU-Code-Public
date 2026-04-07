#ifndef _elsparkesykkelSubclass_h
#define _elsparkesykkelSubclass_h

#include "gjenstandClass.h"

class Elsparkesykkel : public Gjenstand{

private:
	int watt; 
public:
  void visGjenstand() override;
	void settBoolAttributt(bool data) override;
	void settIntAttributt(int data) override; 
	bool hentBoolAtributt() override;
	int hentIntAtrubutt() override; 
	int beregnPris() override; 
};

#endif