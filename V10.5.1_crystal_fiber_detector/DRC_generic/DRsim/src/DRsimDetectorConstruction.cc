#include "DRsimDetectorConstruction.hh"
#include "DRsimCellParameterisation.hh"
#include "DRsimFilterParameterisation.hh"
#include "DRsimMirrorParameterisation.hh"
#include "DRsimSiPMSD.hh"

#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"

#include "G4IntersectionSolid.hh"
#include "G4SDManager.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4GeometryManager.hh"

#include "G4Colour.hh"
#include "G4SystemOfUnits.hh"

#include "Randomize.hh"

using namespace std;

G4ThreadLocal DRsimMagneticField* DRsimDetectorConstruction::fMagneticField = 0;
G4ThreadLocal G4FieldManager* DRsimDetectorConstruction::fFieldMgr = 0;

int DRsimDetectorConstruction::fNofRow = 2;
int DRsimDetectorConstruction::fNofColumn = 1;
int DRsimDetectorConstruction::fNofModules = fNofRow * fNofColumn;

DRsimDetectorConstruction::DRsimDetectorConstruction()
: G4VUserDetectorConstruction(), fMessenger(0), fMaterials(NULL) {
  DefineCommands();
  DefineMaterials();
  
  // crystal spec
  cry_fTowerH = 12*cm;
  cry_fSiPMH = 0.3*mm;
  cry_fTowerX = 20.*mm;
  cry_fAirX= 0.01*mm;
  cry_fSiPMX = 20.*mm;
  cry_fFilterT = 0.01*mm;
  cry_fTotalN=1;
  cry_fTowerN =1;
  cry_fTotalX= cry_fTowerN*20.02*mm;

  clad_C_rMin = 0.49*mm;
  clad_C_rMax = 0.50*mm;
  clad_C_Dz   = 2.5*m;
  clad_C_Sphi = 0.;
  clad_C_Dphi = 2.*M_PI;

  core_C_rMin = 0.*mm;
  core_C_rMax = 0.49*mm;
  core_C_Dz   = 2.5*m;
  core_C_Sphi = 0.;
  core_C_Dphi = 2.*M_PI;

  clad_S_rMin = 0.485*mm;
  clad_S_rMax = 0.50*mm;
  clad_S_Dz   = 2.5*m;
  clad_S_Sphi = 0.;
  clad_S_Dphi = 2.*M_PI;

  core_S_rMin = 0.*mm;
  core_S_rMax = 0.485*mm;
  core_S_Dz   = 2.5*m;
  core_S_Sphi = 0.;
  core_S_Dphi = 2.*M_PI;

  PMTT = 0.3*mm;
  filterT = 0.01*mm;
  reflectorT = 0.03*mm;

  fVisAttrOrange = new G4VisAttributes(G4Colour(1.0,0.5,0.,1.0));
  fVisAttrOrange->SetVisibility(true);
  fVisAttrBlue = new G4VisAttributes(G4Colour(0.,0.,1.0,1.0));
  fVisAttrBlue->SetVisibility(true);
  fVisAttrGray = new G4VisAttributes(G4Colour(0.3,0.3,0.3,0.3));
  fVisAttrGray->SetVisibility(true);
  fVisAttrGreen = new G4VisAttributes(G4Colour(0.3,0.7,0.3));
  fVisAttrGreen->SetVisibility(true);
}

DRsimDetectorConstruction::~DRsimDetectorConstruction() {
  delete fMessenger;
  delete fMaterials;

  delete fVisAttrOrange;
  delete fVisAttrBlue;
  delete fVisAttrGray;
  delete fVisAttrGreen;
}

void DRsimDetectorConstruction::DefineMaterials() {
  fMaterials = DRsimMaterials::GetInstance();
}

