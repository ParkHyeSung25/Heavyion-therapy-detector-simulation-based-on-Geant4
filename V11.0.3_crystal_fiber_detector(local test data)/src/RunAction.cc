#include "RunAction.hh"

#include "G4AutoLock.hh"
#include "G4Threading.hh"

#include <iostream>

namespace { G4Mutex RunActionMutex = G4MUTEX_INITIALIZER; }
RootInterface* RunAction::sRootIO = 0;
int RunAction::sNumEvt = 0;

RunAction::RunAction(G4int seed, G4String filename)
: G4UserRunAction() {
  fSeed = seed;
  fFilename = filename;

  G4AutoLock lock(&RunActionMutex);

  if (!sRootIO) {
    sRootIO = new RootInterface(fFilename+"_"+std::to_string(fSeed)+".root");
    sRootIO->create();
  }
}

RunAction::~RunAction() {
  if (IsMaster()) {
    G4AutoLock lock(&RunActionMutex);

    if (sRootIO) {
      sRootIO->write();
      sRootIO->close();
      delete sRootIO;
      sRootIO = 0;
    }
  }
}

void RunAction::BeginOfRunAction(const G4Run*) {}

void RunAction::EndOfRunAction(const G4Run*) {}
