#ifndef FiberParam_H
#define FiberParam_H 1

#include "G4VPVParameterisation.hh"
#include "DetectorConstruction.hh"
#include <vector>

class G4VPhysicalVolume;

class FiberParam : public G4VPVParameterisation {
public:
  FiberParam(const G4int numx_, const G4int numy_, const fiberSpec* spec);
  virtual ~FiberParam();

  virtual void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume* physVol) const;
  virtual void ComputeDimensions(G4Tubs& fiber, const G4int copyNo, const G4VPhysicalVolume* physVol) const;
  virtual G4Material* ComputeMaterial(const G4int copyNo, G4VPhysicalVolume* physVol) const;

  bool IsCerenkov(G4int col, G4int row) const;

  std::vector<G4double> X;
  std::vector<G4double> Y;
  G4int numx;
  G4int numy;

private:
  const fiberSpec* fFiberSpec;
};

class CellParam : public G4VPVParameterisation {
public:
  CellParam(const FiberParam*);
  virtual ~CellParam();

  virtual void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume* physVol) const;

private:
  const FiberParam* fFiberParam;
};

#endif
