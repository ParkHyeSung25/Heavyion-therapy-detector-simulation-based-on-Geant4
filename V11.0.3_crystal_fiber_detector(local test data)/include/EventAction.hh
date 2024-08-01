#ifndef EventAction_h
#define EventAction_h 1

#include "Interface.h"
#include "SiPMHit.hh"
#include "SiPMSD.hh"

#include "G4UserEventAction.hh"

class RunAction;

class EventAction : public G4UserEventAction {
public:
  EventAction();
  virtual ~EventAction();

  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);

  void fillEdeps(Interface::EdepData& edepData);
  void fillSecondaries(Interface::SecondaryData secondary);
  void fillSteps(Interface::StepData step);
  void fillOpticalPhoton(Interface::Photon& photon, G4int oPnumber);
  void fillPhysics(Interface::Physicalevent& physical,G4double x,G4double y,G4double z,G4double energy,G4String PartName,G4String PhysicName);
  //void fillVexs(Interface::Vertax& vexData);

private:
  std::vector<G4int> fSiPMCID;

  void clear();
  void fillHits(SiPMHit* hit);
  void queue();

  Interface::EventData* fEventData;
  std::map<int,Interface::TowerData> fTowerMap;
  std::map<int,Interface::EdepData> fEdepMap;
  std::vector<Interface::Physicalevent> fPhysicalMap;
  std::vector<Interface::Photon> fPhotonVector;
  // std::map<int,Interface::TotalPhysical> fPhysicalMap;
};

#endif
