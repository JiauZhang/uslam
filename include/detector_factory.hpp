# ifndef __DETECTOR_FACTORY__H__
# define __DETECTOR_FACTORY__H__

#include <map>
#include <string>
#include <vector>

#include "detector.hpp"

namespace uslam {

class Detector;

class DetectorRegistry {
 public:
  typedef shared_ptr<Detector> (*Creator)(const DetectorParameter&);
  typedef std::map<string, Creator> CreatorRegistry;

  static CreatorRegistry& Registry() {
    static CreatorRegistry* g_registry_ = new CreatorRegistry();
    return *g_registry_;
  }

  // Adds a creator.
  static void AddCreator(const string& type, Creator creator) {
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 0) {
        std::cout << "Detector type " << type << " already registered.";
	} else {
		registry[type] = creator;
	}
  }

  // Get a detector using a DetectorParameter.
  static shared_ptr<Detector> CreateDetector(const DetectorParameter& param) {
    const string& type = param.type;
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Detector type: " << type \
				  << " (known types: " << DetectorTypeListString() << ")";
		return NULL;
	} else {
		return registry[type](param);
	}
  }

  static vector<string> DetectorTypeList() {
    CreatorRegistry& registry = Registry();
    vector<string> detector_types;
    for (typename CreatorRegistry::iterator iter = registry.begin();
         iter != registry.end(); ++iter) {
      detector_types.push_back(iter->first);
    }
    return detector_types;
  }

 private:
  // Detector registry should never be instantiated - everything is done with its
  // static variables.
  DetectorRegistry() {}

  static string DetectorTypeListString() {
    vector<string> detector_types = DetectorTypeList();
    string detector_types_str;
    for (vector<string>::iterator iter = detector_types.begin();
         iter != detector_types.end(); ++iter) {
      if (iter != detector_types.begin()) {
        detector_types_str += ", ";
      }
      detector_types_str += *iter;
    }
    return detector_types_str;
  }
}; // DetectorRegistry

class DetectorRegisterer {
 public:
  DetectorRegisterer(const string& type, \
					 shared_ptr<Detector> (*creator)(const DetectorParameter&)) {
    DetectorRegistry::AddCreator(type, creator);
  }
};

#define REGISTER_DETECTOR_CREATOR(type, creator)             \
  static DetectorRegisterer g_creator_##type(#type, creator) \

#define REGISTER_DETECTOR_CLASS(type)                                             \
  shared_ptr<Detector> Creator_##type##Detector(const DetectorParameter& param) \
  {                                                                            \
    return shared_ptr<Detector>(new type##Detector(param));           \
  }                                                                            \
  REGISTER_DETECTOR_CREATOR(type, Creator_##type##Detector)
	
} // namespace uslam

# endif