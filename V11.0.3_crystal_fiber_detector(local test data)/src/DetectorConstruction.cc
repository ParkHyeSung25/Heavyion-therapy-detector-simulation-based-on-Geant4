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
// $Id: DetectorConstruction.cc 77656 2013-11-27 08:52:57Z gcosmo $
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class

#include "DetectorConstruction.hh"
#include "FiberParam.hh"

#include "G4SDManager.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4MaterialTable.hh"
#include "G4NistManager.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"

#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4PVReplica.hh"
#include "G4UserLimits.hh"

#include "G4RunManager.hh"
#include "G4GenericMessenger.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4LogicalSkinSurface.hh"

#include "G4ios.hh"
#include "G4SystemOfUnits.hh"

#include <stdio.h>
#include <algorithm>
#include <cmath>


// Geant4 10 to 11
//  FASTTIMECONSTANT -> SCINTILLATIONTIMECONSTANT1
//  SLOWTIMECONSTANT -> SCINTILLATIONTIMECONSTANT2
//  FASTCOMPONENT -> SCINTILLATIONCOMPONENT1
//  SLOWCOMPONENT -> SCINTILLATIONCOMPONENT2
//  YIELDRATIO -> SCINTILLATIONYIELD1
// Geant4 10 to 11

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(), 
  fMessenger(0),
  fVisAttributes()
{
    fNistMan = G4NistManager::Instance(); //  Nist에 담겨 있는 물질정보 데이터 베이스를 가져온다.
    CreateMaterials();
    fVisAttrOrange = new G4VisAttributes(G4Colour(1.0,0.5,0.,1.0));
    fVisAttrOrange->SetVisibility(true);
    fVisAttrBlue = new G4VisAttributes(G4Colour(0.,0.,1.0,1.0));
    fVisAttrBlue->SetVisibility(true);
    fVisAttrTransparent = new G4VisAttributes();
    fVisAttrTransparent->SetVisibility(false);
    fVisAttrGreen = new G4VisAttributes(G4Colour(0.3,0.7,0.3));
    fVisAttrGreen->SetVisibility(true);

    fFiberSpec = new fiberSpec(
      0.49*mm,  // rMin_cladC
      0.485*mm, // rMin_cladS
      0.5*mm,   // rMax
      12.*cm,     // towerH
      FindMaterial("Polystyrene"),
      FindMaterial("PMMA"),
      FindMaterial("FluorinatedPolymer"),
      fVisAttrOrange,
      fVisAttrBlue
    );
    fTowerH = 12*cm;
    fSiPMH = 0.3*mm;
    fTowerX = 20.*mm;
    fFoilX = 0.016*mm;
    fAirX= 0.01*mm;
    fSiPMX = 20.*mm;
    fFilterT = 0.01*mm;
    fTotalN=1;
    fTowerN =2;
    fTotalX= fTowerN*20.052*mm;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
    delete fMessenger;
    if (fFiberSpec) delete fFiberSpec;
    if (Waferlogical) delete Waferlogical;
    for (G4int i=0; i<G4int(fVisAttributes.size()); ++i) 
    {
      delete fVisAttributes[i];
    }  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* DetectorConstruction::GetMaterial(const G4String matName) {
    G4Material* mat = fNistMan->FindOrBuildMaterial(matName); // 위 Nist로 가져온 데이터베이스 중 matName 에 해당하는 물질정보를 가져와 mat에 저장

    if (!mat) mat = G4Material::GetMaterial(matName);
    if (!mat) {
        std::ostringstream o;
        o << "Material " << matName << " not found!";
        G4Exception("Materials::GetMaterial","",FatalException,o.str().c_str());
    }
    return mat;
}
// surface
G4OpticalSurface* DetectorConstruction::GetOpticalSurface(const G4String surfName) {
  if (surfName=="SiPMSurf") return SiPMSurf;
  else if (surfName=="FilterSurf") return FilterSurf;
  else if (surfName=="AluminumSurf") return AluminumSurf;
  else if (surfName=="AirSurf") return AirSurf;
  else {
    std::ostringstream o;
    o << "OpticalSurface " << surfName << " not found!";
    G4Exception("CBDsimMaterials::GetOpticalSurface","",FatalException,o.str().c_str());
  }

  return nullptr;
}


void DetectorConstruction::CreateMaterials() {
    fNistMan->FindOrBuildMaterial("G4_Galactic"); // 성간물질 : 이론상 진공에 가장 가까운 물질
    fNistMan->FindOrBuildMaterial("G4_AIR");
    fNistMan->FindOrBuildMaterial("G4_Ar");
    fNistMan->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");

    G4Element* H  = new G4Element("Hydrogen", "H", 1, 1.01*g/mole);
    G4Element* C  = new G4Element("Carbon", "C", 6, 12.01*g/mole);
    G4Element* N  = new G4Element("Nitrogen", "N", 7, 14.01*g/mole);
    G4Element* O  = new G4Element("Oxygen", "O", 8, 16.00*g/mole);
    G4Element* F  = new G4Element("Fluorine", "F", 9, 18.9984*g/mole);
    G4Element* Si = new G4Element("Silicon", "Si", 14, 28.085*g/mole);
    G4Element* Y  = new G4Element("Yttrium", "Y", 39, 88.905*g/mole);
    G4Element* Ce = new G4Element("Cerium", "Ce", 58, 140.116*g/mole);
    G4Element* Lu = new G4Element("Lutetium", "Lu", 71, 174.9668*g/mole);
    G4Element* W  = new G4Element("Tungsten", "W", 74, 183.8400*g/mole);
    G4Element* Pb = new G4Element("Lead", "Pb", 82, 207.2*g/mole);
    G4Element* Al = new G4Element("Aluminum", "Al", 13, 26.982*g/mole);
    G4Element* Cs = new G4Element("Cesium", "Cs", 55, 132.90545*g/mole);
    G4Element* I  = new G4Element("Iodine", "I", 53, 126.90447*g/mole);
    G4Element* Bi = new G4Element("Bismuth", "Bi", 83, 208.980*g/mole);
    G4Element* Ge = new G4Element("Germanium", "Ge", 32, 72.630*g/mole);


    mAl = new G4Material("Aluminum", 13, 26.982*g/mole, 2.70*g/cm3);
    mCu = new G4Material("Copper", 29, 63.546*g/mole, 8.96*g/cm3);
    mSi = new G4Material("Silicon", 14., 28.09*g/mole, 2.33*g/cm3);

    mVacuum = G4Material::GetMaterial("G4_Galactic");
    mAir = G4Material::GetMaterial("G4_AIR");
    mAr = G4Material::GetMaterial("G4_Ar");
    
    G4Material* CsI = new G4Material("CsI",4.51*g/cm3,2);
    CsI->AddElement(Cs,1);
    CsI->AddElement(I,1);
    CSI->GetIonisation()->SetBirksConstant(0.00129*mm/MeV);

    BGO = new G4Material("BGO", 7.13*g/cm3, 3);
    BGO -> AddElement(Bi, 4);
    BGO -> AddElement(Ge, 3);
    BGO -> AddElement(O, 12);
    BGO->GetIonisation()->SetBirksConstant(0.00107*mm/MeV);
    
    PWO = new G4Material("PWO", 8.28*g/cm3, 3);
    PWO -> AddElement(Pb, 1);
    PWO -> AddElement(W, 1);
    PWO -> AddElement(O, 4);
    
    LSO = new G4Material("LSO", 7.40*g/cm3, 4);
    LSO->AddElement(Lu, 76.25*perCent);
    LSO->AddElement(Ce, 0.2*perCent);
    LSO->AddElement(Si, 6.12*perCent);
    LSO->AddElement(O , 17.43*perCent);

    LYSO = new G4Material("LYSO", 7.25*g/cm3, 5);
    LYSO->AddElement(Lu, 73.856*perCent);
    LYSO->AddElement(Y , 1.975*perCent);
    LYSO->AddElement(Si, 6.240*perCent);
    LYSO->AddElement(O , 17.773*perCent);
    LYSO->AddElement(Ce, 0.156*perCent);
    LYSO->GetIonisation()->SetBirksConstant(0.0076*mm/MeV);
        
    FluoPoly = new G4Material("FluorinatedPolymer", 1.43*g/cm3, 2);
    FluoPoly->AddElement(C, 2);
    FluoPoly->AddElement(F, 2);

    Glass = new G4Material("Glass", 1.032*g/cm3, 2);
    Glass->AddElement(C, 91.533*perCent);
    Glass->AddElement(H, 8.467*perCent);

    PS = new G4Material("Polystyrene", 1.05*g/cm3, 2);
    PS->AddElement(C, 8);
    PS->AddElement(H, 8);

    PMMA = new G4Material("PMMA", 1.19*g/cm3, 3);
    PMMA->AddElement(C, 5);
    PMMA->AddElement(H, 8);
    PMMA->AddElement(O, 2);

    Gelatin = new G4Material("Gelatin", 1.27*g/cm3, 4);
    Gelatin->AddElement(C, 102);
    Gelatin->AddElement(H, 151);
    Gelatin->AddElement(N, 31);
    Gelatin->AddElement(O, 39);
    
    
    ///--- Material property tables for absorber materials ---
    G4MaterialPropertiesTable* mpPWO;
    G4MaterialPropertiesTable* mpLSO;
    G4MaterialPropertiesTable* mpLYSO;
    G4MaterialPropertiesTable* mpCsI;
    G4MaterialPropertiesTable* mpBGO;
    G4MaterialPropertiesTable* mpAir;
    G4MaterialPropertiesTable* mpPS;
    G4MaterialPropertiesTable* mpPMMA;
    G4MaterialPropertiesTable* mpFluoPoly;
    G4MaterialPropertiesTable* mpGlass;
    G4MaterialPropertiesTable* mpSiPM;
    G4MaterialPropertiesTable* mpFilter;
    G4MaterialPropertiesTable* mpFilterSurf;
    G4MaterialPropertiesTable* mpAl;
    G4MaterialPropertiesTable* mpAlSurf;
    G4MaterialPropertiesTable* mpAirSurf;
    
    G4double opEn[] = { // from 900nm to 300nm with 25nm step
      1.37760*eV, 1.41696*eV, 1.45864*eV, 1.50284*eV, 1.54980*eV, 1.59980*eV, 1.65312*eV, 1.71013*eV,
      1.77120*eV, 1.83680*eV, 1.90745*eV, 1.98375*eV, 2.06640*eV, 2.15625*eV, 2.25426*eV, 2.36160*eV,
      2.47968*eV, 2.61019*eV, 2.75520*eV, 2.91728*eV, 3.09960*eV, 3.30625*eV, 3.54241*eV, 3.81490*eV, 4.13281*eV
    };
    
    const G4int nEnt = sizeof(opEn) / sizeof(G4double);
    // http://nuclear.korea.ac.kr/~lamps/geant4/G4MaterialPropertiesIndex_8hh_source.html

    G4double RI_Air[nEnt]; std::fill_n(RI_Air,nEnt,1.0);
    mpAir = new G4MaterialPropertiesTable();
    mpAir->AddProperty("RINDEX",opEn,RI_Air,nEnt);
    mAir->SetMaterialPropertiesTable(mpAir);
    
    mpAirSurf = new G4MaterialPropertiesTable();
    AirSurf = new G4OpticalSurface("AirSurf", glisur, polished, dielectric_dielectric);
    AirSurf->SetMaterialPropertiesTable(mpAirSurf);

    G4double refl_Al[nEnt]={//https://eng.libretexts.org/Bookshelves/Materials_Science/Supplemental_Modules_(Materials_Science)/Optical_Properties/Metallic_Reflection
      0.894, 0.887, 0.880, 0.873, 0.866, 0.876, 0.887, 0.897,
      0.908, 0.910, 0.912, 0.914, 0.916, 0.918, 0.920, 0.921,
      0.923, 0.925, 0.927, 0.928, 0.930, 0.928, 0.925, 0.923, 0.92};
    mpAlSurf = new G4MaterialPropertiesTable();
    mpAlSurf->AddProperty("REFLECTIVITY", opEn, refl_Al, nEnt);
    AluminumSurf = new G4OpticalSurface("AluminumSurf", unified, polished, dielectric_metal);
    AluminumSurf->SetMaterialPropertiesTable(mpAlSurf);
    
    mpAl = new G4MaterialPropertiesTable();
    mAl->SetMaterialPropertiesTable(mpAl);
    
    
    //--- LSO ---
    G4double RI_LSO[nEnt]; std::fill_n(RI_LSO, nEnt, 1.82);
    G4double Abslength_LSO[nEnt]; std::fill_n(Abslength_LSO, nEnt, 1.14*cm);
    G4double scintFast_LSO[nEnt]={
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.03, 0.07, 0.12, 0.16, 0.32,
      0.50, 0.68, 0.92, 0.97, 0.50, 0.07, 0.00, 0.00, 0.00};
    mpLSO = new G4MaterialPropertiesTable();
    mpLSO->AddProperty("RINDEX",opEn,RI_LSO,nEnt);
    mpLSO->AddProperty("ABSLENGTH",opEn,Abslength_LSO,nEnt);
    mpLSO->AddConstProperty("SCINTILLATIONYIELD",30000./MeV);
    mpLSO->AddConstProperty("RESOLUTIONSCALE",1.0);
    mpLSO->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_LSO,nEnt);
    mpLSO->AddConstProperty("SCINTILLATIONTIMECONSTANT1",40*ns);
    LSO->SetMaterialPropertiesTable(mpLSO);
    
    //--- LYSO ---
    G4double RI_LYSO[nEnt]; std::fill_n(RI_LYSO, nEnt, 1.81);
    G4double Abslength_LYSO[nEnt]; std::fill_n(Abslength_LYSO, nEnt, 42*cm);
    G4double scintFast_LYSO[nEnt] = {
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.03, 0.07, 0.12, 0.16, 0.32,
      0.50, 0.68, 0.92, 0.97, 0.50, 0.07, 0.00, 0.00, 0.00
    };
    mpLYSO = new G4MaterialPropertiesTable();
    mpLYSO->AddProperty("RINDEX",opEn,RI_LYSO,nEnt);
    mpLYSO->AddProperty("ABSLENGTH",opEn,Abslength_LYSO,nEnt);
    mpLYSO->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_LYSO,nEnt);
    mpLYSO->AddConstProperty("SCINTILLATIONYIELD",33200./MeV);
    mpLYSO->AddConstProperty("RESOLUTIONSCALE",2.0);
    mpLYSO->AddConstProperty("SCINTILLATIONTIMECONSTANT1",36*ns);
    LYSO->SetMaterialPropertiesTable(mpLYSO);
    
    //--- PbWO4 ---
    G4double RI_PWO[nEnt]; std::fill_n(RI_PWO,nEnt,2.16);
    G4double Abslength_PWO[nEnt]; std::fill_n(Abslength_PWO,nEnt,0.92*cm);
    //G4double scintFast_PWO[nEnt]={};
    //G4double scintSlow_PWO[nEnt]={};
    mpPWO = new G4MaterialPropertiesTable();
    mpPWO->AddProperty("RINDEX",opEn,RI_PWO,nEnt);
    mpPWO->AddProperty("ABSLENGTH",opEn,Abslength_PWO,nEnt);
    //mpPWO->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_PWO,nEnt);
    //mpPWO->AddProperty("SCINTILLATIONCOMPONENT2",opEn,scintSlow_PWO,nEnt);
    mpPWO->AddConstProperty("SCINTILLATIONYIELD",400/MeV);
    mpPWO->AddConstProperty("RESOLUTIONSCALE",1.0);
    mpPWO->AddConstProperty("SCINTILLATIONTIMECONSTANT1",6*ns);
    mpPWO->AddConstProperty("SCINTILLATIONTIMECONSTANT2",30*ns);
    PWO->SetMaterialPropertiesTable(mpPWO);
    
    //--- CsI ---
    G4double RI_CsI[nEnt]; std::fill_n(RI_CsI,nEnt,1.95);
    G4double Abslength_CsI[nEnt]; std::fill_n(Abslength_CsI,nEnt,40*cm);
    //G4double scintFast_PWO[nEnt]={};
    //G4double scintSlow_PWO[nEnt]={};
    mpCsI = new G4MaterialPropertiesTable();
    mpCsI->AddProperty("RINDEX",opEn,RI_CsI,nEnt);
    mpCsI->AddProperty("ABSLENGTH",opEn,Abslength_CsI,nEnt);
    //mpPWO->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_PWO,nEnt);
    //mpPWO->AddProperty("SCINTILLATIONCOMPONENT2",opEn,scintSlow_PWO,nEnt);
    /*G4double scintFast_CsI[nEnt] = {
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.00, 0.00, 0.01, 0.03, 0.04,
      0.05, 0.05, 0.04, 0.04, 0.04, 0.07, 0.17, 0.49, 0.59};/
    };
    G4double scintSlow_CsI[nEnt] = {
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.00, 0.00, 0.01, 0.02, 0.03,
      0.03, 0.03, 0.03, 0.02, 0.03, 0.05, 0.11, 0.32, 0.39
    };*/
    G4double scintFast_CsI[nEnt] = {
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.00, 0.00, 0.02, 0.05, 0.07,
      0.08, 0.08, 0.07, 0.06, 0.07, 0.12, 0.28, 0.81, 0.98
    };
    mpCsI->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_CsI,nEnt);
    //mpCSI->AddProperty("SCINTILLATIONCOMPONENT2",opEn,scintSlow_CsI,nEnt);
    mpCsI->AddConstProperty("SCINTILLATIONYIELD",1900/MeV);
    mpCsI->AddConstProperty("RESOLUTIONSCALE",1.0);
    mpCsI->AddConstProperty("SCINTILLATIONTIMECONSTANT1",15.7*ns);
    //mpCsI->AddConstProperty("SCINTILLATIONTIMECONSTANT2",35.8*ns);
    CsI->SetMaterialPropertiesTable(mpCsI);
    
    //--- BGO ---
    G4double RI_BGO[nEnt]; std::fill_n(RI_BGO,nEnt,2.15);
    G4double Abslength_BGO[nEnt]; std::fill_n(Abslength_BGO,nEnt,40*cm);
    //G4double scintFast_PWO[nEnt]={};
    //G4double scintSlow_PWO[nEnt]={};
    G4double scintFast_BGO[nEnt] = {
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.02,
      0.12, 0.47, 0.98, 0.72, 0.08, 0.02, 0.00, 0.00, 0.00
    };
    mpBGO = new G4MaterialPropertiesTable();
    mpBGO->AddProperty("RINDEX",opEn,RI_BGO,nEnt);
    mpBGO->AddProperty("ABSLENGTH",opEn,Abslength_BGO,nEnt);
    mpBGO->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_BGO,nEnt);
    //mpPWO->AddProperty("SCINTILLATIONCOMPONENT2",opEn,scintSlow_PWO,nEnt);
    mpBGO->AddConstProperty("SCINTILLATIONYIELD",8000/MeV);
    mpBGO->AddConstProperty("RESOLUTIONSCALE",1.0);
    mpBGO->AddConstProperty("SCINTILLATIONTIMECONSTANT1",300*ns);
    BGO->SetMaterialPropertiesTable(mpBGO);
    
    G4double RI_PMMA[nEnt] = {
      1.48329, 1.48355, 1.48392, 1.48434, 1.48467, 1.48515, 1.48569, 1.48628,
      1.48677, 1.48749, 1.48831, 1.48899, 1.49000, 1.49119, 1.49219, 1.49372,
      1.49552, 1.49766, 1.49953, 1.50252, 1.50519, 1.51000, 1.51518, 1.52182, 1.53055
    };
    G4double AbsLen_PMMA[nEnt] = {
      0.414*m, 0.543*m, 0.965*m, 2.171*m, 2.171*m, 3.341*m, 4.343*m, 1.448*m,
      4.343*m, 14.48*m, 21.71*m, 8.686*m, 28.95*m, 54.29*m, 43.43*m, 48.25*m,
      54.29*m, 48.25*m, 43.43*m, 28.95*m, 21.71*m, 4.343*m, 2.171*m, 0.869*m, 0.434*m
    };
    mpPMMA = new G4MaterialPropertiesTable();
    mpPMMA->AddProperty("RINDEX",opEn,RI_PMMA,nEnt);
    mpPMMA->AddProperty("ABSLENGTH",opEn,AbsLen_PMMA,nEnt);
    PMMA->SetMaterialPropertiesTable(mpPMMA);

    G4double RI_FluoPoly[nEnt]; std::fill_n(RI_FluoPoly, nEnt, 1.42);
    mpFluoPoly = new G4MaterialPropertiesTable();
    mpFluoPoly->AddProperty("RINDEX",opEn,RI_FluoPoly,nEnt);
    FluoPoly->SetMaterialPropertiesTable(mpFluoPoly);
    
    G4double RI_PS[nEnt] = {
      1.57483, 1.57568, 1.57644, 1.57726, 1.57817, 1.57916, 1.58026, 1.58148,
      1.58284, 1.58435, 1.58605, 1.58796, 1.59013, 1.59328, 1.59621, 1.59960,
      1.60251, 1.60824, 1.61229, 1.62032, 1.62858, 1.63886, 1.65191, 1.66888, 1.69165
    };
    G4double AbsLen_PS[nEnt] = {
      2.714*m, 3.102*m, 3.619*m, 4.343*m, 5.791*m, 7.896*m, 4.343*m, 7.896*m,
      5.429*m, 36.19*m, 17.37*m, 36.19*m, 5.429*m, 28.95*m, 21.71*m, 14.48*m,
      12.41*m, 8.686*m, 7.238*m, 1.200*m, 0.200*m, 0.500*m, 0.200*m, 0.100*m, 0.100*m
    };
    G4double scintFast_PS[nEnt] = {
      0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
      0.00, 0.00, 0.00, 0.00, 0.00, 0.03, 0.07, 0.13,
      0.33, 0.63, 1.00, 0.50, 0.00, 0.00, 0.00, 0.00, 0.00
    };
    mpPS = new G4MaterialPropertiesTable();
    mpPS->AddProperty("RINDEX",opEn,RI_PS,nEnt);
    mpPS->AddProperty("ABSLENGTH",opEn,AbsLen_PS,nEnt);
    mpPS->AddProperty("SCINTILLATIONCOMPONENT1",opEn,scintFast_PS,nEnt);
    mpPS->AddConstProperty("SCINTILLATIONYIELD",10./keV);
    mpPS->AddConstProperty("RESOLUTIONSCALE",1.0);
    mpPS->AddConstProperty("SCINTILLATIONTIMECONSTANT1",2.8*ns);
    PS->SetMaterialPropertiesTable(mpPS);
    PS->GetIonisation()->SetBirksConstant(0.126*mm/MeV);
    
    // G4double RI_Glass[nEnt]; std::fill_n(RI_Glass, nEnt, 1.81);
    G4double RI_Glass[nEnt]; std::fill_n(RI_Glass, nEnt, 1.52);
    G4double Abslength_Glass[nEnt]; std::fill_n(Abslength_Glass, nEnt, 420.*cm);
    mpGlass = new G4MaterialPropertiesTable();
    mpGlass->AddProperty("RINDEX",opEn,RI_Glass,nEnt);
    mpGlass->AddProperty("ABSLENGTH",opEn,Abslength_Glass,nEnt);
    Glass->SetMaterialPropertiesTable(mpGlass);
    
    G4double refl_SiPM[nEnt]; std::fill_n(refl_SiPM, nEnt, 0.);
    G4double eff_SiPM[nEnt] = {
      0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.10,
      0.11, 0.13, 0.15, 0.17, 0.19, 0.20, 0.22, 0.23,
      0.24, 0.25, 0.24, 0.23, 0.21, 0.20, 0.17, 0.14, 0.10
    };
    // G4double eff_SiPM[nEnt]; std::fill_n(eff_SiPM, nEnt, 1.);
    mpSiPM = new G4MaterialPropertiesTable();
    mpSiPM->AddProperty("REFLECTIVITY",opEn,refl_SiPM,nEnt);
    mpSiPM->AddProperty("EFFICIENCY",opEn,eff_SiPM,nEnt);
    SiPMSurf = new G4OpticalSurface("SiPMSurf",glisur,polished,dielectric_metal);
    SiPMSurf->SetMaterialPropertiesTable(mpSiPM);

    G4double filterEff[nEnt] = {
      1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000,
      1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 0.900, 0.734,
      0.568, 0.402, 0.296, 0.070, 0.000, 0.000, 0.000, 0.000, 0.000
    };
    G4double filterRef[nEnt]; std::fill_n(filterRef,nEnt,0.);
    G4double RI_gel[nEnt]; std::fill_n(RI_gel,nEnt,1.52);
    mpFilter = new G4MaterialPropertiesTable();
    mpFilter->AddProperty("RINDEX",opEn,RI_gel,nEnt);
    Gelatin->SetMaterialPropertiesTable(mpFilter);
    
    mpFilterSurf = new G4MaterialPropertiesTable();
    mpFilterSurf->AddProperty("TRANSMITTANCE",opEn,filterEff,nEnt);
    mpFilterSurf->AddProperty("REFLECTIVITY",opEn,filterRef,nEnt);
    FilterSurf = new G4OpticalSurface("FilterSurf",glisur,polished,dielectric_dielectric);
    FilterSurf->SetMaterialPropertiesTable(mpFilterSurf);
    
    G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
    G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // Construct materials
    CreateMaterials();
    G4Material* scintillator
      = G4Material::GetMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    G4bool checkOverlaps = true;

    // geometries --------------------------------------------------------------
    G4VSolid* worldSolid 
      = new G4Box("worldBox",10.*m,10.*m,10.*m);
    G4LogicalVolume* worldLogical
      = new G4LogicalVolume(worldSolid,mVacuum,"worldLogical");
    G4VPhysicalVolume* worldPhysical
      = new G4PVPlacement(0,G4ThreeVector(),worldLogical,"worldPhysical",0,
                          false,0,checkOverlaps);
    worldLogical->SetVisAttributes(fVisAttrTransparent);
    
    G4VSolid* towertotalSolid = new G4Box("towertotalSolid",fTotalX/2.,fTotalX/2.,(fTowerH+fSiPMH*2)/2.);
    G4RotationMatrix* towerRot = new G4RotationMatrix(90.*deg,0.*deg,0.);
    G4LogicalVolume* towertotalLogical = new G4LogicalVolume(towertotalSolid,FindMaterial("G4_AIR"),"towertotalLogical");
    new G4PVPlacement(towerRot,G4ThreeVector(0.5*m,0,0),towertotalLogical,"towertotalPhysical",worldLogical,false,0);

    G4VSolid* detectortotSolid = new G4Box("detectortotSolid",fFoilX+fAirX+fTowerX/2.,fFoilX+fAirX+fTowerX/2.,fSiPMH+fTowerH/2.);
    G4LogicalVolume* detectortotLogical = new G4LogicalVolume(detectortotSolid,FindMaterial("G4_AIR"),"detectortotLogical");
    G4VSolid* detectorSolid = new G4Box("detectorSolid",fTowerX/2.,fTowerX/2.,fTowerH/2.);
    G4LogicalVolume* detectorLogical = new G4LogicalVolume(detectorSolid,FindMaterial("CsI"),"detectorLogical");
    G4VPhysicalVolume* detectorPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),detectorLogical,"detectorPhysical",detectortotLogical,false,0);
    detectorLogical->SetVisAttributes(fVisAttrBlue);
    
    G4VSolid* foilSolid1 = new G4Box("foilSolid1",fFoilX/2.,fTowerX/2.+fAirX+fFoilX/2.,fSiPMH+fTowerH/2.);
    G4LogicalVolume* foilLogical1 = new G4LogicalVolume(foilSolid1,mAl,"foilLogical1");
    G4VPhysicalVolume* foilPhysical1 = new G4PVPlacement(0,G4ThreeVector(fTowerX/2.+fFoilX/2.+fAirX,fFoilX/2.,0.),foilLogical1,"foilPhysical1",detectortotLogical,false,0);
    G4VPhysicalVolume* foilPhysical3 = new G4PVPlacement(0,G4ThreeVector(-(fTowerX/2.+fFoilX/2.+fAirX),-(fFoilX/2.),0.),foilLogical1,"foilPhysical3",detectortotLogical,false,0);
    new G4LogicalSkinSurface("AlSurf1",foilLogical1,FindSurface("AluminumSurf"));
    foilLogical1->SetVisAttributes(fVisAttrOrange);
    
    G4VSolid* foilSolid2 = new G4Box("foilSolid2",fTowerX/2.+fAirX+fFoilX/2.,fFoilX/2.,fSiPMH+fTowerH/2.);
    G4LogicalVolume* foilLogical2 = new G4LogicalVolume(foilSolid2,mAl,"foilLogical2");
    G4VPhysicalVolume* foilPhysical2 = new G4PVPlacement(0,G4ThreeVector(-(fFoilX/2.),fTowerX/2.+fFoilX/2.+fAirX,0.),foilLogical2,"foilPhysical2",detectortotLogical,false,0);
    G4VPhysicalVolume* foilPhysical4 = new G4PVPlacement(0,G4ThreeVector(fFoilX/2.,-(fTowerX/2.+fFoilX/2.+fAirX),0.),foilLogical2,"foilPhysical4",detectortotLogical,false,0);
    new G4LogicalSkinSurface("AlSurf2",foilLogical2,FindSurface("AluminumSurf"));
    foilLogical2->SetVisAttributes(fVisAttrOrange);
    
    G4VSolid* sipmEnvSolid = new G4Box("sipmEnvSolid",fSiPMX/2.,fSiPMX/2.,fSiPMH/2.);
    G4LogicalVolume* sipmEnvLogical = new G4LogicalVolume(sipmEnvSolid,FindMaterial("G4_Galactic"),"sipmEnvLogical");
    G4VSolid* waferSolid = new G4Box("waferSolid",fSiPMX/2.,fSiPMX/2.,fFilterT/2.);
    Waferlogical = new G4LogicalVolume(waferSolid,FindMaterial("Silicon"),"waferLogical");
    G4VPhysicalVolume* waferPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,(fSiPMH-fFilterT)/2.),Waferlogical,"waferPhysical",sipmEnvLogical,false,0);
    G4LogicalSkinSurface* waferSurface = new G4LogicalSkinSurface("SiPMSurf",Waferlogical,FindSurface("SiPMSurf"));
    Waferlogical->SetVisAttributes(fVisAttrGreen);

    G4VSolid* windowSolid = new G4Box("windowSolid",fSiPMX/2.,fSiPMX/2.,(fSiPMH-fFilterT)/2.);
    G4LogicalVolume* windowLogical = new G4LogicalVolume(windowSolid,FindMaterial("Glass"),"windowLogical");
    G4VPhysicalVolume* windowPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,-fFilterT/2.),windowLogical,"windowPhysical",sipmEnvLogical,false,0);
    G4VPhysicalVolume* sipmEnvPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,(fTowerH+fSiPMH)/2.),sipmEnvLogical,"sipmEnvPhysical",detectortotLogical,false,0);

    G4VSolid* sipmEnvSolidFront = new G4Box("sipmEnvSolidFront",fSiPMX/2.,fSiPMX/2.,fSiPMH/2.);
    G4LogicalVolume* sipmEnvLogicalFront = new G4LogicalVolume(sipmEnvSolidFront,FindMaterial("G4_Galactic"),"sipmEnvLogicalFront");
    G4VSolid* waferSolidFront = new G4Box("waferSolidFront",fSiPMX/2.,fSiPMX/2.,fFilterT/2.);
    WaferlogicalFront = new G4LogicalVolume(waferSolidFront,FindMaterial("Silicon"),"waferLogicalFront");
    G4VPhysicalVolume* waferPhysicalFront = new G4PVPlacement(0,G4ThreeVector(0.,0.,-(fSiPMH-fFilterT)/2.),WaferlogicalFront,"waferPhysicalFront",sipmEnvLogicalFront,false,0);
    G4LogicalSkinSurface* waferSurfaceFront = new G4LogicalSkinSurface("SiPMSurf",WaferlogicalFront,FindSurface("SiPMSurf"));
    WaferlogicalFront->SetVisAttributes(fVisAttrGreen);

    G4VSolid* windowSolidFront = new G4Box("windowSolidFront",fSiPMX/2.,fSiPMX/2.,(fSiPMH-fFilterT)/2.);
    G4LogicalVolume* windowLogicalFront = new G4LogicalVolume(windowSolidFront,FindMaterial("Glass"),"windowLogicalFront");
    G4VPhysicalVolume* windowPhysicalFront = new G4PVPlacement(0,G4ThreeVector(0.,0.,fFilterT/2.),windowLogicalFront,"windowPhysicalFront",sipmEnvLogicalFront,false,0);
    G4VPhysicalVolume* sipmEnvPhysicalFront = new G4PVPlacement(0,G4ThreeVector(0.,0.,-(fTowerH+fSiPMH)/2.),sipmEnvLogicalFront,"sipmEnvPhysicalFront",detectortotLogical,false,0);
    
    FiberParam* fiber_Param = new FiberParam(fTowerN,fTowerN,fFiberSpec);
    G4VPVParameterisation* cellParam = new CellParam(fiber_Param);
    G4PVParameterised* towerEnvPhysical = new G4PVParameterised("cell",detectortotLogical,towertotalLogical,kZAxis,fiber_Param->numx*fiber_Param->numy,cellParam);
        
    return worldPhysical;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::ConstructSDandField()
{
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    G4String SiPMname = "SiPMSD";

    SiPMSD* sipmSD = new SiPMSD(SiPMname+"B",SiPMname+"BC",std::make_pair(fTowerN,fTowerN));
    SDman->AddNewDetector(sipmSD);
    Waferlogical->SetSensitiveDetector(sipmSD);

    SiPMSD* sipmSDFront = new SiPMSD(SiPMname+"F",SiPMname+"FC",std::make_pair(fTowerN,fTowerN));
    sipmSDFront->IsFrontFunction();
    SDman->AddNewDetector(sipmSDFront);
    WaferlogicalFront->SetSensitiveDetector(sipmSDFront);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


fiberSpec::fiberSpec(G4double rMin_cladC_, G4double rMin_cladS_, G4double rMax_, G4double towerH_,
  G4Material* matPS_, G4Material* matPMMA_, G4Material* matFluoPoly_, G4VisAttributes* visAttrOrange_, G4VisAttributes* visAttrBlue_) {

  rMin_cladC = rMin_cladC_;
  rMin_cladS = rMin_cladS_;
  rMax = rMax_;
  towerH = towerH_;
  matPS = matPS_;
  matPMMA = matPMMA_;
  matFluoPoly = matFluoPoly_;
  visAttrOrange = visAttrOrange_;
  visAttrBlue = visAttrBlue_;
}

fiberSpec::~fiberSpec() {}