G4VPhysicalVolume* DRsimDetectorConstruction::Construct() {
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();

  checkOverlaps = false;

  G4VSolid* worldSolid             = new G4Box("worldBox",10.*m,10.*m,10.*m);
  worldLogical                     = new G4LogicalVolume(worldSolid,FindMaterial("G4_Galactic"),"worldLogical");
  G4VPhysicalVolume* worldPhysical = new G4PVPlacement(0,G4ThreeVector(),worldLogical,"worldPhysical",0,false,0,checkOverlaps);

  fFrontL     = 0.;
  fTowerDepth = 120.; 
  fModuleH    = 20.;
  fModuleW    = 1.;
  fFiberUnitH = 1.;


  // fRandomSeed = 1;
  doFiber     = true;
  doReflector = false;
  doPMT       = true;

  fiberUnit   = new G4Box("fiber_SQ", (fFiberUnitH/2) *mm, (1./2) *mm, (fTowerDepth/2) *mm);
  
  // G4Tubs에서 -> G4Box로 바꿔서 cylinder type에서 square type으로 변경
  fiberClad   = new G4Box("fiber",   clad_C_rMax *mm, clad_C_rMax *mm, fTowerDepth/2. * mm);   // S is the same
  fiberCoreC  = new G4Box("fiberC",  core_C_rMax *mm, core_C_rMax *mm, fTowerDepth/2. * mm);
  fiberCoreS  = new G4Box("fiberS",  core_S_rMax *mm, core_S_rMax *mm, fTowerDepth/2. * mm);

  dimCalc = new dimensionCalc();
  dimCalc->SetFrontL(fFrontL);
  dimCalc->SetTower_height(fTowerDepth);
  dimCalc->SetPMTT(PMTT+filterT);
  dimCalc->SetReflectorT(reflectorT);
  dimCalc->SetNofModules(fNofModules);
  dimCalc->SetNofRow(fNofRow);

  ModuleBuild(ModuleLogical,PMTGLogical,PMTfilterLogical,PMTcellLogical,PMTcathLogical,ReflectorMirrorLogical,fiberUnitIntersection,fiberCladIntersection,fiberCoreIntersection,fModuleProp);

  delete dimCalc;
  return worldPhysical;
}

void DRsimDetectorConstruction::ConstructSDandField() {
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  G4String SiPMName = "SiPMSD";
  DRsimInterface::DRsimModuleProperty ModulePropCrystal;
  ModulePropCrystal.towerXY   = std::make_pair(cry_fTowerN,cry_fTowerN);
  ModulePropCrystal.ModuleNum = 1;
  
  DRsimSiPMSD* cry_sipmSD = new DRsimSiPMSD(SiPMName+"BCry",SiPMName+"BCCry",ModulePropCrystal);
  SDman->AddNewDetector(cry_sipmSD);
  cry_sipmSD->IsCrystalFunction();
  cry_fWaferlogical->SetSensitiveDetector(cry_sipmSD);


  //DRsimSiPMSD* cry_sipmSDFront = new DRsimSiPMSD(SiPMName+"FCry",SiPMName+"FCCry",ModulePropCrystal);
  //cry_sipmSDFront->IsFrontFunction();
  //cry_sipmSDFront->IsCrystalFunction();
  //SDman->AddNewDetector(cry_sipmSDFront);
  //cry_fWaferlogicalFront->SetSensitiveDetector(cry_sipmSDFront);
  // ! Not a memory leak - SDs are deleted by G4SDManager. Deleting them manually will cause double delete!
  if ( doPMT ) {
    for (int i = 0; i < fNofModules; i++) {
      DRsimSiPMSD* SiPMSDmodule = new DRsimSiPMSD("Module"+std::to_string(i), "ModuleC"+std::to_string(i), fModuleProp.at(i));
      SDman->AddNewDetector(SiPMSDmodule);
      PMTcathLogical[i]->SetSensitiveDetector(SiPMSDmodule);
    }
  }
}

