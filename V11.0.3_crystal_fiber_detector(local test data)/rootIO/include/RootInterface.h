#ifndef RootInterface_h
#define RootInterface_h 1

#include "Interface.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"

class RootInterface {
public:
  RootInterface(const std::string& filename);
  ~RootInterface();

  void fill(const Interface::EventData* evt);
  void GetChain(const std::string& treename);
  void read(Interface::EventData& evt);
  void create();
  void set();
  void write();
  void close();

  TTree* getTree();
  unsigned int entries() { return fTree->GetEntries(); }
  unsigned int numEvt() { return fNumEvt; }

private:
  void init();
  void PrepareChain();
  
  TChain* fChain;
  TFile* fFile;
  TTree* fTree;
  std::string fFilename;
  Interface::EventData* fEventData;
  unsigned int fNumEvt;
};

#endif
