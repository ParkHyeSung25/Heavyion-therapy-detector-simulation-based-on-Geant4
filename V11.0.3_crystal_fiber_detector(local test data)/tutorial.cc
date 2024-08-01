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
// $Id: example.cc 70284 2013-05-28 17:26:43Z perl $
//
/// \file example.cc
/// \brief Main program of the analysis/ example

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

#include "G4MTRunManager.hh"
#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "G4OpticalPhysics.hh"
#include "FTFP_BERT.hh"
#include "FTFP_BERT_HP.hh"
#include "QGSP_BERT_HP.hh"
#include "Randomize.hh"
#include "G4EmStandardPhysics_option4.hh"
//#include "G4Cerenkov.hh"
//#include "G4Scintillation.hh"
#include "G4StepLimiterPhysics.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4ScoringManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
    //Detect interactive mode (if no argument) and define UI session
    G4UIExecutive* ui = nullptr;
    if ( argc == 1 ) { //No commands line argument
      //Let G4UIExecutive guess what is the best available UI
      ui = new G4UIExecutive(argc,argv);
    }

    G4int seed = 0;
    G4String filename;
    if (argc > 2) seed = std::atoi(argv[2]);
    if (argc > 3) filename = argv[3];
    
    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
    CLHEP::HepRandom::setTheSeed(seed);
    
    // Construct the default run manager
    //auto* runManager = G4RunManagerFactory::CreateRunManager();
    #ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    #else
    G4RunManager* runManager = new G4RunManager;
    #endif
    // Mandatory user initialization classes
    // =============================================
    // Exercise 3a
    // Activate UI-command base scorer.
    // Add here the lines to activate command line
    // based scorer.
    // Remember to add the correct "include" statement
    // =============================================
    
    G4VModularPhysicsList* physicsList = new FTFP_BERT;
    G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
    physicsList->RegisterPhysics(opticalPhysics);
    auto opticalParams = G4OpticalParameters::Instance();
    opticalParams->SetProcessActivation("Cerenkov", true);
    opticalParams->SetProcessActivation("Scintillation", true);
    opticalParams->SetScintTrackSecondariesFirst(true);
    opticalParams->SetCerenkovTrackSecondariesFirst(true);
    opticalParams->SetCerenkovMaxPhotonsPerStep(100);
    opticalParams->SetCerenkovMaxBetaChange(10.0);
    
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(physicsList);
    runManager->SetUserInitialization(new ActionInitialization(seed,filename));

    // Activate UI-command base scorer
//    G4ScoringManager * scManager = G4ScoringManager::GetScoringManager();
//    scManager->SetVerboseLevel(1);
    
    // Visualization manager construction
    G4VisManager* visManager = new G4VisExecutive;
    // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
    // G4VisManager* visManager = new G4VisExecutive("Quiet");
    visManager->Initialize();
    
    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    
    if (argc>1) {
        // execute an argument macro file if exist
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else {
      //We have visualization, initialize defaults: look in init_vis.mac macro
      UImanager->ApplyCommand("/control/execute init_vis.mac");
      UImanager->ApplyCommand("/control/execute init.mac");

      if (ui->IsGUI() ) {
         UImanager->ApplyCommand("/control/execute gui.mac");
      }
      ui->SessionStart();
      delete ui;
    }
    // Job termination
    // Free the store: user actions, physics_list and detector_description are
    // owned and deleted by the run manager, so they should not be deleted 
    // in the main() program !
  
    delete visManager;
    delete runManager;
    
    return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
