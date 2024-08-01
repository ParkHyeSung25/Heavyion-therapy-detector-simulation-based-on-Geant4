#include "SiPMHit.hh"

G4ThreadLocal G4Allocator<SiPMHit>* SiPMHitAllocator = 0;

SiPMHit::SiPMHit(G4int wavBin, G4int timeBin)
: G4VHit(),
fPhotons(0),
fSiPMnum(-1),
fTowernum(-1),
fX(-1),
fY(-1),
fFront(0),
fTowerX(-1),
fTowerY(-1),
fWavBin(wavBin),
fTimeBin(timeBin)
{}

SiPMHit::~SiPMHit() {}

SiPMHit::SiPMHit(const SiPMHit &right)
: G4VHit() {
  fSiPMnum = right.fSiPMnum;
  fPhotons = right.fPhotons;
  fTowernum = right.fTowernum;
  fX = right.fX;
  fY = right.fY;
  fFront=right.fFront;
  fTowerX = right.fTowerX;
  fTowerY = right.fTowerY;
  fTimeStruct = right.fTimeStruct;
  fWavlenSpectrum=right.fWavlenSpectrum;

}

const SiPMHit& SiPMHit::operator=(const SiPMHit &right) {
  fSiPMnum = right.fSiPMnum;
  fPhotons = right.fPhotons;
  fTowernum = right.fTowernum;
  fX = right.fX;
  fY = right.fY;
  fFront = right.fFront;
  fTowerX = right.fTowerX;
  fTowerY = right.fTowerY;
  fTimeStruct = right.fTimeStruct;
  fWavlenSpectrum=right.fWavlenSpectrum;

  return *this;
}

G4bool SiPMHit::operator==(const SiPMHit &right) const {
  return (fSiPMnum==right.fSiPMnum && fTowernum==right.fTowernum && fFront==right.fFront);
}

void SiPMHit::CountWavlenSpectrum(Interface::hitRange range) {
  auto it = fWavlenSpectrum.find(range);
  if (it==fWavlenSpectrum.end()) fWavlenSpectrum.insert(std::make_pair(range,1));
  else it->second++;
}

void SiPMHit::CountTimeStruct(Interface::hitRange range){
  auto it=fTimeStruct.find(range);
  if (it==fTimeStruct.end())  fTimeStruct.insert(std::make_pair(range,1));
  else it->second++;

}
