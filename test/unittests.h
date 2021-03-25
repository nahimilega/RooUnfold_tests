#ifndef __UNITTESTS_H__
#define __UNITTESTS_H__

#include "RooUnfoldResponse.h"
#include "TVector.h"

void RooUnfoldGenerate();
RooUnfoldResponse BuildRooUnfoldResponse();
TVector BuildRooUnfoldBayes();
void WriteRooUnfoldBayes();

#endif
