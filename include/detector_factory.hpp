# ifndef __MATCHER_FACTORY__H__
# define __MATCHER_FACTORY__H__

#include <map>
#include <string>
#include <vector>

#include "detector.hpp"

namespace uslam {

template <typename Dtype>
class Detector;

template <typename Dtype>
class DetectorRegistry {
 public:
  typedef shared_ptr<Detector<Dtype> > (*Creator)(const DetectorParameter&);
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
  static shared_ptr<Detector<Dtype> > CreateDetector(const DetectorParameter& param) {
    const string& type = param.type();
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Detector type: " << type \
				  << " (known types: " << DetectorTypeListString() << ")";
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


template <typename Dtype>
class DetectorRegisterer {
 public:
  DetectorRegisterer(const string& type, \
					 shared_ptr<Detector<Dtype> > (*creator)(const DetectorParameter&)) {
    DetectorRegistry<Dtype>::AddCreator(type, creator);
  }
};


#define REGISTER_MATCHER_CREATOR(type, creator)                                  \
  static DetectorRegisterer<float> g_creator_f_##type(#type, creator<float>);     \
  static DetectorRegisterer<double> g_creator_d_##type(#type, creator<double>)    \

#define REGISTER_MATCHER_CLASS(type)                                             \
  template <typename Dtype>                                                    \
  shared_ptr<Detector<Dtype> > Creator_##type##Detector(const DetectorParameter& param) \
  {                                                                            \
    return shared_ptr<Detector<Dtype> >(new type##Detector<Dtype>(param));           \
  }                                                                            \
REGISTER_MATCHER_CREATOR(type, Creator_##type##Detector)
	
} // namespace uslam

# endif