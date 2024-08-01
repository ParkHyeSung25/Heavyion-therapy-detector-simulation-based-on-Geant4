#ifndef SiPMSD_h
#define SiPMSD_h 1

#include "SiPMHit.hh"

#include "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include <utility>

class SiPMSD : public G4VSensitiveDetector {
public:
  SiPMSD(const G4String& name, const G4String& hitsCollectionName, std::pair<int,int> xy);
  virtual ~SiPMSD();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory*);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);
  void IsFrontFunction(){fIsFront=1;}

private:
  SiPMHitsCollection* fHitCollection;
  G4int fHCID;
  G4int fIsFront;
  std::pair<int,int> fTowerXY;
  G4int fWavBin;
  G4int fTimeBin;
  G4float fWavlenStart;
  G4float fWavlenEnd;
  G4float fTimeStart;
  G4float fTimeEnd;
  G4float fWavlenStep;
  G4float fTimeStep;

    G4double wavToE(G4double wav) { return h_Planck*c_light/wav; }

  Interface::hitRange findWavRange(G4double en);
  Interface::hitRange findTimeRange(G4double stepTime);
};

#endif
