#include "RootInterface.h"

RootInterface::RootInterface(const std::string& filename)
: fFilename(filename), fNumEvt(0) {
  init();
}

RootInterface::~RootInterface() {}

void RootInterface::PrepareChain(){
  fEventData = new Interface::EventData();
}

void RootInterface::GetChain(const std::string& treename){
  fChain = new TChain(treename.c_str());
  fChain->Add((fFilename+"/*.root").c_str());
  fTree = fChain;
  fTree->SetBranchAddress((treename+"EventData").c_str(),&fEventData);
}

void RootInterface::init() {
  fEventData = new Interface::EventData();
  fFile = TFile::Open(fFilename.c_str(),"UPDATE");
}

void RootInterface::create() {
  fTree = new TTree("crystaldetector","crystaldetector");
  fTree->Branch("EventData",fEventData);
}

void RootInterface::set() {
  fTree = (TTree*)fFile->Get("crystaldetector");
  fTree->SetBranchAddress("EventData",&fEventData);
}

void RootInterface::fill(const Interface::EventData* evt) {
  *fEventData = *evt;
  fTree->Fill();
}

void RootInterface::read(Interface::EventData& evt) {
  fTree->GetEntry(fNumEvt);
  evt = *fEventData;
  fNumEvt++;
}

void RootInterface::write() {
  fFile->WriteTObject(fTree);
}

void RootInterface::close() {
  if (fFile) fFile->Close();
  if (fEventData) delete fEventData;
  if (fChain) delete fChain;
}
