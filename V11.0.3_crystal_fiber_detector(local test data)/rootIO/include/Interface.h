#ifndef Interface_h
#define Interface_h 1

#include <vector>
#include <utility>
#include <map>

class Interface {
public:
  Interface() {};
  ~Interface() {};

  typedef std::pair<float,float> hitRange;
  typedef std::pair<int,int> hitXY;
  typedef std::map<hitRange, int> TimeStruct;
  typedef std::map<hitRange, float> WaveForm;
  typedef std::map<hitRange, int> WavlenSpectrum;

  struct SiPMData {
    SiPMData() {};
    virtual ~SiPMData() {};

    int count;
    int SiPMnum;
    int x;
    int y;
    //threeVector pos;
    TimeStruct timeStruct;
    WaveForm waveForm;
    WavlenSpectrum wavlenSpectrum;
  };

  struct Physicalevent{
    Physicalevent() {};
    virtual ~Physicalevent() {};

    double x;
    double y;
    double z;
    int physicalID;
    int particleID;
    double energy;
  };

  struct TowerData {
    TowerData() {};
    virtual ~TowerData() {};

    int numx;
    int numy;
    int towerNum;
    std::vector<SiPMData> SiPMs;
    std::vector<SiPMData> SiPMFronts;
  };

  struct EdepData {
    EdepData() {};
    virtual ~EdepData() {};

    float Edep;
    int towerNum;
  };

  struct Photon {
    Photon() {};
    virtual ~Photon() {};

    int opticalPhotonNumber;

  };

  struct LeakageData {
    LeakageData() {};
    virtual ~LeakageData() {};

    float E;
    float px;
    float py;
    float pz;
    float vx;
    float vy;
    float vz;
    float vt;
    int pdgId;
  };

  struct SecondaryData {
    SecondaryData() {};
    virtual ~SecondaryData() {};

    float E;
    float px;
    float py;
    float pz;
    float vx;
    float vy;
    float vz;
    float vt;
    int pdgId;
    int trackId;
  };
  
  struct StepData {
    StepData() {};
    virtual ~StepData() {};

    float E;
    float px;
    float py;
    float pz;
    float vx;
    float vy;
    float vz;
    float vt;
    int pdgId;
    int trackId;
  };


  struct GenData {
    GenData() {};
    virtual ~GenData() {};

    float E;
    float px;
    float py;
    float pz;
    float vx;
    float vy;
    float vz;
    float vt;
    int pdgId;
  };


  struct EventData {
    EventData() {};
    virtual ~EventData() {};

    int event_number;
    std::vector<TowerData> towers;
    std::vector<EdepData> Edeps;
    std::vector<LeakageData> leaks;
    std::vector<SecondaryData> seconds;
    std::vector<StepData> steps;
    std::vector<GenData> GenPtcs;
    std::vector<Photon> opticalPhotons;
    std::vector<Physicalevent> totPhysicals;
  };

};

#endif