void DRsimDetectorConstruction::ModuleBuild(G4LogicalVolume* ModuleLogical_[], 
                                            G4LogicalVolume* PMTGLogical_[], G4LogicalVolume* PMTfilterLogical_[], G4LogicalVolume* PMTcellLogical_[], G4LogicalVolume* PMTcathLogical_[], 
                                            G4LogicalVolume* ReflectorMirrorLogical_[],
                                            std::vector<G4LogicalVolume*> fiberUnitIntersection_[], std::vector<G4LogicalVolume*> fiberCladIntersection_[], std::vector<G4LogicalVolume*> fiberCoreIntersection_[], 
                                            std::vector<DRsimInterface::DRsimModuleProperty>& ModuleProp_) {
  //G4RotationMatrix* towerRot = new G4RotationMatrix(90.*deg,90.*deg,0.);
  G4ThreeVector *towerPosition = new G4ThreeVector(0.*m,0.,0.5*m);
  G4RotationMatrix* cry_towerRot= new G4RotationMatrix(0.*deg,-90.*deg,-90.*deg);  

  //G4VSolid* cry_towerEnvSolid = new G4Box("crystaltowerEnvSolid",cry_fAirX+cry_fTowerX/2.,cry_fAirX+cry_fTowerX/2.,cry_fSiPMH/2.+cry_fTowerH/2.);
  G4VSolid* cry_towerEnvSolid = new G4Box("crystaltowerEnvSolid",cry_fAirX+cry_fTowerX/2.,cry_fAirX+cry_fTowerX/2.,cry_fSiPMH+cry_fTowerH/2.);
  // cry_fAirX = 0.01 mm,  cry_fTowerX = 20.*mm, cry_fSiPMH = 0.3*mm;, cry_fTowerH = 12*cm;
  // 20.01 mm, 20.01 mm, 60.3 mm
  G4LogicalVolume* cry_towerEnvLogical = new G4LogicalVolume(cry_towerEnvSolid,FindMaterial("G4_AIR"),"crystaltowerEnvLogical");
  new G4PVPlacement(cry_towerRot,dimCalc->GetOrigin(0)+G4ThreeVector(0.*m,0.0718*m,0*m),cry_towerEnvLogical,"crystaltowerEnvPhysical",worldLogical,false,0,checkOverlaps);
  //new G4PVPlacement(cry_towerRot,dimCalc->GetOrigin(0)+G4ThreeVector(0.*m,0.06165*m,0*m),cry_towerEnvLogical,"crystaltowerEnvPhysical",worldLogical,false,0,checkOverlaps);

  G4VSolid* cry_towerSolid = new G4Box("crystaltowerSolid",cry_fTowerX/2.,cry_fTowerX/2.,cry_fTowerH/2.);
  G4LogicalVolume* cry_towerLogical = new G4LogicalVolume(cry_towerSolid,FindMaterial("BGO"),"crystaltowerLogical");
  G4VPhysicalVolume* cry_towerPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),cry_towerLogical,"crystaltowerPhysical",cry_towerEnvLogical,false,0); // new G4PVPlacement(theta, position, LogicalVolume, "PhysicalBoxName", motherLogicalVolume, false, 0);
  //G4VPhysicalVolume* cry_towerPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,-cry_fSiPMH/2.),cry_towerLogical,"crystaltowerPhysical",cry_towerEnvLogical,false,0);

  cry_towerLogical->SetVisAttributes(fVisAttrBlue);

  // install SiPM
  G4VSolid* cry_sipmEnvSolid = new G4Box("crystalsipmEnvSolid",cry_fSiPMX/2.,cry_fSiPMX/2.,cry_fSiPMH/2.);
  G4LogicalVolume* cry_sipmEnvLogical = new G4LogicalVolume(cry_sipmEnvSolid,FindMaterial("G4_Galactic"),"crystalsipmEnvLogical");

  G4VSolid* cry_waferSolid = new G4Box("crystalwaferSolid",cry_fSiPMX/2.,cry_fSiPMX/2.,cry_fFilterT/2.);
  cry_fWaferlogical = new G4LogicalVolume(cry_waferSolid,FindMaterial("Silicon"),"crystalwaferLogical");
  G4VPhysicalVolume* cry_waferPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,(cry_fSiPMH-cry_fFilterT)/2.),cry_fWaferlogical,"crystalwaferPhysical",cry_sipmEnvLogical,false,0);
  G4LogicalSkinSurface* cry_waferSurface = new G4LogicalSkinSurface("crystalSiPMSurf",cry_fWaferlogical,FindSurface("SiPMSurf"));

  cry_fWaferlogical->SetVisAttributes(fVisAttrGreen);

  G4VSolid* cry_windowSolid = new G4Box("crystalwindowSolid",cry_fSiPMX/2.,cry_fSiPMX/2.,(cry_fSiPMH-cry_fFilterT)/2.);
  G4LogicalVolume* cry_windowLogical = new G4LogicalVolume(cry_windowSolid,FindMaterial("Glass"),"crystalwindowLogical");
  G4VPhysicalVolume* cry_windowPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,-cry_fFilterT/2.),cry_windowLogical,"crystalwindowPhysical",cry_sipmEnvLogical,false,0);

  G4VPhysicalVolume* cry_sipmEnvPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,(cry_fTowerH+cry_fSiPMH)/2.),cry_sipmEnvLogical,"crystalsipmEnvPhysical",cry_towerEnvLogical,false,0);
  //G4VPhysicalVolume* cry_sipmEnvPhysical = new G4PVPlacement(0,G4ThreeVector(0.,0.,(cry_fTowerH)/2.),cry_sipmEnvLogical,"crystalsipmEnvPhysical",cry_towerEnvLogical,false,0);

  //G4VSolid* cry_sipmEnvSolidFront = new G4Box("crystalsipmEnvSolidFront",cry_fSiPMX/2.,cry_fSiPMX/2.,cry_fSiPMH/2.);
  //G4LogicalVolume* cry_sipmEnvLogicalFront = new G4LogicalVolume(cry_sipmEnvSolidFront,FindMaterial("G4_Galactic"),"crystalsipmEnvLogicalFront");

  //G4VSolid* cry_waferSolidFront = new G4Box("crystalwaferSolidFront",cry_fSiPMX/2.,cry_fSiPMX/2.,cry_fFilterT/2.);
  //cry_fWaferlogicalFront = new G4LogicalVolume(cry_waferSolidFront,FindMaterial("Silicon"),"crystalwaferLogicalFront");
  //G4VPhysicalVolume* cry_waferPhysicalFront = new G4PVPlacement(0,G4ThreeVector(0.,0.,-(cry_fSiPMH-cry_fFilterT)/2.),cry_fWaferlogicalFront,"crystalwaferPhysicalFront",cry_sipmEnvLogicalFront,false,0);
  //G4LogicalSkinSurface* cry_waferSurfaceFront = new G4LogicalSkinSurface("crystalSiPMSurf",cry_fWaferlogicalFront,FindSurface("SiPMSurf"));

  //cry_fWaferlogicalFront->SetVisAttributes(fVisAttrGreen);

  //G4VSolid* cry_windowSolidFront = new G4Box("crystalwindowSolidFront",cry_fSiPMX/2.,cry_fSiPMX/2.,(cry_fSiPMH-cry_fFilterT)/2.);
  //G4LogicalVolume* cry_windowLogicalFront = new G4LogicalVolume(cry_windowSolidFront,FindMaterial("Glass"),"crystalwindowLogicalFront");
  //G4VPhysicalVolume* cry_windowPhysicalFront = new G4PVPlacement(0,G4ThreeVector(0.,0.,cry_fFilterT/2.),cry_windowLogicalFront,"crystalwindowPhysicalFront",cry_sipmEnvLogicalFront,false,0);  

  //G4VPhysicalVolume* cry_sipmEnvPhysicalFront = new G4PVPlacement(0,G4ThreeVector(0.,0.,-(cry_fTowerH+cry_fSiPMH)/2.),cry_sipmEnvLogicalFront,"crystalsipmEnvPhysicalFront",cry_towerEnvLogical,false,0);
  
  G4RotationMatrix* towerRot= new G4RotationMatrix(90.*deg,90.*deg,90.*deg);  
  G4RotationMatrix* fiberRot= new G4RotationMatrix(90.*deg,90.*deg,90.*deg);  

  for (int i = 0; i < fNofModules; i++) {    
    moduleName = setModuleName(i);
    //G4cout<<"#############################"<<G4endl; 
    //G4cout<<dimCalc->GetOrigin(i).getY()<<G4endl; 
    //G4cout<<"#############################"<<G4endl; 
    dimCalc->SetisModule(true);
    module = new G4Box("Mudule", (fModuleH/2.) *mm, (fModuleW/2.) *mm, (fTowerDepth/2.) *mm );

    ModuleLogical_[i] = new G4LogicalVolume(module,FindMaterial("G4_Galactic"),moduleName);
    // G4VPhysicalVolume* modulePhysical = new G4PVPlacement(0,dimCalc->GetOrigin(i),ModuleLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);
    //new G4PVPlacement(0,dimCalc->GetOrigin(i),ModuleLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);
    //new G4PVPlacement(0,*towerPosition,ModuleLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);
    if(i%2==1) new G4PVPlacement(0,dimCalc->GetOrigin(i),ModuleLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);

    if(i%2==0 )new G4PVPlacement(fiberRot,dimCalc->GetOrigin(i),ModuleLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);

    if ( doPMT ) {
      dimCalc->SetisModule(false);  
      pmtg = new G4Box("PMTG", (fModuleH/2.) *mm, (fModuleW/2.) *mm, (PMTT+filterT)/2. *mm );
      PMTGLogical_[i]  = new G4LogicalVolume(pmtg,FindMaterial("G4_AIR"),moduleName);
      //new G4PVPlacement(0,dimCalc->GetOrigin_PMTG(i),PMTGLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);
      if(i%2==1)new G4PVPlacement(0,dimCalc->GetOrigin_PMTG(i),PMTGLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);
      if(i%2==0)new G4PVPlacement(towerRot,dimCalc->GetOrigin_PMTG_even(i),PMTGLogical_[i],moduleName,worldLogical,false,0,checkOverlaps);
    }

    FiberImplement(i,ModuleLogical_,fiberUnitIntersection_,fiberCladIntersection_,fiberCoreIntersection_);

    DRsimInterface::DRsimModuleProperty ModulePropSingle;
    ModulePropSingle.towerXY   = fTowerXY;
    ModulePropSingle.ModuleNum = i;
    ModuleProp_.push_back(ModulePropSingle);

    if ( doPMT ) {
      G4VSolid* SiPMlayerSolid = new G4Box("SiPMlayerSolid", (fModuleH/2.) *mm, (fModuleW/2.) *mm, (PMTT/2.) *mm );
      G4LogicalVolume* SiPMlayerLogical = new G4LogicalVolume(SiPMlayerSolid,FindMaterial("G4_AIR"),"SiPMlayerLogical");
      new G4PVPlacement(0,G4ThreeVector(0.,0.,filterT/2.),SiPMlayerLogical,"SiPMlayerPhysical",PMTGLogical_[i],false,0,checkOverlaps);

      G4VSolid* filterlayerSolid = new G4Box("filterlayerSolid", (fModuleH/2.) *mm, (fModuleW/2.) *mm, (filterT/2.) *mm );
      G4LogicalVolume* filterlayerLogical = new G4LogicalVolume(filterlayerSolid,FindMaterial("Glass"),"filterlayerLogical");
      new G4PVPlacement(0,G4ThreeVector(0.,0.,-PMTT/2.),filterlayerLogical,"filterlayerPhysical",PMTGLogical_[i],false,0,checkOverlaps);

      G4VSolid* PMTcellSolid = new G4Box("PMTcellSolid", 1./2. *mm, 1./2. *mm, PMTT/2. *mm );
      PMTcellLogical_[i] = new G4LogicalVolume(PMTcellSolid,FindMaterial("Glass"),"PMTcellLogical_");

      DRsimCellParameterisation* PMTcellParam = new DRsimCellParameterisation(fTowerXY.first,fTowerXY.second);
      G4PVParameterised* PMTcellPhysical = new G4PVParameterised("PMTcellPhysical",PMTcellLogical_[i],SiPMlayerLogical,kXAxis,fTowerXY.first*fTowerXY.second,PMTcellParam);

      G4VSolid* PMTcathSolid = new G4Box("PMTcathSolid", 1./2. *mm, 1./2. *mm, filterT/2. *mm );
      PMTcathLogical_[i] = new G4LogicalVolume(PMTcathSolid,FindMaterial("Silicon"),"PMTcathLogical_");
      new G4PVPlacement(0,G4ThreeVector(0.,0.,(PMTT-filterT)/2.*mm),PMTcathLogical_[i],"PMTcathPhysical",PMTcellLogical_[i],false,0,checkOverlaps);
      new G4LogicalSkinSurface("Photocath_surf",PMTcathLogical_[i],FindSurface("SiPMSurf"));

      G4VSolid* filterSolid = new G4Box("filterSolid", 1./2. *mm, 1./2. *mm, filterT/2. *mm );
      PMTfilterLogical_[i] = new G4LogicalVolume(filterSolid,FindMaterial("Gelatin"),"PMTfilterLogical_");

      DRsimFilterParameterisation* filterParam = new DRsimFilterParameterisation(fTowerXY.first,fTowerXY.second);
      G4PVParameterised* filterPhysical = new G4PVParameterised("filterPhysical",PMTfilterLogical_[i],filterlayerLogical,kXAxis,fTowerXY.first*fTowerXY.second,filterParam);
      new G4LogicalBorderSurface("filterSurf",filterPhysical,PMTcellPhysical,FindSurface("FilterSurf"));
          
      PMTcathLogical_[i]->SetVisAttributes(fVisAttrGreen);
      PMTfilterLogical_[i]->SetVisAttributes(fVisAttrOrange);
    }

    if ( doReflector ) {
      G4VSolid* ReflectorlayerSolid = new G4Box("ReflectorlayerSolid", (fModuleH/2.) *mm, (fModuleW/2.) *mm, (reflectorT/2.) *mm );
      G4LogicalVolume* ReflectorlayerLogical = new G4LogicalVolume(ReflectorlayerSolid,FindMaterial("G4_Galactic"),"ReflectorlayerLogical");
      new G4PVPlacement(0,dimCalc->GetOrigin_Reflector(i),ReflectorlayerLogical,"ReflectorlayerPhysical",worldLogical,false,0,checkOverlaps);

      G4VSolid* mirrorSolid = new G4Box("mirrorSolid", 1./2. *mm, 1./2. *mm, reflectorT/2. *mm );
      ReflectorMirrorLogical_[i] = new G4LogicalVolume(mirrorSolid,FindMaterial("Aluminum"),"ReflectorMirrorLogical_");

      DRsimMirrorParameterisation* mirrorParam = new DRsimMirrorParameterisation(fTowerXY.first,fTowerXY.second);
      G4PVParameterised* mirrorPhysical = new G4PVParameterised("mirrorPhysical",ReflectorMirrorLogical_[i],ReflectorlayerLogical,kXAxis,fTowerXY.first*fTowerXY.second/2,mirrorParam);
      // new G4LogicalBorderSurface("MirrorSurf",mirrorPhysical,modulePhysical,FindSurface("MirrorSurf"));
      new G4LogicalSkinSurface("MirrorSurf",ReflectorMirrorLogical_[i],FindSurface("MirrorSurf"));

      ReflectorMirrorLogical_[i]->SetVisAttributes(fVisAttrGray);
    }
  }
}

