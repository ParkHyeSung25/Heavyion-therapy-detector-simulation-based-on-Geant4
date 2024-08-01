// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__rootIO
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include/Interface.h"
#include "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include/RootInterface.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *InterfacecLcLSiPMData_Dictionary();
   static void InterfacecLcLSiPMData_TClassManip(TClass*);
   static void *new_InterfacecLcLSiPMData(void *p = nullptr);
   static void *newArray_InterfacecLcLSiPMData(Long_t size, void *p);
   static void delete_InterfacecLcLSiPMData(void *p);
   static void deleteArray_InterfacecLcLSiPMData(void *p);
   static void destruct_InterfacecLcLSiPMData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Interface::SiPMData*)
   {
      ::Interface::SiPMData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Interface::SiPMData));
      static ::ROOT::TGenericClassInfo 
         instance("Interface::SiPMData", "Interface.h", 19,
                  typeid(::Interface::SiPMData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &InterfacecLcLSiPMData_Dictionary, isa_proxy, 4,
                  sizeof(::Interface::SiPMData) );
      instance.SetNew(&new_InterfacecLcLSiPMData);
      instance.SetNewArray(&newArray_InterfacecLcLSiPMData);
      instance.SetDelete(&delete_InterfacecLcLSiPMData);
      instance.SetDeleteArray(&deleteArray_InterfacecLcLSiPMData);
      instance.SetDestructor(&destruct_InterfacecLcLSiPMData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Interface::SiPMData*)
   {
      return GenerateInitInstanceLocal((::Interface::SiPMData*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Interface::SiPMData*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *InterfacecLcLSiPMData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Interface::SiPMData*)nullptr)->GetClass();
      InterfacecLcLSiPMData_TClassManip(theClass);
   return theClass;
   }

   static void InterfacecLcLSiPMData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *InterfacecLcLTowerData_Dictionary();
   static void InterfacecLcLTowerData_TClassManip(TClass*);
   static void *new_InterfacecLcLTowerData(void *p = nullptr);
   static void *newArray_InterfacecLcLTowerData(Long_t size, void *p);
   static void delete_InterfacecLcLTowerData(void *p);
   static void deleteArray_InterfacecLcLTowerData(void *p);
   static void destruct_InterfacecLcLTowerData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Interface::TowerData*)
   {
      ::Interface::TowerData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Interface::TowerData));
      static ::ROOT::TGenericClassInfo 
         instance("Interface::TowerData", "Interface.h", 45,
                  typeid(::Interface::TowerData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &InterfacecLcLTowerData_Dictionary, isa_proxy, 4,
                  sizeof(::Interface::TowerData) );
      instance.SetNew(&new_InterfacecLcLTowerData);
      instance.SetNewArray(&newArray_InterfacecLcLTowerData);
      instance.SetDelete(&delete_InterfacecLcLTowerData);
      instance.SetDeleteArray(&deleteArray_InterfacecLcLTowerData);
      instance.SetDestructor(&destruct_InterfacecLcLTowerData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Interface::TowerData*)
   {
      return GenerateInitInstanceLocal((::Interface::TowerData*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Interface::TowerData*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *InterfacecLcLTowerData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Interface::TowerData*)nullptr)->GetClass();
      InterfacecLcLTowerData_TClassManip(theClass);
   return theClass;
   }

   static void InterfacecLcLTowerData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *InterfacecLcLEdepData_Dictionary();
   static void InterfacecLcLEdepData_TClassManip(TClass*);
   static void *new_InterfacecLcLEdepData(void *p = nullptr);
   static void *newArray_InterfacecLcLEdepData(Long_t size, void *p);
   static void delete_InterfacecLcLEdepData(void *p);
   static void deleteArray_InterfacecLcLEdepData(void *p);
   static void destruct_InterfacecLcLEdepData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Interface::EdepData*)
   {
      ::Interface::EdepData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Interface::EdepData));
      static ::ROOT::TGenericClassInfo 
         instance("Interface::EdepData", "Interface.h", 56,
                  typeid(::Interface::EdepData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &InterfacecLcLEdepData_Dictionary, isa_proxy, 4,
                  sizeof(::Interface::EdepData) );
      instance.SetNew(&new_InterfacecLcLEdepData);
      instance.SetNewArray(&newArray_InterfacecLcLEdepData);
      instance.SetDelete(&delete_InterfacecLcLEdepData);
      instance.SetDeleteArray(&deleteArray_InterfacecLcLEdepData);
      instance.SetDestructor(&destruct_InterfacecLcLEdepData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Interface::EdepData*)
   {
      return GenerateInitInstanceLocal((::Interface::EdepData*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Interface::EdepData*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *InterfacecLcLEdepData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Interface::EdepData*)nullptr)->GetClass();
      InterfacecLcLEdepData_TClassManip(theClass);
   return theClass;
   }

   static void InterfacecLcLEdepData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *InterfacecLcLLeakageData_Dictionary();
   static void InterfacecLcLLeakageData_TClassManip(TClass*);
   static void *new_InterfacecLcLLeakageData(void *p = nullptr);
   static void *newArray_InterfacecLcLLeakageData(Long_t size, void *p);
   static void delete_InterfacecLcLLeakageData(void *p);
   static void deleteArray_InterfacecLcLLeakageData(void *p);
   static void destruct_InterfacecLcLLeakageData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Interface::LeakageData*)
   {
      ::Interface::LeakageData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Interface::LeakageData));
      static ::ROOT::TGenericClassInfo 
         instance("Interface::LeakageData", "Interface.h", 72,
                  typeid(::Interface::LeakageData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &InterfacecLcLLeakageData_Dictionary, isa_proxy, 4,
                  sizeof(::Interface::LeakageData) );
      instance.SetNew(&new_InterfacecLcLLeakageData);
      instance.SetNewArray(&newArray_InterfacecLcLLeakageData);
      instance.SetDelete(&delete_InterfacecLcLLeakageData);
      instance.SetDeleteArray(&deleteArray_InterfacecLcLLeakageData);
      instance.SetDestructor(&destruct_InterfacecLcLLeakageData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Interface::LeakageData*)
   {
      return GenerateInitInstanceLocal((::Interface::LeakageData*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Interface::LeakageData*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *InterfacecLcLLeakageData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Interface::LeakageData*)nullptr)->GetClass();
      InterfacecLcLLeakageData_TClassManip(theClass);
   return theClass;
   }

   static void InterfacecLcLLeakageData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *InterfacecLcLGenData_Dictionary();
   static void InterfacecLcLGenData_TClassManip(TClass*);
   static void *new_InterfacecLcLGenData(void *p = nullptr);
   static void *newArray_InterfacecLcLGenData(Long_t size, void *p);
   static void delete_InterfacecLcLGenData(void *p);
   static void deleteArray_InterfacecLcLGenData(void *p);
   static void destruct_InterfacecLcLGenData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Interface::GenData*)
   {
      ::Interface::GenData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Interface::GenData));
      static ::ROOT::TGenericClassInfo 
         instance("Interface::GenData", "Interface.h", 120,
                  typeid(::Interface::GenData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &InterfacecLcLGenData_Dictionary, isa_proxy, 4,
                  sizeof(::Interface::GenData) );
      instance.SetNew(&new_InterfacecLcLGenData);
      instance.SetNewArray(&newArray_InterfacecLcLGenData);
      instance.SetDelete(&delete_InterfacecLcLGenData);
      instance.SetDeleteArray(&deleteArray_InterfacecLcLGenData);
      instance.SetDestructor(&destruct_InterfacecLcLGenData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Interface::GenData*)
   {
      return GenerateInitInstanceLocal((::Interface::GenData*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Interface::GenData*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *InterfacecLcLGenData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Interface::GenData*)nullptr)->GetClass();
      InterfacecLcLGenData_TClassManip(theClass);
   return theClass;
   }

   static void InterfacecLcLGenData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *InterfacecLcLEventData_Dictionary();
   static void InterfacecLcLEventData_TClassManip(TClass*);
   static void *new_InterfacecLcLEventData(void *p = nullptr);
   static void *newArray_InterfacecLcLEventData(Long_t size, void *p);
   static void delete_InterfacecLcLEventData(void *p);
   static void deleteArray_InterfacecLcLEventData(void *p);
   static void destruct_InterfacecLcLEventData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Interface::EventData*)
   {
      ::Interface::EventData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Interface::EventData));
      static ::ROOT::TGenericClassInfo 
         instance("Interface::EventData", "Interface.h", 136,
                  typeid(::Interface::EventData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &InterfacecLcLEventData_Dictionary, isa_proxy, 4,
                  sizeof(::Interface::EventData) );
      instance.SetNew(&new_InterfacecLcLEventData);
      instance.SetNewArray(&newArray_InterfacecLcLEventData);
      instance.SetDelete(&delete_InterfacecLcLEventData);
      instance.SetDeleteArray(&deleteArray_InterfacecLcLEventData);
      instance.SetDestructor(&destruct_InterfacecLcLEventData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Interface::EventData*)
   {
      return GenerateInitInstanceLocal((::Interface::EventData*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Interface::EventData*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *InterfacecLcLEventData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Interface::EventData*)nullptr)->GetClass();
      InterfacecLcLEventData_TClassManip(theClass);
   return theClass;
   }

   static void InterfacecLcLEventData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_InterfacecLcLSiPMData(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::SiPMData : new ::Interface::SiPMData;
   }
   static void *newArray_InterfacecLcLSiPMData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::SiPMData[nElements] : new ::Interface::SiPMData[nElements];
   }
   // Wrapper around operator delete
   static void delete_InterfacecLcLSiPMData(void *p) {
      delete ((::Interface::SiPMData*)p);
   }
   static void deleteArray_InterfacecLcLSiPMData(void *p) {
      delete [] ((::Interface::SiPMData*)p);
   }
   static void destruct_InterfacecLcLSiPMData(void *p) {
      typedef ::Interface::SiPMData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Interface::SiPMData

namespace ROOT {
   // Wrappers around operator new
   static void *new_InterfacecLcLTowerData(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::TowerData : new ::Interface::TowerData;
   }
   static void *newArray_InterfacecLcLTowerData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::TowerData[nElements] : new ::Interface::TowerData[nElements];
   }
   // Wrapper around operator delete
   static void delete_InterfacecLcLTowerData(void *p) {
      delete ((::Interface::TowerData*)p);
   }
   static void deleteArray_InterfacecLcLTowerData(void *p) {
      delete [] ((::Interface::TowerData*)p);
   }
   static void destruct_InterfacecLcLTowerData(void *p) {
      typedef ::Interface::TowerData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Interface::TowerData

namespace ROOT {
   // Wrappers around operator new
   static void *new_InterfacecLcLEdepData(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::EdepData : new ::Interface::EdepData;
   }
   static void *newArray_InterfacecLcLEdepData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::EdepData[nElements] : new ::Interface::EdepData[nElements];
   }
   // Wrapper around operator delete
   static void delete_InterfacecLcLEdepData(void *p) {
      delete ((::Interface::EdepData*)p);
   }
   static void deleteArray_InterfacecLcLEdepData(void *p) {
      delete [] ((::Interface::EdepData*)p);
   }
   static void destruct_InterfacecLcLEdepData(void *p) {
      typedef ::Interface::EdepData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Interface::EdepData

namespace ROOT {
   // Wrappers around operator new
   static void *new_InterfacecLcLLeakageData(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::LeakageData : new ::Interface::LeakageData;
   }
   static void *newArray_InterfacecLcLLeakageData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::LeakageData[nElements] : new ::Interface::LeakageData[nElements];
   }
   // Wrapper around operator delete
   static void delete_InterfacecLcLLeakageData(void *p) {
      delete ((::Interface::LeakageData*)p);
   }
   static void deleteArray_InterfacecLcLLeakageData(void *p) {
      delete [] ((::Interface::LeakageData*)p);
   }
   static void destruct_InterfacecLcLLeakageData(void *p) {
      typedef ::Interface::LeakageData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Interface::LeakageData

namespace ROOT {
   // Wrappers around operator new
   static void *new_InterfacecLcLGenData(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::GenData : new ::Interface::GenData;
   }
   static void *newArray_InterfacecLcLGenData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::GenData[nElements] : new ::Interface::GenData[nElements];
   }
   // Wrapper around operator delete
   static void delete_InterfacecLcLGenData(void *p) {
      delete ((::Interface::GenData*)p);
   }
   static void deleteArray_InterfacecLcLGenData(void *p) {
      delete [] ((::Interface::GenData*)p);
   }
   static void destruct_InterfacecLcLGenData(void *p) {
      typedef ::Interface::GenData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Interface::GenData

namespace ROOT {
   // Wrappers around operator new
   static void *new_InterfacecLcLEventData(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::EventData : new ::Interface::EventData;
   }
   static void *newArray_InterfacecLcLEventData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Interface::EventData[nElements] : new ::Interface::EventData[nElements];
   }
   // Wrapper around operator delete
   static void delete_InterfacecLcLEventData(void *p) {
      delete ((::Interface::EventData*)p);
   }
   static void deleteArray_InterfacecLcLEventData(void *p) {
      delete [] ((::Interface::EventData*)p);
   }
   static void destruct_InterfacecLcLEventData(void *p) {
      typedef ::Interface::EventData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Interface::EventData

namespace ROOT {
   static TClass *vectorlEInterfacecLcLTowerDatagR_Dictionary();
   static void vectorlEInterfacecLcLTowerDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLTowerDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLTowerDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLTowerDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLTowerDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLTowerDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::TowerData>*)
   {
      vector<Interface::TowerData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::TowerData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::TowerData>", -2, "vector", 493,
                  typeid(vector<Interface::TowerData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLTowerDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::TowerData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLTowerDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLTowerDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLTowerDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLTowerDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLTowerDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::TowerData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::TowerData>","std::__1::vector<Interface::TowerData, std::__1::allocator<Interface::TowerData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::TowerData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLTowerDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::TowerData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLTowerDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLTowerDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLTowerDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::TowerData> : new vector<Interface::TowerData>;
   }
   static void *newArray_vectorlEInterfacecLcLTowerDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::TowerData>[nElements] : new vector<Interface::TowerData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLTowerDatagR(void *p) {
      delete ((vector<Interface::TowerData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLTowerDatagR(void *p) {
      delete [] ((vector<Interface::TowerData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLTowerDatagR(void *p) {
      typedef vector<Interface::TowerData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::TowerData>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLStepDatagR_Dictionary();
   static void vectorlEInterfacecLcLStepDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLStepDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLStepDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLStepDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLStepDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLStepDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::StepData>*)
   {
      vector<Interface::StepData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::StepData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::StepData>", -2, "vector", 493,
                  typeid(vector<Interface::StepData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLStepDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::StepData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLStepDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLStepDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLStepDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLStepDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLStepDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::StepData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::StepData>","std::__1::vector<Interface::StepData, std::__1::allocator<Interface::StepData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::StepData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLStepDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::StepData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLStepDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLStepDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLStepDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::StepData> : new vector<Interface::StepData>;
   }
   static void *newArray_vectorlEInterfacecLcLStepDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::StepData>[nElements] : new vector<Interface::StepData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLStepDatagR(void *p) {
      delete ((vector<Interface::StepData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLStepDatagR(void *p) {
      delete [] ((vector<Interface::StepData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLStepDatagR(void *p) {
      typedef vector<Interface::StepData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::StepData>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLSiPMDatagR_Dictionary();
   static void vectorlEInterfacecLcLSiPMDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLSiPMDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLSiPMDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLSiPMDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLSiPMDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLSiPMDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::SiPMData>*)
   {
      vector<Interface::SiPMData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::SiPMData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::SiPMData>", -2, "vector", 493,
                  typeid(vector<Interface::SiPMData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLSiPMDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::SiPMData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLSiPMDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLSiPMDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLSiPMDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLSiPMDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLSiPMDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::SiPMData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::SiPMData>","std::__1::vector<Interface::SiPMData, std::__1::allocator<Interface::SiPMData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::SiPMData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLSiPMDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::SiPMData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLSiPMDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLSiPMDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLSiPMDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::SiPMData> : new vector<Interface::SiPMData>;
   }
   static void *newArray_vectorlEInterfacecLcLSiPMDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::SiPMData>[nElements] : new vector<Interface::SiPMData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLSiPMDatagR(void *p) {
      delete ((vector<Interface::SiPMData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLSiPMDatagR(void *p) {
      delete [] ((vector<Interface::SiPMData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLSiPMDatagR(void *p) {
      typedef vector<Interface::SiPMData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::SiPMData>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLSecondaryDatagR_Dictionary();
   static void vectorlEInterfacecLcLSecondaryDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLSecondaryDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLSecondaryDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLSecondaryDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLSecondaryDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLSecondaryDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::SecondaryData>*)
   {
      vector<Interface::SecondaryData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::SecondaryData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::SecondaryData>", -2, "vector", 493,
                  typeid(vector<Interface::SecondaryData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLSecondaryDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::SecondaryData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLSecondaryDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLSecondaryDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLSecondaryDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLSecondaryDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLSecondaryDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::SecondaryData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::SecondaryData>","std::__1::vector<Interface::SecondaryData, std::__1::allocator<Interface::SecondaryData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::SecondaryData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLSecondaryDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::SecondaryData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLSecondaryDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLSecondaryDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLSecondaryDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::SecondaryData> : new vector<Interface::SecondaryData>;
   }
   static void *newArray_vectorlEInterfacecLcLSecondaryDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::SecondaryData>[nElements] : new vector<Interface::SecondaryData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLSecondaryDatagR(void *p) {
      delete ((vector<Interface::SecondaryData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLSecondaryDatagR(void *p) {
      delete [] ((vector<Interface::SecondaryData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLSecondaryDatagR(void *p) {
      typedef vector<Interface::SecondaryData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::SecondaryData>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLPhysicaleventgR_Dictionary();
   static void vectorlEInterfacecLcLPhysicaleventgR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLPhysicaleventgR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLPhysicaleventgR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLPhysicaleventgR(void *p);
   static void deleteArray_vectorlEInterfacecLcLPhysicaleventgR(void *p);
   static void destruct_vectorlEInterfacecLcLPhysicaleventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::Physicalevent>*)
   {
      vector<Interface::Physicalevent> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::Physicalevent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::Physicalevent>", -2, "vector", 493,
                  typeid(vector<Interface::Physicalevent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLPhysicaleventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::Physicalevent>) );
      instance.SetNew(&new_vectorlEInterfacecLcLPhysicaleventgR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLPhysicaleventgR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLPhysicaleventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLPhysicaleventgR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLPhysicaleventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::Physicalevent> >()));

      ::ROOT::AddClassAlternate("vector<Interface::Physicalevent>","std::__1::vector<Interface::Physicalevent, std::__1::allocator<Interface::Physicalevent> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::Physicalevent>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLPhysicaleventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::Physicalevent>*)nullptr)->GetClass();
      vectorlEInterfacecLcLPhysicaleventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLPhysicaleventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLPhysicaleventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::Physicalevent> : new vector<Interface::Physicalevent>;
   }
   static void *newArray_vectorlEInterfacecLcLPhysicaleventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::Physicalevent>[nElements] : new vector<Interface::Physicalevent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLPhysicaleventgR(void *p) {
      delete ((vector<Interface::Physicalevent>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLPhysicaleventgR(void *p) {
      delete [] ((vector<Interface::Physicalevent>*)p);
   }
   static void destruct_vectorlEInterfacecLcLPhysicaleventgR(void *p) {
      typedef vector<Interface::Physicalevent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::Physicalevent>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLPhotongR_Dictionary();
   static void vectorlEInterfacecLcLPhotongR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLPhotongR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLPhotongR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLPhotongR(void *p);
   static void deleteArray_vectorlEInterfacecLcLPhotongR(void *p);
   static void destruct_vectorlEInterfacecLcLPhotongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::Photon>*)
   {
      vector<Interface::Photon> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::Photon>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::Photon>", -2, "vector", 493,
                  typeid(vector<Interface::Photon>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLPhotongR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::Photon>) );
      instance.SetNew(&new_vectorlEInterfacecLcLPhotongR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLPhotongR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLPhotongR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLPhotongR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLPhotongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::Photon> >()));

      ::ROOT::AddClassAlternate("vector<Interface::Photon>","std::__1::vector<Interface::Photon, std::__1::allocator<Interface::Photon> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::Photon>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLPhotongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::Photon>*)nullptr)->GetClass();
      vectorlEInterfacecLcLPhotongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLPhotongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLPhotongR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::Photon> : new vector<Interface::Photon>;
   }
   static void *newArray_vectorlEInterfacecLcLPhotongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::Photon>[nElements] : new vector<Interface::Photon>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLPhotongR(void *p) {
      delete ((vector<Interface::Photon>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLPhotongR(void *p) {
      delete [] ((vector<Interface::Photon>*)p);
   }
   static void destruct_vectorlEInterfacecLcLPhotongR(void *p) {
      typedef vector<Interface::Photon> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::Photon>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLLeakageDatagR_Dictionary();
   static void vectorlEInterfacecLcLLeakageDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLLeakageDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLLeakageDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLLeakageDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLLeakageDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLLeakageDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::LeakageData>*)
   {
      vector<Interface::LeakageData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::LeakageData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::LeakageData>", -2, "vector", 493,
                  typeid(vector<Interface::LeakageData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLLeakageDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::LeakageData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLLeakageDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLLeakageDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLLeakageDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLLeakageDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLLeakageDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::LeakageData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::LeakageData>","std::__1::vector<Interface::LeakageData, std::__1::allocator<Interface::LeakageData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::LeakageData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLLeakageDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::LeakageData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLLeakageDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLLeakageDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLLeakageDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::LeakageData> : new vector<Interface::LeakageData>;
   }
   static void *newArray_vectorlEInterfacecLcLLeakageDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::LeakageData>[nElements] : new vector<Interface::LeakageData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLLeakageDatagR(void *p) {
      delete ((vector<Interface::LeakageData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLLeakageDatagR(void *p) {
      delete [] ((vector<Interface::LeakageData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLLeakageDatagR(void *p) {
      typedef vector<Interface::LeakageData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::LeakageData>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLGenDatagR_Dictionary();
   static void vectorlEInterfacecLcLGenDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLGenDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLGenDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLGenDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLGenDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLGenDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::GenData>*)
   {
      vector<Interface::GenData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::GenData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::GenData>", -2, "vector", 493,
                  typeid(vector<Interface::GenData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLGenDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::GenData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLGenDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLGenDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLGenDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLGenDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLGenDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::GenData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::GenData>","std::__1::vector<Interface::GenData, std::__1::allocator<Interface::GenData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::GenData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLGenDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::GenData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLGenDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLGenDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLGenDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::GenData> : new vector<Interface::GenData>;
   }
   static void *newArray_vectorlEInterfacecLcLGenDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::GenData>[nElements] : new vector<Interface::GenData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLGenDatagR(void *p) {
      delete ((vector<Interface::GenData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLGenDatagR(void *p) {
      delete [] ((vector<Interface::GenData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLGenDatagR(void *p) {
      typedef vector<Interface::GenData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::GenData>

namespace ROOT {
   static TClass *vectorlEInterfacecLcLEdepDatagR_Dictionary();
   static void vectorlEInterfacecLcLEdepDatagR_TClassManip(TClass*);
   static void *new_vectorlEInterfacecLcLEdepDatagR(void *p = nullptr);
   static void *newArray_vectorlEInterfacecLcLEdepDatagR(Long_t size, void *p);
   static void delete_vectorlEInterfacecLcLEdepDatagR(void *p);
   static void deleteArray_vectorlEInterfacecLcLEdepDatagR(void *p);
   static void destruct_vectorlEInterfacecLcLEdepDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Interface::EdepData>*)
   {
      vector<Interface::EdepData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Interface::EdepData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Interface::EdepData>", -2, "vector", 493,
                  typeid(vector<Interface::EdepData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEInterfacecLcLEdepDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Interface::EdepData>) );
      instance.SetNew(&new_vectorlEInterfacecLcLEdepDatagR);
      instance.SetNewArray(&newArray_vectorlEInterfacecLcLEdepDatagR);
      instance.SetDelete(&delete_vectorlEInterfacecLcLEdepDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEInterfacecLcLEdepDatagR);
      instance.SetDestructor(&destruct_vectorlEInterfacecLcLEdepDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Interface::EdepData> >()));

      ::ROOT::AddClassAlternate("vector<Interface::EdepData>","std::__1::vector<Interface::EdepData, std::__1::allocator<Interface::EdepData> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Interface::EdepData>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEInterfacecLcLEdepDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Interface::EdepData>*)nullptr)->GetClass();
      vectorlEInterfacecLcLEdepDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEInterfacecLcLEdepDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEInterfacecLcLEdepDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::EdepData> : new vector<Interface::EdepData>;
   }
   static void *newArray_vectorlEInterfacecLcLEdepDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Interface::EdepData>[nElements] : new vector<Interface::EdepData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEInterfacecLcLEdepDatagR(void *p) {
      delete ((vector<Interface::EdepData>*)p);
   }
   static void deleteArray_vectorlEInterfacecLcLEdepDatagR(void *p) {
      delete [] ((vector<Interface::EdepData>*)p);
   }
   static void destruct_vectorlEInterfacecLcLEdepDatagR(void *p) {
      typedef vector<Interface::EdepData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Interface::EdepData>

namespace ROOT {
   static TClass *maplEpairlEfloatcOfloatgRcOintgR_Dictionary();
   static void maplEpairlEfloatcOfloatgRcOintgR_TClassManip(TClass*);
   static void *new_maplEpairlEfloatcOfloatgRcOintgR(void *p = nullptr);
   static void *newArray_maplEpairlEfloatcOfloatgRcOintgR(Long_t size, void *p);
   static void delete_maplEpairlEfloatcOfloatgRcOintgR(void *p);
   static void deleteArray_maplEpairlEfloatcOfloatgRcOintgR(void *p);
   static void destruct_maplEpairlEfloatcOfloatgRcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<pair<float,float>,int>*)
   {
      map<pair<float,float>,int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<pair<float,float>,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<pair<float,float>,int>", -2, "map", 916,
                  typeid(map<pair<float,float>,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEpairlEfloatcOfloatgRcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<pair<float,float>,int>) );
      instance.SetNew(&new_maplEpairlEfloatcOfloatgRcOintgR);
      instance.SetNewArray(&newArray_maplEpairlEfloatcOfloatgRcOintgR);
      instance.SetDelete(&delete_maplEpairlEfloatcOfloatgRcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEpairlEfloatcOfloatgRcOintgR);
      instance.SetDestructor(&destruct_maplEpairlEfloatcOfloatgRcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<pair<float,float>,int> >()));

      ::ROOT::AddClassAlternate("map<pair<float,float>,int>","std::__1::map<std::__1::pair<float, float>, int, std::__1::less<std::__1::pair<float, float> >, std::__1::allocator<std::__1::pair<std::__1::pair<float, float> const, int> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<pair<float,float>,int>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEpairlEfloatcOfloatgRcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<pair<float,float>,int>*)nullptr)->GetClass();
      maplEpairlEfloatcOfloatgRcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEpairlEfloatcOfloatgRcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEpairlEfloatcOfloatgRcOintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<pair<float,float>,int> : new map<pair<float,float>,int>;
   }
   static void *newArray_maplEpairlEfloatcOfloatgRcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<pair<float,float>,int>[nElements] : new map<pair<float,float>,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEpairlEfloatcOfloatgRcOintgR(void *p) {
      delete ((map<pair<float,float>,int>*)p);
   }
   static void deleteArray_maplEpairlEfloatcOfloatgRcOintgR(void *p) {
      delete [] ((map<pair<float,float>,int>*)p);
   }
   static void destruct_maplEpairlEfloatcOfloatgRcOintgR(void *p) {
      typedef map<pair<float,float>,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<pair<float,float>,int>

namespace ROOT {
   static TClass *maplEpairlEfloatcOfloatgRcOfloatgR_Dictionary();
   static void maplEpairlEfloatcOfloatgRcOfloatgR_TClassManip(TClass*);
   static void *new_maplEpairlEfloatcOfloatgRcOfloatgR(void *p = nullptr);
   static void *newArray_maplEpairlEfloatcOfloatgRcOfloatgR(Long_t size, void *p);
   static void delete_maplEpairlEfloatcOfloatgRcOfloatgR(void *p);
   static void deleteArray_maplEpairlEfloatcOfloatgRcOfloatgR(void *p);
   static void destruct_maplEpairlEfloatcOfloatgRcOfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<pair<float,float>,float>*)
   {
      map<pair<float,float>,float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<pair<float,float>,float>));
      static ::ROOT::TGenericClassInfo 
         instance("map<pair<float,float>,float>", -2, "map", 916,
                  typeid(map<pair<float,float>,float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEpairlEfloatcOfloatgRcOfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(map<pair<float,float>,float>) );
      instance.SetNew(&new_maplEpairlEfloatcOfloatgRcOfloatgR);
      instance.SetNewArray(&newArray_maplEpairlEfloatcOfloatgRcOfloatgR);
      instance.SetDelete(&delete_maplEpairlEfloatcOfloatgRcOfloatgR);
      instance.SetDeleteArray(&deleteArray_maplEpairlEfloatcOfloatgRcOfloatgR);
      instance.SetDestructor(&destruct_maplEpairlEfloatcOfloatgRcOfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<pair<float,float>,float> >()));

      ::ROOT::AddClassAlternate("map<pair<float,float>,float>","std::__1::map<std::__1::pair<float, float>, float, std::__1::less<std::__1::pair<float, float> >, std::__1::allocator<std::__1::pair<std::__1::pair<float, float> const, float> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<pair<float,float>,float>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEpairlEfloatcOfloatgRcOfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<pair<float,float>,float>*)nullptr)->GetClass();
      maplEpairlEfloatcOfloatgRcOfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEpairlEfloatcOfloatgRcOfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEpairlEfloatcOfloatgRcOfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<pair<float,float>,float> : new map<pair<float,float>,float>;
   }
   static void *newArray_maplEpairlEfloatcOfloatgRcOfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<pair<float,float>,float>[nElements] : new map<pair<float,float>,float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEpairlEfloatcOfloatgRcOfloatgR(void *p) {
      delete ((map<pair<float,float>,float>*)p);
   }
   static void deleteArray_maplEpairlEfloatcOfloatgRcOfloatgR(void *p) {
      delete [] ((map<pair<float,float>,float>*)p);
   }
   static void destruct_maplEpairlEfloatcOfloatgRcOfloatgR(void *p) {
      typedef map<pair<float,float>,float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<pair<float,float>,float>

namespace {
  void TriggerDictionaryInitialization_librootIO_Impl() {
    static const char* headers[] = {
"include/Interface.h",
"include/RootInterface.h",
nullptr
    };
    static const char* includePaths[] = {
"/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include",
"/opt/homebrew/Cellar/root/6.26.06_2/include/root",
"/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO",
"/opt/homebrew/Cellar/root/6.26.06_2/include/root",
"/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "librootIO dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "librootIO dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "include/Interface.h"
#include "include/RootInterface.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Interface", payloadCode, "@",
"Interface::EdepData", payloadCode, "@",
"Interface::EventData", payloadCode, "@",
"Interface::GenData", payloadCode, "@",
"Interface::LeakageData", payloadCode, "@",
"Interface::SiPMData", payloadCode, "@",
"Interface::TowerData", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("librootIO",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_librootIO_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_librootIO_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_librootIO() {
  TriggerDictionaryInitialization_librootIO_Impl();
}
