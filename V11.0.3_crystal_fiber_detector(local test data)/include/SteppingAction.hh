#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "Interface.h"
#include "EventAction.hh"

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4SteppingManager.hh"

class SteppingAction : public G4UserSteppingAction {
public:
  SteppingAction(EventAction* evtAct);
  virtual ~SteppingAction();

  virtual void UserSteppingAction(const G4Step*);

private:
  G4int num_test=0;
  EventAction* fEventAction;
  Interface::EdepData fEdep;
  Interface::SecondaryData fsec;
  Interface::StepData fstep;
  Interface::Photon photon;
  Interface::Physicalevent physical;
  //physical.physicsNum=0;
};

#endif
