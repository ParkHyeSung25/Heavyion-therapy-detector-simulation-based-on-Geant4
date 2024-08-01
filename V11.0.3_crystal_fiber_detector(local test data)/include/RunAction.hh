#ifndef RunAction_h
#define RunAction_h 1

#include "RootInterface.h"
#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class RunAction : public G4UserRunAction {
public:
  RunAction(G4int seed, G4String filename);
  virtual ~RunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);

  static RootInterface* sRootIO;
  static int sNumEvt;

private:
  G4int fSeed;
  G4String fFilename;
};

#endif
