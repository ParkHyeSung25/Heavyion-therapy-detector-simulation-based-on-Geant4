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
// $Id: DetectorConstruction.hh 76474 2013-11-11 10:36:34Z gcosmo $
//
/// \file DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"
#include "G4FieldManager.hh"
#include "G4VisAttributes.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "G4Material.hh"
#include "SiPMSD.hh"

#include <vector>

class G4VPhysicalVolume;
class G4Material;
class G4VisAttributes;
class G4GenericMessenger;
class fiberSpec;
/// Detector construction

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction();
    virtual ~DetectorConstruction();
    
    //Here the geomtry is constructed. This method is called only by
    //master thread and all geometry built here is shared among threads
    virtual G4VPhysicalVolume* Construct();
    
    //Some components of geometry are thread pricate:
    //SensitiveDetectors and megnetic field.
    //Build them here because this method is called by
    //each thread
    virtual void ConstructSDandField();

    //This is just a convinience: a method where all materials needed
    //are created
    G4Material* GetMaterial(const G4String);
    G4OpticalSurface* GetOpticalSurface(const G4String);

private:
    void CreateMaterials();
    G4Material* FindMaterial(G4String matName) { return GetMaterial(matName); }
    G4OpticalSurface* FindSurface(G4String surfName) { return GetOpticalSurface(surfName); }
    
    G4GenericMessenger* fMessenger;
    std::vector<G4VisAttributes*> fVisAttributes;
        
    G4NistManager* fNistMan;
    G4VisAttributes* fVisAttrOrange;
    G4VisAttributes* fVisAttrBlue;
    G4VisAttributes* fVisAttrTransparent;
    G4VisAttributes* fVisAttrGreen;
    
    G4Material* mAl;
    G4Material* mCu;
    G4Material* mSi;
    G4Material* mVacuum;
    G4Material* mAir;
    G4Material* mAr;
    G4OpticalSurface* SiPMSurf;
    G4OpticalSurface* FilterSurf;
    G4OpticalSurface* AluminumSurf;
    G4OpticalSurface* AirSurf;
    
    G4Material* CsI;
    G4Material* BGO;
    G4Material* PWO;
    G4Material* LSO;
    G4Material* LYSO;
    G4Material* FluoPoly;
    G4Material* Glass;
    G4Material* PS;
    G4Material* PMMA;
    G4Material* Gelatin;
    
    G4double fTowerH;
    G4double fSiPMH;
    G4double fTowerX;
    G4double fFoilX;
    G4double fAirX;
    G4double fSiPMX;
    G4double fFilterT;
    G4int fTotalN;
    G4int fTowerN;
    G4double fTotalX;
    
    std::vector<SiPMSD*> fSiPMSD;
    G4LogicalVolume* Waferlogical;
    G4LogicalVolume* WaferlogicalFront;

    const fiberSpec* fFiberSpec;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
class fiberSpec {
public:
  fiberSpec(G4double rMin_cladC, G4double rMin_cladS, G4double rMax, G4double towerH,
    G4Material* matPS, G4Material* matPMMA, G4Material* matFluoPoly, G4VisAttributes* visAttrOrange, G4VisAttributes* visAttrBlue);
  virtual ~fiberSpec();

  G4double rMin_cladC;
  G4double rMin_cladS;
  G4double rMax;
  G4double towerH;

  G4Material* matPS;
  G4Material* matPMMA;
  G4Material* matFluoPoly;

  G4VisAttributes* visAttrOrange;
  G4VisAttributes* visAttrBlue;
};

#endif