void DRsimDetectorConstruction::DefineCommands() {}

void DRsimDetectorConstruction::FiberImplement(G4int i, G4LogicalVolume* ModuleLogical__[], 
                                              std::vector<G4LogicalVolume*> fiberUnitIntersection__[], std::vector<G4LogicalVolume*> fiberCladIntersection__[], 
                                              std::vector<G4LogicalVolume*> fiberCoreIntersection__[]) {

  fFiberX.clear();
  fFiberY.clear();
  fFiberWhich.clear();

  int NofFiber = 1;   
  int NofPlate = 20;   
  double randDeviation = 0.; //  double randDeviation = fFiberUnitH - 1.;
  fTowerXY = std::make_pair(NofPlate,NofFiber);
  
  G4bool fWhich = true;  
  for (int k = 0; k < NofPlate; k++) {
    for (int j = 0; j < NofFiber; j++) { 
      /*
        ? fX : # of plate , fY : # of fiber in the plate
      */
      G4float fX = -20.*mm/2 + k*1.*mm + 0.5*mm;
      G4float fY = -1.*mm/2 + j*1.*mm + 0.5*mm;
      fWhich = true;
      fFiberX.push_back(fX);
      fFiberY.push_back(fY);
      fFiberWhich.push_back(fWhich);
    }
    // if ( NofFiber%2==0 ) { fWhich = !fWhich; }   
  }
  
  if ( doFiber ) {
    for (unsigned int j = 0; j<fFiberX.size(); j++) {

      if ( !fFiberWhich.at(j) ) { //c fibre

        tfiberCladIntersection = new G4IntersectionSolid("fiberClad",fiberClad,module,0,G4ThreeVector(-fFiberX.at(j),-fFiberY.at(j),0.));
        fiberCladIntersection__[i].push_back(new G4LogicalVolume(tfiberCladIntersection,FindMaterial("FluorinatedPolymer"),name));
        new G4PVPlacement(0,G4ThreeVector(fFiberX.at(j),fFiberY.at(j),0),fiberCladIntersection__[i].at(j),name,ModuleLogical__[i],false,j,checkOverlaps);

        tfiberCoreIntersection = new G4IntersectionSolid("fiberCore",fiberCoreC,module,0,G4ThreeVector(-fFiberX.at(j),-fFiberY.at(j),0.));
        fiberCoreIntersection__[i].push_back(new G4LogicalVolume(tfiberCoreIntersection,FindMaterial("PMMA"),name));
        new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),fiberCoreIntersection__[i].at(j),name,fiberCladIntersection__[i].at(j),false,j,checkOverlaps);

        fiberCladIntersection__[i].at(j)->SetVisAttributes(fVisAttrGray);
        fiberCoreIntersection__[i].at(j)->SetVisAttributes(fVisAttrBlue);
      } else { // s fibre

        tfiberCladIntersection = new G4IntersectionSolid("fiberClad",fiberClad,module,0,G4ThreeVector(-fFiberX.at(j),-fFiberY.at(j),0.));
        fiberCladIntersection__[i].push_back(new G4LogicalVolume(tfiberCladIntersection,FindMaterial("PMMA"),name));
        new G4PVPlacement(0,G4ThreeVector(fFiberX.at(j),fFiberY.at(j),0),fiberCladIntersection__[i].at(j),name,ModuleLogical__[i],false,j,checkOverlaps);

        tfiberCoreIntersection = new G4IntersectionSolid("fiberCore",fiberCoreS,module,0,G4ThreeVector(-fFiberX.at(j),-fFiberY.at(j),0.));
        fiberCoreIntersection__[i].push_back(new G4LogicalVolume(tfiberCoreIntersection,FindMaterial("Polystyrene"),name));
        new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),fiberCoreIntersection__[i].at(j),name,fiberCladIntersection__[i].at(j),false,j,checkOverlaps);

        fiberCladIntersection__[i].at(j)->SetVisAttributes(fVisAttrGray);
        fiberCoreIntersection__[i].at(j)->SetVisAttributes(fVisAttrOrange);
      }
    }
  }
}

