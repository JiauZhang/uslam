# ifndef __VIEWER_FACTORY__H__
# define __VIEWER_FACTORY__H__

#include <map>
#include <string>
#include <vector>

#include "viewer.hpp"

namespace uslam {

template <typename Dtype>
class Viewer;

template <typename Dtype>
class ViewerRegistry {
 public:
  typedef shared_ptr<Viewer<Dtype> > (*Creator)(const ViewerParameter&);
  typedef std::map<string, Creator> CreatorRegistry;

  static CreatorRegistry& Registry() {
    static CreatorRegistry* g_registry_ = new CreatorRegistry();
    return *g_registry_;
  }

  // Adds a creator.
  static void AddCreator(const string& type, Creator creator) {
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 0) {
        std::cout << "Viewer type " << type << " already registered.";
	} else {
		registry[type] = creator;
	}
  }

  // Get a viewer using a ViewerParameter.
  static shared_ptr<Viewer<Dtype> > CreateViewer(const ViewerParameter& param) {
    const string& type = param.type();
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Viewer type: " << type \
				  << " (known types: " << ViewerTypeListString() << ")";
	} else {
		return registry[type](param);
	}
  }

  static vector<string> ViewerTypeList() {
    CreatorRegistry& registry = Registry();
    vector<string> viewer_types;
    for (typename CreatorRegistry::iterator iter = registry.begin();
         iter != registry.end(); ++iter) {
      viewer_types.push_back(iter->first);
    }
    return viewer_types;
  }

 private:
  // Viewer registry should never be instantiated - everything is done with its
  // static variables.
  ViewerRegistry() {}

  static string ViewerTypeListString() {
    vector<string> viewer_types = ViewerTypeList();
    string viewer_types_str;
    for (vector<string>::iterator iter = viewer_types.begin();
         iter != viewer_types.end(); ++iter) {
      if (iter != viewer_types.begin()) {
        viewer_types_str += ", ";
      }
      viewer_types_str += *iter;
    }
    return viewer_types_str;
  }
}; // ViewerRegistry


template <typename Dtype>
class ViewerRegisterer {
 public:
  ViewerRegisterer(const string& type, \
					 shared_ptr<Viewer<Dtype> > (*creator)(const ViewerParameter&)) {
    ViewerRegistry<Dtype>::AddCreator(type, creator);
  }
};


#define REGISTER_MATCHER_CREATOR(type, creator)                                  \
  static ViewerRegisterer<float> g_creator_f_##type(#type, creator<float>);     \
  static ViewerRegisterer<double> g_creator_d_##type(#type, creator<double>)    \

#define REGISTER_MATCHER_CLASS(type)                                             \
  template <typename Dtype>                                                    \
  shared_ptr<Viewer<Dtype> > Creator_##type##Viewer(const ViewerParameter& param) \
  {                                                                            \
    return shared_ptr<Viewer<Dtype> >(new type##Viewer<Dtype>(param));           \
  }                                                                            \
REGISTER_MATCHER_CREATOR(type, Creator_##type##Viewer)
	
} // namespace uslam

# endif