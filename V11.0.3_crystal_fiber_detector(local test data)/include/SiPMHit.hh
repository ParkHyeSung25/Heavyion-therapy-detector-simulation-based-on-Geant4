#ifndef SiPMHit_h
#define SiPMHit_h 1

#include "Interface.h"
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class SiPMHit : public G4VHit {
public:
  SiPMHit(G4int wavBin, G4int timeBin);
  SiPMHit(const SiPMHit& right);
  virtual ~SiPMHit();

  const SiPMHit& operator=(const SiPMHit &right);
  G4bool operator==(const SiPMHit &right) const;

  inline void *operator new(size_t);
  inline void operator delete(void* aHit);

  G4int GetSiPMnum() const { return fSiPMnum; }
  void SetSiPMnum(G4int n) { fSiPMnum = n; }
  G4int GetTowernum() const { return fTowernum; }
  void SetTowernum(G4int n) { fTowernum = n; }

  G4int GetX() const { return fX; }
  void SetX(G4int n) { fX = n; }
  G4int GetY() const { return fY; }
  void SetY(G4int n) { fY = n; }

  G4int GetTowerX() const { return fTowerX; }
  void SetTowerX(G4int n) { fTowerX = n; }
  G4int GetTowerY() const { return fTowerY; }
  void SetTowerY(G4int n) { fTowerY = n; }

  G4int GetIsFront() {return fFront;}
  void SetFront() {fFront=1;}


  void photonCount() { fPhotons++; }
  G4int GetPhotonCount() const { return fPhotons; }

  void CountWavlenSpectrum(Interface::hitRange range);
  Interface::WavlenSpectrum GetWavlenSpectrum() const { return fWavlenSpectrum; }

  void CountTimeStruct(Interface::hitRange range);
  Interface::TimeStruct GetTimeStruct() const { return fTimeStruct; }
private:
  G4int fPhotons;
  G4int fSiPMnum;
  G4int fTowernum;
  G4int fX;
  G4int fY;
  G4int fFront;
  G4int fTowerX;
  G4int fTowerY;
  Interface::WavlenSpectrum fWavlenSpectrum;
  Interface::TimeStruct fTimeStruct;

  G4int fWavBin;
  G4int fTimeBin;
};

// G4THitsCollection은 Geant4에서 제공하는 템플릿 클래스로, G4VHit 클래스를 저장하는 컬렉션 클래스를 만들 때 사용
typedef G4THitsCollection<SiPMHit> SiPMHitsCollection; // 즉 입자와 상호작용하여 생성된 정보를 저장하는 SiPMHit 클래스의 객체들을 SiPMHitsCollection로 관리

// extern @ : @ 함수 or 변수의 type 정의가 이미 다른 곳에서 이루어졌다는 뜻
// G4ThreadLocal로 정의하면 멀티 쓰레드 or 프로세스 사용할 때 여러 쓰레드에서 코드를 동시에 참조할 때 정의가 겹치지 않도록 방지할 수 있다.
extern G4ThreadLocal G4Allocator<SiPMHit>* SiPMHitAllocator;

inline void* SiPMHit::operator new(size_t) {
  if (!SiPMHitAllocator) SiPMHitAllocator = new G4Allocator<SiPMHit>;
  return (void*)SiPMHitAllocator->MallocSingle();
}

inline void SiPMHit::operator delete(void*aHit) {
  SiPMHitAllocator->FreeSingle((SiPMHit*) aHit);
}

#endif
