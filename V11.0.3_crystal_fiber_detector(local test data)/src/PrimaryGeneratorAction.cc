//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: PrimaryGeneratorAction.cc 77781 2013-11-28 07:54:07Z gcosmo $
//
/// \file PrimaryGeneratorAction.cc
/// \brief Implementation of the PrimaryGeneratorAction class

#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4GenericMessenger.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4AutoLock.hh"

namespace { G4Mutex PrimaryGeneratorActionMutex = G4MUTEX_INITIALIZER; }
int PrimaryGeneratorAction::sNumEvt = 0;
G4ThreadLocal int PrimaryGeneratorAction::sIdxEvt = 0;

PrimaryGeneratorAction::PrimaryGeneratorAction(G4int seed)
: G4VUserPrimaryGeneratorAction() {
  fSeed = seed;
  fNumPtc = 1;
  fTheta = 0.;
  fPhi = 0.;
  fRandX = 0.*mm;
  fRandY = 0.*mm;
  fY_0 = 0.*cm;
  fZ_0 = 0.*cm;

  fParticleGun = new G4ParticleGun(fNumPtc);

  G4ParticleTable* ptcTable = G4ParticleTable::GetParticleTable();
  G4String ptcName;
  fElectron = ptcTable->FindParticle(ptcName="e-");
  fMuon = ptcTable->FindParticle(ptcName="mu-");
  fPion = ptcTable->FindParticle(ptcName="pi+");
  fKaon0L = ptcTable->FindParticle(ptcName="kaon0L");
  fProton = ptcTable->FindParticle(ptcName="proton");
  fOptPhoton = ptcTable->FindParticle(ptcName="opticalphoton");
  fGamma = ptcTable->FindParticle(ptcName="gamma");

  DefineCommands();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
  if (fMessenger) delete fMessenger;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* evt) {
  fY = (G4UniformRand()-0.5)*fRandX + fY_0;
  fZ = (G4UniformRand()-0.5)*fRandY + fZ_0;
  fOrigin.set(0.,fY,fZ);

  fParticleGun->SetParticlePosition(fOrigin);

  fDirection.setREtaPhi(1.,0.,0.);
  fDirection.rotateY(fTheta);
  fDirection.rotateZ(fPhi);

  fParticleGun->SetParticleMomentumDirection(fDirection);

  G4AutoLock lock(&PrimaryGeneratorActionMutex);
  fParticleGun->GeneratePrimaryVertex(evt);
  sIdxEvt = sNumEvt;
  sNumEvt++;
}

void PrimaryGeneratorAction::DefineCommands() {
  // Define /generator command directory using generic messenger class
  fMessenger = new G4GenericMessenger(this, "/generator/", "Primary generator control");

  G4GenericMessenger::Command& etaCmd = fMessenger->DeclareMethodWithUnit("theta","rad",&PrimaryGeneratorAction::SetTheta,"theta of beam");
  etaCmd.SetParameterName("theta",true);
  etaCmd.SetDefaultValue("0.");

  G4GenericMessenger::Command& phiCmd = fMessenger->DeclareMethodWithUnit("phi","rad",&PrimaryGeneratorAction::SetPhi,"phi of beam");
  phiCmd.SetParameterName("phi",true);
  phiCmd.SetDefaultValue("0.");

  G4GenericMessenger::Command& y0Cmd = fMessenger->DeclareMethodWithUnit("y0","cm",&PrimaryGeneratorAction::SetY0,"y_0 of beam");
  y0Cmd.SetParameterName("y0",true);
  y0Cmd.SetDefaultValue("0.");

  G4GenericMessenger::Command& z0Cmd = fMessenger->DeclareMethodWithUnit("z0","cm",&PrimaryGeneratorAction::SetZ0,"z_0 of beam");
  z0Cmd.SetParameterName("z0",true);
  z0Cmd.SetDefaultValue("0.");

  G4GenericMessenger::Command& randxCmd = fMessenger->DeclareMethodWithUnit("randx","mm",&PrimaryGeneratorAction::SetRandX,"x width of beam");
  randxCmd.SetParameterName("randx",true);
  randxCmd.SetDefaultValue("10.");

  G4GenericMessenger::Command& randyCmd = fMessenger->DeclareMethodWithUnit("randy","mm",&PrimaryGeneratorAction::SetRandY,"y width of beam");
  randyCmd.SetParameterName("randy",true);
  randyCmd.SetDefaultValue("10.");
}
